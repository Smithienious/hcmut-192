#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

ifstream ifs;

int main(int argc, char **argv)
{
    ifs.open(argv[1]);

    char str1[100];
    char str2[100];

    ifs.get(str1, 100, '\n');
    ifs.ignore(100, '\n');
    ifs.get(str2, 100, '\n');
    ifs.ignore(100, '\n');

    char *pos = strstr(str1, str2);
    if (pos == NULL)
        cout << "Not found";
    else
    {
        pos += strlen(str2);

        for (int i = 0; *(pos + i) != NULL; i += 1)
            cout << *(pos + i);
    }

    cout << endl;

    ifs.close();
    return 0;
}