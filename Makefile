# Copy this to the terminal for easy aliases:
# alias r="make run" alias b="make build" alias c="clear"

build:
	gcc main.c -o main -std=c99 -Wall -pedantic

build-debug:
	gcc main.c -o main -g -std=c99 -Wall -pedantic

build-curl-ex:
	gcc curl_ex.c $$(curl-config --cflags --libs) -o curl_ex

run:
	@clear && ./main

buildrun: build run

git:
	git add -A && git commit -m "update"

clean:
	rm -rf main.DSYM main main2 curl_ex