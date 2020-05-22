#include <iostream>
#include <fstream>

using namespace std;

int permutation(int n, int m)
{
	//TODO
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
