/*****Version 1.1***********/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
using namespace std;

//read data from input file to corresponding variables
//return 1 if successfully done, otherwise return 0
int readFile(const char* filename, int& baseHP1,int& baseHP2,int& wp1,int& wp2,int& ground)
{
	ifstream in;
	in.open(filename);
	
	if (!in.good()) return 0;

	in >> baseHP1;
	in >> wp1;
	in >> baseHP2;
	in >> wp2;
	in >> ground;

	in.close();

	if (baseHP1 < 99 || baseHP1 > 999)
		return 0;
	if (wp1 < 0 || wp1 > 3)
		return 0;
	if (baseHP2 < 1 || baseHP2 > 888)
		return 0;
	if (wp2 < 0 || wp2 > 3)
		return 0;
	if (ground < 1 || ground > 999)
		return 0;

	return 1;

}

// TODO: Your code goes here
bool isPrime(int n){
	bool result = true;

	if (n < 2)
		result = false;
	else{
		for (int i = 2; i < sqrt(n) + 1; i += 1){
			if (n % i == 0){
				result =  false;
				break;
			}
		}
	}

	return result;
}

void display(float fOut)
// display value of fOut in format of 0.XX
// no exception handled
{
	if (fOut == 1){
		cout << fOut;
	}
	else{
		char s[10];
		sprintf(s,"%.2f",fOut);
		cout << s;
	}
}


int main(int argc, char** argv)
{
	if (argc < 2) return 1;

	const char* filename = argv[1];
	cout << filename << endl;

	int baseHP1,baseHP2,wp1,wp2,ground;
	float fOut = 0.0;
	readFile(filename, baseHP1, baseHP2, wp1, wp2, ground);
	
	// TODO: Your code goes here
	float realHP1, realHP2;

	// Paladin
	bool isPaladin1 = isPrime(baseHP1);
	bool isPaladin2 = isPrime(baseHP2);

	// Weapon of choice
	if (wp1 == 3 && wp2 == 2){ wp2 = 1; }

	// Knights of the Round Table
	switch (wp1){
		case 0:
			realHP1 = round(baseHP1 / 10);
			break;
		case 1:
		case 2:
		case 3:
			realHP1 = baseHP1;
			break;
	}

	if (ground == baseHP1){
		realHP1 *= 1.1;
		if (realHP1 > 999){ realHP1 = 999; }
	}

	if (wp1 == 3){
		realHP1 *= 2;
		if (realHP1 > 999){ realHP1 = 999; }
	}

	// Saxon warrior
	switch (wp2){
		case 0:
			realHP2 = round(baseHP2 / 10);
			break;
		case 1:
		case 2:
		case 3:
			realHP2 = baseHP2;
			break;
	}

	if (ground == baseHP2){
		realHP2 *= 1.1;
		if (realHP2 > 999){ realHP2 = 999; }
	}

	// Calculate probability value
	fOut = (realHP1 - realHP2 + 999) / 2000;

	if (wp1 == 2 && realHP1 < realHP2){ fOut = 0.5; }
	if (wp2 == 2 && realHP2 < realHP1){ fOut = 0.5;	}

	if (isPaladin1 && isPaladin2){
		if (baseHP1 > baseHP2){ fOut = 0.99; }
		else if (baseHP1 == baseHP2){ fOut = 0.5; }
		else fOut = 0.01;
	}
	else if (isPaladin1){ fOut = 0.99; }
	else if (isPaladin2){ fOut = 0.01; }

	if (baseHP2 == 888){ fOut = 0; }
	if (baseHP1 == 999){ fOut = 1; }

	display(fOut);

	return 0;
}
