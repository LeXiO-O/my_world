/*
** EPITECH PROJECT, 2026
** my_rev_str.c
** File description:
** t3
*/

#include "../../include/my.h"

char *my_strndup(char const *src, int len)
{
    int newstrlen = 0;
    int oldstrlen = len;
    char *newstr = malloc(sizeof(char) * (oldstrlen + 1));

    newstr[len] = '\0';
    while (newstrlen < oldstrlen) {
        newstr[newstrlen] = src[newstrlen];
        newstrlen++;
    }
    return (newstr);
}
