/*
** EPITECH PROJECT, 2026
** my_str_to_word_array.c
** File description:
** displays the number given as a parameter
*/


#include "../../include/my.h"

static int count_word(int e, char const *str, const char *sep)
{
    int is_cur_true = 0;
    int is_prev_true = 0;

    if (e == 0)
        return (0);
    for (int z = 0; sep[z]; z++) {
        if (str[e] == sep[z])
            is_cur_true = 1;
    }
    for (int a = 0; sep[a]; a++) {
        if (str[e - 1] == sep[a])
            is_prev_true = 1;
    }
    if (is_cur_true && !is_prev_true)
        return (1);
    return (0);
}

static int nosep(char const *str, const char *sep, int i, int l)
{
    int notsep = 0;

    if (str[l] == sep[i]){
        notsep = 1;
        return notsep;
    }
    return notsep;
}

static void dup_cont(int count, char const *str, const char *sep, char **ctain)
{
    int notsep = 0;
    int word_tag = 0;

    for (int l = 0; str[l]; l++) {
        notsep = 0;
        for (int i = 0; sep[i]; i++)
            notsep += nosep(str, sep, i, l);
        if (!notsep)
            count++;
        if (count_word(l, str, sep) == 1) {
            word_tag++;
            ctain[word_tag - 1] = my_strndup(str + (l - count), count);
            count = 0;
        }
    }
    if (count > 0) {
        word_tag++;
        ctain[word_tag - 1] = my_strndup(
            str + (my_strlen(str) - count), count);
    }
}

int part1_to_array
(char const *str, const char *sep)
{
    int is_last_sep = 0;
    int nbr_wrd = 0;

    for (int e = 0; str[e]; e++) {
        nbr_wrd += count_word(e, str, sep);
    }
    for (int i = 0; sep[i] != '\0'; i++)
        if (str[my_strlen(str) - 1] == sep[i])
            is_last_sep = 1;
    if (!is_last_sep)
        nbr_wrd++;
    return nbr_wrd;
}

char **my_str_to_word_array(char const *str, const char *sep)
{
    int nbr_wrd = 0;
    int count = 0;
    int is_last_sep = 0;
    char **container = NULL;

    if (str == NULL || sep == NULL ||
        my_strlen(str) == 0 || my_strlen(sep) == 0) {
        return NULL;
    }
    nbr_wrd = part1_to_array(str, sep);
    container = malloc(sizeof(char*) * (nbr_wrd + 1));
    if (container == NULL)
        return NULL;
    container[nbr_wrd] = NULL;
    dup_cont(count, str, sep, container);
    return (container);
}
