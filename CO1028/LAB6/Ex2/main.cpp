#include <iostream>
#include <fstream>
using namespace std;
bool completeNum(int N)
{
    // TODO
}

int main(int argc, char **argv)
{
    ifstream ifs;
    ifs.open(argv[1]);
    int N;
    try
    {
        while (ifs >> N)
        {
            cout << completeNum(N) << endl;
        }
    }
    catch (char const *s)
    {
        printf("An exception occurred. Exception type: %s\n", s);
    }

    ifs.close();
    return 0;
}
