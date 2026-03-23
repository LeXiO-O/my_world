/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../../include/myworld.h"

unsigned int clear_button(scene_ingame_t *ingame)
{
    ingame->buttons[4].isnt_click = create_sprite
        ("asset/ingame/clear_1.png",
        &(sfVector2f){BTN_CLEAR_POS_X, BTN_CLEAR_POS_Y});
    if (ingame->buttons[4].isnt_click == NULL)
        return 84;
    ingame->buttons[4].is_click = create_sprite
        ("asset/ingame/clear_2.png",
        &(sfVector2f){BTN_CLEAR_POS_X, BTN_CLEAR_POS_Y});
    if (ingame->buttons[4].is_click == NULL)
        return 84;
    ingame->buttons[4].on_click = on_click_clear;
    ingame->buttons[4].data = ingame;
    if (ingame_set_sound_for_button(ingame, 4) == 84)
        return 84;
    return 0;
}
