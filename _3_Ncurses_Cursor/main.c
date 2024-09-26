// About: initscr, endwin, refresh, getch, printw
/********************************************************************************
* Definitions
********************************************************************************/
#include <ncurses.h>

/********************************************************************************
* Code
********************************************************************************/
int main(int argc, char** argv)
{
    char temp = 0;

    //Open a new interface on the terminal
    //Set up memory for this screen
    initscr();

    //update what changed
    refresh();


    //deallocate screen before end program
    //return shell terminal
    endwin();
    return 0;
}