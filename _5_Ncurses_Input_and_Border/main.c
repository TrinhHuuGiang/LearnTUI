// This file is licensed under the GNU General Public License v3. See the end of this file for details.
// About: 
//1. input mode
// - cbreak/nocbreak: Activates immediate input mode for the keyboard, allowing input 
//           without needing to press Enter.
//           The difference between cbreak and nocbreak is:
//              + cbreak: Characters are available immediately, and the input is sent 
//                to the program without waiting for Enter. However, when Enter is 
//                pressed, the \n is also pushed into the buffer.
//              + nocbreak: Characters are buffered until Enter is pressed, and all 
//                characters typed will remain in the buffer until the newline is received.
// - raw/noraw: Disables handling of control key combinations (like Ctrl + C), 
//        so the program won't exit on Ctrl + C. Instead, it treats Ctrl and C
//        as separate characters.
//        Note that if you using cbreak, it will overwrite raw mode
// - noecho: Prevents characters typed from the keyboard from being displayed
//        on the screen.
//
//2. border style
// - wborder: Adds a customizable border around all edges of a window.
// - box: Adds a simple border to a window, using specified characters for the 
//        avertical and horizontal edges.
// -

/********************************************************************************
* Definitions
********************************************************************************/
#include <ncurses.h>

/********************************************************************************
* Code
********************************************************************************/
int main()
{

    /*[NCURSES START]*/
    initscr();

    /*[1_Set input mode]*/

    /*[nocbreak]*/
    //let input 'a' then enter
    nocbreak(); //this mode wait until \n or an character not combination
    printw("nocbreak mode, input: %c\n", getch());
    getch();//the enter left in buffer so get it
    
    /*[cbreack]*/
    //let input 'a' but not enter
    cbreak(); //this mode no wait \n, anything is executed
    printw("cbreak mode, input: %c\n", getch());
    
    /*[raw]*/
    //let input Ctrl + C -> so now it is a character ^C
    raw(); //this mode get anything you input like a character
    printw("raw mode, input: %c\n", getch());

    /*reset mode*/
    noraw();// and return nocbreak mode

    /*[noecho]*/
    //in this mode, let input a character 'b'
    noecho();//hide what you input
    printw("cbreak mode, input: %c\n", getch());
    getch();//ignore \n

    /*stop to watch*/
    getch();


    /*[2_Set Border]*/
    /*[box] - see _4_Ncurses_Window*/
    /*[wborder]*/
    // border or wborder(WINDOW*,left,right,top,bot, tlc, trc, blc, brc)
    border('>','<','^','v','+','+','+','+');

    getch();//to watch changed
    /*[NCURSES END]*/
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