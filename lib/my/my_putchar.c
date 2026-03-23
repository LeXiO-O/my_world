/*
** EPITECH PROJECT, 2026
** lib
** File description:
** Task01
*/

#include <unistd.h>
#include "../../include/my.h"

int my_putchar(char c)
{
    return write(1, &c, 1);
}
