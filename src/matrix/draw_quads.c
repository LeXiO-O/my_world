/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../include/myworld.h"

static sfTexture *get_texture_for_height(game_state_t *window, int height)
{
    if (window->is_six_seven == false) {
        if (height <= 0)
            return window->texture.water;
        if (height <= 3)
            return window->texture.stone;
        if (height <= 6)
            return window->texture.dirt;
        if (height >= 6)
            return window->texture.grass;
    } else {
        if (height <= 0)
            return window->texture.lava;
        if (height <= 3)
            return window->texture.stone;
        if (height > 3)
            return window->texture.obsidian;
    }
    return NULL;
}

static int max_int(int a, int b)
{
    return a > b ? a : b;
}

static int get_highest_quads
(int highest_quads, game_state_t *window, int x, int y)
{
    window->x = x;
    window->y = y;
    highest_quads = max_int(max_int(
            window->matrix_size[y][x], window->matrix_size[y][x + 1]),
        max_int(
            window->matrix_size[y + 1][x],
            window->matrix_size[y + 1][x + 1]));
    return highest_quads;
}

static int fill_quads(game_state_t *window, int x, int y, sfVertexArray *array)
{
    int highest_quads = 0;

    if (x + 1 < window->size_matrix_y && y + 1 < window->size_matrix_x) {
        highest_quads = get_highest_quads(highest_quads, window, x, y);
        window->state.texture = get_texture_for_height(window, highest_quads);
        array = create_line(
            &window->map2d[y][x], &window->map2d[y][x + 1],
            &window->map2d[y + 1][x], &window->map2d[y + 1][x + 1]);
        array = if_mouse_on(array, window);
        sfRenderWindow_drawVertexArray(window->window, array, &window->state);
        sfVertexArray_destroy(array);
        array = create_line(
            &window->map2d[y][x], &window->map2d[y + 1][x],
            &window->map2d[y][x + 1], &window->map2d[y + 1][x + 1]);
        array = if_mouse_on(array, window);
        sfRenderWindow_drawVertexArray(window->window, array, &window->state);
        sfVertexArray_destroy(array);
    }
    return 0;
}

static int compare_quads(const void *a, const void *b)
{
    quad_sort_t *vertex_1 = (quad_sort_t *)a;
    quad_sort_t *vertex_2 = (quad_sort_t *)b;

    return (vertex_1->z > vertex_2->z) -
        (vertex_1->z < vertex_2->z);
}

static void manage_sort(game_state_t *window, quad_sort_t *quads, int total)
{
    for (int i = 0; i < total; i++) {
        quads[i].z = 0;
        if (quads[i].x + 1 < window->size_matrix_y &&
            quads[i].y + 1 < window->size_matrix_x) {
            quads[i].z = get_highest_quads
                (quads[i].z, window, quads[i].x, quads[i].y);
        }
    }
    qsort(quads, total, sizeof(quad_sort_t), compare_quads);
    for (int i = 0; i < total; i++)
        fill_quads(window, quads[i].x, quads[i].y, NULL);
}

unsigned int draw_2d_map(game_state_t *window)
{
    int total = window->size_matrix_x * window->size_matrix_y;
    quad_sort_t *quads = malloc(sizeof(quad_sort_t) * total);
    int index = 0;

    if (quads == NULL)
        return 84;
    for (int y = 0; y < window->size_matrix_x; y++) {
        for (int x = 0; x < window->size_matrix_y; x++) {
            quads[index].x = x;
            quads[index].y = y;
            quads[index].screen_y = window->map2d[y][x].y;
            index++;
        }
    }
    manage_sort(window, quads, total);
    free(quads);
    return 0;
}
