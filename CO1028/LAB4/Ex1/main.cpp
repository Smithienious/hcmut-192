#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

bool palindrome(char strg[], int j)
{
	//TODO
}

int main(int argc, char **argv)
{
	ifstream ifs;
	ifs.open(argv[1]);
	char strg[100];
	try
	{
		while (ifs.getline(strg, 100, '\n'))
		{
			cout << strg << " " << palindrome(strg, 0) << endl;
			if (strg[0] == '*')
				break;
		}
	}
	catch (char const *s)
	{
		printf("An exception occurred. Exception type: %s\n", s);
	}

	ifs.close();
	return 0;
}
