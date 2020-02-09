/*
** EPITECH PROJECT, 2019
** My Sh
** File description:
** Tools 2
*/

#include "stddef.h"
#include <stdlib.h>
#include <string.h>

char *my_revstr(char *str);
static int without_tabspace(char *str)
{
    int i = 0;

    for (; str[i] == ' ' || str[i] == 9; i ++);
    return (i);
}

static int without_tabspacen(char *str)
{
    int i = 0;

    for (; str[i] == ' ' || str[i] == 9 || str[i] == '\n'; i ++);
    return (i);
}

static char *without_tabword(char *str)
{
    int i = 0;

    for (; str[i]; i ++)
        if (str[i] == 9)
            str[i] = ' ';
    str[i] = '\0';
    return (str);
}

char *beautifull_str(char *str)
{
    int i = 0;
    int w = 0;
    char *new_str = malloc(sizeof(char) * (strlen(str) + 1));

    if (str == NULL)
        return (NULL);
    i = without_tabspace(str);
    for (; str[i]; i ++, w ++)
        new_str[w] = str[i];
    new_str[w] = '\0';
    new_str = my_revstr(new_str);
    w = without_tabspacen(new_str);
    new_str = my_revstr(new_str);
    new_str[strlen(new_str) - w] = '\0';
    new_str = without_tabword(new_str);
    return (new_str);
}
