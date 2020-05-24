#include <iostream>
#include <fstream>

using namespace std;

int linearSearch(int *a, int key, int sizeofArray)
{
	int result = 0;

	if (sizeofArray > 0)
		if (key != *(a + sizeofArray - 1))
			result = linearSearch(a, key, sizeofArray - 1);
		else
			result = sizeofArray - 1;
	else
		result = -1;

	return result;
}

// you should remove element in array
// function return array
int *removeElement(int *a, int &n, int position)
{
	int temp;
	n -= 1;

	for (int i = position; i < n; i += 1)
	{
		temp = a[i];
		a[i] = a[i + 1];
		a[i + 1] = temp;
	}

	return a;
}

int main(int argc, char **argv)
{
	ifstream ifs;
	ifs.open(argv[1]);

	int N, M, position;
	ifs >> N;
	ifs >> M;
	ifs >> position;
	int i = 0;
	int *a = new int[N];
	try
	{

		while (ifs >> a[i])
		{
			i++;
		}
		cout << linearSearch(a, M, N) << endl;
		int *newA = removeElement(a, N, position);
		for (int i = 0; i < N; i++)
		{
			cout << newA[i] << " ";
		}
		cout << endl;
	}
	catch (char const *s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	ifs.close();
	return 0;
}
