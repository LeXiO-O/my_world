/*
** EPITECH PROJECT, 2026
** my.h
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H

    #include <stdio.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <SFML/Graphics/Export.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/Graphics/PrimitiveType.h>
    #include <SFML/Graphics/RenderStates.h>
    #include <SFML/Graphics/Vertex.h>
    #include <SFML/Window/Event.h>
    #include <SFML/Window/VideoMode.h>
    #include <SFML/Window/WindowHandle.h>
    #include <SFML/Window/Window.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Graphics.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Types.h>
    #include <stdbool.h>
    #include <math.h>
    #include <time.h>

int my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
char **my_str_to_word_array(const char *str, const char *str_separateur);
int my_str_isnum(char const *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strdup(char const *src);
char *my_strndup(char const *src, int len);
int mini_printf(const char *format, ...);
void free_array(char **map);
void *my_memcpy(void *dest, const void *src, size_t size);
void my_err_msg(const char *msg);
int my_memcmp(void *dest, const void *src, size_t size);

#endif /* MY_H */
