/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../../include/myworld.h"

unsigned int six_seven_button(scene_ingame_t *ingame)
{
    ingame->buttons[2].isnt_click = create_sprite
        ("asset/ingame/lava_1.png",
        &(sfVector2f){BTN_67_POS_X, BTN_67_POS_Y});
    if (ingame->buttons[2].isnt_click == NULL)
        return 84;
    ingame->buttons[2].is_click = create_sprite
        ("asset/ingame/lava_2.png",
        &(sfVector2f){BTN_67_POS_X, BTN_67_POS_Y});
    if (ingame->buttons[2].is_click == NULL)
        return 84;
    ingame->buttons[2].on_click = on_click_six_seven;
    ingame->buttons[2].data = ingame;
    if (ingame_set_sound_for_button(ingame, 2) == 84)
        return 84;
    return 0;
}
