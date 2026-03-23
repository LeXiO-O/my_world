/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../include/myworld.h"

void handle_event
(game_state_t *window, scene_menu_t *scene_menu,
    scene_ingame_t *scene_ingame)
{
    sfEvent event = {0};

    window->is_mouse_pressed = false;
    while (sfRenderWindow_pollEvent(window->window, &event)) {
        if (event.type == sfEvtClosed)
            window->is_select = false;
        menu_to_ingame(&event, window, scene_menu, scene_ingame);
        handle_mouse_menu(window, scene_menu, &event);
        handle_mouse_ingame(window, scene_ingame, &event);
        handle_keyboard(window, &event);
        if (event.type == sfEvtMouseButtonPressed &&
            event.mouseButton.button == sfMouseLeft) {
            window->is_mouse_pressed = true;
        }
    }
}
