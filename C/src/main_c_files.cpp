#include <iostream>

using namespace std;

string *openFile(string str);

static bool _write = false;
static bool _printf = false;

static void printer_error(string str, int line) {
    for (int i = str.length(); i < 75; i ++)
        str += " ";
    printf("%sl.%d\n", str.c_str(), line);
}

//tab[i].replace(tab[i].find(";;"), sizeof(";;") - 1, ";");
int norminette_c(string *tab) {
    for (int i = 0; tab[i] != ""; i ++) {
        if (tab[i].find(" printf") != string::npos) _printf = true;
        if (tab[i].find(" write") != string::npos) _write = true;
        if (tab[i].find(";;") != string::npos) printer_error("/!\\ Info: \";;\"", i);
        if (tab[i].find("char *") != string::npos) printer_error("/!\\ \"char *\"", i);
        if (tab[i].find(" ;") != string::npos) printer_error("/!\\ \" ;\" do not need space before ;", i);
        if (tab[i].find("){") != string::npos) printer_error("/!\\ Info: \'{\' should be separate by a space", i);
        if (tab[i].find("\t") != string::npos) printer_error("/!\\ Info: \"\t\" better to use \"    \" than a tab", i);
        if (tab[i].length() > 80) printer_error("/!\\ Error: max line length " + to_string(tab[i].length())  + " > 80", i);
    }

    if (_write && _printf)
        printf("/!\\ You are using write AND printf in your program\n");
    return 0;
}