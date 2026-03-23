/*
** EPITECH PROJECT, 2026
** my_err_msg
** File description:
** write an err
*/

#include <unistd.h>
#include "../../include/my.h"

void my_err_msg(const char *msg)
{
    unsigned int msg_len = my_strlen(msg);

    write(2, msg, msg_len);
}
