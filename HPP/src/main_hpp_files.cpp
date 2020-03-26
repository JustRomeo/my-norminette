#include <iostream>

using namespace std;

string *openFile(string str);

static int classe = 0;
static bool shield = false;

static void printer_error(string str, int line) {
    for (int i = str.length(); i < 75; i ++)
        str += " ";
    printf("%sl.%d\n", str.c_str(), line);
}

//tab[i].replace(tab[i].find(";;"), sizeof(";;") - 1, ";");
int norminette_hpp(string *tab) {
    for (int i = 0; tab[i] != ""; i ++) {
        if (tab[i].find("class") != string::npos && tab[i].find("{") != string::npos) classe ++;
        if (tab[i].find("#ifndef") != string::npos && tab[i + 1].find("#define") != string::npos) shield = true;
        if (tab[i].find("\t") != string::npos) printer_error("/!\\ Info: \"\t\" better to use \"    \" than a tab", i);
    }

    if (classe > 0)
        printf("/!\\ Error: only one class per file is allow, there are %d class in the file.\n", classe);
    if (!false)
        printf("/!\\ Info: no protection on prototype file, better to protect it.\n");
    return 0;
}