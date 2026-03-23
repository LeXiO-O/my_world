/*
** EPITECH PROJECT, 2026
** MYWORLD.h
** File description:
** MYWORLD.h
*/

#ifndef MYWORLD_H
    #define MYWORLD_H

    /* MATRIX */
    #define MAP_X 6
    #define MAP_Y 6
    #define PI 3.14159265359
    #define OFFSET_X 960.0f
    #define OFFSET_Y 650.0f
    #define SCALE 600.0f
    #define RADIUS_ZONE 10.0f

    /* WINDOW */
    #define WINDOW_WIDTH 1920
    #define WINDOW_HEIGHT 1080
    #define BPP 32

    /* TAB BUTTON SIZE */
    #define NB_BUTTONS_MENU 2
    #define NB_BUTTONS_INGAME 10
    #define NB_TEXT_BOX 2


    /* MENU - TEXT BOX */
    #define POS_X_BOX 808
    #define POS_Y_BOX 800
    #define STD_USER_MAX 8
    #define TITLE_POS_X 500
    #define TITLE_POS_Y 200
    #define BOX_MENU_POS_X 300.0f
    #define BOX_MENU_POS_Y 75.0f
    #define BOX_MENU_OUTLINE 3.0f
    #define BOX_TEXT_POS_X 870.0f
    #define BOX_TEXT_POS_Y 800.0f

    /* MENU - SPRITE_POS */
    #define BTN_PLAY_POS_X 750
    #define BTN_PLAY_POS_Y 600
    #define BTN_QUIT_POS_X 1800
    #define BTN_QUIT_POS_Y 50
    #define BACKGROUND_POS 0
    #define POS_X_HELPER 740
    #define POS_Y_HELPER 500

    /* INGAME - SPRITE_POS */
    #define BTN_UP_POS_X 100
    #define BTN_UP_POS_Y 20
    #define BTN_DOWN_POS_X 300
    #define BTN_DOWN_POS_Y 20
    #define BTN_67_POS_X 500
    #define BTN_67_POS_Y 20
    #define BTN_REROLL_POS_X 685
    #define BTN_REROLL_POS_Y 25
    #define BTN_CLEAR_POS_X 800
    #define BTN_CLEAR_POS_Y 25
    #define BTN_HOME_POS_X 910
    #define BTN_HOME_POS_Y 25
    #define BTN_HELP_POS_X 1050
    #define BTN_HELP_POS_Y 13
    #define BTN_QUIT2_POS_X 1800
    #define BTN_QUIT2_POS_Y 13
    #define BTN_LOAD_POS_X 1580
    #define BTN_LOAD_POS_Y 200
    #define BTN_SAVE_POS_X 1580
    #define BTN_SAVE_POS_Y 350

    /* INGAME - TEXT BOX */
    #define STD_USER_IG_MAX 18
    #define BOX_THICKNESS 3.0f
    #define BOX_LOAD_GAME_POS_X 1450
    #define BOX_LOAD_GAME_POS_Y 150
    #define BOX_LOAD_GAME_SIZE_X 400
    #define BOX_LOAD_GAME_SIZE_Y 80
    #define BOX_SAVE_GAME_POS_X 1450
    #define BOX_SAVE_GAME_POS_Y 300
    #define BOX_SAVE_GAME_SIZE_X 400
    #define BOX_SAVE_GAME_SIZE_Y 80
    #define BOX_TEXT1_GAME_SIZE_X 1450
    #define BOX_TEXT1_GAME_SIZE_Y 150
    #define BOX_TEXT2_GAME_SIZE_X 1450
    #define BOX_TEXT2_GAME_SIZE_Y 300

    /* INGAME - SAVE & LOAD */
    #define PATH "map_files/"
    #define PATH_LEN 10
    #define FILE_UPDATE 0
    #define MAGIC "VLMYW67"
    #define MAGIC_LEN 7

    #include "my.h"
    #include "csfml_ws.h"

typedef enum scene_e {

    SCENE_MENU = 1,
    SCENE_INGAME

} scene_t;

typedef struct {
    int x;
    int y;
    float screen_y;
    int z;
} quad_sort_t;

typedef struct sprite_s {
    sfSprite *sprite;
    sfTexture *texture;
} sprite_t;

typedef struct texture_state_s {

    sfTexture *water;
    sfTexture *lava;
    sfTexture *dirt;
    sfTexture *obsidian;
    sfTexture *grass;
    sfTexture *stone;

} texture_state_t;

typedef struct game_state_s {

    scene_t scene;
    sfRenderWindow *window;
    char **matrix;
    int **matrix_size;
    sfVector2f **map2d;
    int size_matrix_y;
    int size_matrix_x;
    int selected_x;
    int selected_y;
    int x;
    int y;
    float scale;
    float zoom;
    float rot;
    float height;
    int grid_x;
    int grid_y;
    sfVector2f offset;
    sfRenderStates state;
    bool is_select;
    bool refresh;
    bool is_mouse_pressed;
    bool is_six_seven;
    bool is_running;
    sfVertex *current_vertex;
    float diff_mouse_vertex_x;
    float diff_mouse_vertex_y;
    float distance_squared;
    sfVector2f *vertex_select;
    sfEvent event;
    texture_state_t texture;

} game_state_t;

typedef struct button_s {

    sprite_t *isnt_click;
    sprite_t *is_click;
    int is_on;
    sfFont *helper_font;
    sfText *help_button;
    sfText *help_key;
    sfSoundBuffer *sound_buffer;
    sfSound *sound;
    void (*on_click)(game_state_t *state, void *data);
    void *data;

} button_t;

typedef struct scene_menu_s {

    bool box_is_active;
    sprite_t *background;
    sprite_t *title;
    sprite_t *helper;
    sfRectangleShape *box;
    sfVector2f pos_box;
    sfVector2f pos_text;
    sfFont *font_box;
    sfText *text;
    button_t buttons[NB_BUTTONS_MENU];
    int lenght_std_user;
    char std_user[STD_USER_MAX];

} scene_menu_t;

typedef struct text_box_s {

    sfRectangleShape *box;
    sfVector2f pos_box;
    sfVector2f pos_text;
    sfFont *font_box;
    sfText *text;
    bool box_is_active;
    int lenght_std_user;
    char std_user[STD_USER_IG_MAX];
} text_box_t;

typedef struct scene_ingame_s {

    sprite_t *tool_bar;
    button_t buttons[NB_BUTTONS_INGAME];
    text_box_t text_box[NB_TEXT_BOX];

} scene_ingame_t;

/* function for the project */

/* function lib */
sprite_t *create_sprite
(const char *str, sfVector2f *position);
void closewindow
(sfEvent event, sfRenderWindow *window);
sfRenderWindow *create_window
(const char *name_of_the_mainloop, const unsigned int *size_of_window);

/* create_sprite */
unsigned int create_all_sprite
(scene_menu_t *scene_menu, scene_ingame_t *scene_ingame);
unsigned int create_sprite_ingame
(scene_ingame_t *ingame);
unsigned int create_buttons_ingame
(scene_ingame_t *ingame);
unsigned int helper_text(scene_ingame_t *ingame);
unsigned int handle_box_ingame(scene_ingame_t *ingame);
unsigned int ingame_set_sound_for_button(scene_ingame_t *ingame, int i);

/* handle_event */
void handle_event
(game_state_t *window, scene_menu_t *scene_menu, scene_ingame_t *scene_ingame);
void handle_mouse_menu
(game_state_t *window, scene_menu_t *menu, sfEvent *event);
void handle_mouse_ingame
(game_state_t *window, scene_ingame_t *ingame, sfEvent *event);
unsigned int handle_box_menu
(scene_menu_t *menu);
void handle_keyboard(game_state_t *window, sfEvent *event);
int menu_to_ingame
(sfEvent *event, game_state_t *window,
    scene_menu_t *scene_menu, scene_ingame_t *scene_ingame);
void update_2d_map(game_state_t *window);

/* draw */
void draw_all_sprites
(game_state_t *window, scene_menu_t *menu, scene_ingame_t *ingame);
unsigned int draw_2d_map(game_state_t *window);
void update_texture(game_state_t *window, int x, int y);

/* matrix */
unsigned int create_and_show_matrix(game_state_t *window);
sfVertexArray *create_line
(sfVector2f *point1, sfVector2f *point2,
    sfVector2f *point3, sfVector2f *point4);
sfVertexArray *if_mouse_on(sfVertexArray *vertex_array,
    game_state_t *window);
unsigned int create_matrix
(game_state_t *window);
void apply_perlin_to_matrix(game_state_t *window, float scale, float amplitude);

/* function on_click */
void on_click_quit(game_state_t *state, void *data);
void on_click_play(game_state_t *state, void *data);
void on_click_up(game_state_t *state, void *data);
void on_click_down(game_state_t *state, void *data);
void on_click_six_seven(game_state_t *state, void *data);
void on_click_load(game_state_t *state, void *data);
void on_click_save(game_state_t *state, void *data);
void on_click_clear(game_state_t *state, void *data);
void on_click_menu(game_state_t *state, void *data);
void on_click_reroll(game_state_t *state, void *data);
void on_click_help(game_state_t *state, void *data);

/* buttons */
unsigned int save_button(scene_ingame_t *ingame);
unsigned int load_button(scene_ingame_t *ingame);
unsigned int up_button(scene_ingame_t *ingame);
unsigned int down_button(scene_ingame_t *ingame);
unsigned int six_seven_button(scene_ingame_t *ingame);
unsigned int reroll_button(scene_ingame_t *ingame);
unsigned int clear_button(scene_ingame_t *ingame);
unsigned int home_button(scene_ingame_t *ingame);
unsigned int help_button(scene_ingame_t *ingame);
unsigned int quit_button(scene_ingame_t *ingame);

/* save_load */
unsigned int manage_save(game_state_t *state, scene_ingame_t *ingame);
unsigned int manage_load(game_state_t *state, scene_ingame_t *ingame);

/* parsing box */
unsigned int parsing_std_user(game_state_t *state, scene_menu_t *menu);

/* free */
void free_asset_window(game_state_t *window);
void free_asset_ingame(scene_ingame_t *ingame);
void free_asset_menu(scene_menu_t *menu);

#endif /* MYWORLD_H */
