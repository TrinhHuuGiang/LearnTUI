// This file is licensed under the GNU General Public License v3. See the end of this file for details.
// About: initscr, endwin, refresh(more in _4_Ncurses_Window), getch, printw
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