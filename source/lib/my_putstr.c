/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-tom.desalmand
** File description:
** my_putstr.c
*/

#include "../../include/runner.h"

void my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}

char *my_itoa(int num)
{
    int len = 0;
    char *str;

    for (int i = num; i > 0; len++)
        i /= 10;
    str = malloc(sizeof(char) * (len + 1));
    str[len] = '\0';
    for (int i = len; i > 0; i--) {
        str[i - 1] = num % 10 + '0';
        num /= 10;
    }
    return str;
}
