#include <iostream>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;

string *openFile(string str);
int norminette_c(string *tab);
int norminette_asm(string *tab);
int norminette_cpp(string *tab);
int norminette_hpp(string *tab);
int norminette_haskell(string *tab);

static void color_file(string str) {
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

static int normifile(string str) {
    char *av[2];
    av[0] = strdup("Exec");
    av[1] = strdup(str.c_str());

    color_file(str.c_str());
    if (str.find(".cpp") != string::npos)
        norminette_cpp(openFile(str));
    else if (str.find(".a") != string::npos);
    else if (str.find(".c") != string::npos)
        norminette_c(openFile(str));
    else if (str.find(".hpp") != string::npos)
        norminette_hpp(openFile(str));
    else if (str.find(".py") != string::npos);
    else if (str.find(".js") != string::npos);
    else if (str.find(".sh") != string::npos);
    else if (str.find(".hs") != string::npos)
        norminette_haskell(openFile(str));
    else if (str.find(".h") != string::npos);
    else if (str.find(".asm") != string::npos)
        norminette_asm(openFile(str));
    else if (str.find(".o") != string::npos);
    else if (str.find("Makefile") != string::npos);
    else
        printf("i do not recognize this file type ...\n");
    return 0;
}

static int normifolder(int cascade = 0, string filepath = "") {
    string str;
    struct dirent *print;
    DIR *Folder;

    if (filepath == "");
    else
        chdir(filepath.c_str());
    Folder = opendir(".");
    if (!Folder) {
        printf("Empty Folder :/\n");
        return 1;
    }
    print = readdir(Folder);
    for (size_t i = 0; print; i ++) {
        if (print->d_name[0] == '.');
        else if(print->d_type == DT_DIR) {
            char cwd[1024];
            getcwd(cwd, sizeof(cwd));
            normifolder(cascade + 1, print->d_name);
            chdir("..");
        } else {
            char cwd[1024];
            getcwd(cwd, sizeof(cwd));
            normifile(print->d_name);
        }
        print = readdir(Folder);
    }
    return 0;
}

int normimain(int ac, char **av) {
    if (ac > 2)
        return 0;
    else if (ac > 1)
        normifile(av[1]);
    else
        normifolder();
    return 0;
}