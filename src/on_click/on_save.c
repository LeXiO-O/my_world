/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../include/myworld.h"

void on_click_save(game_state_t *state, void *data)
{
    scene_ingame_t *ingame = (scene_ingame_t *)data;

    if (manage_save(state, ingame) == 84)
        my_err_msg("save error!\n");
    return;
}
