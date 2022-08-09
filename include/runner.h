/*
** EPITECH PROJECT, 2021
** B-MUL-100-LYN-1-1-myrunner-tom.desalmand
** File description:
** runner.h
*/

#ifndef MY_H_

#include <stdio.h>
#include <SFML/Graphics.h>
#include <SFML/Network.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct windows {
    sfRenderWindow *window;
} windows_t;

typedef struct texts {
    sfText *t1;
    sfText *t2;
    sfText *t3;
    sfText *te;
    sfText *tl;
    sfText *tw;
    sfText *scoret;
    sfText *st;

} texts_t;

typedef struct variables {
    sfTime time;
    sfClock *clock;
    float s;
    int status;
    int bird_status;
    float bird_jump;
    sfIntRect bird1;
    sfIntRect bird2;
    sfIntRect bird3;
    sfIntRect button;
    sfIntRect block1;
    sfIntRect block2;
    sfIntRect block3;
    sfIntRect block4;
    sfIntRect end;
    sfFloatRect viewrect;
    char **map1;
    char **map2;
    int len_map;
    int score;
    int map_nb;
} variables_t;

typedef struct coords {
    sfView *view;
    sfVector2f coord_bg;
    sfVector2f coord_cl;
    sfVector2f coord1;
    sfVector2f coord2;
    sfVector2f coord3;
    sfVector2f coordblock;
    sfVector2f coord_button;
    sfVector2f coord_view;
    sfVector2f coord_bird;
    sfVector2f coord_end;
} coords_t;

typedef struct sprites {
    sfSprite *sp_logo;
    sfSprite *bg_sp;
    sfSprite *cl_sp;
    sfSprite *sp_1;
    sfSprite *sp_2;
    sfSprite *sp_3;
    sfSprite *sp_block1;
    sfSprite *sp_block2;
    sfSprite *sp_block3;
    sfSprite *sp_block4;
    sfSprite *sp_button;
    sfSprite *sp_bird;
    sfSprite *sp_end;
} sprites_t;

typedef struct textures {
    sfTexture *te_logo;
    sfTexture *bg_te;
    sfTexture *cl_te;
    sfTexture *te_1;
    sfTexture *te_2;
    sfTexture *te_3;
    sfTexture *te_block1;
    sfTexture *te_block2;
    sfTexture *te_button;
    sfTexture *te_bird;
} textures_t;

typedef struct musics {
    sfMusic *theme;
    sfMusic *jump;
} musics_t;

typedef struct game {
    windows_t *windows;
    variables_t *variables;
    sprites_t *sprites;
    textures_t *textures;
    coords_t *coords;
    texts_t *texts;
    musics_t *musics;
} game_t;

#define MY_H_

// game init //
void reset(game_t *game);
void setTextureRect(sfSprite *sprite, sfIntRect rect);
void initialize_game(game_t *game);
void put_in_memory(game_t *game);
void create_window(game_t *game, int width, int height);
void variables_memory(game_t *game);
void sprites_memory(game_t *game);
void textures_memory(game_t *game);
void append_textures(game_t *game);
void texts_memory(game_t *game);
void coords_memory(game_t *game);
void create_textures(sfTexture **texture, char *path);
void set_font(game_t *game);
void set_coords(game_t *game);
void music_memory(game_t *game);
void setTexture(sfSprite *sprite, sfTexture *texture);

// game_desc //
void print_game_description();

// map //
void check_end(game_t *game);
char **get_map(game_t *game, char *path);
void draw_map(game_t *game, char **map);
void draw_blocks(game_t *game, char block);
void set_block_pos(game_t *game);
void draw_bird(game_t *game);
void bird_jump(game_t *game);
void bird_pos_status(game_t* game);

// in-game //
void set_score_position_game(game_t *game);
void set_score_position_end(game_t *game);
void display_background(game_t *game);
void check_background_pos(game_t *game);
void move_background(game_t *game);
void move_background2(game_t *game);
void drawSprite(sfRenderWindow *window, sfSprite *sprite);
void game_launch(game_t *game);
void game_launch2(game_t *game);
int game_launch3(game_t * game);
void test_menu(game_t *game);
void update_window(game_t *game);
void draw_menu(game_t *game);
void draw_endl(game_t *game);
void draw_endw(game_t *game);
char *my_itoa(int num);

// library //
char *my_strcpy(char *dest , char const *src);
int my_strlen(char const *str);
void my_putchar(char c);
void my_putstr(char const *str);

// game end //
void test_end(game_t *game);
void window_events(game_t *game);
void free_in_memory(game_t *game);
void free_in_memory2(game_t *game);
void free_struct(game_t *game);
void check_colision(game_t *game);

#endif
