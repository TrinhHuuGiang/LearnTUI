// About: move(x,y) -x is row, y is column
//        mvprintw(x,y, string, param) 
//        clear() - clear screen
/********************************************************************************
* Definitions
********************************************************************************/
#include <ncurses.h>

/********************************************************************************
* Code
********************************************************************************/
int main(int argc, char** argv)
{
    char temp;
    //Open a new interface on the terminal
    //Set up memory for this screen
    initscr();

    //update what changed
    refresh();

    //try print at (20,20)
    move(20,20);
    printw("Hello World!!");


    //stop to watch, type anything to continue
    //print that key at (2,0)
    temp = getch();
    while(getch() != '\n')
    {
        //do nothing
    }
    move(2,0);
    printw("%c", temp);

    //or move + print
    mvprintw(5,5,"move & print");

    getch(); // stop to watch

    //clear screen
    clear();

    //then say bye
    mvprintw(10, 20, "Bye bye");
    getch();

    //deallocate screen before end program
    //return shell terminal
    endwin();
    return 0;
}