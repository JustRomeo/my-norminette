#include <iostream>
#include <unistd.h>
#include <sys/stat.h>

using namespace std;

static bool isbinary(const char *filepath) {
    struct stat st;

    if (stat(filepath, &st) < 0)
        return false;
    return st.st_mode & S_IEXEC != 0 ? true : false;
}

void color_file(string str) {
    if (isbinary(str.c_str()))
        printf("\e[32m%s\e[0m\n", str.c_str());
    else if (str.find("Makefile") != string::npos)
        printf("\e[33m%s\e[0m\n", str.c_str());
    else if (str.find(".cmake") != string::npos)
        printf("%s\n", str.c_str());
    else if (str.find(".asm") != string::npos)
        printf("%s\n", str.c_str());
    else if (str.find(".rar") != string::npos)
        printf("\e[31m%s\e[0m\n", str.c_str());
    else if (str.find(".txt") != string::npos)
        printf("\e[37m%s\e[0m\n", str.c_str());
    else if (str.find(".gif") != string::npos)
        printf("\e[95m%s\e[0m\n", str.c_str());
    else if (str.find(".png") != string::npos)
        printf("\e[95m%s\e[0m\n", str.c_str());
    else if (str.find(".jpg") != string::npos)
        printf("\e[95m%s\e[0m\n", str.c_str());
    else if (str.find(".ogg") != string::npos)
        printf("\e[95m%s\e[0m\n", str.c_str());
    else if (str.find(".otf") != string::npos)
        printf("\e[95m%s\e[0m\n", str.c_str());
    else if (str.find(".wav") != string::npos)
        printf("\e[95m%s\e[0m\n", str.c_str());
    else if (str.find(".cpp") != string::npos)
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
    else if (str.find(".a") != string::npos)
        printf("%s\n", str.c_str());
    else if (str.find(".c") != string::npos)
        printf("%s\n", str.c_str());
    else if (str.find(".h") != string::npos)
        printf("\e[35m%s\e[0m\n", str.c_str());
    else if (str.find(".o") != string::npos)
        printf("%s\n", str.c_str());
    else
        printf("Unknown Type: %s\n", str.c_str());
}