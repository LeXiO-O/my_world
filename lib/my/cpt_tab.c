/*
** EPITECH PROJECT, 2026
** my_getnbr
** File description:
** 5th task
*/

#include "../../include/my.h"

int cpt_tab(char **recup_tab)
{
    int count = 0;

    for (int i = 0; recup_tab[i] != NULL; i++)
        count++;
    return count;
}
