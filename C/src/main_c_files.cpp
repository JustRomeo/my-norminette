#include <iostream>
#include <vector>
#include <string>

using namespace std;

static size_t unit_test = 0;
static size_t _functions = 0;
static bool _header[4] = {false, false, false, false};

void printer_error(string str, int line);

static bool indent(string line)
{
    size_t i = 0;

    if (line == " ")
        return true;
    for (i; line[i] && line[i] == ' '; i ++);
    if (i % 4 != 0)
        return false;
    return true;
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

    if (tab[indexe].find(";") != string::npos || tab[indexe].find("=") != string::npos)
        return;
    string fname = find_function_name(tab[i]);
    _functions ++;
    for (int z = 0; fname[z]; z ++) {
        if (isupper(fname[z])) {
            string printer = "\t-> Function Name \e[93m" + fname + "\e[0m should not contain Uppercase";
            printer_error(printer, i);
            break;
        }
    } for (; tab[i] != "}" && tab[i] != ""; i ++)
        if (tab[i] == "{")
            rem ++;
    if (tab[i] == "}")
        rem ++;
    i -= rem;
    if (tab[indexe].find("{") != string::npos) {
        i --;
        printer_error("\t-> \'{\' must be next line, and NOT next to prototype", i);
    }
    if (i - indexe > 20)
        printf("\t-> Too long functions \e[93m%s\e[0m (%d > 20).\n", fname.c_str(), i - indexe);
}

int norminette_c(string *tab) {
    _functions = 0;

    if (tab[0] == "" || tab[1] == "" || tab[2] == "" || tab[3] == "" || tab[4] == "" || tab[5] == "" || tab[6] == "")
        printf("\t-> Header Problem: Not Epitech Compliant\n");
    if (tab[0].find("/*") != string::npos) _header[0] = true;
    if (tab[1].find("** EPITECH PROJECT, ") != string::npos) _header[1] = true;
    if (tab[3].find("** File description:") != string::npos) _header[2] = true;
    if (tab[5].find("*/") != string::npos) _header[3] = true;
    if (!_header[0] || !_header[1] || !_header[2] || !_header[3])
        printf("\t-> Header Problem: Not Epitech Compliant\n");

    for (int i = 0; tab[i] != ""; i ++) {
        if (tab[i].find("//") != string::npos)
            printer_error("\t-> Info: Commantary !", i);
        else if (tab[i][0] != ' ' && tab[i][0] != '\t' && tab[i].find("Test") != string::npos)
            unit_test ++;
        else {
            if (tab[i].find(";;") != string::npos) printer_error("\t-> Info: \";;\"", i);
            if (tab[i].find("char*") != string::npos) printer_error("\t-> \"char*\" should be \"char *\"", i);
            if (tab[i].find(" ;") != string::npos) printer_error("\t-> \" ;\" do not need space before ;", i);
            if (tab[i].find("){") != string::npos) printer_error("\t-> Info: \'{\' should be separate by a space", i);
            if (tab[i][0] != ' ' && tab[i][0] != '\t' && tab[i].find("(") != string::npos) proto(tab, i);
            if (tab[i].find("\t") != string::npos) printer_error("\t-> Info: \"\t\" better to use \"    \" than a tab", i);
            if (tab[i].length() > 80) printer_error("\t-> Error: max line length " + to_string(tab[i].length())  + " > 80", i);
            if (!indent(tab[i])) printer_error("\t-> Error: Bad indentation", i);
            if (tab[i].find("static") != string::npos && tab[i].find("const") == string::npos && tab[i].find(";") != string::npos)
                printer_error("\t-> Static variable must be a constant", i);
        }
    }
    if (_functions > 5)
        printf("\t-> %d functions in the file, max norme complient it's 5.\n", _functions);
    return 0;
}