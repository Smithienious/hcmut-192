/*****Version 1.1***********/
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <math.h>

//read data from input file to corresponding variables
//return 1 if successfully done, otherwise return 0
int readFile(int& baseHP1,int& baseHP2,int& wp1,int& wp2,int& ground)
{
	char const *file_name = "input.txt";
	std::ifstream in;
	in.open(file_name);
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
	in.close();
	return 1;
}

void display(float fOut)
//display value of fOut in format of 0.XX
// no exception handled
{
	if (fOut == 1){
		std::cout << fOut;
	}
	else{
		char s[10];
		sprintf(s,"%.2f",fOut);
		std::cout << s;
	}
}


int main(void)
{
	int baseHP1,baseHP2,wp1,wp2,ground;
	float fOut = 0.0;
	readFile(baseHP1,baseHP2,wp1,wp2,ground);
	
	//write your code here
	float realHP1, realHP2;

	// Paladin
	bool isPaladin1 = true, isPaladin2 = true;

	for (int i = 2; i < sqrt(baseHP1) + 1; i++){
		if (baseHP1 % i == 0){
			isPaladin1 = false;
			break;
		}
	}

	for (int i = 2; i < sqrt(baseHP2) + 1; i++){
		if (baseHP2 % i == 0){
			isPaladin2 = false;
			break;
		}
	}

	// Weapon of choice
	if (wp1 == 3 && wp2 == 2){ wp2 = 1; }

	// Knights of the Round Table
	switch (wp1){
		case 0:
			realHP1 = round(baseHP1 / 10.0);
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

	if (wp1 == 2 && realHP1 < realHP2){
		fOut = 0.5;
	}

	if (wp2 == 2 && realHP2 < realHP1){
		fOut = 0.5;
	}

	if (isPaladin1 && isPaladin2){
		if (baseHP1 > baseHP2){ fOut = 0.99; }
		else if (baseHP1 == baseHP2){ fOut = 0.5; }
		else fOut = 0.01;
	}
	else if (isPaladin1){ fOut = 0.99; }
	else if (isPaladin2){ fOut = 0.01; }

	if (baseHP2 == 888 && baseHP1 != 999){ fOut = 0; }
	if (baseHP1 == 999){ fOut=1; }

	display(fOut);

	return 0;
}
