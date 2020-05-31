#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

#define MAX_LEN 200

void removeLastSubString(char *str, char *sub)
{
	if (strstr(str, sub) == NULL)
		return;

	char *pos = strstr(str, sub);

	while (strstr(pos + 1, sub) != NULL)
	{
		pos = strstr(pos + 1, sub);
	}

	if (pos != NULL)
		memmove(pos, pos + strlen(sub), strlen(str) - strlen(sub));
}

int main(int argc, char **argv)
{
	ifstream ifs;
	ifs.open(argv[1]);

	char str1[MAX_LEN];
	char str2[MAX_LEN];

	ifs.get(str1, MAX_LEN, '\n');
	ifs.ignore(MAX_LEN, '\n');
	ifs.get(str2, MAX_LEN, '\n');
	ifs.ignore(MAX_LEN, '\n');

	removeLastSubString(str1, str2);
	cout << str1 << endl;
	ifs.close();
	return 0;
}
