#! /bin/bash
# Mike Roylance - roylance.michael@gmail.com
# test if executable exists
if [ ! -e "./tokenizer" ]
then
	make
fi

# run file
./tokenizer $1 $2