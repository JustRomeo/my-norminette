#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

static string *strtowordarray(string str) {
    string *tab;
    string token;
    size_t pos = 0;
    int mallok = 0;
    int indexe = 0;
    string delimiter = "\n";

    for (int z = 0; z < str.length(); z ++)
        if (str[z] == '\n')
            mallok ++;
    tab = new string[mallok + 1];
    for (; (pos = str.find(delimiter)) != string::npos; indexe ++) {
        token = str.substr(0, pos);
        if (token == "")
            tab[indexe] = " ";
        else tab[indexe] = token;
        str.erase(0, pos + delimiter.length());
    }
    return tab;
}

string *openFile(string str) {
    string *tab;
    string file;
    ifstream src (str);

    if (src.is_open()) {
        getline(src, file, '\0');
        tab = strtowordarray(file);
    } else {
        cerr << "Error: " << str << ": No such file or directory" << endl;
        return NULL;
    }
    src.close();
    return tab;
}