#include <iostream>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#include "C.hpp"
#include "H.hpp"
#include "ASM.hpp"
#include "Cpp.hpp"
#include "Hpp.hpp"
#include "Haskell.hpp"
#include "Python.hpp"

#include "System.hpp"

#include "prototype.hpp"

using namespace std;
static int normifile(string str) {
    color_file(str);
    if (str.find(".cpp") != string::npos)
        Cpp().norminette_cpp(System().openfile(str));
    else if (str.find(".cmake") != string::npos);
    else if (str.find(".cabal") != string::npos);
    else if (str.find(".json") != string::npos);
    else if (str.find(".a") != string::npos);
    else if (str.find(".c") != string::npos)
        C().norminette_c(System().openfile(str));
    else if (str.find(".hpp") != string::npos)
        Hpp().norminette_hpp(System().openfile(str));
    else if (str.find(".py") != string::npos)
        Python().norminette_python(System().openfile(str));
    else if (str.find(".js") != string::npos);
    else if (str.find(".sh") != string::npos);
    else if (str.find(".hs") != string::npos)
        Haskell().norminette_haskell(System().openfile(str));
    else if (str.find(".h") != string::npos)
        H().norminette_h(System().openfile(str));
    else if (str.find(".asm") != string::npos)
        ASM().norminette_asm(System().openfile(str));
    else if (str.find(".o") != string::npos);
    else if (str.find("Makefile") != string::npos);
    else if (str.find(".xml") != string::npos);
    else if (str.find(".md") != string::npos);
    else if (str.find(".sql") != string::npos);
    else if (str.find(".jpg") != string::npos);
    else if (str.find(".png") != string::npos);
    else if (str.find(".row") != string::npos);
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