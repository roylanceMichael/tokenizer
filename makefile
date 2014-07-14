CC=g++
CFLAGS=-c -Wall
all: 
	$(CC) -o tokenizer source/main.cpp source/tokenizer.cpp source/transformMap.cpp 
	