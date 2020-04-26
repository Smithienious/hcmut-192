#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

bool ArmstrongNum(int n){
    int step = 0;
    while (n / std::pow(10, step) >= 10)
    {
        step += 1;
    }

    int digit[step + 1], sum = 0, N = n;
    for (int i = step; i >= 0; i -= 1)
    {
        digit[i] = N / std::pow(10, i);
        N -= digit[i] * std::pow(10, i);
        sum += std::pow(digit[i], step + 1);
    }

    return sum == n;
}

int main(int arg, char** argv){
    ifstream ifs;
	ifs.open(argv[1]);
	int N;
	try
	{
		ifs >> N;
        printf("%s\n", ArmstrongNum(N)?"true":"false");
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	ifs.close();
	return 0;
}