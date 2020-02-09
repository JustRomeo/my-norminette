#include "../include/lib.hpp"
#include "../include/prototype.hpp"

int norminette_cpp(int ac, char **av, char **env) {
    if (ac > 2) {
        printf("USAGE:\t./norminette\n");
        printf("\t- without agument(s), do all files in the folder.");
        printf("\t- with only one agument, do the file at the path you gave.");
    } //else if (ac == 1)
    //     many_files();
    // else
    //     one_file();
    return 0;
}