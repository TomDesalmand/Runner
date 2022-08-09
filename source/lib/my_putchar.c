/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-tom.desalmand
** File description:
** my_putchar.c
*/

#include "../../include/runner.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
