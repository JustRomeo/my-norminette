#include <iostream>
using namespace std;

void color_file(string str) {
    if (str.find(".cpp") != string::npos)
        printf("%s\n", str.c_str());
    else if (str.find(".a") != string::npos)
        printf("%s\n", str.c_str());
    else if (str.find(".c") != string::npos)
        printf("%s\n", str.c_str());
    else if (str.find(".hpp") != string::npos)
        printf("\e[35m%s\e[0m\n", str.c_str());
    else if (str.find(".py") != string::npos)
        printf("%s\n", str.c_str());
    else if (str.find(".js") != string::npos)
        printf("%s\n", str.c_str());
    else if (str.find(".sh") != string::npos)
        printf("\e[32m%s\e[0m\n", str.c_str());
    else if (str.find(".hs") != string::npos)
        printf("%s\n", str.c_str());
    else if (str.find(".h") != string::npos)
        printf("\e[35m%s\e[0m\n", str.c_str());
    else if (str.find(".asm") != string::npos)
        printf("%s\n", str.c_str());
    else if (str.find(".o") != string::npos)
        printf("%s\n", str.c_str());
    else if (str.find("Makefile") != string::npos)
        printf("\e[33m%s\e[0m\n", str.c_str());
    else
        printf("Unknown Type\n");
}