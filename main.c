/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-tom.desalmand
** File description:
** main.c
*/

#include "include/runner.h"

void print_game_description()
{
    my_putstr("Game Description:\n");
    my_putstr("==========================================================\n");
    my_putstr("The goal of this game is too complete a level without dying.");
    my_putchar('\n');
    my_putchar('\n');
    my_putstr("Controls:\n");
    my_putstr("Space bar to fly and avoid the obstacles\n");
    my_putstr("Echap to leave game\n");
    my_putstr("==========================================================\n");
}

void initialize_game(game_t *game)
{
    game->variables->map2 = get_map(game, "maps/map2.txt");
    game->variables->map1 = get_map(game, "maps/map1.txt");
    variables_memory(game);
    create_window(game, 1920, 1080);
    while (sfRenderWindow_isOpen(game->windows->window)) {
        game->variables->time = sfClock_getElapsedTime(game->variables->clock);
        game->variables->s = game->variables->time.microseconds / 1000000.0;
        set_coords(game);
        check_background_pos(game);
        game_launch(game);
        window_events(game);
    }
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] && av[1][1] == 'h') {
        print_game_description();
        return 0;
    } if (ac == 2) {
        game_t *game = malloc(sizeof(game_t));
        put_in_memory(game);
        initialize_game(game);
        free_in_memory(game);
        return 0;
    } else {
        my_putstr("Invalid arguments given.\n");
        return 84;
    }
    return 0;
}
