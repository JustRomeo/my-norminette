/*
** EPITECH PROJECT, 2018
** NORMINETTE
** File description:
** error F
*/

#include "prototype.h"

static int F1error(char **file, char *name)
{
    int c = 0;
    int nb_char = 0;
    int nb_error = 0;

    return (nb_error);
}

static int F2error(char **file, char *name)
{
    int c = 0;
    int w = 0;
    int nb_dot = 0;
    int nb_error = 0;

    for (int i = 0; file[i] != NULL; i ++) {
        if (my_str("int ", file[i]) == 0 || my_str("char *", file[i]) == 0 ||
            my_str("char **", file[i]) == 0 || my_str("void", file[i]) == 0) {
            for (w = 0; file[i][w] && file[i][w] != ' '; w ++);
            for (w ++; file[i][w] && file[i][w] == '*'; w ++);
            if ((file[i][w] > 47 && file[i][w] < 58) ||
                (file[i][w] > 64 && file[i][w] < 91)) {
                printf("\t--> F2: Line : %d\t%s\n", i + 1, name);
            }
        }
        nb_dot = 0;
    }
    return (nb_error);
}

static int F3error(char **file, char *name)
{
    int y = 0;
    int line = 1;
    int nb_char = 0;
    int nb_error = 0;

    for (int i = 0; file[i] != NULL; i ++) {
        for (int c = 0; file[i][c]; c ++, nb_char ++);
        if (nb_char > 80) {
            nb_error ++;
            printf("\t--> F3: Line : %d\t%s\n", i + 1, name);
        }
        nb_char = 0;
        line ++;
    }
    return (nb_error);
}

static int F4error(char **file, char *name)
{
    int c = 0;
    int k = 0;
    int nb_line = 0;
    int nb_error = 0;
    int nb_brackets = 0;

    for (int i = 4; file[i] != NULL; i ++) {
        if (nb_brackets < 1) {
            if (nb_line > SZ_MAX_FUNC + 1) {
                printf("\t--> F4: Line : %d (%d)\t%s\n", (i - (nb_line + 1)), nb_line - 1, name);
                nb_error ++;
            }
            nb_line = 0;
        } if (nb_brackets > 0)
              nb_line ++;
        for (int c = 0; file[i][c] ; c ++) {
            if (file[i][c] == '{')
                nb_brackets ++;
            if (file[i][c] == '}')
                nb_brackets --;
        }
    }
    return (nb_error);
}

static int F5error(char **file, char *name)
{
    int w = 0;
    int c = 0;
    int nb_dot = 0;
    int nb_error = 0;

    for (int i = 0; file[i] != NULL; i ++) {
        if (my_str("int ", file[i]) == 0 || my_str("char *", file[i]) == 0 ||
            my_str("char **", file[i]) == 0 || my_str("void", file[i]) == 0) {
            for (w = 0; file[i][w] && file[i][w] != '('; w ++);
            for (w; file[i][w] && file[i][w] != ')'; w ++)
                if (file[i][w] == ',')
                    nb_dot ++;
            if (nb_dot > ARGMNTS_MAX + 1) {
                printf("\t--> F5: Line : %d (%d)\t%s\n", i + 1, nb_dot + 1, name);
                nb_error ++;
            }
        }
        nb_dot = 0;
    }
    return (nb_error);
}

static int F6error(char **file, char *name)
{
    int c = 0;
    int line = 1;
    int nb_bracket = 0;
    int nb_error = 0;
    int noh = 0;

    for (int i = 4; file[i] != NULL; i ++) {
        for (int c = 0; file[i][c] ; c ++) {
            if (file[i][c] == '{')
                nb_bracket ++;
            if (file[i][c] == '}')
                nb_bracket --;
            if (nb_bracket > 0 && ((file[i][c] == '/' && file[i][c + 1] == '/') ||
                                   (file[i][c] == '/' && file[i][c + 1] == '*'))) {
                printf("\t--> F6: Line : %d\t%s\n", i + 1, name);
                nb_error ++;
            }
        }
    }
    return (nb_error);
}

int F_error(char **file, norm_s *fault, f_norm *norm, char *name)
{
    norm->F2 += F2error(file, name);
    norm->F3 += F3error(file, name);
    norm->F4 += F4error(file, name);
    norm->F5 += F5error(file, name);
    norm->F6 += F6error(file, name);
    fault->major += norm->F2 + norm->F3 + norm->F4 + norm->F5;
    fault->minor += norm->F6;
    return (0);
}
