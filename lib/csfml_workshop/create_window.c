/*
** EPITECH PROJECT, 2026
** create_window.c
** File description:
** create_window.c
*/

#include "../../include/csfml_ws.h"

sfRenderWindow *create_window
(const char *name_of_the_mainloop, const unsigned int *size_of_window)
{
    const char *title = name_of_the_mainloop;
    const sfContextSettings *settings = NULL;
    sfVideoMode mode =
    {size_of_window[0], size_of_window[1], size_of_window[2]};
    sfRenderWindow *window =
        sfRenderWindow_create(mode, title, sfResize | sfClose, settings);

    return window;
}
