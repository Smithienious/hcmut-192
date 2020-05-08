#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void printOrder(char *str1, char *str2, char *str3)
{
	// TODO
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