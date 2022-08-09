/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-tom.desalmand
** File description:
** init.c
*/

#include "../../include/runner.h"

void put_in_memory(game_t *game)
{
    game->windows = malloc(sizeof(windows_t));
    game->variables = malloc(sizeof(variables_t));
    game->sprites = malloc(sizeof(sprites_t));
    game->textures = malloc(sizeof(textures_t));
    game->coords = malloc(sizeof(coords_t));
    game->texts = malloc(sizeof(texts_t));
    game->musics = malloc(sizeof(musics_t));
}

void variables_memory(game_t *game)
{
    game->variables->clock = sfClock_create();
    game->variables->map_nb = 0;
    game->variables->s = 1.0;
    game->variables->status = 0;
    game->variables->bird_status = 1;
    game->variables->bird_jump = 0.0;
    game->variables->score = 0;
    game->variables->bird1 = (sfIntRect){100, 75, 135, 100};
    game->variables->bird2 = (sfIntRect){235, 75, 130, 100};
    game->variables->bird3 = (sfIntRect){365, 75, 130, 100};
    game->variables->button = (sfIntRect){100, 300, 800, 600};
    game->variables->block1 = (sfIntRect){0, 150, 150, 150};
    game->variables->block2 = (sfIntRect){0, 0, 150, 150};
    game->variables->block3 = (sfIntRect){0, 0, 150, 150};
    game->variables->block4 = (sfIntRect){0, 150, 150, 150};
    game->variables->viewrect = (sfFloatRect){0.0, 0.0, 1920.0, 1080.0};
    game->variables->end = (sfIntRect){100, 300, 800, 200};
    game->coords->view = sfView_create();
    game->coords->view = sfView_createFromRect(game->variables->viewrect);
    sprites_memory(game);
}

void sprites_memory(game_t *game)
{
    game->sprites->sp_logo = sfSprite_create();
    game->sprites->bg_sp = sfSprite_create();
    game->sprites->cl_sp = sfSprite_create();
    game->sprites->sp_1 = sfSprite_create();
    game->sprites->sp_2 = sfSprite_create();
    game->sprites->sp_3 = sfSprite_create();
    game->sprites->sp_button = sfSprite_create();
    game->sprites->sp_end = sfSprite_create();
    game->sprites->sp_block1 = sfSprite_create();
    game->sprites->sp_block2 = sfSprite_create();
    game->sprites->sp_block3 = sfSprite_create();
    game->sprites->sp_block4 = sfSprite_create();
    game->sprites->sp_bird = sfSprite_create();
    textures_memory(game);
}

void textures_memory(game_t *game)
{
    create_textures(&game->textures->te_logo, "image/logo.png");
    create_textures(&game->textures->bg_te, "image/bg.png");
    create_textures(&game->textures->cl_te, "image/bg4.png");
    create_textures(&game->textures->te_1, "image/bg1.png");
    create_textures(&game->textures->te_2, "image/bg2.png");
    create_textures(&game->textures->te_3, "image/bg3.png");
    create_textures(&game->textures->te_button, "image/menu.png");
    create_textures(&game->textures->te_block1, "image/pipe.png");
    create_textures(&game->textures->te_block2, "image/pipe_r.png");
    create_textures(&game->textures->te_bird, "image/bird.png");
    append_textures(game);
}

void append_textures(game_t *game)
{
    setTexture(game->sprites->sp_logo, game->textures->te_logo);
    setTexture(game->sprites->bg_sp, game->textures->bg_te);
    setTexture(game->sprites->cl_sp, game->textures->cl_te);
    setTexture(game->sprites->sp_1, game->textures->te_1);
    setTexture(game->sprites->sp_2, game->textures->te_2);
    setTexture(game->sprites->sp_3, game->textures->te_3);
    setTexture(game->sprites->sp_button, game->textures->te_button);
    setTexture(game->sprites->sp_end, game->textures->te_button);
    setTexture(game->sprites->sp_block1, game->textures->te_block1);
    setTexture(game->sprites->sp_block2, game->textures->te_block1);
    setTexture(game->sprites->sp_block3, game->textures->te_block2);
    setTexture(game->sprites->sp_block4, game->textures->te_block2);
    setTexture(game->sprites->sp_bird, game->textures->te_bird);
    sfSprite_setTextureRect(game->sprites->sp_button, game->variables->button);
    sfSprite_setTextureRect(game->sprites->sp_end, game->variables->end);
    sfSprite_setTextureRect(game->sprites->sp_block1, game->variables->block1);
    sfSprite_setTextureRect(game->sprites->sp_block2, game->variables->block2);
    sfSprite_setTextureRect(game->sprites->sp_block3, game->variables->block3);
    sfSprite_setTextureRect(game->sprites->sp_block4, game->variables->block4);
    coords_memory(game);
}
