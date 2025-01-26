
chooser: src/chooser.c
	${CC} -o chooser src/chooser.c -g -Wall -Wextra -pedantic -O3

all: chooser


.PHONY: all