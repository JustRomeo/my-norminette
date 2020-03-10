/*
** Roméo's PROJECT, 2018
** lookingfor.c
** File description:
** HEADER
*/

#include "prototype.h"

int lookingfor_open(char **file, char *name)
{
    int nb_char = 0;
    int nb_error = 0;

    for (int i = 0; file[i]; i ++) {
        for (int c = 0; file[i][c]; c ++) {
            if (file[i][c] == ' ' && file[i][c + 1] == 'o' &&
                file[i][c + 2] == 'p' && file[i][c + 3] == 'e' &&
                file[i][c + 4] == 'n' && file[i][c + 5] == '(')
                nb_error ++;
            if (nb_error != 0 && file[i][c] == ' ' && file[i][c + 1] == 'c' &&
                file[i][c + 2] == 'l' && file[i][c + 3] == 'o' &&
                file[i][c + 4] == 's' && file[i][c + 5] == 'e')
                nb_error --;
        }
    }
    return (nb_error);
}

int lookingfor_free(char **file, char *name)
{
    int nb_char = 0;
    int nb_error = 0;

    for (int i = 0; file[i]; i ++) {
        for (int c = 0; file[i][c]; c ++) {
            if (file[i][c] == ' ' && file[i][c + 1] == 'm' &&
                file[i][c + 2] == 'a' && file[i][c + 3] == 'l' &&
                file[i][c + 4] == 'l' && file[i][c + 5] == 'o')
                nb_error ++;
            if (nb_error != 0 && file[i][c] == ' ' && file[i][c + 1] == 'f' &&
                file[i][c + 2] == 'r' && file[i][c + 3] == 'e' &&
                file[i][c + 4] == 'e')
                nb_error --;
        }
    }
    return (nb_error);
}
