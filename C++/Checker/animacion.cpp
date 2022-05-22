#define TEST

#include <ncurses.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#include <menu.h>
#include <form.h>

//Maquetacion de las funciones a usar

void initf(WINDOW *win, int starty, int startx, int width, char *string);
void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string);

/*
void menu();
void gen();
void quit();
void makemainwin(char *tittle);
WINDOW *create_newwin(int height, int width, int starty, int startx);
static char* trim_whitespaces(char *str);
*/

int main(int argc, char *argv[])
{	
    //Desabilitmos el pointer blinking
    curs_set(0);
    cbreak();
    //No reflejamos el input del usuario
    noecho();
    //Obtenemos las teclas especiales
	keypad(stdscr, TRUE);
    //Iniciamos ncurses
    initscr();			/* Start curses mode 		*/
    //Iniciamos la localizacion en nada
    setlocale(LC_ALL, "");
	if(has_colors() == FALSE)
    {
		printf("Your terminal does not support color, skiping\n");
        getchar();
	}
    start_color();			/* Start color 			*/
	init_pair(1, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(1));
    refresh();

    //Iniciamos la animacion del principio
    char init[] = " PacifiK ";
    //getch();
    
    initf(stdscr,LINES / 2, (COLS / 2)-8,13,init);
    getchar();
}

void initf(WINDOW *win, int starty, int startx, int width, char *string)
{	
    usleep(700000);
    refresh();
    curs_set(0);
    int length, x, y;
	float temp;

	if(win == NULL)
		win = stdscr;
	getyx(win, y, x);
	if(startx != 0)
		x = startx;
	if(starty != 0)
		y = starty;
	if(width == 0)
		width = 80;

	length = strlen(string);
	temp = (width - length)/ 2-3;
	x = startx + (int)temp;

    attron(A_BOLD);
    mvwprintw(win, y, x, "By: ", string);
    refresh();
    usleep(500000);
    attron(A_REVERSE);
    char init[] = "         ";
    printw("%s",init);
    refresh();
    usleep(1000000);
    attroff(A_REVERSE);
    mvwprintw(win, y, x, "By: ", string);
    attroff(A_BOLD);
    attron(A_REVERSE);
    for(int I = 0; string[I]!= 0; I++)
    {
	    printw("%c", string[I]);
        refresh();
        usleep(100000);
    }
    getmaxyx(win,y,x);
    usleep(400000);
    char continuar[] = " < V.0.0.1 > ";
    print_in_middle(stdscr,LINES / 2 + 2, (COLS / 2) - (strlen(continuar)/2),strlen(continuar),continuar);
    usleep(700000);

    char cont[] = " < Presiona cualquier tecla para continuar... > ";
    print_in_middle(stdscr,LINES - 2, (COLS / 2) - (strlen(cont)/2),strlen(cont),cont);
    attroff(A_REVERSE);
    refresh();
}
void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string)
{	int length, x, y;
	float temp;

	if(win == NULL)
		win = stdscr;
	getyx(win, y, x);
	if(startx != 0)
		x = startx;
	if(starty != 0)
		y = starty;
	if(width == 0)
		width = 80;

	length = strlen(string);
	temp = (width - length)/ 2 -3;
	x = startx + (int)temp;
	mvwprintw(win, y, x, "%s", string);
	refresh();
}
