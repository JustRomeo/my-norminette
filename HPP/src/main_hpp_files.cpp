#include <iostream>

using namespace std;

static int classe = 0;
static bool shield = false;

string *openFile(string str);
void printer_error(string str, int line);

int norminette_hpp(string *tab) {
    for (int i = 0; tab[i] != ""; i ++) {
        if (tab[i].find("class") != string::npos && tab[i].find("{") != string::npos) classe ++;
        if (tab[i].find("#ifndef") != string::npos && tab[i + 1].find("#define") != string::npos) shield = true;
        if (tab[i].find("\t") != string::npos) printer_error("\t-> Info: \"\t\" better to use \"    \" than a tab", i);
    }

    if (classe > 1)
        printf("\t-> Error: only one class per file is allow, there are %d class in the file.\n", classe);
    if (!shield)
        printf("\t-> Info: no protection on prototype file, better to protect it.\n");
    return 0;
}