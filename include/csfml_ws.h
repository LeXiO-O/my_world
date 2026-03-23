/*
** EPITECH PROJECT, 2026
** csfml.h
** File description:
** csfml.h
*/

#ifndef CSFML_WS_H
    #define CSFML_WS_H

    #include "my.h"

void closewindow(sfEvent event, sfRenderWindow *window);
sfRenderWindow *create_window
(const char *name_of_the_mainloop, const unsigned int *size_of_window);
sfTexture *missing_texture(sfSprite *sprite);
char *helper_text_button(void);
char *helper_text_key(void);

#endif /* CSFML_WS */
