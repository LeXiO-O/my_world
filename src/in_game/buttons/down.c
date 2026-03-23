/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../../include/myworld.h"

unsigned int down_button(scene_ingame_t *ingame)
{
    ingame->buttons[1].isnt_click = create_sprite
        ("asset/ingame/down_1.png",
        &(sfVector2f){BTN_DOWN_POS_X, BTN_DOWN_POS_Y});
    if (ingame->buttons[1].isnt_click == NULL)
        return 84;
    ingame->buttons[1].is_click = create_sprite
        ("asset/ingame/down_2.png",
        &(sfVector2f){BTN_DOWN_POS_X, BTN_DOWN_POS_Y});
    if (ingame->buttons[1].is_click == NULL)
        return 84;
    ingame->buttons[1].on_click = on_click_down;
    ingame->buttons[1].data = ingame;
    if (ingame_set_sound_for_button(ingame, 1) == 84)
        return 84;
    return 0;
}
