#include <iostream>

static int normifile(std::string str) {
    printf("file: %s\n", str.c_str());
    if (str.find(".cpp") != std::string::npos)
        printf("it's a CPP file\n");
    else if (str.find(".c") != std::string::npos)
        printf("it's a C file\n");
    else if (str.find(".hpp") != std::string::npos)
        printf("it's a HPP file\n");
    else if (str.find(".h") != std::string::npos)
        printf("it's a H file\n");
    else if (str.find(".py") != std::string::npos)
        printf("it's a Python file\n");
    else if (str.find(".js") != std::string::npos)
        printf("it's a JavaScript file\n");
    else
        printf("i do not recognize this file type ...\n");
    return 0;
}

static int normifolder(void) {
    printf("folder\n");
    return 0;
}

int normimain(int ac, char **av) {
    if (ac == 1) normifolder();
    else normifile(av[1]);
    return 0;
}