/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../include/myworld.h"

void on_click_reroll
(game_state_t *state, void __attribute__((unused)) *data)
{
    create_matrix(state);
    state->refresh = true;
}
