#include <iostream>
#include <fstream>

using namespace std;

int gcd(int p, int q)
{
	//TODO
}

int main(int argc, char** argv)
{
	ifstream ifs;
	ifs.open(argv[1]);
	int p;
	int q;
	try
	{
		ifs >> p;
		ifs >> q;
		cout << gcd(p, q) << endl;
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	ifs.close();
	return 0;
}
