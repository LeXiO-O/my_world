/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../include/myworld.h"

unsigned int parsing_std_user(game_state_t *state, scene_menu_t *menu)
{
    state->matrix = my_str_to_word_array(menu->std_user, "X");
    if (state->matrix == NULL)
        return 84;
    if (state->matrix[0] != NULL &&
        state->matrix[1] != NULL &&
        state->matrix[2] == NULL) {
        if (my_str_isnum(state->matrix[0]) == 0 &&
            my_str_isnum(state->matrix[1]) == 0 &&
            state->matrix[0][0] != '0' &&
            state->matrix[1][0] != '0')
            return 1;
    }
    return 0;
}
