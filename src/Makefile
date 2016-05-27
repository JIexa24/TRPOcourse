CC = gcc

all:  one

one:  main.o ceasar.o vizhiner.o atbash.o
	$(CC) main.o ceasar.o vizhiner.o atbash.o -o main

main.o: main.c
	$(CC) -c main.c

ceasar.o: ceasar.c
	$(CC) -c ceasar.c

vizhiner.o: vizhiner.c
	$(CC) -c vizhiner.c

atbash.o: atbash.c
	$(CC) -c atbash.c

