##
## EPITECH PROJECT, 2021
## B-MUL-100-LYN-1-1-myrunner-tom.desalmand
## File description:
## Makefile
##

LIBRARY_FILES = $(wildcard source/*/*.c)

PROJECT_FILES = main.c

BINARY_FILE = my_runner

all:
	gcc $(PROJECT_FILES) $(LIBRARY_FILES) -o $(BINARY_FILE) -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-network -lcsfml-audio -g3

clean:
	rm -f $(BINARY_FILE)

fclean: clean

re: fclean all