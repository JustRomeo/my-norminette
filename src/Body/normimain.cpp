#include <iostream>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

using namespace std;

#include "library.hpp"
#include "prototype.hpp"

#include "Cpp.hpp"
#include "Hpp.hpp"
#include "System.hpp"

static int normifile(string str) {
    char *av[2];
    av[0] = strdup("Exec");
    av[1] = strdup(str.c_str());

    color_file(str);
    if (str.find(".cpp") != string::npos)
        Cpp().norminette_cpp(System().openfile(str));
    else if (str.find(".cabal") != string::npos);
    else if (str.find(".json") != string::npos);
    else if (str.find(".a") != string::npos);
    else if (str.find(".c") != string::npos)
        norminette_c(openFile(str));
    else if (str.find(".hpp") != string::npos)
        Hpp().norminette_hpp(System().openfile(str));
    else if (str.find(".py") != string::npos);
    else if (str.find(".js") != string::npos);
    else if (str.find(".sh") != string::npos);
    else if (str.find(".hs") != string::npos)
        norminette_haskell(openFile(str));
    else if (str.find(".h") != string::npos)
        norminette_h(openFile(str));
    else if (str.find(".asm") != string::npos)
        norminette_asm(openFile(str));
    else if (str.find(".o") != string::npos);
    else if (str.find("Makefile") != string::npos);
    return 0;
}

static int normifolder(int cascade = 0, string filepath = "") {
    string str;
    DIR *Folder;
    struct dirent *print;

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