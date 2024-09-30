// About: getyx, getbegyx, getmaxyx
// col y, rox x. or coordinate (x,y)

/********************************************************************************
* Definitions
********************************************************************************/
#include <ncurses.h>
#define h1 (10)
#define w1 (40)
#define r1 (0)
#define c1 (0)
#define h2 (10)
#define w2 (20)
#define r2 (20)
#define c2 (40)

/********************************************************************************
* Code
********************************************************************************/
int main()
{
    WINDOW* win1;
    WINDOW* win2;
    int x,y; // save row x, col y

    /*[NCURSES START]*/
    initscr();
    /*[Using cbreak mode]*/
    cbreak();
    
    /*Init 2 child window*/
    win1 = newwin(h1,w1,r1,c1);
    win2 = newwin(h2,w2,r2,c2);
    refresh();//update 2 child window in to stdscr

    //wrap box for 2 window with heigh include | and width include -
    box(win1, '|', '-');
    wprintw(win1,"This is box 1");//draw defaut 0,0 at box1
    wrefresh(win1);//update box 1

    box(win2, '|', '-');
    wprintw(win2,"This is box 2");//draw box2
    wrefresh(win2);//update box 2

    //[Get INFO Win 2]
    for(int i = 0; i< 3; i++)
    {
        switch (i)
        {
        case 0:
            getbegyx(win2,y,x);//this is a function macro
            //so can change value instantly for variable y and x
            //get begin row x, col y
            mvwprintw(win1,i+1,1,"- start win 2_____ [row, col]=[%d,%d]",x,y);
            break;
        case 1:
            getmaxyx(win2,y,x);//get end row x, col y
            mvwprintw(win1,i+1,1,"- End win 2_______ [row, col]=[%d,%d]",x,y);
            break;
        case 2:
            getyx(win2,y,x);//get cursor coordinate
            mvwprintw(win1,i+1,1,"- Cursor win 2 now [row, col]=[%d,%d]",x,y);
            break;
        default:
            break;
        }
        //[Refresh info in to Win 1]
        wrefresh(win1);//update box 1
    }


    /*[NCURSES END]*/
    mvwprintw(win1,5,1,"Press ' ' to end");
    wrefresh(win1);
    getch();
    endwin();
    /*[PROGRAM END]*/
    return 0;

}