#include <stdio.h>
#include <iostream>

int usage(void) {
    printf("Version(3.0.1)\n\n");
    printf("Usage:\n");
    printf("\t- without agument(s), do all files in the folder.\n");
    printf("\t- with only one agument, do the file at the path you gave.\n");
    printf("\n");
    printf("Langage gestion:\n");
    printf("  - ASM\n");
    printf("  - C\n");
    printf("  - Cpp\n");
    printf("  - hpp\n");
    printf("  - Haskell\n");
    printf("\n");

    return 0;
}

void version(void) {
    printf("Version(3.0.1)\n");
}