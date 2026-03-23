/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../include/myworld.h"

static void draw_scene_menu
(game_state_t *window, scene_menu_t *menu)
{
    if (window->scene != SCENE_MENU)
        return;
    sfRenderWindow_drawSprite(window->window, menu->background->sprite, NULL);
    sfRenderWindow_drawSprite(window->window, menu->title->sprite, NULL);
    sfRenderWindow_drawSprite(window->window, menu->helper->sprite, NULL);
    sfRenderWindow_drawRectangleShape(window->window, menu->box, NULL);
    sfRenderWindow_drawText(window->window, menu->text, NULL);
    for (int i = 0; i < NB_BUTTONS_MENU; i++) {
        if (menu->buttons[i].is_on == 1)
            sfRenderWindow_drawSprite
        (window->window, menu->buttons[i].is_click->sprite, NULL);
        else
            sfRenderWindow_drawSprite
        (window->window, menu->buttons[i].isnt_click->sprite, NULL);
    }
}

static void is_helper
(game_state_t *window, scene_ingame_t *ingame, int i)
{
    if (i == 6) {
        sfRenderWindow_drawText
        (window->window, ingame->buttons[6].help_button, NULL);
        sfRenderWindow_drawText
        (window->window, ingame->buttons[6].help_key, NULL);
    }
}

static void draw_scene_ingame
(game_state_t *window, scene_ingame_t *ingame)
{
    if (window->scene != SCENE_INGAME)
        return;
    for (int e = 0; e != NB_TEXT_BOX; e++) {
        sfRenderWindow_drawRectangleShape
        (window->window, ingame->text_box[e].box, NULL);
        sfRenderWindow_drawText(window->window, ingame->text_box[e].text, NULL);
    }
    sfRenderWindow_drawSprite(window->window, ingame->tool_bar->sprite, NULL);
    for (int i = 0; i < NB_BUTTONS_INGAME; i++) {
        if (ingame->buttons[i].is_on == 1) {
            is_helper(window, ingame, i);
            sfRenderWindow_drawSprite
            (window->window, ingame->buttons[i].is_click->sprite, NULL);
        } else
            sfRenderWindow_drawSprite
        (window->window, ingame->buttons[i].isnt_click->sprite, NULL);
    }
    return;
}

static void display_game
(game_state_t *window, scene_menu_t *menu, scene_ingame_t *ingame)
{
    draw_2d_map(window);
    draw_scene_menu(window, menu);
    draw_scene_ingame(window, ingame);
}

void draw_all_sprites
(game_state_t *window, scene_menu_t *menu, scene_ingame_t *ingame)
{
    sfRenderWindow_clear(window->window, sfWhite);
    if (window->refresh) {
        update_2d_map(window);
        window->refresh = false;
    }
    display_game(window, menu, ingame);
    sfRenderWindow_display(window->window);
}
