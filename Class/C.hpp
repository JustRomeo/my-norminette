#ifndef __C__
#define __C__

#include <vector>
#include <iostream>

using namespace std;
class C {
    public:
        C();
        ~C();

        string find_function_name(string);
        int norminette_c(vector<string> tab);
        void proto(vector<string> tab, int indexe);

    private:
        bool _header[4];
        size_t _unit_test;
        size_t _functions;

    protected:
};

#endif