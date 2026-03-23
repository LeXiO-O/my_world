/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../../include/myworld.h"

unsigned int up_button(scene_ingame_t *ingame)
{
    ingame->buttons[0].isnt_click = create_sprite
        ("asset/ingame/up_1.png",
        &(sfVector2f){BTN_UP_POS_X, BTN_UP_POS_Y});
    if (ingame->buttons[0].isnt_click == NULL)
        return 84;
    ingame->buttons[0].is_click = create_sprite
        ("asset/ingame/up_2.png",
        &(sfVector2f){BTN_UP_POS_X, BTN_UP_POS_Y});
    if (ingame->buttons[0].is_click == NULL)
        return 84;
    ingame->buttons[0].on_click = on_click_up;
    ingame->buttons[0].data = ingame;
    if (ingame_set_sound_for_button(ingame, 0) == 84)
        return 84;
    return 0;
}
