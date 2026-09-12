# Copy this to the terminal for easy aliases:
# alias r="make run"
# alias b="make build"
# alias c="clear"

build:
	gcc main.c -o main -std=c99 -Wall -pedantic

build-debug:
	gcc main.c -o main -g -std=c99 -Wall -pedantic


run:
	@clear && ./main

buildrun: build run

git:
	git add -A && git commit -m "update"