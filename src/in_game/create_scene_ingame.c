/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../include/myworld.h"

unsigned int create_sprite_ingame
(scene_ingame_t *ingame)
{
    ingame->tool_bar = create_sprite
        ("asset/ingame/tool_bar.png", &(sfVector2f){0, 0});
    if (ingame->tool_bar == NULL)
        return 84;
    return 0;
}
