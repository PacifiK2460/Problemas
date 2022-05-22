#define TEST

#include <ncurses.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#include <menu.h>
#include <form.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 	4


//Maquetacion de las funciones a usar
void menu();
void gen();
void quit();
void makemainwin(char *tittle);
void initf(WINDOW *win, int starty, int startx, int width, char *string);
void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string);
WINDOW *create_newwin(int height, int width, int starty, int startx);
static char* trim_whitespaces(char *str);

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
        menu();
	}
    start_color();			/* Start color 			*/
	init_pair(1, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(1));
    refresh();

    //Iniciamos la animacion del principio
    char init[] = " PacifiK ";
    //getch();
    
    if(argc == 2 && strcmp ("quiet",argv[1]) == 0)
    {
        print_in_middle(stdscr,LINES/2,(COLS/2)-3,7,"Shhh...");
    }
    else
    {
        initf(stdscr,LINES / 2, (COLS / 2)-8,13,init);
        getchar();
    }
    menu();
}

void menu()
{
    refresh();
    //Creamos nueva ventana principal
    makemainwin(" [ MENU PRINCIPAL ] ");

    //Iniciamo las opciones
    char *opciones[] =
    {
                " [Crear CC's / Extrapolacion]   ",
                "        [Live Checker]   ",
                "           [Salir]   ",
    };

    //Creamos los items del menu
    ITEM **my_items;
	int c;				
	MENU *my_menu;
    int n_opciones, i;
	ITEM *cur_item;
    
    //Creamos una ventana para los items
    WINDOW *my_menu_win;

    //Iniciamos loas items
    n_opciones = ARRAY_SIZE(opciones);
    my_items = (ITEM **)calloc(n_opciones + 1, sizeof(ITEM *));
    for(i = 0; i < n_opciones; ++i)
	{      
        my_items[i] = new_item(" ",opciones[i]);
	}
	my_items[n_opciones] = (ITEM *)NULL;

    //Creamos el menu
	my_menu = new_menu((ITEM **)my_items);
    set_menu_mark(my_menu, " > ");

    //Juntamos el menu y la ventana principal
    my_menu_win = newwin(10, 40, 3, (COLS/2)-(strlen(opciones[0])/2)-5);
    keypad(my_menu_win, TRUE);
     
    //Juntamos las ventanas y subvenanas
    set_menu_win(my_menu, my_menu_win);
    set_menu_sub(my_menu, derwin(my_menu_win, 6, 38, 3, 1));

    //Ponemos el menu
	post_menu(my_menu);
	refresh();

    int run = 0;

	while((c = wgetch(my_menu_win)) != KEY_F(1))
	{       
        switch(c)
        {	
			case 10: /* Enter */
			{	
                switch (run)
                {
                    case 0:
                        gen();
                        break;
                    case 2:
                        quit();
                        break;
                }
                break;
			}
            case KEY_DOWN:
                if(run < 2) run++;
                menu_driver(my_menu, REQ_DOWN_ITEM);
                break;
            case KEY_UP:
                if(run > 0) run--;
                menu_driver(my_menu, REQ_UP_ITEM);
                break;
			break;
		}
	}	
	unpost_menu(my_menu);
	for(i = 0; i < n_opciones; ++i)
		free_item(my_items[i]);
	free_menu(my_menu);
    quit();
}

void gen()
{
    FIELD *field[3];
	FORM  *my_form;
	WINDOW *my_form_win;
	int ch, rows, cols;
	
	field[0] = new_field(1, 16, 0, 0, 0, 0);
	field[1] = new_field(1, 16, 0, 18, 0, 0);
	field[2] = NULL;

	/* Set field options */
	set_field_back(field[0], A_UNDERLINE);
    set_field_buffer(field[0],0,"");
	field_opts_off(field[0], O_AUTOSKIP); 

	/* Set field options */
	set_field_back(field[1], A_UNDERLINE);
    set_field_buffer(field[1],0,"");
	field_opts_off(field[1], O_AUTOSKIP); 

	
	/* Create the my_form and post it */
	my_form = new_form(field);
	
	/* Calculate the area required for the my_form */
	scale_form(my_form, &rows, &cols);

	/* Create the window to be associated with the my_form */
        my_form_win = newwin(rows + 2, cols + 2, 5, (COLS/2)-18);
        keypad(my_form_win, TRUE);

	/* Set main window and sub window */
        set_form_win(my_form, my_form_win);
        set_form_sub(my_form, derwin(my_form_win, rows, cols, 1, 1));


	/* Print a border around the main window and print a title */
        box(my_form_win, 0, 0);

    mvwprintw(my_form_win,0,1,"[BIN: ]");
    mvwprintw(my_form_win,0,19,"[CANT: ]");
	
	post_form(my_form);
	makemainwin(" [ Crear CC's / Extrapolacion ] ");

	wrefresh(my_form_win);


	char indicaciones[] = "Escribe el bin abajo, completa los espacios en blanco con una x.";
    print_in_middle(stdscr,3,((COLS/2)-((strlen(indicaciones))/2)),strlen(indicaciones),indicaciones);
	refresh();

	keypad(stdscr, TRUE);
    curs_set(1);

    set_field_type(field[0],          /* field to alter */
                   TYPE_REGEXP,           /* type to associate */
                   "^([0-9]{6}(([0-9]|x)|X){0,10})");         /* expression to match */


    int i,cha;
    bool c;
	while ((cha = wgetch(my_form_win)) != KEY_F(1))
        switch (cha) {
                #ifdef TEST 
                case KEY_F(2):

                   // mvprintw(LINES-5,1,"type: %d",5);
                    // Or the current field buffer won't be sync with what is displayed
                    form_driver(my_form, REQ_NEXT_FIELD);
                    form_driver(my_form, REQ_PREV_FIELD);
                    mvprintw(LINES-9, 2,"RES %i",(field_buffer(field[0],0)[0] != ' ' && form_driver(my_form,REQ_VALIDATION) == 0));
                    mvprintw(LINES-8, 2,"CHA %c",field_buffer(field[0],0)[0]);
                    mvprintw(LINES-7, 2,"REQ %i\t\t\t",form_driver(my_form,REQ_VALIDATION));

                    mvprintw(LINES-5, 2,"TESTING:");
                    refresh();
                    move(LINES-4, 2);

                    for (i = 0; field[i]; i++) {
                        printw("%s", trim_whitespaces(field_buffer(field[i], 0)));

                        if (field_opts(field[i]) & O_ACTIVE)
                            printw("\"\t");
                        else
                            printw(": \"");
                    }

                    refresh();
                    pos_form_cursor(my_form);
                    break;
                #endif
                case KEY_DOWN:
                    form_driver(my_form, REQ_NEXT_FIELD);
                    form_driver(my_form, REQ_END_LINE);    
                    break;

                case KEY_BTAB:
                case KEY_CTAB:
                case KEY_STAB:
                case KEY_CATAB:
                case KEY_UP:
                    form_driver(my_form, REQ_PREV_FIELD);
                    form_driver(my_form, REQ_END_LINE);
                    break;

                case KEY_LEFT:
                    form_driver(my_form, REQ_PREV_CHAR);
                    break;

                case KEY_RIGHT:
                    form_driver(my_form, REQ_NEXT_CHAR);
                    break;

                // Delete the char before cursor
                case KEY_BACKSPACE:
                case 127:
                    form_driver(my_form, REQ_DEL_PREV);
                    break;

                // Delete the char under the cursor
                case KEY_DC:
                    form_driver(my_form, REQ_DEL_CHAR);
                    break;

                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                case '0':
                case 'x':
                    form_driver(my_form, cha);
                    break;
                /*
                case KEY_ENTER:
                case 10:
                    c = (field_buffer(field[0],0)[0] != ' ' && form_driver(my_form,REQ_VALIDATION) == 0) && (atoi(field_buffer(field_buffer[1],0)) >= 1);
                    refresh();
                    break;*/
            }

        wrefresh(stdscr);

	unpost_form(my_form);
	free_form(my_form);
	free_field(field[0]);

    quit();
}

void quit()
{
    attroff(COLOR_PAIR(1));
    curs_set(0);
    endwin();
    exit(1);
}

static char* trim_whitespaces(char *str)
{
	char *end;

	// trim leading space
	while(isspace(*str))
		str++;

	if(*str == 0) // all spaces?
		return str;

	// trim trailing space
	end = str + strnlen(str, 128) - 1;

	while(end > str && isspace(*end))
		end--;

	// write new null terminator
	*(end+1) = '\0';

	return str;
}

void makemainwin(char *tittle)
{
    curs_set(0);
    cbreak();
    noecho();
	keypad(stdscr, TRUE);
    WINDOW *menu = create_newwin(LINES,COLS,0,0);

    attron(A_REVERSE);
    print_in_middle(stdscr,1,((COLS/2)-((strlen(tittle))/2)),strlen(tittle),tittle);
    attroff(A_REVERSE);

    attron(A_BOLD);
	mvprintw(LINES - 3, 1, "Usa las flechas de movimiento para moverte y presiona <ENTER> para seleccionar la opción.");
    mvprintw(LINES - 2, 1, "Presiona <F1> para salir.");
    attroff(A_BOLD);
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
	temp = (width - length)/ 2;
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

WINDOW *create_newwin(int height, int width, int starty, int startx)
{	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);		/* 0, 0 gives default characters 
					 * for the vertical and horizontal
					 * lines			*/
	wrefresh(local_win);		/* Show that box 		*/

	return local_win;
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
	temp = (width - length)/ 2;
	x = startx + (int)temp;
	mvwprintw(win, y, x, "%s", string);
	refresh();
}
