#include <iostream>
#include <fstream>

using namespace std;

bool completeNum(int N)
{
    int sum = 0;
    for (int i = 1; i <= N; i += 1)
        if (N % i == 0)
            sum += i;
    return sum == 2 * N;
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
