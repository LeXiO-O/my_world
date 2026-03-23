/*
** EPITECH PROJECT, 2026
** my_strcat
** File description:
** Task02
*/

#include <stdio.h>

static int mystrcatlen(char const *str)
{
    int e = 0;

    while (*str != '\0'){
        str = str + 1;
        e = e + 1;
    }
    return (e);
}

char *my_strcat(char *dest, char const *src)
{
    int i = mystrcatlen(dest);
    int j = 0;

    while (src[j] != '\0'){
        dest[i] = src[j];
        j = j + 1;
        i = i + 1;
    }
    dest[i] = '\0';
    return (dest);
}
