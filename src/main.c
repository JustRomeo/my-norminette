/*
** Roméo's PROJECT, 2018
** NORMINETTE
** File description:
** main de la norminette
*/

#include "prototype.h"

static int ui_mouli(char ***file, char **name, norm_s *fault, f_norm *norm)
{
    for (int i = 0; name[i] != NULL; i ++)
        printf("\t[%s]\n", name[i]);
    printf("\n\n\tNorminette\n\n\n");
    printf("\e[35mCoding Style\t----------------------------\e[0m\n");
    multi_norminette(file, name, fault, norm);
    print_type(norm);
    printf("\n\e[35mSummarise\t----------------------------\e[0m\n");
    printf("info  : %d\n", fault->nfo);
    printf("minor : %d\n", fault->minor);
    printf("major : %d\n", fault->major);
    printf("\n");
}

static int many_file(char *str, norm_s *fault, f_norm *norm)
{
    DIR *fd = 0;
    FILE *sfd = 0;
    char *bcp = NULL;
    char *path = my_strcpy(path, "./");
    char ***buffer = NULL;
    char **name_buffer = NULL;
    size_t size_bcp = 0;
    struct dirent *print;
    int nb_f = 0;

    if (str != NULL)
        path = my_strcat(path, str);
    fd = opendir(path);
    print = readdir(fd);
    buffer = malloc(sizeof(char **) * (MALLOC_FILE + 1));
    name_buffer = malloc(sizeof(char *) * (MALLOC_FILE + 1));
    buffer[0] = NULL;
    name_buffer[0] = NULL;
    while (print != NULL) {
        buffer[nb_f] = malloc(sizeof(char *) * (MALLOC_LINE + 1));
        while (my_str("c.", my_revstr(print->d_name)) != 0) {
            if (cdisok(my_revstr(print->d_name)) == 0 &&
                my_str(".", print->d_name) != 0 &&
                my_str("..", print->d_name) != 0) {
                printf("\e[36m- - - - - - - - - - %s - - - - - - - - - -\e[0m\n", print->d_name);
                chdir(print->d_name);
                rec ++;
                many_file(NULL, fault, norm);
                rec --;
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
        name_buffer[nb_f] = my_strcpy(name_buffer[nb_f], print->d_name);
        name_buffer[nb_f + 1] = NULL;
        for (int i = 0; getline(&bcp, &size_bcp, sfd) != -1; i ++) {
            buffer[nb_f][i] = my_strcpy(buffer[nb_f][i], bcp);
            buffer[nb_f][i][my_strlen(buffer[nb_f][i]) - 1] = '\0';
            buffer[nb_f][i + 1] = NULL;
        }
        print = readdir(fd);
        fclose(sfd);
        nb_f ++;
    }
    buffer[nb_f] = NULL;
    name_buffer[nb_f] = NULL;
    if (rec > 0)
        multi_norminette(buffer, name_buffer, fault, norm);
    if (rec == 0)
        ui_mouli(buffer, name_buffer, fault, norm);

    //Free(s)
    if (str)
        free(str);
    if (bcp)
        free(bcp);
    if (path)
        free(path);
    return (0);
}

int main(int ac, char **av)
{
    norm_s *fault = init_fault();
    f_norm *norm = init_norm();
    char *str = NULL;

    if (ac == 2 && av[1] != NULL)
        str = my_strcpy(str, av[1]);
    return (many_file(str, fault, norm));
}
