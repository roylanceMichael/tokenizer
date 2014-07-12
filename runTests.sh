#! /bin/bash
# Mike Roylance - roylance.michael@gmail.com
g++ source/tests.cpp source/tokenizer.cpp -o tests.o
./tests.o $1 $2