#include <iostream>
#include <fstream>
using namespace std;

void print_primenum(int l, int r){
	bool result = false;

	l = (l < 2) ? 2 : l;

	for (int i = l; i < r && !result; i += 1)
	{
		result = true;
		for (int j = 2; j < i && result; j += 1)
			if (i % j == 0)
				result = false;
		if (result)
		{
			cout << i;
			l = i + 1;
		}
	}

	for (int i = l; i < r; i += 1)
	{
		result = true;
		for (int j = 2; j < i && result; j += 1)
			if (i % j == 0)
				result = false;

		if (result)
			cout << " " << i;
	}

	cout << "\n";
}

int main(int arg, char** argv){
    ifstream ifs;
	ifs.open(argv[1]);
	int l, r;
	try
	{
		ifs >> l >> r;
        print_primenum(l , r);
	}
	catch (char const* s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	ifs.close();
	return 0;
}