#include <iostream>

using namespace std;

string *openFile(string str);

static int classe = 0;

static void printer_error(string str, int line) {
    for (int i = str.length(); i < 75; i ++)
        str += " ";
    printf("%sl.%d\n", str.c_str(), line);
}

//tab[i].replace(tab[i].find(";;"), sizeof(";;") - 1, ";");
int norminette_hpp(string *tab) {
    for (int i = 0; tab[i] != ""; i ++) {
        if (tab[i].find("class") != string::npos && tab[i].find("{") != string::npos) classe ++;
        if (classe > 0) printer_error("/!\\ Error: only one class per file is allow", i);
    }
    return 0;
}