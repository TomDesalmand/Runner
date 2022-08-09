/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-tom.desalmand
** File description:
** map.c
*/

#include "../../include/runner.h"

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    char **array_2d = malloc(sizeof(char *) * (nb_rows + 1));
    for (int i = 0; i < nb_rows; i++) {
        array_2d[i] = malloc(sizeof(char) * (nb_cols + 1));
        array_2d[i][nb_cols] = '\0';
    }
    array_2d[nb_rows] = NULL;
    return array_2d;
}

char **get_map(game_t *game, char *path)
{
    FILE *file = fopen(path, "r");
    char *buffer = NULL;
    size_t buffer_size = 0;
    int line_count = 0;
    ssize_t line_size = getline(&buffer, &buffer_size, file);
    game->variables->len_map = line_size;
    char **map = mem_alloc_2d_array(10, line_size);
    my_strcpy(map[line_count], buffer);
    while (line_size >= 0) {
        line_count++;
        line_size = getline(&buffer, &buffer_size, file);
        my_strcpy(map[line_count], buffer);
    }
    map[line_count] = NULL;
    free(buffer);
    fclose(file);
    return map;
}

void check_colision(game_t *game)
{
    sfFloatRect block1 = sfSprite_getGlobalBounds(game->sprites->sp_block1);
    sfFloatRect block2 = sfSprite_getGlobalBounds(game->sprites->sp_block2);
    sfFloatRect block3 = sfSprite_getGlobalBounds(game->sprites->sp_block3);
    sfFloatRect block4 = sfSprite_getGlobalBounds(game->sprites->sp_block4);
    sfFloatRect birdr = sfSprite_getGlobalBounds(game->sprites->sp_bird);
    if (sfFloatRect_intersects(&block1, &birdr, NULL))
        game->variables->status = 3;
    if (sfFloatRect_intersects(&block2, &birdr, NULL))
        game->variables->status = 3;
    if (sfFloatRect_intersects(&block3, &birdr, NULL))
        game->variables->status = 3;
    if (sfFloatRect_intersects(&block2, &birdr, NULL))
        game->variables->status = 3;
    if (sfSprite_getPosition(game->sprites->sp_bird).y > 1100 ||
    sfSprite_getPosition(game->sprites->sp_bird).y < -150)
        game->variables->status = 3;
}

void check_end(game_t *game)
{
    if (game->coords->coord_bird.x >= 150 * game->variables->len_map)
        game->variables->status = 4;
}

void reset(game_t *game)
{
    sfMusic_stop(game->musics->jump);
    sfMusic_stop(game->musics->theme);
    sfView_reset(game->coords->view, game->variables->viewrect);
    game->variables->score = 0;
    game->variables->status = 0;
    game->variables->bird_status = 1;
    game->variables->bird_jump = 0.0;
    game->coords->coord_bg = (sfVector2f){0.0, 0.0};
    game->coords->coord_cl = (sfVector2f){0.0, 250.0};
    game->coords->coord1 = (sfVector2f){0.0, 275.0};
    game->coords->coord2 = (sfVector2f){0.0, 275.0};
    game->coords->coord3 = (sfVector2f){0.0, 275.0};
    game->coords->coordblock = (sfVector2f){0.0, 0.0};
    game->coords->coord_view = (sfVector2f){0.0, 0.0};
    game->coords->coord_bird = (sfVector2f){300.0, 500.0};
}
