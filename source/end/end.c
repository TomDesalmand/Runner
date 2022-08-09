/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-tom.desalmand
** File description:
** end.c
*/

#include "../../include/runner.h"

void free_in_memory(game_t *game)
{
    sfMusic_destroy(game->musics->jump);
    sfMusic_destroy(game->musics->theme);
    sfText_destroy(game->texts->st);
    sfText_destroy(game->texts->scoret);
    sfText_destroy(game->texts->tw);
    sfText_destroy(game->texts->tl);
    sfText_destroy(game->texts->te);
    sfText_destroy(game->texts->t3);
    sfText_destroy(game->texts->t2);
    sfText_destroy(game->texts->t1);
    sfTexture_destroy(game->textures->te_bird);
    sfTexture_destroy(game->textures->te_block2);
    sfTexture_destroy(game->textures->te_block1);
    sfTexture_destroy(game->textures->te_button);
    sfTexture_destroy(game->textures->te_3);
    sfTexture_destroy(game->textures->te_2);
    sfTexture_destroy(game->textures->te_1);
    sfTexture_destroy(game->textures->cl_te);
    sfTexture_destroy(game->textures->bg_te);
    sfTexture_destroy(game->textures->te_logo);
}

void free_in_memory2(game_t *game)
{
    sfSprite_destroy(game->sprites->sp_bird);
    sfSprite_destroy(game->sprites->sp_block4);
    sfSprite_destroy(game->sprites->sp_block3);
    sfSprite_destroy(game->sprites->sp_block2);
    sfSprite_destroy(game->sprites->sp_block1);
    sfSprite_destroy(game->sprites->sp_end);
    sfSprite_destroy(game->sprites->sp_button);
    sfSprite_destroy(game->sprites->sp_3);
    sfSprite_destroy(game->sprites->sp_2);
    sfSprite_destroy(game->sprites->sp_1);
    sfSprite_destroy(game->sprites->cl_sp);
    sfSprite_destroy(game->sprites->bg_sp);
    sfSprite_destroy(game->sprites->sp_logo);
    sfView_destroy(game->coords->view);
    sfClock_destroy(game->variables->clock);
    sfRenderWindow_destroy(game->windows->window);
    free_struct(game);
}

void free_struct(game_t *game)
{
    free(game->musics);
    free(game->texts);
    free(game->coords);
    free(game->textures);
    free(game->sprites);
    free(game->variables);
    free(game->windows);
    free(game);
}

void window_events(game_t *game)
{
    sfRenderWindow *w = game->windows->window;
    sfEvent event;
    while (sfRenderWindow_pollEvent(game->windows->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->windows->window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            sfRenderWindow_close(game->windows->window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace &&
        (game->variables->status == 1 || game->variables->status == 2)) {
            game->variables->bird_status = 2;
            if (game->variables->bird_jump >= 0.0)
                game->variables->bird_jump -= 0.005;
                sfMusic_play(game->musics->jump);
        }
    }
}

void test_end(game_t *game)
{
    sfRenderWindow *w = game->windows->window;
    if (sfMouse_getPositionRenderWindow(w).x > 550.0 &&
    sfMouse_getPositionRenderWindow(w).x < 1350.0 &&
    sfMouse_getPositionRenderWindow(w).y > 100.0 &&
    sfMouse_getPositionRenderWindow(w).y < 300.0 &&
    sfMouse_isButtonPressed(sfMouseLeft)) {
        reset(game);
        game->variables->status = 0;
    }
}
