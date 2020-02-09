/*
** EPITECH PROJECT, 2018
** NORMINETTE
** File description:
** error V
*/

#include "prototype.h"

static int V1error(char *file)
{
    int c = 0;
    int nb_char = 0;
    int nb_error = 0;

    return (nb_error);
}

static int V2error(char *file)
{
    int c = 0;
    int nb_char = 0;
    int nb_error = 0;

    return (nb_error);
}

static int V3error(char **file)
{
    int c = 0;
    int nb_char = 0;
    int nb_error = 0;

    for (int y = 0; file[y] != NULL; y ++) {
        if (my_str("char", beautifull_str(file[y])) == 0 &&
            my_str("char ", beautifull_str(file[y])) != 0 &&
            my_str("char_", beautifull_str(file[y])) != 0) {
            nb_error ++;
            printf("\t--> V3: Line : %d\n", y + 1);
        } if (my_str("int", beautifull_str(file[y])) == 0 &&
              my_str("int ", beautifull_str(file[y])) != 0 &&
              my_str("int_", beautifull_str(file[y])) != 0) {
            nb_error ++;
            printf("\t--> V3: Line : %d\n", y + 1);
        } if (my_str("void", beautifull_str(file[y])) == 0 &&
              my_str("void ", beautifull_str(file[y])) != 0 &&
              my_str("void_", beautifull_str(file[y])) != 0) {
            nb_error ++;
            printf("\t--> V3: Line : %d\n", y + 1);
        }
    }
    return (nb_error);
}

int V_error(char **file, norm_s *fault, f_norm *norm, char *name)
{
    norm->V3 += V3error(file);
    fault->minor += norm->V3;
    return (0);
}
