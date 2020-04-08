#include <iostream>
#include <vector>
#include <string>

using namespace std;

string *openFile(string str);

static size_t unit_test = 0;
static size_t _functions = 0;
static bool _write = false;
static bool _printf = false;

static void printer_error(string str, int line) {
    for (int i = str.length(); i < 75; i ++)
        str += " ";
    printf("%sl.%d\n", str.c_str(), line);
}

static void split(string str, string splitBy, vector<string>& tokens)
{
    string frag;
    size_t splitAt;
    size_t splitLen = splitBy.size();

    tokens.push_back(str);
    while (true) {
        frag = tokens.back();
        splitAt = frag.find(splitBy);
        if(splitAt == string::npos)
            break;
        tokens.back() = frag.substr(0, splitAt);
        tokens.push_back(frag.substr(splitAt+splitLen, frag.size() - (splitAt+splitLen)));
    }
}

static string find_function_name(string line) {
    string name = line;

    if (name.find("static ") != string::npos)
        name.replace(name.find("static "), sizeof("static ") - 1, "");
    if (name.find("(void)") != string::npos)
        name.replace(name.find("(void)"), sizeof("(void)") - 1, "");
    if (name.find("(") != string::npos && name.find(")") != string::npos) {
        vector<string> results;
        split(name, "(", results);
        name = results[0];
    }
    vector<string> results;
    split(name, " ", results);
    name = results[1];
    return name;
}

static void proto(string *tab, int indexe) {
    int rem = 1;
    int i = indexe;

    string fname = find_function_name(tab[i]);
    _functions ++;
    for (; tab[i] != "}" && tab[i] != ""; i ++) {
        if (tab[i] == "{")
            rem ++;
    }
    if (tab[i] == "}")
        rem ++;
    i -= rem;
    if (tab[indexe].find("{") != string::npos) {
        i --;
        printer_error("/!\\ \'{\' must be next line, and NOT next to prototype", i);
    }
    if (i - indexe > 20)
        printf("/!\\ Too long functions %s (%d > 20).\n", fname.c_str(), i - indexe);
}

int norminette_c(string *tab) {
    _functions = 0;

    for (int i = 0; tab[i] != ""; i ++) {
        if (tab[i].find("//") != string::npos)
            printer_error("/!\\ Info: Commantary !", i);
        else if (tab[i][0] != ' ' && tab[i][0] != '\t' && tab[i].find("Test") != string::npos)
            unit_test ++;
        else {
            if (tab[i].find(" write") != string::npos) _write = true;
            if (tab[i].find(" printf") != string::npos) _printf = true;
            if (tab[i].find(";;") != string::npos) printer_error("/!\\ Info: \";;\"", i);
            if (tab[i].find("char*") != string::npos) printer_error("/!\\ \"char*\" should be \"char *\"", i);
            if (tab[i].find(" ;") != string::npos) printer_error("/!\\ \" ;\" do not need space before ;", i);
            if (tab[i].find("){") != string::npos) printer_error("/!\\ Info: \'{\' should be separate by a space", i);
            if (tab[i][0] != ' ' && tab[i][0] != '\t' && tab[i].find("(") != string::npos) proto(tab, i);
            if (tab[i].find("\t") != string::npos) printer_error("/!\\ Info: \"\t\" better to use \"    \" than a tab", i);
            if (tab[i].length() > 80) printer_error("/!\\ Error: max line length " + to_string(tab[i].length())  + " > 80", i);
        }
    }

    if (_write && _printf)
        printf("/!\\ You are using write AND printf in your program.\n");
    if (_functions > 5)
        printf("/!\\ %d functions in the file, max norme complient it's 5.\n", _functions);
    return 0;
}