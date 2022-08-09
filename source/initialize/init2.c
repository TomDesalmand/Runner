/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-tom.desalmand
** File description:
** init2.c
*/

#include "../../include/runner.h"

void coords_memory(game_t *game)
{
    game->coords->coord_bg = (sfVector2f){0.0, 0.0};
    game->coords->coord_cl = (sfVector2f){0.0, 250.0};
    game->coords->coord1 = (sfVector2f){0.0, 275.0};
    game->coords->coord2 = (sfVector2f){0.0, 275.0};
    game->coords->coord3 = (sfVector2f){0.0, 275.0};
    game->coords->coordblock = (sfVector2f){0.0, 0.0};
    game->coords->coord_view = (sfVector2f){0.0, 0.0};
    game->coords->coord_bird = (sfVector2f){300.0, 500.0};
    texts_memory(game);
}

void texts_memory(game_t *game)
{
    game->texts->t1 = sfText_create();
    game->texts->t2 = sfText_create();
    game->texts->t3 = sfText_create();
    game->texts->te = sfText_create();
    game->texts->tl = sfText_create();
    game->texts->tw = sfText_create();
    game->texts->scoret = sfText_create();
    game->texts->st = sfText_create();
    sfText_setString(game->texts->t1, "Easy");
    sfText_setString(game->texts->t2, "Hard");
    sfText_setString(game->texts->t3, "Quit");
    sfText_setString(game->texts->te, "Back To Menu");
    sfText_setString(game->texts->tl, "Game Over");
    sfText_setString(game->texts->tw, "Game Win");
    sfText_setString(game->texts->scoret, "Score:");
    set_font(game);
}

void set_font(game_t *game)
{
    sfText_setCharacterSize(game->texts->t1, 100);
    sfText_setCharacterSize(game->texts->t2, 100);
    sfText_setCharacterSize(game->texts->t3, 100);
    sfText_setCharacterSize(game->texts->te, 75);
    sfText_setCharacterSize(game->texts->tl, 200);
    sfText_setCharacterSize(game->texts->tw, 200);
    sfText_setCharacterSize(game->texts->scoret, 50);
    sfText_setCharacterSize(game->texts->st, 50);
    sfText_setFont(game->texts->t1, sfFont_createFromFile("image/ft.ttf"));
    sfText_setFont(game->texts->t2, sfFont_createFromFile("image/ft.ttf"));
    sfText_setFont(game->texts->t3, sfFont_createFromFile("image/ft.ttf"));
    sfText_setFont(game->texts->te, sfFont_createFromFile("image/ft.ttf"));
    sfText_setFont(game->texts->tl, sfFont_createFromFile("image/ft.ttf"));
    sfText_setFont(game->texts->tw, sfFont_createFromFile("image/ft.ttf"));
    sfText_setFont(game->texts->scoret, sfFont_createFromFile("image/ft.ttf"));
    sfText_setFont(game->texts->st, sfFont_createFromFile("image/ft.ttf"));
    music_memory(game);
}

void music_memory(game_t *game)
{
    game->musics->theme = sfMusic_createFromFile("image/song.wav");
    game->musics->jump = sfMusic_createFromFile("image/flap.wav");
    sfMusic_setLoop(game->musics->theme, sfTrue);
}

void create_window(game_t *game, int width, int height)
{
    sfVideoMode mode;
    mode.width = width;
    mode.height = height;
    mode.bitsPerPixel = 32;
    game->windows->window = sfRenderWindow_create(mode, "", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->windows->window, 60);
    sfRenderWindow_setMouseCursorVisible(game->windows->window, sfTrue);
    sfRenderWindow_setPosition(game->windows->window, (sfVector2i){0,0});
}
