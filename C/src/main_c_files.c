/*
** Roméo's PROJECT, 2018
** NORMINETTE
** File description:
** main de la norminette
*/

#include "prototype.h"

static int ui_mouli(char ***file, char **name, norm_s *fault, f_norm *norm)
{
    for (int i = 0; name[i]; i ++)
        printf("\t[%s]\n", name[i]);
    printf("\n\n\tNorminette\n\n\n");
    printf("\e[35mCoding Style\t----------------------------\e[0m\n");
    multi_norminette(file, name, fault, norm);
    print_type(norm);
    printf("\n\e[35mSummarise\t----------------------------\e[0m\n");
    printf("info : %d\n", fault->nfo);
    printf("minor: %d\n", fault->minor);
    printf("major: %d\n", fault->major);
    printf("\n");
}

static int many_file(char *str, norm_s *fault, f_norm *norm)
{
    DIR *fd = 0;
    int nb_f = 0;
    FILE *sfd = 0;
    char *bcp = NULL;
    size_t size_bcp = 0;
    struct dirent *print;
    char ***buffer = NULL;
    char **name_buffer = NULL;
    char *path = strdup("./");

    if (str && str[0] && str[0] != '.')
        strcat(path, str);
    fd = opendir(path);
    print = readdir(fd);
    buffer = malloc(sizeof(char **) * (MALLOC_FILE + 1));
    name_buffer = malloc(sizeof(char *) * (MALLOC_FILE + 1));
    for (; print; nb_f ++) {
        buffer[nb_f] = malloc(sizeof(char *) * (MALLOC_LINE + 1));
        while (my_str("c.", my_revstr(print->d_name)) != 0) {
            if (cdisok(my_revstr(print->d_name)) == 0 && my_str(".", print->d_name) != 0 && my_str("..", print->d_name) != 0) {
                printf("\e[36m- - - - - - - - - - %s - - - - - - - - - -\e[0m\n", print->d_name);
                chdir(print->d_name);
                many_file(NULL, fault, norm);
                chdir("..");
            }
            print = readdir(fd);
            if (!print)
                break;
        }
        if (!print)
            break;
        sfd = fopen(my_revstr(print->d_name), "r");
        if (!sfd)
            break;
        name_buffer[nb_f] = strdup(print->d_name);
        name_buffer[nb_f + 1] = NULL;
        for (int i = 0; getline(&bcp, &size_bcp, sfd) != -1; i ++) {
            buffer[nb_f][i] = strdup(bcp);
            buffer[nb_f][i][strlen(buffer[nb_f][i]) - 1] = '\0';
            buffer[nb_f][i + 1] = NULL;
        }
        print = readdir(fd);
        fclose(sfd);
    }
    buffer[nb_f] = NULL;
    name_buffer[nb_f] = NULL;
    rec > 0 ? multi_norminette(buffer, name_buffer, fault, norm) : ui_mouli(buffer, name_buffer, fault, norm);
    free_all(str, bcp, path, name_buffer, buffer);
    return (0);
}

int norminette_c(int ac, char **av) {
    norm_s *fault = init_fault();
    f_norm *norm = init_norm();
    char *str = NULL;

    if (ac == 2 && av[1])
        str = strdup(av[1]);
    return (many_file(str, fault, norm));
}
