#ifndef __SYSTEM__
#define __SYSTEM__

#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

#include "Exception.hpp"

using namespace std;
class System {
    public:
        System();
        ~System();

        void savefile(string filepath);
        bool execution(string filepath);
        vector<string> openfile(string filepath);
        vector<string> strtowordarray(string str, string delimiter);

    private:
};

#endif