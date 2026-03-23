/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../../include/myworld.h"

unsigned int home_button(scene_ingame_t *ingame)
{
    ingame->buttons[5].isnt_click = create_sprite
        ("asset/ingame/home_1.png",
        &(sfVector2f){BTN_HOME_POS_X, BTN_HOME_POS_Y});
    if (ingame->buttons[5].isnt_click == NULL)
        return 84;
    ingame->buttons[5].is_click = create_sprite
        ("asset/ingame/home_2.png",
        &(sfVector2f){BTN_HOME_POS_X, BTN_HOME_POS_Y});
    if (ingame->buttons[5].is_click == NULL)
        return 84;
    ingame->buttons[5].on_click = on_click_menu;
    ingame->buttons[5].data = ingame;
    if (ingame_set_sound_for_button(ingame, 5) == 84)
        return 84;
    return 0;
}
