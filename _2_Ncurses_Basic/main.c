// About: initscr, endwin, refresh, getch, printw
/********************************************************************************
* Definitions
********************************************************************************/
#include <ncurses.h>

/********************************************************************************
* Code
********************************************************************************/
int main(int argc,const char** argv)
{
    char temp = 0;

    //Open a new interface on the terminal
    //Set up memory for this screen
    initscr();

    //update what changed
    refresh();

    //print "hello world"
    printw("Hello World!!\nPress a key: ");

    //get a value user type
    temp = getch();
    while (getch()!='\n')
    {
        /* No code */
    }
    
    //print the word on to screen
    printw("%c", temp);

    //stop screen
    printw("\nPress any key to end!!");
    getch();

    //deallocate screen before end program
    //return shell terminal
    endwin();
    return 0;
}