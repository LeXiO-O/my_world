/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../../include/myworld.h"

unsigned int quit_button(scene_ingame_t *ingame)
{
    ingame->buttons[7].isnt_click = create_sprite
        ("asset/menu/quit_button1.png",
        &(sfVector2f){BTN_QUIT2_POS_X, BTN_QUIT2_POS_Y});
    if (ingame->buttons[7].isnt_click == NULL)
        return 84;
    ingame->buttons[7].is_click = create_sprite
        ("asset/menu/quit_button2.png",
        &(sfVector2f){BTN_QUIT2_POS_X, BTN_QUIT2_POS_Y});
    if (ingame->buttons[7].is_click == NULL)
        return 84;
    ingame->buttons[7].on_click = on_click_quit;
    ingame->buttons[7].data = ingame;
    if (ingame_set_sound_for_button(ingame, 7) == 84)
        return 84;
    return 0;
}
