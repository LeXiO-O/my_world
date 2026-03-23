/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../include/myworld.h"

void on_click_six_seven(game_state_t *state, __attribute__((unused)) void *data)
{
    if (state->is_six_seven == true) {
        state->is_six_seven = false;
    } else {
        state->is_six_seven = true;
    }
    state->refresh = true;
}
