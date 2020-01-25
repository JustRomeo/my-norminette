/*
** EPITECH PROJECT, 2018
** structures.h
** File description:
** HEADER
*/

typedef struct linked_list
{
    int data;
    struct linked_list *next;
} linked_list_t;

typedef struct norm_s
{
    int nfo;
    int minor;
    int major;
} norm_s;

typedef struct f_norm
{
    int A1;
    int A2;
    int C1;
    int C2;
    int C3;
    int F1;
    int F2;
    int F3;
    int F4;
    int F5;
    int F6;
    int G1;
    int G2;
    int G3;
    int G4;
    int G5;
    int H1;
    int H2;
    int H3;
    int L1;
    int L2;
    int L3;
    int L4;
    int L5;
    int L6;
    int O1;
    int O2;
    int O3;
    int O4;
    int V1;
    int V2;
    int V3;
} f_norm;
