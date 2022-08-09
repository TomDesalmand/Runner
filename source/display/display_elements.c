/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-tom.desalmand
** File description:
** display_elements.c
*/

#include "../../include/runner.h"

void set_coords(game_t *game)
{
    bird_pos_status(game);
    sfSprite_setPosition(game->sprites->sp_logo, (sfVector2f){525.0, 50.0});
    sfSprite_setPosition(game->sprites->bg_sp, game->coords->coord_bg);
    sfSprite_setPosition(game->sprites->cl_sp, game->coords->coord_cl);
    sfSprite_setPosition(game->sprites->sp_1, game->coords->coord1);
    sfSprite_setPosition(game->sprites->sp_2, game->coords->coord2);
    sfSprite_setPosition(game->sprites->sp_3, game->coords->coord3);
    sfSprite_setPosition(game->sprites->sp_button, (sfVector2f){550.0, 350.0});
    sfSprite_setPosition(game->sprites->sp_end, (sfVector2f)
    {game->coords->coord_view.x + 550, game->coords->coord_view.y + 100});
    sfSprite_setPosition(game->sprites->sp_bird, game->coords->coord_bird);
    sfText_setPosition(game->texts->t1, (sfVector2f){805.0, 375.0});
    sfText_setPosition(game->texts->t2, (sfVector2f){785.0, 575.0});
    sfText_setPosition(game->texts->t3, (sfVector2f){805.0, 775.0});
    sfText_setPosition(game->texts->te, (sfVector2f)
    {game->coords->coord_view.x + 615, game->coords->coord_view.y + 145});
    sfText_setPosition(game->texts->tl, (sfVector2f)
    {game->coords->coord_view.x + 250, game->coords->coord_view.y + 345});
    sfText_setPosition(game->texts->tw, (sfVector2f)
    {game->coords->coord_view.x + 265, game->coords->coord_view.y + 345});
}

void display_background(game_t *game)
{
    drawSprite(game->windows->window, game->sprites->bg_sp);
    drawSprite(game->windows->window, game->sprites->cl_sp);
    drawSprite(game->windows->window, game->sprites->sp_3);
    drawSprite(game->windows->window, game->sprites->sp_2);
    drawSprite(game->windows->window, game->sprites->sp_1);
}

void check_background_pos(game_t *game)
{
    sfVector2f c = game->coords->coord_view;
    if (sfSprite_getPosition(game->sprites->sp_1).x <= c.x - 1920)
        game->coords->coord1.x = c.x;
    if (sfSprite_getPosition(game->sprites->sp_2).x <= c.x - 1920)
        game->coords->coord2.x = c.x;
    if (sfSprite_getPosition(game->sprites->sp_3).x <= c.x - 1920)
        game->coords->coord3.x = c.x;
    if (sfSprite_getPosition(game->sprites->cl_sp).x <= c.x - 1920)
        game->coords->coord_cl.x = c.x;
}

void move_background(game_t *game)
{
    game->coords->coord1.x -= 2.5;
    game->coords->coord2.x -= 1.5;
    game->coords->coord3.x -= 0.8;
    game->coords->coord_cl.x -= 0.3;
}

void move_background2(game_t *game)
{
    sfView_move(game->coords->view, (sfVector2f){4.0, 0.0});
    game->coords->coord_view.x += 4.0;
    game->coords->coord_bird.x += 4.0;
    game->coords->coord1.x += 1.5;
    game->coords->coord2.x += 2.5;
    game->coords->coord3.x += 3.2;
    game->coords->coord_cl.x += 3.7;
    game->coords->coord_bg.x += 4.0;
}
