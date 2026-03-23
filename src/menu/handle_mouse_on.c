/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../include/myworld.h"

static void fill_box(scene_menu_t *menu, sfEvent *event)
{
    char charactere = event->text.unicode;

    if (event->type == sfEvtTextEntered && menu->box_is_active) {
        if (charactere == '\b' && menu->lenght_std_user > 0) {
            menu->lenght_std_user--;
            menu->std_user[menu->lenght_std_user] = '\0';
        }
        if (charactere >= 32 && charactere < 127 &&
            menu->lenght_std_user < STD_USER_MAX - 1) {
            menu->std_user[menu->lenght_std_user] = charactere;
            menu->lenght_std_user++;
            menu->std_user[menu->lenght_std_user] = '\0';
            menu->box_is_active = false;
        }
    }
    sfText_setString(menu->text, menu->std_user);
}

static void handle_mouse_box
(game_state_t *window, scene_menu_t *menu, sfEvent *event)
{
    sfVector2i mouse_pos = sfMouse_getPosition((sfWindow *)window->window);
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(menu->box);

    if (sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y)) {
        if (event->type == sfEvtKeyPressed) {
            menu->box_is_active = true;
        }
    }
    fill_box(menu, event);
}

void handle_mouse_menu
(game_state_t *window, scene_menu_t *menu, sfEvent *event)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window->window);
    sfFloatRect bounds;

    for (int i = 0; i < NB_BUTTONS_MENU; i++) {
        bounds = sfSprite_getGlobalBounds(menu->buttons[i].isnt_click->sprite);
        if (sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y)) {
            menu->buttons[i].is_on = 1;
        } else
            menu->buttons[i].is_on = 0;
    }
    handle_mouse_box(window, menu, event);
}
