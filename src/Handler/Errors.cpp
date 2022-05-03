#include "Errors.hpp"

Errors::Errors() {}
Errors::~Errors() {}

void Errors::printer_error(string str, int line) {
    for (size_t i = str.length(); i < 75; i ++)
        str += " ";
    printf("%sl.%d\n", str.c_str(), line + 1);
}