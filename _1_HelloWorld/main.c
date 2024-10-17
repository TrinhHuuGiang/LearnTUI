// This file is licensed under the GNU General Public License v3. See the end of this file for details.
#include <stdio.h>

int main(int argc,const char** argv)
{
    if (argc == 1)
    {
        printf("Argument [ 0] - [%s]\n", argv[0]);  // Print default input
        printf("No additional arguments provided (argc < 2)\n");  // 
        return -1;
    }

    for (int i = 0; i < argc; i++)
    {
        printf("Argument [%2d] - [%s]\n", i, argv[i]);  // Print input argument
    }

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
