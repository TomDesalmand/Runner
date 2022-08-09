/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-tom.desalmand
** File description:
** init_functions.c
*/

#include "../../include/runner.h"

void create_textures(sfTexture **texture, char *path)
{
    *texture = sfTexture_createFromFile(path, NULL);
}

void setTexture(sfSprite *sprite, sfTexture *texture)
{
    sfSprite_setTexture(sprite, texture, sfTrue);
}

void setTextureRect(sfSprite *sprite, sfIntRect rect)
{
    sfSprite_setTextureRect(sprite, rect);
}
