#include "Python.hpp"
#include "Errors.hpp"

Python::Python() {}
Python::~Python() {}

void Python::norminette_python(vector<string> tab) {
    for (int i = 0; i < tab.size(); i ++) {
        if (tab[i].find("#") != string::npos)
            Errors().printer_error("\t-> Info: Commantary !", i);
        else {
            if (tab[i].find(";;") != string::npos)
                Errors().printer_error("\t-> Info: \";\" not necessary in Python", i);
        }
    }
}