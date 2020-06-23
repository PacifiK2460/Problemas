/* Auto-generated by libinteractive. Do not edit. */
#include <errno.h>
#include <fcntl.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#if !defined(PRIuS)
#define PRIuS "zu"
#endif

#define NUM_PROCESSES 2
#define NUM_PIPES 2
#define LABEL_FORMAT "[%14s] "

#define print_error(fmt, ...) fprintf(stderr, LABEL_FORMAT " (%s:%" PRIuS ") " fmt ": %s\n", \
	"ERROR", __FILE__, __LINE__, ##__VA_ARGS__, strerror(errno))

static const char* interfaces[] = {
	"Main", "Bubble"
};
static const char* pipeNames[] = {
	"./Bubble_in", "./Bubble_out"
};
static char* const commands[][2] = {
	{ "libinteractive/Main/Main", NULL },
	{ "libinteractive/Bubble/Bubble", NULL },
};
static char* const debug_commands[][4] = {
	{ "libinteractive/Main/Main", NULL, NULL, NULL },
	{ "/usr/bin/gdbserver", "127.0.0.1:8042", "libinteractive/Bubble/Bubble_debug", NULL },
};
static char* const envs[][1] = {
	{ NULL },
	{ NULL },
};

typedef struct {
	int fd;
	bool closed;
	ssize_t pos;
	char buf[1024];
} buffer;

static buffer buffers[2 * NUM_PROCESSES];
static int pids[NUM_PROCESSES] = {0};

static void execute(size_t i, int input_fd, bool debug) {
	int localpipes[4];
	if (pipe(localpipes) == -1) {
		print_error("pipe");
		return;
	}
	if (pipe(localpipes + 2) == -1) {
		print_error("pipe");
		return;
	}

	int pid = vfork();
	if (pid == -1) {
		print_error("fork");
	} else if (pid > 0) {
		// Close write end of the pipes.
		close(localpipes[1]);
		close(localpipes[3]);

		pids[i] = pid;
		buffers[2*i].fd = localpipes[0];
		buffers[2*i+1].fd = localpipes[2];
	} else {
		// Close read ends of local pipes.
		close(localpipes[0]);
		close(localpipes[2]);

		// Close stdout,stderr and redirect them to the pipes.
		if (dup2(localpipes[1], 1) == -1) {
			print_error("dup2");
		}
		if (dup2(localpipes[3], 2) == -1) {
			print_error("dup2");
		}

		// Close duplicated ends.
		close(localpipes[1]);
		close(localpipes[3]);

		// Close stdin except for the first program.
		if (i == 0) {
			if (dup2(input_fd, 0) == -1) {
				print_error("dup2");
			}
			if (input_fd != 0) {
				close(input_fd);
			}
		} else {
			close(0);
		}

		if (!debug) {
			if (execve(commands[i][0], commands[i], envs[i]) == -1) {
				print_error("execve %s", commands[i][0]);
				_exit(1);
			}
		} else {
			if (execve(debug_commands[i][0], debug_commands[i], envs[i]) == -1) {
				print_error("execve %s", commands[i][0]);
				_exit(1);
			}
		}
	}
}

static int recursively_mkdir_parents(const char* filename) {
	char path_buffer[1024];
	strcpy(path_buffer, filename);
	char* path = path_buffer;
	if (*path == '/')
		++path;

	for (char* current = strchr(path, '/');
	     current != NULL;
	     current = strchr(current + 1, '/')) {
		*current = '\0';
		if (mkdir(path_buffer, 0755) == -1 && errno != EEXIST) {
			print_error("mkdir %s", path_buffer);
			return -1;
		}
		*current = '/';
	}
	return 0;
}

static int run(int input_fd, bool debug) {
	long maxrss = 0;
	long long utime = 0;

	int retval = 0;
	struct stat st;
	for (size_t i = 0; i < NUM_PIPES; i++) {
		if (stat(pipeNames[i], &st) != -1) {
			if (S_ISFIFO(st.st_mode)) {
				// Pipe already exists.
				continue;
			} else {
				if (unlink(pipeNames[i]) == -1) {
					print_error("unlink %s", pipeNames[i]);
					retval = 1;
					goto cleanup;
				}
			}
		} else if (errno != ENOENT) {
			print_error("stat %s", pipeNames[i]);
			retval = 1;
			goto cleanup;
		}
		if (recursively_mkdir_parents(pipeNames[i]) == -1) {
			retval = 1;
			goto cleanup;
		}
		if (mknod(pipeNames[i], 0664 | S_IFIFO, 0) == -1) {
			print_error("mknod %s", pipeNames[i]);
			retval = 1;
			goto cleanup;
		}
	}

	memset(buffers, 0, sizeof(buffers));

	// Execute the children
	for (size_t i = 0; i < NUM_PROCESSES; i++) {
		execute(i, input_fd, debug);
	}

	// Redirect children's outputs to screen
	fd_set readfds, writefds, exceptfds;
	FD_ZERO(&writefds);
	FD_ZERO(&exceptfds);
	while (1) {
		FD_ZERO(&readfds);
		int nfds = 0;
		for (size_t i = 0; i < 2 * NUM_PROCESSES; i++) {
			if (buffers[i].closed) continue;
			FD_SET(buffers[i].fd, &readfds);
			if (nfds < buffers[i].fd) {
				nfds = buffers[i].fd;
			}
		}

		if (nfds == 0) {
			// All children are done writing.
			break;
		}

		int ready = select(nfds + 1, &readfds, &writefds, &exceptfds, NULL);

		if (ready == -1) {
			print_error("select");
			break;
		}

		for (size_t i = 0; i < 2 * NUM_PROCESSES; i++) {
			if (!FD_ISSET(buffers[i].fd, &readfds)) continue;
			ssize_t nbytes = read(buffers[i].fd,
					buffers[i].buf + buffers[i].pos,
					sizeof(buffers[i].buf) - buffers[i].pos);
			if (nbytes == -1) {
				print_error("read %zu", i);
			} else if (nbytes > 0) {
				buffers[i].pos += nbytes;
				off_t off = 0;
				for (int j = 0; j < buffers[i].pos; j++) {
					if (buffers[i].buf[j] == '\n') {
						buffers[i].buf[j] = '\0';
						if (i == 0) {
							if (isatty(1) && isatty(2)) {
								fprintf(stderr, "\033[1m" LABEL_FORMAT "\033[0m%s\n",
									interfaces[i / 2], buffers[i].buf + off);
							} else if (isatty(1)) {
								fprintf(stdout, "\033[1m" LABEL_FORMAT "\033[0m%s\n",
									interfaces[i / 2], buffers[i].buf + off);
							} else {
								fprintf(stdout, "%s\n", buffers[i].buf + off);
							}
						} else {
							fprintf(stderr, LABEL_FORMAT "%s\n",
								interfaces[i / 2], buffers[i].buf + off);
						}
						off = j + 1;
					}
				}
				if (off != 0) {
					buffers[i].pos -= off;
					memmove(buffers[i].buf, buffers[i].buf + off, buffers[i].pos);
				} else if (buffers[i].pos == sizeof(buffers[i].buf)) {
					fwrite(buffers[i].buf, sizeof(buffers[i].buf), 1, i == 0 ? stdout : stderr);
					buffers[i].pos = 0;
				}
			} else {
				buffers[i].closed = true;
			}
		}
	}

	// Wait for children
	for (size_t i = 0; i < NUM_PROCESSES; i++) {
		int status;
		struct rusage usage;
		if (wait4(pids[i], &status, 0, &usage) == -1) {
			print_error("wait4 %zu", i);
		} else if (i != 0) {
			if (maxrss < usage.ru_maxrss) {
				maxrss = usage.ru_maxrss;
			}
			utime += usage.ru_utime.tv_sec * 1000000LL + usage.ru_utime.tv_usec;
		}
	}

cleanup:
	for (size_t i = 0; i < NUM_PIPES; i++) {
		if (unlink(pipeNames[i]) == -1) {
			print_error("unlink %s", pipeNames[i]);
		}
	}

#if defined(__APPLE__)
	// Apple defines rusage.ru_maxrss as bytes, whereas Linux defines it as
	// kilobytes.
	fprintf(stderr, "\nMemory: %7.3f MB\n", maxrss / 1048576.0f);
#else
	fprintf(stderr, "\nMemory: %7.3f MB\n", maxrss / 1024.0f);
#endif
	fprintf(stderr, "Time:   %7.3f s\n", utime / 1e6);

	return retval;
}

int main(int argc, char* argv[]) {
	int retval = 0;
	bool debug = false;
	bool pause = false;
	bool from_stdin = true;
	// Try to use the parameters as input filenames.
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "--pause") == 0) {
			pause = true;
			continue;
		}
		if (strcmp(argv[i], "--debug") == 0) {
			debug = true;
			continue;
		}
		from_stdin = false;
		int input_fd = open(argv[i], O_RDONLY);
		if (input_fd == -1) {
			print_error("open %s", argv[i]);
			continue;
		}
		fprintf(stderr, "%s:\n", argv[i]);
		fflush(stderr);
		if (run(input_fd, debug) != 0) {
			retval = 1;
		}
		close(input_fd);
		fprintf(stderr, "\n");
	}
	// No parameters, use stdin.
	if (from_stdin) {
		retval = run(STDIN_FILENO, debug);
	}
	if (pause) {
		fgetc(stdin);
	}
	return retval;
}