#ifndef __Cpp__
#define __Cpp__

#include <vector>
#include <iostream>

using namespace std;
class Cpp {
    public:
        Cpp();
        ~Cpp();

        string find_function_name(string);
        int norminette_cpp(vector<string> tab);
        void proto(vector<string> tab, int indexe);

    private:
        size_t _unit_test;
        size_t _functions;

    protected:
};

#endif