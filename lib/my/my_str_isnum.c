/*
** EPITECH PROJECT, 2026
** lib
** File description:
** Task01
*/

#include "../../include/my.h"

int my_str_isnum(char const *str)
{
    int i = 0;
    int cpt = 0;
    int cpt_num = 0;

    if (!str || str[0] == '\0')
        return 84;
    for (; str[i] != '\0'; i++) {
        cpt++;
        if (str[i] >= '0' || str[i] <= '9')
            cpt_num++;
    }
    if (cpt == cpt_num)
        return 0;
    return 84;
}
