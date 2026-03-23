/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../include/myworld.h"

unsigned int ingame_set_sound_for_button(scene_ingame_t *ingame, int i)
{
    ingame->buttons[i].sound_buffer =
        sfSoundBuffer_createFromFile("asset/click.wav");
    ingame->buttons[i].sound = sfSound_create();
    if (ingame->buttons[i].sound_buffer == NULL ||
        ingame->buttons[i].sound == NULL)
        return 84;
    sfSound_setBuffer
    (ingame->buttons[i].sound, ingame->buttons[i].sound_buffer);
    return 0;
}

unsigned int end_fonc(scene_ingame_t *ingame)
{
    if (quit_button(ingame) == 84)
        return 84;
    if (home_button(ingame) == 84)
        return 84;
    return 0;
}

unsigned int create_buttons_ingame(scene_ingame_t *ingame)
{
    if (end_fonc(ingame) == 84)
        return 84;
    if (up_button(ingame) == 84)
        return 84;
    if (down_button(ingame) == 84)
        return 84;
    if (six_seven_button(ingame) == 84)
        return 84;
    if (reroll_button(ingame) == 84)
        return 84;
    if (clear_button(ingame) == 84)
        return 84;
    if (help_button(ingame) == 84)
        return 84;
    if (load_button(ingame) == 84)
        return 84;
    if (save_button(ingame) == 84)
        return 84;
    return 0;
}
