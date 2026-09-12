build:
	gcc main.c -o main -std=c99 -Wall -pedantic

build-debug:
	gcc main.c -o main -g -std=c99 -Wall -pedantic


run:
	@clear && ./main

buildrun: build run
