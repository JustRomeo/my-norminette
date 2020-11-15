#ifndef __H__
#define __H__

#include <vector>
#include <iostream>

using namespace std;
class H {
    public:
        H();
        ~H();

        int norminette_h(vector<string> tab);

    private:
        bool shield;
        bool _header[4];
        size_t _unit_test;

    protected:
};

#endif