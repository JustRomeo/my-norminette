/*
** Roméo's PROJECT, 2018
** NORMINETTE
** File description:
** error G
*/

#include "prototype.h"

static int G1error(char **file, char *name)
{
    int c = 0;
    int line = 1;
    int nb_char = 0;
    int nb_error = 0;

    if (file[0][0] != '/' || file[0][1] != '*' || file[0][2] != '\0') {
        nb_error ++;
        printf("\t--> G1: Line : %d\t%s\n", 1, name);
    } if (file[1][0] != '*' || file[1][1] != '*' || file[1][2] != ' ') {
        nb_error ++;
        printf("\t--> G1: Line : %d\t%s\n", 2, name);
    } if (file[2][0] != '*' || file[2][1] != '*' || file[2][2] != ' ') {
        nb_error ++;
        printf("\t--> G1: Line : %d\t%s\n", 3, name);
    } if (file[3][0] != '*' || file[3][1] != '*' || file[3][2] != ' ') {
        nb_error ++;
        printf("\t--> G1: Line : %d\t%s\n", 3, name);
    } if (file[4][0] != '*' || file[4][1] != '*' || file[4][2] != ' ') {
        nb_error ++;
        printf("\t--> G1: Line : %d\t%s\n", 3, name);
    } if (file[5][0] != '*' || file[5][1] != '/' || file[5][2] != '\0') {
        nb_error ++;
        printf("\t--> G1: Line : %d\t%s\n", 4, name);
    }
    return (nb_error);
}

static int G2error(char **file, char *name)
{
    int c = 0;
    int nb_char = 0;
    int nb_error = 0;

    return (nb_error);
}

static int G3error(char **file, char *name)
{
    int c = 0;
    int nb_char = 0;
    int nb_error = 0;

    return (nb_error);
}

static int G4error(char **file, char *name)
{
    int c = 0;
    int line = 1;
    int nb_char = 0;
    int nb_error = 0;

    for (int i = 0; file[i] != NULL; i ++) {
        if (my_str("static", file[i]) == 0 && file[i + 1][0] == '{');
        else if (my_str("static", file[i]) == 0 && my_str("static const", file[i]) != 0) {
            printf("\t--> G4: Line : %d\t%s\n", i + 1, name);
            nb_error ++;
        }
    }
    return (nb_error);
}

static int G5error(char **file, char *name)
{
    int c = 0;
    int nb_char = 0;
    int nb_error = 0;

    return (nb_error);
}

int G_error(char **file, norm_s *fault, f_norm *norm, char *name)
{
    //printf("\e[32m[FUNC]\t\e[0mG1 : File header\n");
    //norm->G1 += G1error(file, name);
    //printf("\e[31m[NONE]\t\e[0mG2 : Separation of functions\n");
    //printf("\e[31m[NONE]\t\e[0mG3 : Indentation of pre-processor directives\n");
    //printf("\e[32m[FUNC]\t\e[0mG4 : Globals Variables\n");
    norm->G4 += G4error(file, name);
    //printf("\e[31m[NONE]\t\e[0mG5 : Static\n");
    norm->G5 += G5error(file, name);
    fault->major += (norm->G1 + norm->G4 + norm->G5);
    return (0);
}
