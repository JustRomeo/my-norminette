/*
** EPITECH PROJECT, 2018
** NORMINETTE
** File description:
** error L
*/

#include "prototype.h"

static int L1error(char **file, char *name)
{
    int line = 1;
    int nb_char = 0;
    int nb_error = 0;

    for (int y = 0; file[y] != NULL; y ++)
        if (my_str("for", beautifull_str(file[y])) != 0)
            for (int c = 0; file[y][c]; c ++)
                if (file[y][c] == ';' && file[y][c + 1] != '\0')
                    if (file[y][c + 1] != '\'' && file[y][c - 1] != '\'') {
                        nb_error ++;
                        printf("\t--> L1: Line : %d\t%s\n", y + 1, name);
                    }
    return (nb_error);
}

static int L2error(char **file, char *name)
{
    int c = 0;
    int nb_space = 0;
    int nb_error = 0;
    int line = 1;

    for (int y = 0; file[y] != NULL; y ++) {
        for (int c = 0; file[y][c] == ' '; c ++)
            nb_space ++;
        if ((nb_space % 4) != 0) {
            nb_error ++;
            printf("\t--> L2: Line : %d\t%s\n", y + 1, name);
        }
        nb_space = 0;
        for (int c = 0; file[y][c]; c ++) {
            if (file[y][c] == 9) {
                nb_error ++;
                printf("\t--> L2: Line : %d\t%s\n", y + 1, name);
            }
        }
    }
    return (nb_error);
}

static int L3error(char **file, char *name)
{
    int c = 0;
    int line = 1;
    int nb_char = 0;
    int nb_error = 0;
    
    for (int y = 0; file[y] != NULL; y ++) {
        if (my_str("return(", beautifull_str(file[y])) == 0 ||
            my_str("while(", beautifull_str(file[y])) == 0 ||
            my_str("if(", beautifull_str(file[y])) == 0 ||
            my_str("else if(", beautifull_str(file[y])) == 0 ||
            my_str("else{", beautifull_str(file[y])) == 0) {
            nb_error ++;
            printf("\t--> L3: Line : %d\t%s\n", y + 1, name);
        }
    }
    return (nb_error);
}

static int L4error(char *file, char *name)
{
    int c = 0;
    int line = 1;
    int nb_brackets = 0;
    int nb_error = 0;

    while (file[c]) {
        if (file[c] == '{') {
            if (file[c + 1] != '\n') {
                nb_error ++;
                //printf("\t--> L4: Line : %d\t%s\n", y + 1, name);
            }
        }
        if (file[c] == '\n')
            line ++;
        c ++;
    }
    c = 0;
    while (file[c] != '\0') {
        if (file[c] == '{')
            nb_brackets ++;
        if (file[c] == '}')
            nb_brackets --;
        c ++;
    }
    if (nb_brackets != 0)
        nb_error ++;
    return (nb_error);
}

static int L5error(char *file, char *name)
{
    int c = 0;
    int nb_char = 0;
    int nb_error = 0;

    return (nb_error);
}

static int L6error(char *file, char *name)
{
    int c = 0;
    int nb_char = 0;
    int nb_error = 0;

    return (nb_error);
}

int L_error(char **file, norm_s *fault, f_norm *norm, char *name)
{
    if (name == NULL || file == NULL || file[0] == NULL)
        return (0);
    norm->L1 += L1error(file, name);
    norm->L2 += L2error(file, name);
    norm->L3 += L3error(file, name);
    fault->major += norm->L1;
    fault->minor += norm->L2 + norm->L3;
    return (0);
}
