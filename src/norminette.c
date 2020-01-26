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
    for (int i = 0; file[i]; i ++)
        A_error(file[i], fault, norm, name[i]);
    for (int i = 0; file[i]; i ++)
        C_error(file[i], fault, norm, name[i]);
    for (int i = 0; file[i]; i ++)
        F_error(file[i], fault, norm, name[i]);
    for (int i = 0; file[i]; i ++)
        G_error(file[i], fault, norm, name[i]);
    for (int i = 0; file[i]; i ++)
        H_error(file[i], fault, norm, name[i]);
    for (int i = 0; file[i]; i ++)
        L_error(file[i], fault, norm, name[i]);
    for (int i = 0; file[i]; i ++)
        O_error(file[i], fault, norm, name[i]);
    for (int i = 0; file[i]; i ++)
        V_error(file[i], fault, norm, name[i]);
    return (0);
}
