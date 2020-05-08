#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void printOrder(char *str1, char *str2, char *str3)
{
	if (strcmp(str1, str2) < 0)
	{
		if (strcmp(str1, str3) < 0)
		{
			cout << str1 << endl;
			if (strcmp(str2, str3) < 0)
			{
				cout << str2 << endl;
				cout << str3 << endl;
			}
			else
			{
				cout << str3 << endl;
				cout << str2 << endl;
			}
		}
		else
		{
			cout << str3 << endl;
			cout << str1 << endl;
			cout << str2 << endl;
		}
	}
	else
	{
		if (strcmp(str2, str3) < 0)
		{
			cout << str2 << endl;
			if (strcmp(str1, str3) < 0)
			{
				cout << str1 << endl;
				cout << str3 << endl;
			}
			else
			{
				cout << str3 << endl;
				cout << str1 << endl;
			}
		}
		else
		{
			cout << str3 << endl;
			cout << str2 << endl;
			cout << str1 << endl;
		}
	}
}

int main(int argc, char **argv)
{
	ifstream ifs;
	ifs.open(argv[1]);

	char str1[100];
	char str2[100];
	char str3[100];

	ifs.get(str1, 100, '\n');
	ifs.ignore(100, '\n');
	ifs.get(str2, 100, '\n');
	ifs.ignore(100, '\n');
	ifs.get(str3, 100, '\n');
	ifs.ignore(100, '\n');

	printOrder(str1, str2, str3);

	ifs.close();
	return 0;
}