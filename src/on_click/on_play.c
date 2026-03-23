/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../include/myworld.h"


void on_click_play(game_state_t *state, void *data)
{
    scene_menu_t *menu = (scene_menu_t *)data;

    if (parsing_std_user(state, menu) != 1)
        return;
    if (create_and_show_matrix(state) != 0)
        return;
    state->scene = SCENE_INGAME;
    create_matrix(state);
    state->refresh = true;
}
