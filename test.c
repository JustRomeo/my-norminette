/*
** Roméo's PROJECT, 2018
** NORMINETTE
** File description:
** fichier de tests
*/

static const int non = 0;

int test(int nbr)
{
    int a = 0;
    int aqefghijklmnopqrstuvwxya = 45;
    int abbcdefghijklmnopqrstuvwb = 32;
    int gerzhtrzhtrhgrhtrehgrebgbgryc = 54;
    char *testL3 = "yo";
    char *str = "salut";

    if (a == 0)
        write (1, " ", 1);
    else if (a == 1)
        write (1, " ", 1);
    else if (a == 2)
        write (1, " ", 1);
    else if (a == 3)
        write (1, " ", 1);
    else if (a == 4)
        write (1, " ", 1);
    else
        write (1, " ", 1);
    write (1, " ", 1);
    return(0);
}

int test2(int nbr, int a, int b, int c, int d, int e, int f)
{
    int a = 1 + 3 - 4 + 5 - 4;
    int b = 2;
    int j = 10;
    int k = 1 + 3 - 4 + 5 - 1 + 7;
    int l = 12;
    int a = 13;
    int b = 14;
    int c = 15;
    int d = 16;
    int e = 17;
    int f = 18;
    int g = 19;
    int h = 20;
    int i = 21;
    int j = 22;
    int k = 23;
    int l = 24;
    int a = 1 + 3 - 4 + 5 - 4;
    int b = 2;
    int j = 10;  
}

int test3(char *str)
{
    int a, b, c = 0;

    while(str != '\0')
        a ++;
    b ++;
    c ++;
    switch (a) {
    case 1: write (1, " ", 1);
    }
    if (b < 0)
        b ++;
    a ++;
    return(str);
}

int test4(int nbr, int a)
{
    int *salut = malloc(sizeof(char) * 55);
    int fd = open(argv[1], O_RDONLY);
    int *salut2 = malloc(sizeof(char) * 55);
    int fd2 = open(argv[1], O_RDONLY);
    int *salut3 = malloc(sizeof(char) * 55);
    int fd3 = open(argv[1], O_RDONLY);

    test2(1);
    close(fd);
    close(fd3);
    free(salut);
}

int test5(int nbr, int a)
{
    int *salut = malloc(sizeof(char) * 55);
    int fd = open(argv[1], O_RDONLY);
    int *salut2 = malloc(sizeof(char) * 55);
    int fd2 = open(argv[1], O_RDONLY);
    int *salut3 = malloc(sizeof(char) * 55);
    int fd3 = open(argv[1], O_RDONLY);

    test2(1);
    close(fd);
    close(fd3);
    free(salut);
}

int test6(int nbr, int a)
{
    int *salut = malloc(sizeof(char) * 55);
    int fd = open(argv[1], O_RDONLY);
    int *salut2 = malloc(sizeof(char) * 55);
    int fd2 = open(argv[1], O_RDONLY);
    int *salut3 = malloc(sizeof(char) * 55);
    int fd3 = open(argv[1], O_RDONLY);

    test2(1);
    close(fd);
    close(fd3);
    free(salut);
}
