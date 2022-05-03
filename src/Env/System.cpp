#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/sysmacros.h>

#include "System.hpp"

System::System() {}
System::~System() {}

static bool isDelimiter(char c, string delimiter) {
    return c == delimiter[0] ? true : false;
}

vector<string> System::strtowordarray(string str, string delimiter) {
    int pos = 0;
    string save;
    int length = 0;
    vector<string> av;
    bool split = false;

    for (int i = 0; str[i]; i ++) {
        if (split && isDelimiter(str[i], delimiter)) {
            save = str.substr(pos, length);
            av.push_back(save);
            pos = 0;
            length = 0;
            split = false;
        } else if (!split && !isDelimiter(str[i], delimiter)) {
            split = !split;
            pos = i;
        } if (split)
            length ++;
    } if (length != 0) {
        save = str.substr(pos, length);
        av.push_back(save);
    }
    return (av);
}

vector<string> System::openfile(string filepath) {
    string line;
    ifstream file;
    vector<string> load;

    file.open(filepath);
    if (!file.is_open())
        throw (Exception("Can't open file to load"));
    while (getline(file, line))
        load.push_back(line);
    file.close();
    line.clear();
    return (load);
}

bool System::execution(string command) {
    pid_t pid = fork();
    vector<string> argv = this->strtowordarray(command, " ");
    int status = 0;

    if (pid == -1) {
        exit(0);
        return 84;
    } else if (pid == 0) {
        if (!(access(argv[0].c_str(), F_OK) != -1)) {
            cout << argv[0].c_str() << ": Command not found" << endl;
            exit(0);
            return (0);
        } if (system(command.c_str()) == -1) {
            cout << argv[0].c_str() << ": Permission Denied" << endl;
            exit (0);
        }
    } if (pid >= 0) {
        waitpid(pid, &status, 0);
        if ((WIFSIGNALED(status)))
            cout << "En gros y'a un problème" << endl;
            // cout << strsignal(WTERMSIG(status)) << endl;
    }
    return 0;
}