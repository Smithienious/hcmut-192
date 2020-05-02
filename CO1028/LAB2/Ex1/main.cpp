#include <iostream>
#include <fstream>

using namespace std;

void Fibonacci(int n) {
    int arr[n + 1];
    arr[0] = 0; arr[1] = 1; arr[2] = 1;

    for (int i = 2; i <= n; i += 1)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    cout << arr[n] << endl;
}

int main(int argc, char** argv)
{
	ifstream ifs;
	ifs.open(argv[1]);
	int a;
	try
	{
		while (ifs >> a)
		{
			Fibonacci(a);
		}
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	ifs.close();
	return 0;
}
