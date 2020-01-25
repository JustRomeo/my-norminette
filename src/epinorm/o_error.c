/*
** EPITECH PROJECT, 2018
** NORMINETTE
** File description:
** error O
*/

#include "prototype.h"

static int O1error(void)
{
    int c = 0;
    int nb_char = 0;
    int nb_error = 0;
    DIR *fd = opendir("./");
    struct dirent *print;

    print = readdir(fd);
    while (print != NULL) {
        name('~', &nb_error, print, 0);
        name('#', &nb_error, print, 0);
        name('~', &nb_error, print, my_strlen(print->d_name) - 1);
        name('o', &nb_error, print, my_strlen(print->d_name) - 1);
        print = readdir(fd);
    }
    return (nb_error);
}

static int O2error(void)
{
    int c = 0;
    int nb_char = 0;
    int nb_error = 0;
    DIR *fd = opendir("./");
    struct dirent *print;

    print = readdir(fd);
    while (print != NULL) {
        notname(&nb_error, print);
        print = readdir(fd);
    }
    return (nb_error);
}

static int O3error(char **file, char *name)
{
    int nb_brackets = 0;
    int nb_error = 0;
    int nb_func = 0;
    int i = 0;
    int status = 0;

    for (i = 4; file[i] != NULL; i ++) {
        for (int c = 0; file[i][c]; c ++) {
            if (file[i][c] == '{') {
                nb_brackets ++;
                status = 1;
            } if (file[i][c] == '}')
                  nb_brackets --;
        } if (nb_brackets == 0 && status == 0) {
            nb_func ++;
            status ++;
        }
    } if (nb_func > MAX_FUNCTNS + 1) {
        printf("\t--> O3: Line : %d (%d)\t%s\n", i, nb_func, name);
        nb_error ++;
    }
    return (nb_error);
}

static int O4error(char *file, char *name)
{
    int c = 0;
    int nb_char = 0;
    int nb_error = 0;

    return (nb_error);
}

int O_error(char **file, norm_s *fault, f_norm *norm, char *name)
{
    norm->O1 += O1error();
    norm->O2 += O2error();
    norm->O3 += O3error(file, name);
    fault->major += (norm->O1 + norm->O2 + norm->O3);
    return (0);
}
