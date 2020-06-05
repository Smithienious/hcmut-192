#include <iostream>
#include <fstream>

using namespace std;

// implement calculate factorial in here
// TODO
int calculateFactorial(int n)
{
    if (n > 1)
        n *= calculateFactorial(n - 1);
    else
        n = 1;
    return n;
}

int main(int argc, char **argv)
{
    ifstream ifs;
    ifs.open(argv[1]);
    int N;
    try
    {
        ifs >> N;
        long result;
        // call function calculateFactorial in here and assign value to the variable result
        // TODO
        result = calculateFactorial(N);
        cout << result << endl;
    }
    catch (char const *s)
    {
        printf("An exception occurred. Exception type: %s\n", s);
    }

    ifs.close();
    return 0;
}
