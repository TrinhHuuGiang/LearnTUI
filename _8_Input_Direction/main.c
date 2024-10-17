// This file is licensed under the GNU General Public License v3. See the end of this file for details.
// About: 
// handle some special input like ->, <-, ^,v button
// using keypad(WINDOW*,true).
// some special using raw() like Ctrl+C, Ctrl+s is presented in Ncurses_Input...
/********************************************************************************
* Definitions
********************************************************************************/
#include <ncurses.h>
#include <string.h>
#define w1 50
#define h1 30
#define M_LEN 5
#define OBJ_LEN 10
/********************************************************************************
* Code
********************************************************************************/
int main()
{
    WINDOW* win1=NULL;
    int maxx = 0,maxy = 0;
    char menu[M_LEN][OBJ_LEN] = {"Cam","Quyt","Ca Phe","Tao Tau","O mai"};

    /*[NCURSES START]*/
    initscr(); //default black white color
    cbreak();//input ignore enter

    /*init new window*/
    getmaxyx(stdscr,maxy,maxx);
    if((maxy-h1)/2 <=0 || (maxx-w1)/2 <=0)
    win1 = newwin(maxy,maxx,0, 0);
    else win1 = newwin(h1,w1,(maxy-h1)/2,(maxx-w1)/2);
    refresh();
    box(win1,'|','-');
    wprintw(win1,"BOX-1");
    wrefresh(win1);

    /*[Set get keypad]*/
    keypad(win1,true);

    /*Input a menu to window*/
    {
        int highlight = 0;
        int temp;
        while (1)
        {
            for(int i = 0; i<M_LEN;i++)
            {
                if(i==highlight)
                {
                    wattron(win1, A_REVERSE);
                }
                mvwprintw(win1,i+1,2,menu[i]);
                wattroff(win1, A_REVERSE);
            }
            temp = wgetch(win1);
            switch (temp)
            {
            case KEY_UP:
                highlight--;
                if(highlight==-1) highlight = M_LEN-1;
                break;
            case KEY_DOWN:
                highlight++;
                if(highlight == M_LEN)  highlight = 0;
                break;
            default:
                break;
            }
        }
    }
    /*[NCURSES END]*/
    printw("\nEnd Program!!!\n");
    endwin();
    /*[PROGRAM END]*/
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