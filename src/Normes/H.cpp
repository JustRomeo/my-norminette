#include "H.hpp"
#include "Errors.hpp"

H::H() {
    shield = false;
    _unit_test = 0;
    for (size_t i = 0; i < 4; i ++)
        _header[i] = false;
}
H::~H() {}

int H::norminette_h(vector<string> tab) {
    if (tab[0] == "" || tab[1] == "" || tab[2] == "" || tab[3] == "" || tab[4] == "" || tab[5] == "" || tab[6] == "")
        printf("\t-> Header Problem: Not Epitech Compliant\n");
    if (tab[0].find("/*") != string::npos)
        _header[0] = true;
    if (tab[1].find("** EPITECH PROJECT, ") != string::npos)
        _header[1] = true;
    if (tab[3].find("** File description:") != string::npos)
        _header[2] = true;
    if (tab[5].find("*/") != string::npos)
        _header[3] = true;
    if (!_header[0] || !_header[1] || !_header[2] || !_header[3])
        printf("\t-> Header Problem: Not Epitech Compliant\n");

    for (int i = 0; i < tab.size(); i ++) {
        if (tab[i].find("#ifndef") != string::npos && tab[i + 1].find("#define") != string::npos)
            shield = true;
        if (tab[i].find("\t") != string::npos)
            Errors().printer_error("\t-> Info: \"\\t\" better to use \"    \" than a tab", i);
        if (tab[i].length() > 80)
            Errors().printer_error("\t-> Error: max line length " + to_string(tab[i].length())  + " > 80", i);
    } if (!shield)
        printf("\t-> Info: no protection on prototype file, better to protect it.\n");
    return 0;
}