README.md

Names: Josh Villanueva, Anthony Savitt, Andrew Christopher De Leon
Class usernames: cssc1074, cssc1067, & cssc1066 (respectively)

CS 570 Summer 2018

Assignment #2, Multi-Processing File Editor

Files manifest (all under cssc1066):
a2.c
a2.h
main.c
makefile
README.md
Test

Description:
A C Program that lists out a menu in which the user selects an option to demonstrate the file editor's capabilities.

To Compile:
Change directory to "a2", type "make" 

To Clean:
Change directory to "a2", type "make clean" 

To Operate:
Change directory to "a2", type "filem"
For testing use "Test" file

Design decisions:
We designed according to the homework.
cssc1074 created the functions parts of 6, 7, 8.
cssc1067 created the functions 1, 2, 5, and parts of 6.
cssc1066 created the main function outline as well as functions 3 and 4 that include child processes.

Extra features:
Compare function, exitValidation function.

Known bugs:
No known bugs

Lessons Learned:
C restrictions on taking user input depending on the data type being recognized especially for switch statements.
Qsort algorithm is very useful with comparing strings to see which order one will be in.
Child processes being able to exit themselves in order to return to the parent which has relations to the main program.
File adaptability, being able to manipulate what files do and what they are.

