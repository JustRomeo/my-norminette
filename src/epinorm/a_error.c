/*
** EPITECH PROJECT, 2018
** acfg_error.c
** File description:
** error A
*/

#include "prototype.h"

static int A1error(char **file, char *name)
{
    int c = 0;
    int nb_error = 0;

    return (nb_error);
}

static int A2error(char **file, char *name)
{
    int c = 0;
    int nb_char = 0;
    int nb_error = 0;

    return (nb_error);
}

int A_error(char **file, norm_s *fault, f_norm *norm, char *name)
{
    if (!name|| !file || !file[0])
        return (0);
    norm->A1 += A1error(file, name);
    norm->A2 += A2error(file, name);
    return (0);
}
