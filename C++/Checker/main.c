#ifdef WIN32
    #include <windows.h>
#else
    #include <termios.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdlib.h> //Library for system function
    #include <stdio.h> //Standar library for input / output
    #include <signal.h> //Catch ctrl-C
    #include <stdbool.h> //bool
    #include <ncurses.h>
    #include <sys/ioctl.h>
    #include <string.h>
    #include <errno.h>
#endif

#include <string.h>
#include <time.h> 
#include <unistd.h>
#include <limits.h>

#define BOLD    "\033[1m"
#define RED     "\x1b[101m\x1b[30m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"
#define BK      "\x1b[30m\x1b[47m"

#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))

static volatile int keepRunning = 1; //Variable to run
void inputreflect(bool enable);
int kbhit(void);
void intHandler(int dummy); 
int display_main();
void logo();
int checksum(void *buffer, size_t len, unsigned int seed);
void quit();
int display_making();
int check(char n[]);
void make(char n[],long long c);

int main(void)
{
    system("clear");
    inputreflect(false);
   //catch ctr-c
    signal(SIGINT, intHandler);
    system("tput smcup"); //Blocks scrolling
    system("setterm -cursor off"); //Remove cursor blinking in terminal
    int o = display_main();
    while(1)
    {
        switch(o)
        {
            case 0:
                o = display_main();
                break;
            case 1:
                o = display_making();
        }
    }
}

int display_main()
{
    //Initializa var sizes
    //l = 80
    wchar_t OriginalC[11] = { 0x3004, 0xA007, 0x1002, 0x1005, 0x2006, 0x4006, 0xA006, 0x7006,
                            0xA006, 0xC004, 0x1000 };
    
    for (unsigned int JQsdo = 0, JIVik = 0; JQsdo < 11; JQsdo++)
    {
            JIVik = OriginalC[JQsdo];
            JIVik = (((JIVik & 0xFFFF) >> 12) | (JIVik << 4)) & 0xFFFF;
            JIVik --;
            OriginalC[JQsdo] = JIVik;
    }
    printf("%s",BOLD);
    for(int i=0;i<11;i++)
        printf("%c",OriginalC[i]);
    printf("%s\n",RESET);

    int key;
    printf("⋯: Usa las flechas de movimiento [← → / ↑↓] y [ENTER] para %s elegir una opcion. %s\n⋯: Presiona %s ctrl + c %s para %s salir. %s\n\n",BK,RESET,RED,RESET,RED,RESET);

    printf("01 ► Validacion de Bin / Crear CCs / Extrapolacion\n04 ► Checker de CCs\n\n");

    char *op[4]; 
    op[0] = " ► Validacion de Bin / Crear CCs / Extrapolacion ";
    op[1] = " ►                 Checker de CCs                ";
    int i=0;

    while(keepRunning)
    {
        if(kbhit())
        {
            key = getchar();
            if(key == 27)
            {
                key = getchar();
                key = getchar();
                switch(key)
                {
                    case 65:
                        //Arriba
                        i--;
                        if(i < 0)
                            i = 1;
                        i = i%2;
                        printf("\r%s%s%s\r",BK,op[i],RESET);  // key left
                        fflush(stdout);
                        break;
                    case 66:
                        //Abajo
                        i++;
                        if(i < 0)
                            i = 1;
                        i = i%2;
                        printf("\r%s%s%s\r",BK,op[i],RESET);  // key left
                        fflush(stdout);break;
                    case 67:
                        //Derecha
                        i--;
                        if(i < 0)
                            i = 1;
                        i = i%2;
                        printf("\r%s%s%s\r",BK,op[i],RESET);  // key left
                        fflush(stdout);
                        break;
                    case 68:
                        //Izquierda
                        i++;
                        if(i < 0)
                            i = 1;
                        i = i%2;
                        printf("\r%s%s%s\r",BK,op[i],RESET);  // key left
                        fflush(stdout);
                        break;
                }
            }
            else if(key == 10)
            {
                return i+1;
            }
        }
        sleep(1/25);
    }
    quit();
}

int display_making()
{
    system("clear");
    system("setterm -cursor on");
    //system("tput rmcup");
    inputreflect(true);
    int key;
    char n[17] = {'\0'};
    int i=0;
    int x = 9;
    int y = 7;

    system("clear");
    printf("%s Creacion de CC's %s\n\n⋯: Escribe los digitos (minimo 6) y opcionalmente los demas.\n⋯: Los digitos necesarios seran marcados con un circulo (%s•%s) y los opcionales con una tacha (%s×%s).\n⋯: Tambien puedes escribir una X para que se extrapole.\n\n%s[BIN]: %s ••••••××××××××××\n",BK,RESET,BOLD,RESET,BOLD,RESET,BK,RESET);
    fflush(stdout);
    gotoxy(x,y);
    //scanf("%d", &number);
    bin:
    while(keepRunning)
    {
        if(kbhit())
        {
            key = getchar();
            if(((key >= 48 && key <= 57)||(key ==88 || key==120)) && x < 25)
            {
                printf("%c",key);
                n[i] = (char) key;
                i++;
                x++;
            }
            else if(key == 127)
            {
                n[i] = '\0';
                if(x > 9) x--,i--;
                gotoxy(x,y);
                if(x > 8 && x <= 14) printf("•");
                else printf("×");
                gotoxy(x,y);
            }
            else if(key == 10 && x > 14) goto cant;
            if(x == 25) system("setterm -cursor off");
            else system("setterm -cursor on");
        }
    }
    return 0;
    cant:
    gotoxy(9,7);
    printf("%s%s%s",BK,n,RESET);
    for(int h = x;h<25;h++) printf("×");
    printf("\n\n%s Cantidad a crear: %s ",BK,RESET);
    fflush(stdout);

    char c[30];
    fgets(c, sizeof(c), stdin);
    long long cantidad = atoi(c);
    if(cantidad <= 0) goto cant;
    printf("\n⋯: Cantidad a crear: %llu\n",cantidad);
    printf("\n\n%s Creando resultados... %s\n\n",BK,RESET);
    //Crear resultados y guardarlos en un archivo
    for(int i=0;i<16;i++)
    {   
        if(n[i] == '\0') n[i] = 'x';
    }
    make(n,cantidad);
    keepRunning = 1;
    return 0;
}

void make(char n[],long long c)
{
    time_t t ; 
    struct tm *tmp ; 
    char strtime[80]; 
    char arch[120];
    char year[5];
    time( &t ); 
      
    tmp = localtime( &t ); 
      
    // using strftime to display time 
    strftime(strtime, sizeof(strtime), "%Y-%m-%d.%X", tmp); 
    strcat(arch,strtime);
    strcat(arch,".pk");

    FILE* file = fopen(arch, "a");
    while(file == NULL)
    {
        file = fopen(arch, "a");
    }
    fprintf(file,"By PacifiK\n");
    char nn[17];
    char tmpd[50];
    char tmpint[50];
    strcpy(nn,n);
    long long h = 0;
    long long final;
    char num;
    srand(time(0));
    while(h < c)
    { 
        strcpy(nn,n);
        for(int i=0;i<16;i++)
        {   
            num = (char) (((rand() % (9 - 0 + 1)) + 0) + 48);
            if(nn[i] == 'x' || nn[i] == 'X') nn[i] = num;
        }
        if(check(nn))
        {
            h++;
            strftime(year,sizeof(year),"%Y",tmp);

            strcpy(tmpd,nn);
            strcat(tmpd," | ");
            sprintf(tmpint, "%d",(((rand() % (12 - 01 + 1)) + 01)));
            strcat(tmpd,tmpint);
            strcat(tmpd," | ");
            sprintf(tmpint, "%d",(atoi(year) + (rand()%(4-1+1)+1)));
            strcat(tmpd, tmpint);
            strcat(tmpd," | ");
            sprintf(tmpint, "%d",(((rand() % (999 - 000 + 1)) + 000)));
            strcat(tmpd,tmpint);
            strcat(tmpd,"\n");
            fprintf(file,tmpd);
        }
    }
    fclose(file);
    char cwd[PATH_MAX];
    getcwd(cwd, sizeof(cwd));
    printf("\n%s Resultados guardados en: file://%s/%s %s\n\n [Presiona cualquier tecla para continuar]: ",BK,cwd,arch,RESET);
    getchar();
}

int check(char n[])
{
    unsigned long long r = 0;
    for(int i=0;i<16;i+=2)
    {
        r+=(((int) n[i] - 48) * 2)%10;
        r+=(((int) n[i] - 48) * 2)/10;
    }
    for(int i=1;i<16;i+=2)
    {
        r+=((int) n[i] - 48);
    }
    r=r%10;
    if(r == 0)
    {
        printf(": %s\n",n);
        return true;
    }
    return false;
}

void quit()
{
    system("setterm -cursor on");
    system("tput rmcup");
    inputreflect(true);
    printf("\n⏻ Ok, saliendo!\n");
    exit(1);
}

//Catch ctrl-c and send the signal to keepRunning to stop
void intHandler(int dummy) {
    keepRunning = 0;
}

void inputreflect(bool enable)
{
#ifdef WIN32
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE); 
    DWORD mode;
    GetConsoleMode(hStdin, &mode);

    if( !enable )
        mode &= ~ENABLE_ECHO_INPUT;
    else
        mode |= ENABLE_ECHO_INPUT;

    SetConsoleMode(hStdin, mode );

#else
    struct termios tty;
    tcgetattr(STDIN_FILENO, &tty);
    if( !enable )
        tty.c_lflag &= ~ECHO;
    else
        tty.c_lflag |= ECHO;

    (void) tcsetattr(STDIN_FILENO, TCSANOW, &tty);
#endif
}

int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }

  return 0;
}

int checksum(void *buffer, size_t len, unsigned int seed)
{
      unsigned char *buf = (unsigned char *)buffer;
      size_t i;

      for (i = 0; i < len; ++i)
            seed += (unsigned int)(*buf++);
      return seed;
}