#include <vector>
#include <memory>

#include "Cpp.hpp"
#include "System.hpp"
#include "Errors.hpp"

Cpp::Cpp() {
    _unit_test = 0;
    _functions = 0;
}
Cpp::~Cpp() {}

string Cpp::find_function_name(string line) {
    string name = line;

    if (name.find("static ") != string::npos)
        name.replace(name.find("static "), sizeof("static ") - 1, "");
    if (name.find("(void)") != string::npos)
        name.replace(name.find("(void)"), sizeof("(void)") - 1, "");
    if (name.find("(") != string::npos && name.find(")") != string::npos)
        name = System().strtowordarray(name, "(")[0];
    if (System().strtowordarray(name, "(").size() > 1)
        name = System().strtowordarray(name, "(")[1];
    return name;
}

void Cpp::proto(vector<string> tab, int indexe) {
    int rem = 1;
    int i = indexe;

    if (tab[indexe].find(";") != string::npos)
        return;
    string fname = find_function_name(tab[i]);
    _functions ++;
    for (; tab[i] != "}" && tab[i] != ""; i ++)
        if (tab[i] == "{")
            rem ++;
    if (tab[i] == "}")
        rem ++;
    i -= rem;
    if (tab[indexe].find("{") != string::npos)
        i --;
    if (i - indexe > 20)
        printf("\t-> Too long functions \e[93m%s\e[0m (%d > 20).\n", fname.c_str(), i - indexe);
}

int Cpp::norminette_cpp(vector<string> tab) {
    _functions = 0;
    for (int i = 0; i < tab.size(); i ++) {
        if (tab[i].find("//") != string::npos)
            Errors().printer_error("\t-> Info: Commantary !", i);
        else if (tab[i][0] != ' ' && tab[i][0] != '\t' && tab[i].find("Test") != string::npos)
            _unit_test ++;
        else {
            if (tab[i].find(";;") != string::npos)
                Errors().printer_error("\t-> Info: \";;\"", i);
            if (tab[i].find("char **") == string::npos && tab[i].find("char *") != string::npos)
                Errors().printer_error("\t-> \"char *\" must be a \"string\"", i);
            if (tab[i].find(" ;") != string::npos)
                Errors().printer_error("\t-> \" ;\" do not need space before ;", i);
            if (tab[i].find("){") != string::npos)
                Errors().printer_error("\t-> Info: \'{\' should be separate by a space", i);
            if (tab[i].find("\t") != string::npos)
                Errors().printer_error("\t-> Info: \"\t\" better to use \"    \" than a tab", i);
            if (tab[i].find(" == true") != string::npos)
                Errors().printer_error("\t-> Info: \" == true\" not usefull", i);
            if (tab[i].find(" == false") != string::npos)
                Errors().printer_error("\t-> Info: \" == false\" can be replace with a \'!\' before condition", i);
            if (tab[i][0] != ' ' && tab[i][0] != '\t' && tab[i].find("(") != string::npos)
                proto(tab, i);
        }
    }
    return 0;
}