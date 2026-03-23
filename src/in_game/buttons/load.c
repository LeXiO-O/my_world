/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../../include/myworld.h"

unsigned int load_button(scene_ingame_t *ingame)
{
    ingame->buttons[8].isnt_click = create_sprite
        ("asset/ingame/load_save/load_red.png",
        &(sfVector2f){BTN_LOAD_POS_X, BTN_LOAD_POS_Y});
    if (ingame->buttons[8].isnt_click == NULL)
        return 84;
    ingame->buttons[8].is_click = create_sprite
        ("asset/ingame/load_save/load_green.png",
        &(sfVector2f){BTN_LOAD_POS_X, BTN_LOAD_POS_Y});
    if (ingame->buttons[8].is_click == NULL)
        return 84;
    ingame->buttons[8].on_click = on_click_load;
    ingame->buttons[8].data = ingame;
    if (ingame_set_sound_for_button(ingame, 8) == 84)
        return 84;
    return 0;
}
