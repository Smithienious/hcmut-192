#include <iostream>
#include <fstream>

using namespace std;

void maxValue(int n, double *a) {
	double max = -1000000000;

	for (int i = 0; i < n; i+= 1)
		if (*(a + i) > max)
			max = *(a + i);

	cout << max << endl;
}

int main(int argc, char** argv)
{
	ifstream ifs;
	ifs.open(argv[1]);

	int size;
	ifs >> size;
	ifs.ignore(1, '\n');
    int i = 0;
	double *a = new double[size];
	try {

		while (ifs >> a[i])
		{
			i++;
		}
		maxValue(size, a);
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	ifs.close();
	return 0;
}
