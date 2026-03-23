/*
** EPITECH PROJECT, 2026
** my_world
** File description:
** my_world
*/

#include "../../include/myworld.h"

static void handle_hor_rotation(game_state_t *window, sfEvent *event)
{
    if (event->key.code == sfKeyLeft)
        window->rot += 3.0f;
    if (event->key.code == sfKeyRight)
        window->rot -= 3.0f;
}

static void handle_zoom(game_state_t *window, sfEvent *event)
{
    if (event->key.code == sfKeyZ)
        window->zoom += 0.05f;
    if (event->key.code == sfKeyS)
        window->zoom -= 0.05f;
    if (window->zoom < 0.1f)
        window->zoom = 0.1f;
    if (window->zoom > 5.0f)
        window->zoom = 5.0f;
}

static void handle_ver_rotation(game_state_t *window, sfEvent *event)
{
    if (event->key.code == sfKeyUp)
        window->height += 3.0f;
    if (event->key.code == sfKeyDown)
        window->height -= 3.0f;
    if (window->height < -15.0f)
        window->height = -15.0f;
    if (window->height > 15.0f)
        window->height = 15.0f;
}

void handle_keyboard(game_state_t *window, sfEvent *event)
{
    if (event->type == sfEvtKeyPressed && event->key.control) {
        handle_hor_rotation(window, event);
        handle_ver_rotation(window, event);
        handle_zoom(window, event);
        window->refresh = true;
    }
}
