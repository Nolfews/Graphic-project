/*
** EPITECH PROJECT, 2023
** header
** File description:
** header
*/

#ifndef HEADER_H_
    #define HEADER_H_
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <stdlib.h>
    #include <time.h>

typedef struct sprite {
    sfSprite *sprite_bg;
    sfTexture *texture_bg;
    sfSprite *sprite_star1;
    sfTexture *texture_star1;
    sfSprite *sprite_star2;
    sfTexture *texture_star2;
    sfSprite *sprite_star3;
    sfTexture *texture_star3;
} s_sprite;

typedef struct music {
    sfMusic *music_game;
}  s_music;

typedef struct rect_sprite {
    sfIntRect rect;
} s_rect;
typedef struct vector {
    sfVector2f vector1;
    sfVector2f vector2;
    sfVector2f vector3;
} s_vector;

void my_put_nbr(int nb);
void my_putchar(char c);
void my_putstr(char const *str);
int my_strlen(char const *str);
int open_window(void);
void analyse_events(sfRenderWindow *window, s_sprite *sp);
int set_background(sfRenderWindow *win, s_sprite *bg, s_music *ms, s_rect *sr);
void close_window(sfRenderWindow *window);
void set_rect(s_sprite *sp, s_rect *sr);
int play_music(s_music *ms);
int set_sprite(sfRenderWindow *window, s_sprite *sp, s_rect *sr);
void draw_sprite(sfRenderWindow *window, s_sprite *sp);
void sprite_anime(sfClock *clock, s_sprite *sp, s_rect *sr);
void sprite_move(s_sprite *sp);
sfRenderWindow *set_window(void);
void clock_sprite(sfClock *clock, s_sprite *sp);
void check_pos_sprite(s_sprite *sp);

#endif /* HEADER_H_ */
