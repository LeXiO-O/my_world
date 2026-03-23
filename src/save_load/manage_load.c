/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../include/myworld.h"

static char *cat_path(scene_ingame_t *ingame)
{
    int line_len = my_strlen(ingame->text_box[0].std_user);
    char *head = malloc(sizeof(char) * (PATH_LEN + line_len + 1));

    if (!head)
        return NULL;
    head[0] = '\0';
    head = my_strcat(head, PATH);
    head = my_strcat(head, ingame->text_box[0].std_user);
    return head;
}

static void fread_matrix(game_state_t *state, FILE *fd)
{
    for (int y = 0; y < state->size_matrix_x; y++)
        fread(state->matrix_size[y], sizeof(int), state->size_matrix_y, fd);
    fclose(fd);
    update_2d_map(state);
    state->refresh = true;
}

unsigned int manage_load(game_state_t *state, scene_ingame_t *ingame)
{
    char *path = cat_path(ingame);
    FILE *fd = fopen(path, "rb");
    char buff[MAGIC_LEN];

    free(path);
    if (!fd)
        return 84;
    fread(buff, 1, MAGIC_LEN, fd);
    if (my_memcmp(buff, MAGIC, MAGIC_LEN) != 0) {
        fclose(fd);
        return 84;
    }
    fread(&state->size_matrix_x, sizeof(int), 1, fd);
    fread(&state->size_matrix_y, sizeof(int), 1, fd);
    if (create_matrix(state) == 84) {
        fclose(fd);
        return 84;
    }
    fread_matrix(state, fd);
    return 0;
}
