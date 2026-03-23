/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../include/myworld.h"

static sfVector2f project_iso_point(game_state_t *window,
    int grid_x, int grid_y, int height_z)
{
    float base_scale = window->scale * window->zoom;
    float tile_vertical_ratio = 0.5f - window->height * (PI / 180);
    float height_ratio = 1.0f - window->height * (PI / 180);
    float rad = window->rot * (PI / 180);
    float center_x = grid_x - (window->size_matrix_y - 1) / 2.0f;
    float center_y = grid_y - (window->size_matrix_x - 1) / 2.0f;
    float rotate_x = (cos(rad) * center_x) - (sin(rad) * center_y);
    float rotate_y = (sin(rad) * center_x) + (cos(rad) * center_y);
    sfVector2f screen_pos;

    window->grid_x = grid_x;
    window->grid_y = grid_y;
    screen_pos.x =
        (rotate_x - rotate_y) * base_scale + window->offset.x;
    screen_pos.y =
        (rotate_x + rotate_y) * base_scale * tile_vertical_ratio -
        ((height_z - 6) * base_scale * height_ratio) + window->offset.y;
    return screen_pos;
}

void update_2d_map(game_state_t *window)
{
    int z = 0;

    for (window->y = 0; window->y < window->size_matrix_x; window->y++) {
        for (window->x = 0; window->x < window->size_matrix_y; window->x++) {
            z = window->matrix_size[window->y][window->x];
            window->map2d[window->y][window->x] =
                project_iso_point(window, window->x, window->y, z);
        }
    }
}

static sfVector2f **create_2d_map(game_state_t *window)
{
    sfVector2f **map2d = malloc(sizeof(sfVector2f *) * window->size_matrix_x);
    int z = 0;

    if (!map2d)
        return NULL;
    for (int y = 0; y < window->size_matrix_x; y++) {
        map2d[y] = malloc(sizeof(sfVector2f) * window->size_matrix_y);
        if (!map2d[y])
            return NULL;
        for (int x = 0; x < window->size_matrix_y; x++) {
            z = window->matrix_size[y][x];
            map2d[y][x] = project_iso_point(window, x, y, z);
        }
    }
    return map2d;
}

static unsigned int param_to_display_matrix
(game_state_t *window)
{
    float dimension_max;

    if (!window || !window->matrix || !window->matrix[0] || !window->matrix[1])
        return 84;
    window->size_matrix_x = my_getnbr(window->matrix[0]);
    window->size_matrix_y = my_getnbr(window->matrix[1]);
    if (window->size_matrix_x <= 0 || window->size_matrix_y <= 0 ||
        window->size_matrix_x > 350 || window->size_matrix_y > 350)
        return 84;
    if (window->size_matrix_x > window->size_matrix_y)
        dimension_max = window->size_matrix_x;
    else
        dimension_max = window->size_matrix_y;
    window->scale = SCALE / dimension_max;
    return 0;
}

unsigned int create_matrix
(game_state_t *window)
{
    window->matrix_size = malloc(sizeof(int *) * window->size_matrix_x);
    if (!window->matrix_size)
        return 84;
    for (int y = 0; y < window->size_matrix_x; y++) {
        window->matrix_size[y] = malloc(sizeof(int) * window->size_matrix_y);
        if (!window->matrix_size[y])
            return 84;
    }
    apply_perlin_to_matrix(window, 0.15f, 12.0f);
    window->map2d = create_2d_map(window);
    if (!window->map2d)
        return 84;
    return 0;
}

unsigned int create_and_show_matrix(game_state_t *window)
{
    if (param_to_display_matrix(window) == 84)
        return 84;
    return 0;
}
