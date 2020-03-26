#include <iostream>

using namespace std;

string *openFile(string str);

static void printer_error(string str, int line) {
    for (int i = str.length(); i < 75; i ++)
        str += " ";
    printf("%sl.%d\n", str.c_str(), line);
}

//tab[i].replace(tab[i].find(";;"), sizeof(";;") - 1, ";");
int norminette_haskell(string *tab) {
    for (size_t i = 0; tab[i] != ""; i ++) {
        if (tab[i].find("\t") != string::npos) printer_error("/!\\ Info: \"\t\" better to use \"    \" than a tab", i);
        if (tab[i].find("<-getargs") != string::npos) printer_error("/!\\ Info: \"<-getargs\" need to have a space after \'-\'", i);
        if (tab[i].find(" :: ") == string::npos && tab[i].find("::") != string::npos)
            printer_error("/!\\ Info: \"::\" should have an space before and after, like \" :: \" than a tab", i);
    }
    return 0;
}