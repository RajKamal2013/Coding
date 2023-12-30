#! /bin/bash 

cp create.c create_dup.c
gcc -g create.c -o create
./create 100 random.txt
