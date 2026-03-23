/*
** EPITECH PROJECT, 2026
** close_window.c
** File description:
** close_window.c
*/

#include "../../include/csfml_ws.h"

void closewindow
(sfEvent event, sfRenderWindow *window)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}
