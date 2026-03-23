/*
** EPITECH PROJECT, 2026
** realloc
** File description:
** realloc
*/

#include "../../include/my.h"

int my_memcmp(void *dest, const void *src, size_t size)
{
    const unsigned char *curdest = dest;
    const unsigned char *cursrc = src;

    for (size_t i = 0; i < size; i++) {
        if (curdest[i] != cursrc[i])
            return curdest[i] - cursrc[i];
    }
    return 0;
}
