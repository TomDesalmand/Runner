/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-tom.desalmand
** File description:
** my_strcpy.c
*/

#include "../../include/runner.h"

char *my_strcpy(char *dest , char const *src)
{
    int c = 0;
    while (c <= my_strlen(src)) {
        dest[c] = src[c];
        c++;
    }
    return dest;
}
