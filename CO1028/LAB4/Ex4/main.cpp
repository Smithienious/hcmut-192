#include <iostream>
#include <fstream>

using namespace std;

int permutation(int n, int m)
{
	int result = 0;
	if (n == m || m == 0)
		result = 1;
	else
		result = permutation(n - 1, m) + permutation(n - 1, m - 1);

	return result;
}

int main(int argc, char **argv)
{
	ifstream ifs;
	ifs.open(argv[1]);
	int N;
	int M;
	try
	{
		ifs >> N;
		ifs >> M;
		cout << permutation(N, M) << endl;
	}
	catch (char const *s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	ifs.close();
	return 0;
}
