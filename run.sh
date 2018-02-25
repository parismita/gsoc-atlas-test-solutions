#!/bin/bash
#Run this in terminal
#+ Command to compile c++ program. here i used common one
g++ -I ~/eigen/ -std=c++11 SymMat.cpp -c
ar rvs SymMAt.a SymMat.o
g++ -I ~/eigen/ -std=c++11 test.cpp SymMAt.a
./a.out
exit 0
