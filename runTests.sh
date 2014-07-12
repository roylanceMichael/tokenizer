#! /bin/bash
# Mike Roylance - roylance.michael@gmail.com
g++ source/tests.cpp source/tokenizer.cpp source/transformMap.cpp -o tests.o
./tests.o $1 $2