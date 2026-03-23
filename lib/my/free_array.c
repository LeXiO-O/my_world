/*
** EPITECH PROJECT, 2026
** setting_up
** File description:
** setting_up
*/

#include "../../include/my.h"
#include <stddef.h>

void free_array(char **map)
{
    if (map == NULL) {
        return;
    }
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
}
