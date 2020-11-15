#include "Hpp.hpp"
#include "Errors.hpp"

Hpp::Hpp() {
    classe = 0;
    shield = false;
}
Hpp::~Hpp() {}

int Hpp::norminette_hpp(vector<string> tab) {
    bool goType = false;
    bool types[3] = {false, false, false};

    classe = 0;
    for (int i = 0; tab[i] != ""; i ++) {
        if (tab[i].find("class") != string::npos && tab[i].find("{") != string::npos)
            classe ++;
        if (tab[i].find("#ifndef") != string::npos && tab[i + 1].find("#define") != string::npos)
            shield = true;
        if (tab[i].find("\t") != string::npos)
            Errors().printer_error("\t-> Info: \"\t\" better to use \"    \" than a tab", i);
        if (tab[i].find("public:") != string::npos)
            types[0] = true;
        if (tab[i].find("private:") != string::npos)
            types[1] = true;
        if (tab[i].find("protected") != string::npos)
            types[2] = true;
    }

    if (classe > 1)
        printf("\t-> Error: only one class per file is allow, there are %d class in the file.\n", classe);
    for (size_t i = 0; i < 4; i ++)
        if (!types[i])
            goType = true;
    if (classe > 0 && goType)
        printf("\t-> Info: Even empty, a class should contain \"public\", \"private\" and \"protected\" variable and function types.\n");
    if (!shield)
        printf("\t-> Info: no protection on prototype file, better to protect it.\n");
    return 0;
}