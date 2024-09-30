// About: Some color and style
// style: attron, attroff
// color: has_color, start_color, can_change_color, init_color, init_pair
/********************************************************************************
* Definitions
********************************************************************************/
#include <ncurses.h>
#define COLOR_1 (1)
#define COLOR_2 (2)
#define COLOR_3 (3)
#define COLOR_4 (4)
#define PAIR_1  (1)
#define PAIR_2  (2)

/********************************************************************************
* Code
********************************************************************************/
int main()
{

    /*[NCURSES START]*/
    initscr(); //default black white color
    
    /*[Check terminal support color]*/
    if(!has_colors())
    {
        printw("Terminal not support color!!\n");
        return -1;
    }
    /*if ok let start color to using color pair*/
    start_color();

    /*[Check if can change color]*/
    if(!can_change_color())
    {
        printw("Can't change color !!\n");
        return -2;
    }
    /*[Let create some color]*/
    //RGB 1000 level
    init_color(COLOR_1,900,0,0);
    init_color(COLOR_2,0,0,900);
    init_color(COLOR_3,0,900,0);
    init_color(COLOR_4,400,400,400);

    //[Let create some pair color for word]
    init_pair(PAIR_1,COLOR_1,COLOR_3);
    init_pair(PAIR_2,COLOR_2,COLOR_4);

    /*[an example - only style]*/

    //[on set STYLE: A_NORMAL, A_REVERSE, ...]
    attron(A_REVERSE);
    attron(A_UNDERLINE); // get more style go to definition
    attron(A_BOLD);
    
    // print an example
    printw("\nThis is a syte\n");


    //[off set STYLE]
    attroff(A_REVERSE);
    attroff(A_UNDERLINE);
    attroff(A_BOLD);

    //[an example - only color pair]
    attron(COLOR_PAIR(PAIR_1));
    // print an example
    printw("\nThis is a color pair\n");
    //[off set color]
    attroff(COLOR_PAIR(PAIR_1));
    //[example 2- only color pair]
    attron(COLOR_PAIR(PAIR_2));
    // print an example
    printw("\nThis is a color pair\n");
    //[off set color]
    attroff(COLOR_PAIR(PAIR_2));

    /*[NCURSES END]*/
    getch();
    endwin();
    /*[PROGRAM END]*/
    return 0;

}