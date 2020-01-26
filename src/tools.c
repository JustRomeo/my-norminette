/*
** EPITECH PROJECT, 2019
**  
** File description:
**  
*/

#include "prototype.h"

int cdisok(char *str)
{
    struct stat sb;

    if (stat(str, &sb) == -1)
        return (84);
    if (S_ISDIR(sb.st_mode) == 0)
        return (84);
    if ((sb.st_mode & S_IXUSR) == 0)
        return (84);
    return (0);
}

void name(char c, int *nb_error, struct dirent *print, int z)
{
    if (print->d_name[z] == c) {
        printf("\t%s\n", print->d_name);
        (*nb_error) ++;
    }
}

void notname(int *nb_error, struct dirent *print)
{
    char *str = strdup(my_revstr(print->d_name));

    if (my_str("c.", print->d_name) != 0 && my_str("h.", print->d_name) != 0 &&
        my_strcmp("Makefile", print->d_name) != 0 &&
        cdisok(print->d_name) != 0) {
        printf("\t%s\n", my_revstr(print->d_name));
        (*nb_error) ++;
    }
    if (str)
        free(str);
}

int output(char *str)
{
    char *out = strdup("[ERROR] ");

    if (str)
        out = strcat(out, str);
    out = strcat(out, " :/");
    printf("%s\n", out);
    if (str)
        free(str);
    if (out)
        free(out);
    return (84);
}
