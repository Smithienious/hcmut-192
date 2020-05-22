#include <iostream>
#include <fstream>

using namespace std;

bool uniqueElement(int size, int *a, int i)
{
	//TODO
}

int main(int argc, char **argv)
{

	ifstream ifs;
	ifs.open(argv[1]);

	int size;
	ifs >> size;
	int i = 0;
	int *a = new int[size];
	try
	{

		while (ifs >> a[i])
		{
			i++;
		}
		cout << uniqueElement(size, a, 0) << endl;
	}
	catch (char const *s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	ifs.close();
	return 0;
}
