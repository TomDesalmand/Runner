/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-tom.desalmand
** File description:
** display_functions.c
*/

#include "../../include/runner.h"

void drawSprite(sfRenderWindow *window, sfSprite *sprite)
{
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

void update_window(game_t *game)
{
    sfRenderWindow_setView(game->windows->window, game->coords->view);
    sfRenderWindow_display(game->windows->window);
    sfRenderWindow_clear(game->windows->window, sfBlack);
    sfClock_restart(game->variables->clock);
}

void draw_menu(game_t *game)
{
    sfMusic_play(game->musics->theme);
    drawSprite(game->windows->window, game->sprites->sp_logo);
    drawSprite(game->windows->window, game->sprites->sp_button);
    sfRenderWindow_drawText(game->windows->window, game->texts->t1, NULL);
    sfRenderWindow_drawText(game->windows->window, game->texts->t2, NULL);
    sfRenderWindow_drawText(game->windows->window, game->texts->t3, NULL);
}

void draw_endl(game_t *game)
{
    drawSprite(game->windows->window, game->sprites->sp_end);
    sfRenderWindow_drawText(game->windows->window, game->texts->te, NULL);
    sfRenderWindow_drawText(game->windows->window, game->texts->tl, NULL);
}

void draw_endw(game_t *game)
{
    drawSprite(game->windows->window, game->sprites->sp_end);
    sfRenderWindow_drawText(game->windows->window, game->texts->te, NULL);
    sfRenderWindow_drawText(game->windows->window, game->texts->tw, NULL);
}
