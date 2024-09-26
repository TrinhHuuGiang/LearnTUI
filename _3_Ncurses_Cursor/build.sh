#!/bin/bash

#create folder build while not exist
mkdir -p build

gcc -o ./build/main main.c -lncurses