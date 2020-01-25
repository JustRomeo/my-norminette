/*
** Roméo's PROJECT, 2018
** NORMINETTE
** File description:
** norminette personnelle
*/

#include "prototype.h"

int multi_norminette(char ***file, char **name, norm_s *fault, f_norm *norm)
{
    if (!file || !file[0] || !name || !name[0])
        return (0);
    for (int i = 0; file[i] != NULL; i ++)
        A_error(file[i], fault, norm, name[i]);
    for (int i = 0; file[i] != NULL; i ++)
        C_error(file[i], fault, norm, name[i]);
    for (int i = 0; file[i] != NULL; i ++)
        F_error(file[i], fault, norm, name[i]);
    for (int i = 0; file[i] != NULL; i ++)
        G_error(file[i], fault, norm, name[i]);
    for (int i = 0; file[i] != NULL; i ++)
        H_error(file[i], fault, norm, name[i]);
    for (int i = 0; file[i] != NULL; i ++)
        L_error(file[i], fault, norm, name[i]);
    for (int i = 0; file[i] != NULL; i ++)
        O_error(file[i], fault, norm, name[i]);
    for (int i = 0; file[i] != NULL; i ++)
        V_error(file[i], fault, norm, name[i]);
    for (int i = 0; file[i] != NULL; i ++)
        else_error(file[i], name[i]);
    return (0);
}
