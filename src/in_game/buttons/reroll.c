/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../../include/myworld.h"

unsigned int reroll_button(scene_ingame_t *ingame)
{
    ingame->buttons[3].isnt_click = create_sprite
        ("asset/ingame/reroll_1.png",
        &(sfVector2f){BTN_REROLL_POS_X, BTN_REROLL_POS_Y});
    if (ingame->buttons[3].isnt_click == NULL)
        return 84;
    ingame->buttons[3].is_click = create_sprite
        ("asset/ingame/reroll_2.png",
        &(sfVector2f){BTN_REROLL_POS_X, BTN_REROLL_POS_Y});
    if (ingame->buttons[3].is_click == NULL)
        return 84;
    ingame->buttons[3].on_click = on_click_reroll;
    ingame->buttons[3].data = ingame;
    if (ingame_set_sound_for_button(ingame, 3) == 84)
        return 84;
    return 0;
}
