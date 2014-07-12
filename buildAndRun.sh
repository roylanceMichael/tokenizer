#! /bin/bash
# Mike Roylance - roylance.michael@gmail.com
g++ source/main.cpp source/tokenizer.cpp -o tokenizer.o
./tokenizer.o $1 $2