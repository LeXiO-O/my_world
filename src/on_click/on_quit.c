/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../include/myworld.h"

void on_click_quit(game_state_t *state, __attribute__((unused)) void *data)
{
    state->is_running = false;
}
