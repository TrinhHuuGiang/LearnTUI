// This file is licensed under the GNU General Public License v3. See the end of this file for details.
// About: WINDOW* : Pointer to a newwindow
// initscr, endwin, refresh using for stdscr (main window)
// newwin, delwin, wclear, box, wprintw, mvwprintw using for new window
/********************************************************************************
* Definitions
********************************************************************************/
#include <ncurses.h>
#define h1 10
#define h2 10
#define h3 10

#define w1 20
#define w2 30
#define w3 40

/********************************************************************************
* Code
********************************************************************************/
int main(int argc,const char** argv)
{
    //Definitions some window pointer
    WINDOW* win1;
    WINDOW* win2;
    WINDOW* win3;
    //Open a new interface on the terminal
    //Set up memory for main screen
    initscr();
    
    //init 3 child window
    win1 = newwin(h1, w1,  0, 0);
    win2 = newwin(h2, w2, 11, 0);
    win3 = newwin(h3, w3, 22, 0);
    refresh();//update 3 child window in to stdscr

    //wrap box for 3 window with heigh include | and width include -
    box(win1, '|', '-');
    wprintw(win1,"This is box 1");//draw defaut 0,0 at box1
    wrefresh(win1);//update box 1

    box(win2, '*', '~');
    mvwprintw(win2,2,3,"This is box 2");//draw at row 2, col 3 at box2
    wrefresh(win2);//update box 2

    box(win3, '\\', '/');
    mvwprintw(win3, h3/2, w3/2, "This is box 3");//draw at middle
    wrefresh(win3);//update box 3

    //wait user
    getch();

    //try clear a win dow
    wclear(win1);
    wrefresh(win1);

    //win1 still exist. to delete, using delwin
    delwin(win1); //free a window
    win1 = NULL; //set NULL avoid using
    refresh();

    //wait user
    getch();
    //deallocate screen before end program
    //return shell terminal
    endwin();
    return 0;
}

/*
    Copyright (C) <2024>  <TrinhHuuGiang>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

    Contact Information:
    <giangtrinhvnbl2k2@gmail.com>
*/