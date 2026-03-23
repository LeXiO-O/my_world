/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../include/myworld.h"

static void change_button_state
(game_state_t *window, scene_menu_t *menu)
{
    for (int i = 0; i < NB_BUTTONS_MENU; i++) {
        if (menu->buttons[i].is_on == 1){
            sfSound_play(menu->buttons[i].sound);
            menu->buttons[i].on_click(window, menu->buttons[i].data);
        }
    }
}

static void button_menu_state
(game_state_t *window, scene_ingame_t *ingame)
{
    for (int i = 0; i < NB_BUTTONS_INGAME; i++) {
        if (ingame->buttons[i].is_on == 1) {
            sfSound_play(ingame->buttons[i].sound);
            ingame->buttons[i].on_click(window, ingame->buttons->data);
        }
    }
}

int menu_to_ingame
(sfEvent *event, game_state_t *window,
    scene_menu_t *scene_menu, scene_ingame_t *scene_ingame)
{
    if (event->type == sfEvtMouseButtonPressed) {
        if (window->scene == SCENE_MENU)
            change_button_state(window, scene_menu);
        if (window->scene == SCENE_INGAME)
            button_menu_state(window, scene_ingame);
    }
    return 0;
}
