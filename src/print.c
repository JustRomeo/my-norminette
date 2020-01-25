/*
** EPITECH PROJECT, 2019
** Norminette 2.0
** File description:
** print file
*/

#include "prototype.h"

static int print_type_3(f_norm *norm)
{
    if (norm->L3 > 0)
        printf("\e[32m[FUNC]\t\e[0mL3 : Bad Spaces\n");
    if (norm->L4 > 0)
        printf("\e[31m[NONE]\t\e[0mL4 : Curly Brackets\n");
    if (norm->L5 > 0);
    if (norm->L6 > 0);
    if (norm->O1 > 0)
        printf("\e[32m[FUNC]\t\e[0mO1 : no useless file\n");
    if (norm->O2 > 0)
        printf("\e[32m[FUNC]\t\e[0mO2 : File Extension\n");
    if (norm->O3 > 0)
        printf("\e[31m[NONE]\t\e[0mO3 : File Coherence\n");
    if (norm->O4 > 0);
    if (norm->V1 > 0)
        printf("\e[31m[NONE]\t\e[0mV1 : Naming Identifiers\n");
    if (norm->V2 > 0)
        printf("\e[31m[NONE]\t\e[0mV2 : Structures\n");
    if (norm->V3 > 0)
        printf("\e[32m[FUNC]\t\e[0mV3 : Pointers\n");
}

static int print_type_2(f_norm *norm)
{
    if (norm->F6 > 0)
        printf("\e[32m[FUNC]\t\e[0mF6 : Comments inside a function\n");
    if (norm->G1 > 0)
        printf("\e[32m[FUNC]\t\e[0mG1 : File header\n");
    if (norm->G2 > 0)
        printf("\e[31m[NONE]\t\e[0mG2 : Separation of functions\n");
    if (norm->G3 > 0)
        printf("\e[31m[NONE]\t\e[0mG3 : preprocessor indentation directives\n");
    if (norm->G4 > 0)
        printf("\e[32m[FUNC]\t\e[0mG4 : Globals Variables\n");
    if (norm->G5 > 0)
        printf("\e[31m[NONE]\t\e[0mG5 : Static\n");
    if (norm->H1 > 0);
    if (norm->H2 > 0);
    if (norm->H3 > 0);
    if (norm->L1 > 0)
        printf("\e[32m[FUNC]\t\e[0mL1 : one thing by line\n");
    if (norm->L2 > 0)
        printf("\e[32m[FUNC]\t\e[0mL2 : Bad Tabulation\n");
    print_type_3(norm);
}

int print_type(f_norm *norm)
{
    printf("\n\e[35mFault Type\t----------------------------\e[0m\n");
    if (norm->A1 > 0)
        printf("\e[31m[NONE]\t\e[0mA1 : Constant Pointers\n");
    if (norm->A2 > 0)
        printf("\e[31m[NONE]\t\e[0mA2 : Typing\n");
    if (norm->C1 > 0)
        printf("\e[31m[NONE]\t\e[0mC1 : Conditional Branching\n");
    if (norm->C2 > 0)
        printf("\e[31m[NONE]\t\e[0mC2 : Ternary\n");
    if (norm->C3 > 0)
        printf("\e[31m[NONE]\t\e[0mC3 : Goto\n");
    if (norm->F1 > 0)
        printf("\e[31m[NONE]\t\e[0mF1 : Coherence of Funcions\n");
    if (norm->F2 > 0)
        printf("\e[32m[FUNC]\t\e[0mF2 : Naming Functions\n");
    if (norm->F3 > 0)
        printf("\e[32m[FUNC]\t\e[0mF3 : Numbers of columns\n");
    if (norm->F4 > 0)
        printf("\e[32m[FUNC]\t\e[0mF4 : Number of Lines\n");
    if (norm->F5 > 0)
        printf("\e[32m[FUNC]\t\e[0mF5 : Arguments\n");
    print_type_2(norm);
}
