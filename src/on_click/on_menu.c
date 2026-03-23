/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../include/myworld.h"

void on_click_menu
(game_state_t *state, void __attribute__((unused)) *data)
{
    state->scene = SCENE_MENU;
    return;
}
