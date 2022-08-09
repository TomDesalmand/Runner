/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-tom.desalmand
** File description:
** display_game_phase.c
*/

#include "../../include/runner.h"

const float CLOCK_TIME = 0.012;

void game_launch(game_t *game)
{
    if (game->variables->s >= CLOCK_TIME) {
        display_background(game);
        switch (game->variables->status) {
        case 0:
            move_background(game);
            draw_menu(game);
            test_menu(game);
            break;
        case 1:
            game->variables->map_nb = 1;
            move_background2(game);
            draw_map(game, game->variables->map1);
            bird_jump(game);
            set_score_position_game(game);
            break;
        default:
            game_launch2(game);
        }
    update_window(game);
    }
}

void game_launch2(game_t *game)
{
    switch (game->variables->status) {
    case 2:
        game->variables->map_nb = 2;
        move_background2(game);
        draw_map(game, game->variables->map2);
        bird_jump(game);
        set_score_position_game(game);
        break;
    case 3:
        if (game->variables->map_nb == 1)
            draw_map(game, game->variables->map1);
        if (game->variables->map_nb == 2)
            draw_map(game, game->variables->map2);
        draw_endl(game);
        test_end(game);
        set_score_position_end(game);
        break;
    default:
        game_launch3(game);
    }
}

int game_launch3(game_t * game)
{
    switch (game->variables->status) {
    case 4:
        if (game->variables->map_nb == 1)
            draw_map(game, game->variables->map1);
        if (game->variables->map_nb == 2)
            draw_map(game, game->variables->map2);
        draw_map(game, game->variables->map1);
        draw_endw(game);
        test_end(game);
        set_score_position_end(game);
        break;
    default:
        return 84;
    }
}

void test_menu(game_t *game)
{
    sfRenderWindow *w = game->windows->window;
    sfSprite *b = game->sprites->sp_button;
    if (sfMouse_getPositionRenderWindow(w).x > sfSprite_getPosition(b).x &&
    sfMouse_getPositionRenderWindow(w).x < sfSprite_getPosition(b).x + 800.0 &&
    sfMouse_getPositionRenderWindow(w).y > sfSprite_getPosition(b).y &&
    sfMouse_getPositionRenderWindow(w).y < sfSprite_getPosition(b).y + 200.0 &&
    sfMouse_isButtonPressed(sfMouseLeft))
        game->variables->status = 1;
    if (sfMouse_getPositionRenderWindow(w).x > sfSprite_getPosition(b).x &&
    sfMouse_getPositionRenderWindow(w).x < sfSprite_getPosition(b).x + 800.0 &&
    sfMouse_getPositionRenderWindow(w).y > sfSprite_getPosition(b).y + 200.0 &&
    sfMouse_getPositionRenderWindow(w).y < sfSprite_getPosition(b).y + 400.0 &&
    sfMouse_isButtonPressed(sfMouseLeft))
        game->variables->status = 2;
    if (sfMouse_getPositionRenderWindow(w).x > sfSprite_getPosition(b).x &&
    sfMouse_getPositionRenderWindow(w).x < sfSprite_getPosition(b).x + 800.0 &&
    sfMouse_getPositionRenderWindow(w).y > sfSprite_getPosition(b).y + 400.0 &&
    sfMouse_getPositionRenderWindow(w).y < sfSprite_getPosition(b).y + 600.0 &&
    sfMouse_isButtonPressed(sfMouseLeft))
        sfRenderWindow_close(game->windows->window);
}

void bird_pos_status(game_t* game)
{
    if (game->variables->status == 3 || game->variables->status == 4 &&
    sfSprite_getPosition(game->sprites->sp_bird).y < 1100.0)
        game->coords->coord_bird.y += 0.004;
    if (game->variables->status != 3)
        game->coords->coord_bird.y += game->variables->bird_jump;
}
