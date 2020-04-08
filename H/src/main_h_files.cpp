#include <iostream>

using namespace std;

static bool shield = false;

string *openFile(string str);
void printer_error(string str, int line);

int norminette_h(string *tab) {
    for (int i = 0; tab[i] != ""; i ++) {
        if (tab[i].find("#ifndef") != string::npos && tab[i + 1].find("#define") != string::npos) shield = true;
        if (tab[i].find("\t") != string::npos) printer_error("\t-> Info: \"\t\" better to use \"    \" than a tab", i);
    }
    if (!shield)
        printf("\t-> Info: no protection on prototype file, better to protect it.\n");
    return 0;
}