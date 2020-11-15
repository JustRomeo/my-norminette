#include "Errors.hpp"
#include "ASM.hpp"

ASM::ASM() {}
ASM::~ASM() {}

int ASM::norminette_asm(vector<string> tab) {
    for (int i = 0; i < tab.size(); i ++) {
        if (tab[i].find("\t") != string::npos)
            Errors().printer_error("/!\\ Info: \"\t\" better to use \"    \" than a tab", i);
    }
    return 0;
}