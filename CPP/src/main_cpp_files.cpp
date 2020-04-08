#include <iostream>

using namespace std;

string *openFile(string str);

static void printer_error(string str, int line) {
    for (int i = str.length(); i < 75; i ++)
        str += " ";
    printf("%sl.%d\n", str.c_str(), line);
}

//tab[i].replace(tab[i].find(";;"), sizeof(";;") - 1, ";");
int norminette_cpp(string *tab) {
    for (int i = 0; tab[i] != ""; i ++) {
        if (tab[i].find(";;") != string::npos) printer_error("/!\\ Info: \";;\"", i);
        if (tab[i].find("char *") != string::npos) printer_error("/!\\ \"char *\"", i);
        if (tab[i].find(" ;") != string::npos) printer_error("/!\\ \" ;\" do not need space before ;", i);
        if (tab[i].find("){") != string::npos) printer_error("/!\\ Info: \'{\' should be separate by a space", i);
        if (tab[i].find("\t") != string::npos) printer_error("/!\\ Info: \"\t\" better to use \"    \" than a tab", i);
        if (tab[i].find("//") != string::npos) printer_error("/!\\ Info: Commantary !", i);
    }
    return 0;
}