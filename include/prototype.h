/*
** EPITECH PROJECT, 2018
** prototype.h
** File description:
** HEADER
*/

#ifndef PROTO_H
#define PROTO_H

#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/sysmacros.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <pwd.h>
#include <time.h>
#include <grp.h>
#include <dirent.h>
#include <string.h>
#include "get_next_line.h"
#include "structures.h"
#include "macro.h"
#include "my.h"

int norminette(char **file, char *name);
void name(char c, int *nb_error, struct dirent *print, int z);
void notname(int *nb_error, struct dirent *print);
int A_error(char **file, norm_s *fault, f_norm *norm, char *name);
int C_error(char **file, norm_s *fault, f_norm *norm, char *name);
int F_error(char **file, norm_s *fault, f_norm *norm, char *name);
int G_error(char **file, norm_s *fault, f_norm *norm, char *name);
int H_error(char **file, norm_s *fault, f_norm *norm, char *name);
int L_error(char **file, norm_s *fault, f_norm *norm, char *name);
int lookingfor_free(char **file, char *name);
int O_error(char **file, norm_s *fault, f_norm *norm, char *name);
int else_error(char **file, char *name);
int V_error(char **file, norm_s *fault, f_norm *norm, char *name);
int lookingfor_open(char **file, char *name);
int lookingfor_free(char **file, char *name);
int output(char *str);
int multi_norminette(char ***file, char **name, norm_s *fault, f_norm *norm);
f_norm *init_norm(void);
norm_s *init_fault(void);
int print_type(f_norm *norm);
int cdisok(char *str);
void free_all(char *str1, char *str2, char *str3, char **tab, char ***tab2);

#endif
