/*
** EPITECH PROJECT, 2019
** Norminette
** File description:
** initialisation file
*/

#include "prototype.h"

norm_s *init_fault(void)
{
    norm_s *norm = malloc(sizeof(norm_s));

    norm->nfo = 0;
    norm->minor = 0;
    norm->major = 0;
    return (norm);
}

f_norm *init_norm(void)
{
    f_norm *norm = malloc(sizeof(f_norm));

    norm->A1 = 0;
    norm->A2 = 0;
    norm->C1 = 0;
    norm->C2 = 0;
    norm->C3 = 0;
    norm->F1 = 0;
    norm->F2 = 0;
    norm->F3 = 0;
    norm->F4 = 0;
    norm->F5 = 0;
    norm->F6 = 0;
    norm->G1 = 0;
    norm->G2 = 0;
    norm->G3 = 0;
    norm->G4 = 0;
    norm->G5 = 0;
    norm->H1 = 0;
    norm->H2 = 0;
    norm->H3 = 0;
    norm->L1 = 0;
    norm->L2 = 0;
    norm->L3 = 0;
    norm->L4 = 0;
    norm->L5 = 0;
    norm->L6 = 0;
    norm->O1 = 0;
    norm->O2 = 0;
    norm->O3 = 0;
    norm->O4 = 0;
    norm->V1 = 0;
    norm->V2 = 0;
    norm->V3 = 0;
    return (norm);
}
