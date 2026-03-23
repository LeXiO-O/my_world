/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../include/myworld.h"

sfVertexArray *create_line
(sfVector2f *point1, sfVector2f *point2,
    sfVector2f *point3, sfVector2f *point4)
{
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = *point1, .color = sfWhite};
    sfVertex vertex2 = {.position = *point2, .color = sfWhite};
    sfVertex vertex3 = {.position = *point3, .color = sfWhite};
    sfVertex vertex4 = {.position = *point4, .color = sfWhite};

    vertex1.texCoords = (sfVector2f){0, 0};
    vertex2.texCoords = (sfVector2f){64, 0};
    vertex3.texCoords = (sfVector2f){64, 64};
    vertex4.texCoords = (sfVector2f){0, 64};
    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_append(vertex_array, vertex3);
    sfVertexArray_append(vertex_array, vertex4);
    sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
    return (vertex_array);
}

static void distance_between_two_points_and_set_color
(game_state_t *window, int vertex_index,
    sfVertexArray *vertex_array, sfVector2f *mouse_world_position)
{
    int offset_x[] = {0, 1, 1, 0};
    int offset_y[] = {0, 0, 1, 1};

    window->current_vertex =
        sfVertexArray_getVertex(vertex_array, vertex_index);
    window->diff_mouse_vertex_x =
        mouse_world_position->x - window->current_vertex->position.x;
    window->diff_mouse_vertex_y =
        mouse_world_position->y - window->current_vertex->position.y;
    window->distance_squared =
        (window->diff_mouse_vertex_x * window->diff_mouse_vertex_x) +
        (window->diff_mouse_vertex_y * window->diff_mouse_vertex_y);
    if (window->distance_squared <= RADIUS_ZONE * RADIUS_ZONE) {
        window->current_vertex->color = (sfColor){255, 0, 0, 255};
        if (window->is_mouse_pressed == true) {
            window->selected_x = window->x + offset_x[vertex_index];
            window->selected_y = window->y + offset_y[vertex_index];
        }
    }
}

sfVertexArray *if_mouse_on(sfVertexArray *vertex_array,
    game_state_t *window)
{
    sfVector2i mouse_pixel_position =
        sfMouse_getPositionRenderWindow(window->window);
    sfVector2f mouse_world_position =
        sfRenderWindow_mapPixelToCoords(window->window,
        mouse_pixel_position, NULL);

    for (int vertex_index = 0; vertex_index < 4; vertex_index++) {
        distance_between_two_points_and_set_color
        (window, vertex_index, vertex_array, &mouse_world_position);
    }
    return vertex_array;
}
