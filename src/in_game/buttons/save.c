/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../../include/myworld.h"

unsigned int save_button(scene_ingame_t *ingame)
{
    ingame->buttons[9].isnt_click = create_sprite
        ("asset/ingame/load_save/save_red.png",
        &(sfVector2f){BTN_SAVE_POS_X, BTN_SAVE_POS_Y});
    if (ingame->buttons[9].isnt_click == NULL)
        return 84;
    ingame->buttons[9].is_click = create_sprite
        ("asset/ingame/load_save/save_green.png",
        &(sfVector2f){BTN_SAVE_POS_X, BTN_SAVE_POS_Y});
    if (ingame->buttons[9].is_click == NULL)
        return 84;
    ingame->buttons[9].on_click = on_click_save;
    ingame->buttons[9].data = ingame;
    if (ingame_set_sound_for_button(ingame, 9) == 84)
        return 84;
    return 0;
}
