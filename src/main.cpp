#include <stdio.h>

static void usage(void) {
    printf("USAGE:\n");
    printf("\t- without agument(s), do all files in the folder.\n");
    printf("\t- with only one agument, do the file at the path you gave.\n");
    printf("\n");
    printf("Langage gestion:\n");
    printf("  - C\n");
    printf("  - CPP\n");
    printf("\n");
}

int main(int ac, char **av, char **env) {
    if (ac > 2)
        usage();
    return 0;
}