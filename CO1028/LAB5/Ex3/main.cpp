#include <iostream>
#include <fstream>
using namespace std;

ifstream ifs;

void readArray(int **a)
{
	for (int i = 0; i < 10; i += 1)
	{
		for (int j = 0; j < 10; j += 1)
		{
			ifs >> a[i][j];
			if (a[i][j] == 0)
				for (; j < 10; j += 1)
				{
					a[i][j] = 0;
				}
		}
	}
}

void printArray(int **a)
{
	for (int i = 0; i < 10; i += 1)
	{
		cout << a[i][0];
		for (int j = 1; j < 10; j += 1)
			cout << " " << a[i][j];
		cout << endl;
	}
}

int main(int argc, char **argv)
{
	ifs.open(argv[1]);

	int **arr;
	arr = new int *[10];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = new int[10];
	}

	readArray(arr);
	printArray(arr);

	for (int i = 0; i < 10; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;

	ifs.close();
	return 0;
}
