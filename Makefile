CC = gcc

all:  one tests

one:  obj/main.o obj/ceasar.o obj/vizhiner.o obj/atbash.o obj/base64.o
	$(CC) obj/*.o -o bin/ciphers

obj/main.o: src/main.c
	$(CC) -c src/main.c -o obj/main.o

obj/ceasar.o: src/ceasar.c
	$(CC) -c src/ceasar.c -o obj/ceasar.o

obj/vizhiner.o: src/vizhiner.c
	$(CC) -c src/vizhiner.c -o obj/vizhiner.o

obj/atbash.o: src/atbash.c
	$(CC) -c src/atbash.c -o obj/atbash.o

obj/base64.o: src/base64.c
	$(CC) -c src/base64.c -o obj/base64.o

restruct:
	rm -f obj/*.o
	rm -f tests/obj/*.o
	rm -f bin/ciphers
	rm -f tests/bin/test
	make all

clear:
	rm -f obj/*.o
	rm -f tests/obj/*.o
	rm -f bin/ciphers
	rm -f tests/bin/test

install:
	make one
	cp bin/ciphers /usr/local/bin

unistall:
	rm -f /usr/local/bin/ciphers

tests: tests/obj/ceasar_test.o obj/ceasar.o tests/obj/vizhiner_test.o obj/vizhiner.o tests/obj/atbash_test.o obj/atbash.o tests/obj/maintest.o
	$(CC) tests/obj/*.o obj/ceasar.o obj/vizhiner.o obj/atbash.o -o tests/bin/test
	./tests/bin/test

tests/obj/maintest.o: tests/src/maintest.c
	$(CC) -c tests/src/maintest.c -o tests/obj/maintest.o

tests/obj/ceasar_test.o: tests/src/ceasar_test.c
	$(CC) -c tests/src/ceasar_test.c -o tests/obj/ceasar_test.o

tests/obj/vizhiner_test.o: tests/src/vizhiner_test.c
	$(CC) -c tests/src/vizhiner_test.c -o tests/obj/vizhiner_test.o

tests/obj/atbash_test.o: tests/src/atbash_test.c
	$(CC) -c tests/src/atbash_test.c -o tests/obj/atbash_test.o
