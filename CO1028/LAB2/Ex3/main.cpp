#include <iostream>
#include <fstream>

using namespace std;

void averageValue(int n, double *a) {
	double sum = 0;

	for (int i = 0; i < n; i+= 1)
		sum += *(a + i);

	cout << sum / n << endl;
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
		averageValue(size, a);
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	ifs.close();
	return 0;
}
