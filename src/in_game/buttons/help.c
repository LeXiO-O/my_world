/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../../include/myworld.h"

unsigned int help_button(scene_ingame_t *ingame)
{
    ingame->buttons[6].isnt_click = create_sprite
        ("asset/ingame/ask.png",
        &(sfVector2f){BTN_HELP_POS_X, BTN_HELP_POS_Y});
    if (ingame->buttons[6].isnt_click == NULL)
        return 84;
    ingame->buttons[6].is_click = create_sprite
        ("asset/ingame/ask.png",
        &(sfVector2f){BTN_HELP_POS_X, BTN_HELP_POS_Y});
    if (ingame->buttons[6].is_click == NULL)
        return 84;
    ingame->buttons[6].on_click = on_click_help;
    ingame->buttons[6].data = ingame;
    if (ingame_set_sound_for_button(ingame, 6) == 84)
        return 84;
    if (helper_text(ingame) == 84)
        return 84;
    return 0;
}
