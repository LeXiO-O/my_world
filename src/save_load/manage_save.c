/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../include/myworld.h"

static char *cat_path(scene_ingame_t *ingame)
{
    int line_len = my_strlen(ingame->text_box[1].std_user);
    char *head = malloc(sizeof(char) * (PATH_LEN + line_len + 1));

    if (!head)
        return NULL;
    head[0] = '\0';
    head = my_strcat(head, PATH);
    head = my_strcat(head, ingame->text_box[1].std_user);
    return head;
}

unsigned int manage_save(game_state_t *state, scene_ingame_t *ingame)
{
    char *path = cat_path(ingame);
    FILE *fd = fopen(path, "wb");

    free(path);
    if (!fd)
        return 84;
    fwrite(MAGIC, 1, MAGIC_LEN, fd);
    fwrite(&state->size_matrix_x, sizeof(int), 1, fd);
    fwrite(&state->size_matrix_y, sizeof(int), 1, fd);
    for (int y = 0; y < state->size_matrix_x; y++) {
        fwrite(state->matrix_size[y], sizeof(int), state->size_matrix_y, fd);
    }
    fclose(fd);
    return 0;
}
