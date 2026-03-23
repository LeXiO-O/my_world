/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../include/myworld.h"

void on_click_clear
(game_state_t *state, __attribute__((unused)) void *data)
{
    if (state->matrix_size == NULL)
        return;
    for (int i = 0; i < state->size_matrix_x; i++) {
        for (int j = 0; j < state->size_matrix_y; j++)
            state->matrix_size[i][j] = 0;
    }
    state->refresh = true;
    return;
}
