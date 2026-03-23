/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../include/myworld.h"

void on_click_load(game_state_t *state, void *data)
{
    scene_ingame_t *ingame = (scene_ingame_t *)data;

    if (manage_load(state, ingame) == 84)
        my_err_msg("load error!\n");
    return;
}
