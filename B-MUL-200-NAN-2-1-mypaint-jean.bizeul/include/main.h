/*
** EPITECH PROJECT, 2024
** paint
** File description:
** main.h
*/

#ifndef MAIN_H_
    #define MAIN_H_
    #include <math.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>

    #define IS_HOVER(button) ((button->state) == (HOVER) ? (1) : (0))
    #define IS_PRESSED(button) ((button->state) == (PRESSED) ? (1) : (0))
    #define IS_RELEASED(button) ((button->state) == (RELEASED) ? (1) : (0))

typedef struct linked_list_s {
    void *data;
    struct linked_list_s *next;
} linked_list_t;

enum e_gui_state {
    NONE = 0,
    HOVER,
    PRESSED,
    RELEASED
};

enum e_shape {
    CIRCLE,
    SQUARE
};

typedef struct textures_s {
    sfTexture *files;
    sfTexture *tools_buttons;
    sfTexture *help;
    sfTexture *colors;
    sfTexture *size;
    sfTexture *shape;
} textures_t;

typedef struct button_s {
    sfSprite *sprite;
    sfIntRect text_rect;
    sfBool (*is_click)(void *paint);
    enum e_gui_state state;
} button_t;

typedef struct menu_scrolling_s {
    button_t *button;
    linked_list_t **buttons;
    enum e_gui_state state;
} menu_scrolling_t;

typedef struct menu_color_selection_s {
    sfCircleShape *circle;
    sfRectangleShape *text_rect;
    enum e_gui_state state;
} menu_color_selection_t;

typedef struct menu_sidebar_s {
    linked_list_t **buttons;
    sfSprite *color;
    sfText *text;
    enum e_gui_state state;
} menu_sidebar_t;

typedef struct layer_s {
    int id;
    sfImage *img_img;
    sfTexture *img_text;
    sfSprite *img_spr;
    struct layer_s *last;
    struct layer_s *next;
} layer_t;

typedef struct board_s {
    int layer;
    sfVector2f last_pos;
    sfVector2f pos;
    sfRectangleShape *backgr;
    layer_t **begin;
    layer_t **end;
    enum e_gui_state state;
    enum e_shape shape;
    int tool_size;
    sfColor color;
} board_t;

typedef struct top_bar_s {
    sfRectangleShape *rect;
    linked_list_t **scrolls;
    sfRenderWindow *save;
    sfRenderWindow *open;
    sfRenderWindow *about;
    sfRenderWindow *help;
    sfText *text;
    sfFont *font;
} top_bar_t;

typedef struct paint_s {
    sfRenderWindow *window;
    board_t *draw;
    top_bar_t *top;
    menu_sidebar_t *side;
    textures_t *textures;
}paint_t;

int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
void push_to_list(linked_list_t **begin, void *data);
int get_linked_list_len(linked_list_t *first_node);
void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nbr);
int mini_printf(char const *format, ...);

sfRenderWindow *create_renderwindow(int width, int height, sfWindowStyle style,
    char *name);

void do_buttons_actions(paint_t *paint);
sfBool reset_layers(void *data);
sfBool save_layers_as_file(void *data);
sfBool open_file(void *data);
sfBool set_tool_to_pencil(void *data);
sfBool set_tool_to_rubber(void *data);
sfBool display_help_window(void *data);
sfBool display_about_window(void *data);
sfBool increase_size(void *data);
sfBool decrease_size(void *data);
sfBool set_shape_square(void *data);
sfBool set_shape_circle(void *data);

paint_t *init_paint_struct(void);
textures_t *init_textures(void);
button_t *init_button(sfTexture *texture, sfVector2f pos, sfVector2f scale,
    sfIntRect text_rect);
top_bar_t *init_top_bar(textures_t *textures);
menu_sidebar_t *init_side_menu(paint_t *paint);
void init_buttons_functions_top_bar(top_bar_t *top_bar);
void init_buttons_functions_side_bar(menu_sidebar_t *sidebar);
board_t *init_drawing_board(void);
layer_t *create_layer(void);
void add_layer_from_end(layer_t *layer, layer_t **end, layer_t **begin);
void delete_all_layers(layer_t **end, layer_t **begin);
sfBool parse_args(int argc, char const **args);
int manage_events(paint_t *paint);
sfVector2f get_mouse_pos(sfRenderWindow *window);
void update_button(sfEvent *event, button_t *button, sfRenderWindow *window);
void update_top_bar_status(top_bar_t *top_bar, sfEvent *event,
    sfRenderWindow *window);
void update_board(sfEvent *event, paint_t *paint);
int is_cursor_on_board(sfRenderWindow *window);
int main_loop(paint_t *paint);
void draw_top_bar(paint_t *paint);
void draw_button(sfRenderWindow *window, button_t *button);
void draw_board(paint_t *paint);
void add_layer_from_end(layer_t *layer, layer_t **end, layer_t **begin);
void draw_side_menu(paint_t *paint);
void draw(paint_t *paint);
void draw_side_menu(paint_t *paint);
void update_side_menu_status(menu_sidebar_t *menu, sfEvent *event,
    sfRenderWindow *window);
void draw_on_board(board_t *board);
void draw_shape(board_t *board, sfVector2f pos);
void free_paint_struct(paint_t *paint);
void event_color(sfEvent *event, paint_t *paint);
void draw_text(paint_t *paint);

#endif /* !MAIN_H_ */
