#include "Errors.hpp"
#include "Haskell.hpp"

Haskell::Haskell() {}
Haskell::~Haskell() {}

int Haskell::norminette_haskell(vector<string> tab) {
    for (size_t i = 0; tab[i] != ""; i ++) {
        if (tab[i].length() > 80)
            Errors().printer_error("\t-> Error: max line length " + to_string(tab[i].length())  + " > 80", i + 1);
        if (tab[i].find("\t") != string::npos)
            Errors().printer_error("\t-> Info: \"\t\" better to use \"    \" than a tab", i);
        if (tab[i].find("<-getargs") != string::npos)
            Errors().printer_error("\t-> Info: \"<-getargs\" need to have a space after \'-\'", i);
        if (tab[i].find(" :: ") == string::npos && tab[i].find("::") != string::npos)
            Errors().printer_error("\t-> Info: \"::\" should have an space before and after, like \" :: \" than a tab", i);
    }
    return 0;
}