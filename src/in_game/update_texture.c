/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../include/myworld.h"

void update_texture(game_state_t *window, int x, int y)
{
    if (window->matrix_size[y][x] > 1) {
        window->state.texture = window->texture.dirt;
    }
}
