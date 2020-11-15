#include <stdio.h>
#include <iostream>

#include "prototype.hpp"

static bool flags_check(std::string str) {
    if (str == "-usage")
        usage();
    else if (str == "-version")
        version();
    else
        return false;
    return true;
}

int main(int ac, char **av, char **env) {
    if (ac > 2)
        return usage();
    else if (ac == 2 && !flags_check(av[1]));

    normimain(ac, av);
    return 0;
}