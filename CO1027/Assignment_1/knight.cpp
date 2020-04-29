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
	const char* file_name = filename;
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

// Test for Paladin
bool isPrime(int n)
{
	bool result = true;

	if (n < 2)
		result = false;
	else
		for (int i = 2; i < sqrt(n) + 1; i += 1)
		{
			if (n % i == 0)
			{
				result =  false;
				break;
			}
		}

	return result;
}

// Test for Dragon Knight
bool canKnight(int C)
{
	int x = 1;
	bool result = false;
	float y;

	while (x < C/2 && !result)
	{
		y = (2.0 * C * x - C * C) / (2.0 * (x - C));

		if (y != int(y))
		{
			x += 1;
			continue;
		}
		
		result = true;
	}

	return result;
}

// Processing levelO and damage
pair<int, int> Opponent(float baseDamage, int i)
{
	int b = (i + 1) % 10;
	int levelO = i > 6 ? (b > 5 ? b : 5) : b;
	int damage = int(baseDamage * levelO * 10);

	return {levelO, damage};
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
    if (argc < 2) return 1;
    const char* filename = argv[1];

	struct knight theKnight;
	int nEvent; //number of events
	int* arrEvent = new int[EVENT_SIZE]; // array of events
	int* nOut;                           // final result
	int i;

	readFile(filename, theKnight, nEvent, arrEvent);
	//cout << theKnight.HP << ' ' << theKnight.level << ' ' << theKnight.remedy << ' ' << theKnight.maidenkiss << ' ' << theKnight.phoenixdown << endl;

	int levelO, damage, N, levelFrog, f1, f2, f3, bEvent;
	float baseDamage;
	int
		maxHP 			= theKnight.HP,
		isTiny 			= 5,
		isFrog 			= 5,
		hasLightwing 	= 5,
		meetOdin 		= 5;
	bool
		isEnded 		= false, 
		hasExcalibur 	= false,
		hasMythril 		= false,
		hasExcalipoor 	= false,
		princessEscaped = false,
		isArthur 		= maxHP == 999,
		isLancelot 		= maxHP == 888,
		isPaladin 		= isPrime(maxHP),
		isKnight 		= canKnight(maxHP),
		isDragonKnight 	= false,
		metOdin			= false;

	for (i = 0; i < nEvent; i += 1)
	{
		int theEvent = arrEvent[i];
		baseDamage = 10;

		// Check Lancelot with level
		if (isLancelot && theKnight.level % 2 == 1)
			isArthur = true;
		else
			isArthur = false;

		// Bowser surrendered
		if (theEvent == 0)
		{
			i = nEvent;
			break;
		}

		// Meet the princess Guinevere
		if (theEvent == 20)
		{
			princessEscaped = true;
			bEvent = i;
			i = nEvent;
			break;
		}

		// Lightwing is active
		if (hasLightwing <= 3)
		{
			if (theEvent == 21)
				hasLightwing = 1;
			else
			{
				hasLightwing += 1;

				switch(theEvent)
				{
					case 6:
						// Meet Shaman
						if (isFrog <= 3 || isTiny <= 3) break;
						levelO = Opponent(0, i).first;

						if (theKnight.level > levelO && !hasExcalipoor ||
							meetOdin <= 3 ||
							isArthur ||
							isPaladin ||
							isDragonKnight)
								theKnight.level += 2;
						else if (!hasMythril)
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
							theKnight.HP = 1;
					break;

					case 7:
						// Meet Siren Vajsh
						if (isFrog <= 3 || isTiny <= 3) break;
						levelO = Opponent(0, i).first;

						if (theKnight.level > levelO && !hasExcalipoor ||
							meetOdin <= 3 ||
							isArthur ||
							isPaladin ||
							isDragonKnight)
								theKnight.level += 2;
						else
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
					break;
				}

				// Odin counter
				if (meetOdin <= 3)
					meetOdin += 1;

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
						isFrog = 5;
						isTiny = 5;
						theKnight.HP = maxHP;
						theKnight.phoenixdown -= 1;
					}
				}

				// Restrictions
				if (theKnight.level > 10)
					theKnight.level = 10;
				if (theKnight.HP > maxHP)
					theKnight.HP = maxHP;
				if (theKnight.remedy > 99)
					theKnight.remedy = 99;
				if (theKnight.maidenkiss > 99)
					theKnight.maidenkiss = 99;
				if (theKnight.phoenixdown > 99)
					theKnight.phoenixdown = 99;
			}

			continue;
		}
		
		switch (theEvent)
		{
		case MADBEAR:
			// Meet MadBear
			baseDamage = (baseDamage > 1.0) ? 1.0 : baseDamage;
		case BANDIT:
			// Meet Bandit
			baseDamage = (baseDamage > 1.5) ? 1.5 : baseDamage;
		case 3:
			// Meet Lord Lupine
			baseDamage = (baseDamage > 4.5) ? 4.5 : baseDamage;
		case 4:
			// Meet Elf
			baseDamage = (baseDamage > 6.5) ? 6.5 : baseDamage;
		case 5:
			// Meet Troll
			baseDamage = (baseDamage > 8.5) ? 8.5 : baseDamage;

			levelO = Opponent(baseDamage, i).first;
			damage = Opponent(baseDamage, i).second;

			if (theKnight.level > levelO && !hasExcalipoor ||
				hasExcalibur ||
				meetOdin <= 3 ||
				isArthur ||
				isPaladin ||
				isDragonKnight)
					theKnight.level += 1;
			else if (theKnight.level < levelO && !hasMythril)
					theKnight.HP -= damage;
		break;

		case 6:
			// Meet Shaman
			if (isFrog <= 3 || isTiny <= 3) break;
			levelO = Opponent(0, i).first;

			if (theKnight.level > levelO && !hasExcalipoor ||
				meetOdin <= 3 ||
				isArthur ||
				isPaladin ||
				isDragonKnight)
					theKnight.level += 2;
			else if (!hasMythril)
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
				theKnight.HP = 1;
		break;

		case 7:
			// Meet Siren Vajsh
			if (isFrog <= 3 || isTiny <= 3) break;
			levelO = Opponent(0, i).first;

			if (theKnight.level > levelO && !hasExcalipoor ||
				meetOdin <= 3 ||
				isArthur ||
				isPaladin ||
				isDragonKnight)
					theKnight.level += 2;
			else
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
		break;

		case 8:
			// Obtain Excalibur sword
			hasExcalibur = true;
			hasExcalipoor = false;
		break;

		case 9:
			// Obtain Mythril armor
			hasMythril = true;
		break;

		case 10:
			//  Obtain Excalipoor sword
			if (isArthur || isPaladin || isKnight || meetOdin <= 3) break;
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
			f1 = 1, f2 = 1;

			while (theKnight.HP < f3)
			{
				f3 = f1 + f2;
				f1 = f2;
				f2 = f3;
			}

			theKnight.HP = f3;
		break;

		case 13:
			// Obtain ghost mushroom of MushGhost
			if (isDragonKnight || isPaladin || hasMythril || meetOdin <= 3) break;
			theKnight.HP -= 50;
			if (theKnight.HP < 51)
				theKnight.HP = 1;
		break;

		case 14:
			// Obtain mushroom of MushKnight
			if (maxHP < 950)
				maxHP += 50;
			theKnight.HP = maxHP;
		break;

		case 15:
			// Obtain Remedy
			if (isTiny <= 3){ isTiny = 3; break; }
			theKnight.remedy += 1;
		break;

		case 16:
			// Obtain MaidenKiss
			if (isFrog <= 3){ isFrog = 3; break; }
			theKnight.maidenkiss += 1;
		break;

		case 17:
			// Obtain PhoenixDown
			theKnight.phoenixdown += 1;
		break;

		case 18:
			// Meet Merlin the Wizard
			if (isTiny < 3 || isFrog < 3)
			{
				isTiny = 3;
				isFrog = 3;
			}

			theKnight.level += 1;
			theKnight.HP = maxHP;
		break;

		case 19:
			// Fall into the Abyss
			if (isDragonKnight || meetOdin <= 3) break;
			if (theKnight.level < 7)
			{
				isEnded = true;
				N = -1;
				i = nEvent;
			}
		break;

		case 21:
			// Obtain wings of Lightwing
			hasLightwing = 1;
		break;

		case 22:
			// Meet Odin
			if (!metOdin) meetOdin = 1;
		break;
		
		case 23:
			// Obtain Dragon Sword
			if (isLancelot) break;
			isDragonKnight = isKnight ? true : false;
		break;

		case 99:
			// Meet Bowser
			if (hasExcalipoor)
			{
				isEnded = true;
				N = -1;
				i = nEvent;
			}
			else if ((isArthur || isLancelot || isPaladin) && theKnight.level >= 8 ||
				theKnight.level == 10 ||
				isDragonKnight ||
				meetOdin <= 3)
					theKnight.level = 10;
			else
			{
				isEnded = true;
				N = -1;
				i = nEvent;
			}
		break;
		}

		// Tiny knight
		if (isTiny == 3) theKnight.HP *= 5;
		if (isTiny < 5)
			isTiny += 1;

		// Frog knight
		if (isFrog == 3) theKnight.level = levelFrog;
		if (isFrog < 5)
			isFrog += 1;

		// Odin counter
		if (meetOdin <= 3)
			meetOdin += 1;

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
				isFrog = 5;
				isTiny = 5;
				theKnight.HP = maxHP;
				theKnight.phoenixdown -= 1;
			}
		}

		// Restrictions
		if (theKnight.level > 10)
			theKnight.level = 10;
		if (theKnight.HP > maxHP)
			theKnight.HP = maxHP;
		if (theKnight.remedy > 99)
			theKnight.remedy = 99;
		if (theKnight.maidenkiss > 99)
			theKnight.maidenkiss = 99;
		if (theKnight.phoenixdown > 99)
			theKnight.phoenixdown = 99;
	}

	// Return to England
	for (i = bEvent - 1; i >= 0 && princessEscaped; i -= 1)
	{
		int theEvent = arrEvent[i];
		baseDamage = 10;

		// Check Lancelot with level
		if (isLancelot && theKnight.level % 2 == 1)
			isArthur = true;
		else
			isArthur = false;

		// Lightwing is active
		if (hasLightwing <= 3)
		{
			if (theEvent == 21)
				hasLightwing = 1;
			else
			{
				hasLightwing += 1;

				switch(theEvent)
				{
					case 6:
						// Meet Shaman
						if (isFrog <= 3 || isTiny <= 3) break;
						levelO = Opponent(0, i).first;

						if (theKnight.level > levelO && !hasExcalipoor ||
							meetOdin <= 3 ||
							isArthur ||
							isPaladin ||
							isDragonKnight)
								theKnight.level += 2;
						else if (!hasMythril)
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
							theKnight.HP = 1;
					break;

					case 7:
						// Meet Siren Vajsh
						if (isFrog <= 3 || isTiny <= 3) break;
						levelO = Opponent(0, i).first;

						if (theKnight.level > levelO && !hasExcalipoor ||
							meetOdin <= 3 ||
							isArthur ||
							isPaladin ||
							isDragonKnight)
								theKnight.level += 2;
						else
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
					break;
				}

				// Odin counter
				if (meetOdin <= 3)
					meetOdin += 1;

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
						isFrog = 5;
						isTiny = 5;
						theKnight.HP = maxHP;
						theKnight.phoenixdown -= 1;
					}
				}

				// Restrictions
				if (theKnight.level > 10)
					theKnight.level = 10;
				if (theKnight.HP > maxHP)
					theKnight.HP = maxHP;
				if (theKnight.remedy > 99)
					theKnight.remedy = 99;
				if (theKnight.maidenkiss > 99)
					theKnight.maidenkiss = 99;
				if (theKnight.phoenixdown > 99)
					theKnight.phoenixdown = 99;
			}

			continue;
		}
		
		switch (theEvent)
		{
		case MADBEAR:
			// Meet MadBear
			baseDamage = (baseDamage > 1.0) ? 1.0 : baseDamage;
		case BANDIT:
			// Meet Bandit
			baseDamage = (baseDamage > 1.5) ? 1.5 : baseDamage;
		case 3:
			// Meet Lord Lupine
			baseDamage = (baseDamage > 4.5) ? 4.5 : baseDamage;
		case 4:
			// Meet Elf
			baseDamage = (baseDamage > 6.5) ? 6.5 : baseDamage;
		case 5:
			// Meet Troll
			baseDamage = (baseDamage > 8.5) ? 8.5 : baseDamage;

			levelO = Opponent(baseDamage, i).first;
			damage = Opponent(baseDamage, i).second;

			if (theKnight.level > levelO && !hasExcalipoor ||
				hasExcalibur ||
				meetOdin <= 3 ||
				isArthur ||
				isPaladin ||
				isDragonKnight)
					theKnight.level += 1;
			else if (theKnight.level < levelO && !hasMythril)
					theKnight.HP -= damage;
		break;

		case 6:
			// Meet Shaman
			if (isFrog <= 3 || isTiny <= 3) break;
			levelO = Opponent(0, i).first;

			if (theKnight.level > levelO && !hasExcalipoor ||
				meetOdin <= 3 ||
				isArthur ||
				isPaladin ||
				isDragonKnight)
					theKnight.level += 2;
			else if (!hasMythril)
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
				theKnight.HP = 1;
		break;

		case 7:
			// Meet Siren Vajsh
			if (isFrog <= 3 || isTiny <= 3) break;
			levelO = Opponent(0, i).first;

			if (theKnight.level > levelO && !hasExcalipoor ||
				meetOdin <= 3 ||
				isArthur ||
				isPaladin ||
				isDragonKnight)
					theKnight.level += 2;
			else
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
		break;

		case 8:
			// Obtain Excalibur sword
			hasExcalibur = true;
			hasExcalipoor = false;
		break;

		case 9:
			// Obtain Mythril armor
			hasMythril = true;
		break;

		case 10:
			//  Obtain Excalipoor sword
			if (isArthur || isPaladin || isKnight || meetOdin <= 3) break;
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
			f1 = 1, f2 = 1;

			while (theKnight.HP < f3)
			{
				f3 = f1 + f2;
				f1 = f2;
				f2 = f3;
			}

			theKnight.HP = f3;
		break;

		case 13:
			// Obtain ghost mushroom of MushGhost
			if (isDragonKnight || isPaladin || hasMythril || meetOdin <= 3) break;
			theKnight.HP -= 50;
			if (theKnight.HP < 51)
				theKnight.HP = 1;
		break;

		case 14:
			// Obtain mushroom of MushKnight
			if (maxHP < 950)
				maxHP += 50;
			theKnight.HP = maxHP;
		break;

		case 15:
			// Obtain Remedy
			if (isTiny <= 3){ isTiny = 3; break; }
			theKnight.remedy += 1;
		break;

		case 16:
			// Obtain MaidenKiss
			if (isFrog <= 3){ isFrog = 3; break; }
			theKnight.maidenkiss += 1;
		break;

		case 17:
			// Obtain PhoenixDown
			theKnight.phoenixdown += 1;
		break;

		case 18:
			// Meet Merlin the Wizard
			if (isTiny < 3 || isFrog < 3)
			{
				isTiny = 3;
				isFrog = 3;
			}

			theKnight.level += 1;
			theKnight.HP = maxHP;
		break;

		case 19:
			// Fall into the Abyss
			if (isDragonKnight || meetOdin <= 3) break;
			if (theKnight.level < 7)
			{
				isEnded = true;
				N = -1;
				i = nEvent;
			}
		break;

		case 21:
			// Obtain wings of Lightwing
			hasLightwing = 1;
		break;

		case 22:
			// Meet Odin
			if (!metOdin) meetOdin = 1;
		break;
		
		case 23:
			// Obtain Dragon Sword
			if (isLancelot) break;
			isDragonKnight = isKnight ? true : false;
		break;

		case 99:
			// Meet Bowser
			if (hasExcalipoor)
			{
				isEnded = true;
				N = -1;
				i = nEvent;
			}
			else if ((isArthur || isLancelot || isPaladin) && theKnight.level >= 8 ||
				theKnight.level == 10 ||
				isDragonKnight ||
				meetOdin <= 3)
					theKnight.level = 10;
			else
			{
				isEnded = true;
				N = -1;
				i = nEvent;
			}
		break;
		}

		// Tiny knight
		if (isTiny == 3) theKnight.HP *= 5;
		if (isTiny < 5)
			isTiny += 1;

		// Frog knight
		if (isFrog == 3) theKnight.level = levelFrog;
		if (isFrog < 5)
			isFrog += 1;

		// Odin counter
		if (meetOdin <= 3)
			meetOdin += 1;

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
				isFrog = 5;
				isTiny = 5;
				theKnight.HP = maxHP;
				theKnight.phoenixdown -= 1;
			}
		}

		// Restrictions
		if (theKnight.level > 10)
			theKnight.level = 10;
		if (theKnight.HP > maxHP)
			theKnight.HP = maxHP;
		if (theKnight.remedy > 99)
			theKnight.remedy = 99;
		if (theKnight.maidenkiss > 99)
			theKnight.maidenkiss = 99;
		if (theKnight.phoenixdown > 99)
			theKnight.phoenixdown = 99;
	}

	if (!isEnded)
		N = theKnight.HP + theKnight.level + theKnight.remedy + theKnight.maidenkiss + theKnight.phoenixdown;
	nOut = &N;
	display(nOut);
	return 0;
}
