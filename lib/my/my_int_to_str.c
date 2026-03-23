/*
** EPITECH PROJECT, 2026
** my_put_nbr.c
** File description:
** displays the number given as a parameter
*/
#include <stdlib.h>
#include <unistd.h>
#include "../../include/my.h"



static int do_nbrlen(int nb)
{
    int len = 0;

    if (nb <= 0)
        len += 1;
    while (nb != 0){
        nb /= 10;
        len++;
    }
    return (len);
}

static void choose_digit(char *intstr, int temp, int pos)
{
    while (temp > 0){
        intstr[pos] = (temp % 10) + '0';
        temp /= 10;
        pos--;
    }
}

char *my_int_to_str(int nb)
{
    int len = do_nbrlen(nb);
    int temp = nb;
    char *intstr = malloc(len + 1);

    if (!intstr)
        return NULL;
    intstr[len] = '\0';
    if (nb == 0){
        intstr[0] = '0';
        return intstr;
    }
    if (nb < 0){
        intstr[0] = '-';
        temp = -temp;
    }
    choose_digit(intstr, temp, len - 1);
    return (intstr);
}
