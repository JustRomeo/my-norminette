/*
** EPITECH PROJECT, 2019
** My_lf_Char
** File description:
** lib
*/

#include "../../include/prototype.h"
#include "../../include/my.h"
#include <sys/sysmacros.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int my_lf_char(char *str, char c)
{
    int z = 0;

    if (str == NULL)
        return (-1);
    while (str[z] != c && str[z] != '\0')
        z ++;
    return (z);
}
