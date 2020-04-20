#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <math.h>

using namespace std;

const int MADBEAR = 1;
const int BANDIT = 2;
const int EVENT_SIZE = 100;
const int MAX_CHARACTER_EACH_LINE = 250;

struct knight
{
   int HP;
   int level;
   int remedy;
   int maidenkiss;
   int phoenixdown;
};

// read data from input file to corresponding variables
// return 1 if successfully done, otherwise return 0
int readFile(const char* filename, knight& theKnight, int& nEvent, int* arrEvent)
{
	const char* file_name = "14.txt";
	FILE* f = 0;
	char* str = new char[MAX_CHARACTER_EACH_LINE];
	int num;

	f = fopen(file_name, "r");
	if (f == NULL)	//file not found || cannot read
		return 0;

	fgets(str, MAX_CHARACTER_EACH_LINE, f);
	if (feof(f))
		return 0;

	int start = 0;
	int len = strlen(str);
	// read HP
	while (start < len && str[start] == ' ')
		start ++;
	num = 0;
	while (start < len && str[start] <= '9' && str[start] >= '0'){
		num = num * 10 + str[start] - '0';
		start++;
	}
	theKnight.HP = num;
	if (theKnight.HP < 1 || theKnight.HP > 999)
		return 0;

	// read level
	while (start < len && (str[start] > '9' || str[start] < '0'))
		start ++;
	num = 0;
	while (start < len && str[start] <= '9' && str[start] >= '0'){
		num = num * 10 + str[start] - '0';
		start++;
	}
	theKnight.level = num;
	if (theKnight.level < 1 || theKnight.level > 10)
		return 0;

	// read remedy
	while (start < len && (str[start] > '9' || str[start] < '0'))
		start ++;
	num = 0;
	while (start < len && str[start] <= '9' && str[start] >= '0'){
		num = num * 10 + str[start] - '0';
		start++;
	}
	theKnight.remedy = num;
	if (theKnight.remedy < 0 || theKnight.remedy > 99)
		return 0;

	// read maidenkiss
	while (start < len && (str[start] > '9' || str[start] < '0'))
		start ++;
	num = 0;
	while (start < len && str[start] <= '9' && str[start] >= '0'){
		num = num * 10 + str[start] - '0';
		start++;
	}
	theKnight.maidenkiss = num;
	if (theKnight.maidenkiss < 0 || theKnight.maidenkiss > 99)
		return 0;

	// read phoenixdown
	while (start < len && (str[start] > '9' || str[start] < '0'))
		start ++;
	num = 0;
	while (start < len && str[start] <= '9' && str[start] >= '0'){
		num = num * 10 + str[start] - '0';
		start++;
	}
	theKnight.phoenixdown = num;
	if (theKnight.phoenixdown < 0 || theKnight.phoenixdown > 99)
		return 0;

	// read events
	nEvent = 0;
	while (1){
		if (feof(f))
			break;
		fgets(str, MAX_CHARACTER_EACH_LINE, f);
		if (str == NULL)
			break;
		start = 0;
		len = strlen(str);
    // cout << "\'" << str << "\'" << "\t" << len << endl;
		while (start < len){
			while (start < len && (str[start] > '9' || str[start] < '0'))
				start++;
			if (start >= len)
				break;
			arrEvent[nEvent] = 0;
			while (start < len && str[start] <= '9' && str[start] >= '0'){
				arrEvent[nEvent] = arrEvent[nEvent] * 10 + str[start] - '0';
				start++;
			}
			nEvent++;
		}
    delete[] str;
	}
	fclose(f);
	return 1;
}

void display(int* nOut)
{
  if (nOut)
    cout << *nOut;
  else
    cout << "Error!";
}


int main(int argc, char** argv)
{
    //if (argc < 2) return 1;
    const char* filename = argv[1];;

   struct knight theKnight;
   int nEvent; //number of events
   int* arrEvent = new int[EVENT_SIZE]; // array of events
   int* nOut;                           // final result
   int i;

	readFile(filename, theKnight, nEvent, arrEvent);
	//cout << theKnight.HP << ' ' << theKnight.level << ' ' << theKnight.remedy << ' ' << theKnight.maidenkiss << ' ' << theKnight.phoenixdown << endl;

	int b, levelO, damage, N, levelFrog;
	int maxHP = theKnight.HP, isTiny = 5, isFrog = 5;
	float baseDamage;
	bool isEnded, hasExcalibur, hasMythril, hasExcalipoor;
	for (i = 0; i < nEvent; i++)
	{
		int theEvent = arrEvent[i];
		//cout << theEvent << endl;
		switch (theEvent)
		{
		case 0:
			// Bowser surrendered
			i = nEvent;
		break;

		case MADBEAR:
			// Meet MadBear
			baseDamage = 1;
			b = (i + 1) % 10;
			levelO = i > 6 ? (b > 5 ? b : 5) : b;
			damage = baseDamage * levelO * 10;

			if ((theKnight.level > levelO || hasExcalibur) && !hasExcalipoor)
				theKnight.level += theKnight.level < 10 ? 1 : 0;
			if (theKnight.level < levelO && (!hasMythril || hasExcalipoor))
				theKnight.HP -= damage;
		break;

		case BANDIT:
			// Meet Bandit
			baseDamage = 1.5;
			b = (i + 1) % 10;
			levelO = i > 6 ? (b > 5 ? b : 5) : b;
			damage = baseDamage * levelO * 10;

			if ((theKnight.level > levelO || hasExcalibur) && !hasExcalipoor)
				theKnight.level += theKnight.level < 10 ? 1 : 0;
			if (theKnight.level < levelO && (!hasMythril || hasExcalipoor))
				theKnight.HP -= damage;
		break;

		case 3:
			// Meet Lord Lupine
			baseDamage = 4.5;
			b = (i + 1) % 10;
			levelO = i > 6 ? (b > 5 ? b : 5) : b;
			damage = baseDamage * levelO * 10;

			if ((theKnight.level > levelO || hasExcalibur) && !hasExcalipoor)
				theKnight.level += theKnight.level < 10 ? 1 : 0;
			if (theKnight.level < levelO && (!hasMythril || hasExcalipoor))
				theKnight.HP -= damage;
		break;

		case 4:
			// Meet Elf
			baseDamage = 6.5;
			b = (i + 1) % 10;
			levelO = i > 6 ? (b > 5 ? b : 5) : b;
			damage = baseDamage * levelO * 10;

			if ((theKnight.level > levelO || hasExcalibur) && !hasExcalipoor)
				theKnight.level += theKnight.level < 10 ? 1 : 0;
			if (theKnight.level < levelO && hasMythril || hasExcalipoor)
				theKnight.HP -= damage;
		break;

		case 5:
			// Meet Troll
			baseDamage = 8.5;
			b = (i + 1) % 10;
			levelO = i > 6 ? (b > 5 ? b : 5) : b;
			damage = baseDamage * levelO * 10;

			if ((theKnight.level > levelO || hasExcalibur) && !hasExcalipoor)
				theKnight.level += theKnight.level < 10 ? 1 : 0;
			if (theKnight.level < levelO && (!hasMythril || hasExcalipoor))
				theKnight.HP -= damage;
		break;

		case 6:
			// Meet Shaman
			if (isFrog <= 3 || isTiny <= 3){ break; }
			b = (i + 1) % 10;
			levelO = i > 6 ? (b > 5 ? b : 5) : b;

			if (theKnight.level > levelO)
			{
				theKnight.level += theKnight.level < 10 ? 2 : 0;
				if (theKnight.level > 10){ theKnight.level = 10; }
			}
			if (theKnight.level < levelO || hasExcalipoor)
			{
				isTiny = 0;
				theKnight.HP = round(theKnight.HP / 5);

				if (theKnight.remedy >= 1)
				{
					theKnight.remedy -= 1;
					isTiny = 3;
				}
			}

			if (theKnight.HP < 5)
			{
				theKnight.HP = 1;
			}
		break;

		case 7:
			// Meet Siren Vajsh
			if (isFrog <= 3 || isTiny <= 3){ break; }
			b = (i + 1) % 10;
			levelO = i > 6 ? (b > 5 ? b : 5) : b;

			if (theKnight.level > levelO)
			{
				theKnight.level += theKnight.level < 10 ? 2 : 0;
				if (theKnight.level > 10) { theKnight.level = 10; }
			}
			if (theKnight.level < levelO || hasExcalipoor)
			{
				isFrog = 0;
				levelFrog = theKnight.level;
				theKnight.level = 1;

				if (theKnight.maidenkiss >= 1)
				{
					theKnight.maidenkiss -= 1;
					isFrog = 3;
				}
			}

			if (theKnight.HP <= 0 && theKnight.phoenixdown >= 1)
			{
				theKnight.phoenixdown -= 1;
				theKnight.HP = maxHP;
			}
		break;

		case 8:
			// Obtain Excalibur sword
			hasExcalibur = true;
		break;

		case 9:
			// Obtain Mythril armor
			hasMythril = true;
		break;

		case 10:
			//  Obtain Excalipoor sword
			if (theKnight.level < 5)
			{
				hasExcalibur = false;
				hasExcalipoor = true;
			}
		break;

		case 11:
			// Obtain mushroom of MushMario
			theKnight.HP += 50;
		break;

		case 12:
			// Obtain mushroom of Fibonacci MushFib
		break;

		case 13:
			// Obtain ghost mushroom of MushGhost
		break;

		case 14:
			// Obtain mushroom of MushKnight
		break;

		case 15:
			// Obtain Remedy
		break;

		case 16:
			// Obtain MaidenKiss
		break;

		case 17:
			// Obtain PhoenixDown
		break;

		case 18:
			// Meet Merlin the Wizard
		break;

		case 19:
			// Fall into the Abyss
		break;

		case 20:
			// Meet the princess Guinevere
		break;

		case 21:
			// Obtain wings of Lightwing
		break;

		case 22:
			// Meet Odin
		break;
		
		case 23:
			// Obtain Dragon Sword
		break;

		case 99:
			// Meet Bowser
		break;
		}

		// Tiny knight
		if (isTiny == 3)
		{
			theKnight.HP *= 5;
			if (theKnight.HP > maxHP){ theKnight.HP = maxHP; }
		}
		if (isTiny < 5){ isTiny += 1; }

		// Frog knight
		if (isFrog == 3){ theKnight.level = levelFrog; }
		if (isFrog < 5){ isFrog += 1; }

		// HP analysing
		if (theKnight.HP <= 0)
		{
			if (theKnight.phoenixdown <= 0)
			{
				isEnded = true;
				N = -1;
				i = nEvent;
			}
			else
			{
				theKnight.HP = maxHP;
				theKnight.phoenixdown -= 1;
			}
		}

		if (theKnight.HP > maxHP){ theKnight.HP = maxHP; }
	}

	if (!isEnded)
		N = theKnight.HP + theKnight.level + theKnight.remedy + theKnight.maidenkiss + theKnight.phoenixdown;
	nOut = &N;
	display(nOut);
	return 0;
}
