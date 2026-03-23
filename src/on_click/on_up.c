/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../include/myworld.h"

void on_click_up(game_state_t *state, __attribute__((unused)) void *data)
{
    if (state->selected_y >= 0 && state->selected_y < state->size_matrix_x &&
        state->selected_x >= 0 && state->selected_x < state->size_matrix_y) {
        state->matrix_size[state->selected_y][state->selected_x] += 1;
        state->refresh = true;
    }
}
