/*
** EPITECH PROJECT, 2026
** cat
** File description:
** t1
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../../include/my.h"

int cat_in_fonction(const char *myfile)
{
    int cond;
    char buffer[30 * 1024] = {0};

    if (myfile == NULL){
    }
    cond = open(myfile, O_RDONLY);
    if (cond == - 1){
        write(2, "error, file not found\n", 22);
        return (84);
    }
    read(cond, buffer, 30 * 1024 - 1);
    my_putstr(buffer);
    close(cond);
    return (0);
}
