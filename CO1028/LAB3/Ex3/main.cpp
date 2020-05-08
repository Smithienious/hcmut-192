#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

ifstream ifs;

int main(int narg, char **argv)
{
    ifs.open(argv[1]);

    char str1[100];
    char str2[100];

    ifs.get(str1, 100, '\n');
    ifs.ignore(100, '\n');
    ifs.get(str2, 100, '\n');
    ifs.ignore(100, '\n');

    // TODO

    ifs.close();
    return 0;
}