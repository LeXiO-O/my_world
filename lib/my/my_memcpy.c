/*
** EPITECH PROJECT, 2026
** realloc
** File description:
** realloc
*/

#include "../../include/my.h"

void *my_memcpy(void *dest, const void *src, size_t size)
{
    const char *copy_src = src;
    char *copy_dest = dest;

    for (unsigned int count = 0; count <= size; count++) {
        copy_dest[count] = copy_src[count];
    }
    return (dest);
}
