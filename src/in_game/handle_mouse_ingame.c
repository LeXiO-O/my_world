/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../include/myworld.h"

static void fill_box(scene_ingame_t *ingame, sfEvent *event, int i)
{
    char charactere = event->text.unicode;

    if (event->type == sfEvtTextEntered && ingame->text_box[i].box_is_active) {
        if (charactere == '\b' && ingame->text_box[i].lenght_std_user > 0) {
            ingame->text_box[i].lenght_std_user--;
            ingame->text_box[i].std_user
            [ingame->text_box[i].lenght_std_user] = '\0';
        }
        if (charactere >= 32 && charactere < 127 &&
            ingame->text_box[i].lenght_std_user < STD_USER_IG_MAX - 1) {
            ingame->text_box[i].std_user
            [ingame->text_box[i].lenght_std_user] = charactere;
            ingame->text_box[i].lenght_std_user++;
            ingame->text_box[i].std_user
            [ingame->text_box[i].lenght_std_user] = '\0';
        }
    }
    sfText_setString(ingame->text_box[i].text, ingame->text_box[i].std_user);
}

static void contain_activation
(game_state_t *window, scene_ingame_t *ingame, sfEvent *event, int i)
{
    sfVector2i mouse_pos = sfMouse_getPosition((sfWindow *)window->window);
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds
        (ingame->text_box[i].box);

    if (sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y)) {
        if (event->type == sfEvtMouseButtonPressed &&
            event->mouseButton.button == sfMouseLeft) {
            ingame->text_box[i].box_is_active = true;
        }
    } else if (event->type == sfEvtMouseButtonPressed &&
        event->mouseButton.button == sfMouseLeft) {
        ingame->text_box[i].box_is_active = false;
    }
}

static void handle_mouse_box
(game_state_t *window, scene_ingame_t *ingame, sfEvent *event)
{
    for (int i = 0; i != NB_TEXT_BOX; i++) {
        contain_activation(window, ingame, event, i);
        fill_box(ingame, event, i);
    }
}

void handle_mouse_ingame
(game_state_t *window, scene_ingame_t *ingame, sfEvent *event)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window->window);
    sfFloatRect bounds = {0};

    for (int i = 0; i < NB_BUTTONS_INGAME; i++) {
        bounds = sfSprite_getGlobalBounds
            (ingame->buttons[i].isnt_click->sprite);
        if (sfFloatRect_contains(&bounds, mouse_pos.x, mouse_pos.y)) {
            ingame->buttons[i].is_on = 1;
        } else
            ingame->buttons[i].is_on = 0;
    }
    handle_mouse_box(window, ingame, event);
}
