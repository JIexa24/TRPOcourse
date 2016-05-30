CC = gcc

all:  one

one:  main.o ceasar.o vizhiner.o atbash.o
	$(CC) Obj/main.o Obj/ceasar.o Obj/vizhiner.o Obj/atbash.o -o /bin/main

main.o: src/main.c
	$(CC) -c src/main.c -o Obj/main.o

ceasar.o: src/ceasar.c
	$(CC) -c src/ceasar.c -o Obj/ceasar.o

vizhiner.o: src/vizhiner.c
	$(CC) -c src/vizhiner.c -o Obj/vizhiner.o

atbash.o: src/atbash.c
	$(CC) -c src/atbash.c -o Obj/atbash.o

clean:
	rm -f Obj/*.o
