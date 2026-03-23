/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../include/myworld.h"

static float fade(float t)
{
    return t * t * t * (t * (t * 6 - 15) + 10);
}

static float rand_val(int x, int y)
{
    int perlin_seed = rand();
    int n = x + y * 57 + perlin_seed;

    srand(time(NULL));
    n = (n << 13) ^ n;
    return (1.0f - ((n * (n * n * 15731 + 789221) + 1376312589)
            & 0x7fffffff) / 1073741824.0f) * 0.5f + 0.5f;
}

static float smooth_noise(float x, float y)
{
    int ix = (int)x;
    int iy = (int)y;
    float fx = x - ix;
    float fy = y - iy;
    float u = fade(fx);
    float v = fade(fy);
    float tl = rand_val(ix, iy);
    float tr = rand_val(ix + 1, iy);
    float bl = rand_val(ix, iy + 1);
    float br = rand_val(ix + 1, iy + 1);
    float top = tl + u * (tr - tl);
    float bot = bl + u * (br - bl);

    return top + v * (bot - top);
}

void apply_perlin_to_matrix(game_state_t *window, float scale, float amplitude)
{
    float value = 0.0f;

    for (int y = 0; y < window->size_matrix_x; y++) {
        for (int x = 0; x < window->size_matrix_y; x++) {
            value = smooth_noise(x * scale, y * scale);
            window->matrix_size[y][x] = (int)(value * amplitude);
        }
    }
}
