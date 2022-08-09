/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-tom.desalmand
** File description:
** map_functions.c
*/

#include "../../include/runner.h"

void draw_map(game_t *game, char **map)
{
    draw_bird(game);
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            check_colision(game);
            check_end(game);
            draw_blocks(game, map[i][j]);
            game->coords->coordblock.x += 150.0;
        }
        game->coords->coordblock.x = 0.0;
        game->coords->coordblock.y += 148.0;
    }
    game->coords->coordblock.y = 0.0;
}

void draw_bird(game_t *game)
{
    if (game->variables->bird_status >= 1) {
        setTextureRect(game->sprites->sp_bird, game->variables->bird1);
        drawSprite(game->windows->window, game->sprites->sp_bird);
    } if (game->variables->bird_status >= 5) {
        setTextureRect(game->sprites->sp_bird, game->variables->bird2);
        drawSprite(game->windows->window, game->sprites->sp_bird);
    } if (game->variables->bird_status >= 9) {
        setTextureRect(game->sprites->sp_bird, game->variables->bird3);
        drawSprite(game->windows->window, game->sprites->sp_bird);
    }
}

void bird_jump(game_t *game)
{
    game->variables->bird_jump += 0.0001;
    if (game->variables->bird_status == 14)
        game->variables->bird_status = 1;
    if (game->variables->bird_status >= 2)
        game->variables->bird_status += 1;
}

void draw_blocks(game_t *game, char block)
{
    switch (block) {
    case '1':
        set_block_pos(game);
        drawSprite(game->windows->window, game->sprites->sp_block1);
        break;
    case '2':
        set_block_pos(game);
        drawSprite(game->windows->window, game->sprites->sp_block2);
        break;
    case '3':
        set_block_pos(game);
        drawSprite(game->windows->window, game->sprites->sp_block3);
        break;
    case '4':
        set_block_pos(game);
        drawSprite(game->windows->window, game->sprites->sp_block4);
        break;
    default:
        return;
    }
}

void set_block_pos(game_t *game)
{
    sfSprite_setPosition(game->sprites->sp_block1, game->coords->coordblock);
    sfSprite_setPosition(game->sprites->sp_block2, game->coords->coordblock);
    sfSprite_setPosition(game->sprites->sp_block3, game->coords->coordblock);
    sfSprite_setPosition(game->sprites->sp_block4, game->coords->coordblock);
}
