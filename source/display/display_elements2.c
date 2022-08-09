/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-tom.desalmand
** File description:
** display_elements2.c
*/

#include "../../include/runner.h"

void set_score_position_game(game_t *game)
{
    game->variables->score += 4;
    sfText_setString(game->texts->st, my_itoa(game->variables->score));
    sfText_setPosition(game->texts->scoret, (sfVector2f)
    {game->coords->coord_view.x + 25, game->coords->coord_view.y + 25});
    sfText_setPosition(game->texts->st, (sfVector2f)
    {game->coords->coord_view.x + 275, game->coords->coord_view.y + 25});
    sfRenderWindow_drawText(game->windows->window, game->texts->scoret, NULL);
    sfRenderWindow_drawText(game->windows->window, game->texts->st, NULL);
}

void set_score_position_end(game_t *game)
{
    sfText_setString(game->texts->st, my_itoa(game->variables->score));
    sfText_setPosition(game->texts->scoret, (sfVector2f)
    {game->coords->coord_view.x + 700, game->coords->coord_view.y + 615});
    sfText_setPosition(game->texts->st, (sfVector2f)
    {game->coords->coord_view.x + 950, game->coords->coord_view.y + 615});
    sfRenderWindow_drawText(game->windows->window, game->texts->scoret, NULL);
    sfRenderWindow_drawText(game->windows->window, game->texts->st, NULL);
}
