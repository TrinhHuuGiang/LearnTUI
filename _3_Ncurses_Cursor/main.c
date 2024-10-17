// This file is licensed under the GNU General Public License v3. See the end of this file for details.
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
int main(int argc,const char** argv)
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