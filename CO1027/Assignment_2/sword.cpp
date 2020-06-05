#ifndef _definition_h_
#include "defs.h"
#define _definition_h_
#endif
#include <algorithm>

//
std::pair<int, int> Opponent(int i, double baseDamage, knight theKnight)
{
	int b = (i + 1) % 10;
	int levelO = (i > 6) ? ((b > 5) ? b : 5) : b;
	int damage = int(baseDamage * levelO * 10);
	int result = 0;

	if (theKnight.level >= levelO)
		result = 1;

	return {result, damage};
}

//
int SumOfFactors(int n)
{
	// Traversing through all prime factors.
	int result = 1;
	for (int i = 2; i * i <= n; i++)
	{
		int count = 0, sum = 1;
		int term = 1;
		while (n % i == 0)
		{
			count++;
			n = n / i;

			term *= i;
			sum += term;
		}

		result *= sum;
	}

	if (n >= 2)
		result *= (1 + n);

	return result;
}

// Function to return gcd of a and b
int GCD(int a, int b)
{
	if (a == 0)
		return b;
	return GCD(b % a, a);
}

//
int isFriendly(int n, int m)
{
	// Finding the sum of factors of n and m
	int sumFactors_n = SumOfFactors(n);
	int sumFactors_m = SumOfFactors(m);

	// Finding GCD of n and sum of its factors.
	int gcd_n = GCD(n, sumFactors_n);

	// Finding GCD of m and sum of its factors.
	int gcd_m = GCD(m, sumFactors_m);

	// Checking if numerator and denominator of
	// abundancy index of both number are equal
	// or not.
	if (n / gcd_n == m / gcd_m &&
		sumFactors_n / gcd_n == sumFactors_m / gcd_m)
		return true;

	else
		return false;
}

// Test for Paladin
int isPrime(int n)
{
	int result = true;

	if (n < 2)
		result = false;
	else
		for (int i = 2; i * i <= n; i += 1)
		{
			if (n % i == 0)
			{
				result = false;
				break;
			}
		}

	return result;
}

// Test for Dragon Knight
int canKnight(int C)
{
	int x = 1;
	int result = false;
	double y = 0.0;

	if (C == 888)
		return result;

	while (x < C / 2 && !result)
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

// Mode 1
void TripletOrder(int &a, int &b, int &c)
{
	if (a < b)
	{
		if (a < c)
		{
			a = 10;
			if (b < c)
			{
				b = 20;
				c = 30;
			}
			else
			{
				c = 20;
				b = 30;
			}
		}
		else
		{
			c = 10;
			a = 20;
			b = 30;
		}
	}
	else
	{

		if (b < c)
		{
			b = 10;

			if (a < c)
			{
				a = 20;
				c = 30;
			}
			else
			{
				c = 20;
				a = 30;
			}
		}
		else
		{
			c = 10;
			b = 20;
			a = 30;
		}
	}
}

//
int Factorial(int n)
{
	int result = 1;

	if (n < 2)
		result = 1;
	else
		result = n * Factorial(n - 1);

	return result;
}

// Mode 2: bruteforce
void BackTrack(knight theKnight, castle arrCastle[], int **actCastle, int nCastle, int pIndex, int nPetal)
{
	int maxHP = theKnight.HP,
		minHP = 0,
		isKnight = canKnight(maxHP),
		isKing = maxHP == 999,
		isLancelot = maxHP == 888,
		isGuinevere = maxHP == 777,
		isPaladin = isPrime(maxHP),
		currCastle = 0,
		hasHakama = 0,
		hasArmor = 0,
		hasShield = 0,
		hasSpear = 0,
		hasHair = 0,
		hasTreasures = 0,
		hasExcalibur = 0,
		hasLionheart = 0,
		cldLionheart = 0,
		hasLove = 0,
		isPoisoned = 0,
		meetOdin = 0,
		cldOdin = 0,
		metOmega = 0,
		n = 0;
	double baseDamage = 10.0;
	std::pair<int, int> rt;

	if (isLancelot)
		hasSpear = 1;
	if (isGuinevere)
		hasHair = 1;
	if (isPaladin)
		hasShield = 1;

	while (nCastle)
	{
		for (int i = 0; i < arrCastle[currCastle].nEvent; i += 1)
		{
			if (nPetal - 1 < 0 && !isKing)
				goto END;

			if (isPoisoned > 0)
				isPoisoned -= 1;
			if (hasLionheart > 0)
				hasLionheart -= 1;
			if (cldLionheart > 0)
				cldLionheart -= 1;
			if (meetOdin > 0)
				meetOdin -= 1;
			if (cldOdin > 0)
				cldOdin -= 1;
			if (nPetal > 0)
				nPetal -= 1;

			hasTreasures = hasShield && hasSpear && hasHair;
			hasLove = hasSpear && hasHair && !hasExcalibur ||
					  isKing && hasHair ||
					  isLancelot && hasHair ||
					  isGuinevere && hasSpear;

			switch (arrCastle[currCastle].arrEvent[i])
			{
			case 1: // Meet MadBear
				baseDamage = (baseDamage > 1.0) ? 1.0 : baseDamage;
			case 2: // Meet Amazon female warrior MoonBringer
				baseDamage = (baseDamage > 1.5) ? 1.5 : baseDamage;
			case 3: // Meet Elf
				baseDamage = (baseDamage > 4.5) ? 4.5 : baseDamage;
			case 4: // Meet Saxon warrior
				baseDamage = (baseDamage > 6.5) ? 6.5 : baseDamage;
			case 5: // Meet Troll
				baseDamage = (baseDamage > 8.5) ? 8.5 : baseDamage;

				rt = Opponent(i, baseDamage, theKnight);

				if (rt.first || hasLionheart ||
					meetOdin || isKing || isLancelot || isPaladin)
					theKnight.gil += int(baseDamage * 100);
				else if (!(isGuinevere && baseDamage == 1.5))
					theKnight.HP -= rt.second;

				if (isPoisoned)
					theKnight.HP -= rt.second;
				break;

			case 6: // Meet Tornbery
				if (isPoisoned)
					break;

				rt = Opponent(i, baseDamage, theKnight);

				if (rt.first || hasLionheart ||
					meetOdin || isKing || isLancelot)
					theKnight.level += 1;
				else if (!isPaladin && !isKnight)
					isPoisoned = 6;

				break;

			case 7: // Meet Queen of Cards
				rt = Opponent(i, baseDamage, theKnight);

				if (rt.first || hasLionheart ||
					meetOdin || isKing || isLancelot)
					theKnight.gil *= 2;
				else if (!hasHakama && !isGuinevere)
					theKnight.gil = int(theKnight.gil / 2.0);

				break;

			case 8: // Meet the merry merchant Nina de Rings
				if (cldLionheart)
					break;

				if (isFriendly(theKnight.HP, theKnight.gil))
				{
					theKnight.HP = maxHP;
					isPoisoned = 0;
					hasLionheart = 6;
					cldLionheart = 7;

					if (isPaladin)
					{
						hasLionheart = -1;
						cldLionheart = -1;
					}
					break;
				}

				if (hasHakama || isGuinevere || isPaladin)
				{
					theKnight.HP = maxHP; // Updated from formal classes
					isPoisoned = 0;
					if (isGuinevere)
						theKnight.gil += 50;
					break;
				}

				if (theKnight.gil < 50)
					break;

				if (isPoisoned)
				{
					theKnight.gil -= 50;
					isPoisoned = 0;
				}

				if (theKnight.gil)
				{
					theKnight.HP += theKnight.gil;
					theKnight.gil = 0;
				}

				if (theKnight.HP > maxHP)
				{
					theKnight.gil += theKnight.HP - maxHP;
					theKnight.HP = maxHP;
				}
				break;

			case 9: // Lost into the Durian Garden
				isPoisoned = 0;
				theKnight.HP = maxHP;
				nPetal += 5;
				if (!hasHakama)
					nPetal = 99;
				break;

			case 10: // Obtain antidote
				theKnight.antidote += 1;
				break;

			case 11: // Meet Odin
				if (cldOdin || meetOdin < 0)
					break;

				meetOdin = 6;
				cldOdin = 7;
				break;

			case 12: // Meet Merlin the Wizard
				isPoisoned = 0;
				theKnight.level += 1;
				maxHP += 100;
				theKnight.HP = maxHP;
				break;

			case 13: // Meet Omega Weapon
				if (metOmega)
					break;

				if (theKnight.level == 10 && hasExcalibur ||
					isKnight && hasLionheart)
				{
					maxHP += (10 - theKnight.level) * 100;
					theKnight.level = 10;
					theKnight.gil = 999;
					metOmega += 1;
				}
				else
					theKnight.HP = 0;

				break;

			case 14: // Meet Hades
				rt = Opponent(i, baseDamage, theKnight);

				if (isKnight && meetOdin)
				{
					hasArmor = 1;
					break;
				}

				meetOdin = 0;

				if (rt.first || hasLionheart || hasLove)
					hasArmor = 1;
				else
					theKnight.HP = 0;
				break;

			case 15: // Obtain Scarlet Hakama
				hasHakama = true;
				break;

			case 16: // Meet LockedDoor
				if (isLancelot && isKnight)
					break;

				if (theKnight.level <= ((i + 1) % 10))
					i = arrCastle[currCastle].nEvent;
				break;

			case 95: // Obtain Paladin shield
				hasShield = true;
				break;

			case 96: // Obtain Lancelot's spear
				hasSpear = true;
				break;

			case 97: // Obtain Guinevere's hair
				hasHair = true;
				break;

			case 98: // Obtain Excalibur sword
				if (!hasTreasures && !isKing)
					break;
				hasExcalibur = true;
				break;

			case 99: // Encounter Ultimecia
				if (hasExcalibur || hasLionheart)
				{
					if (isPoisoned)
					{
						theKnight.HP = int(theKnight.HP / 3.0);
						theKnight.HP = (theKnight.HP < 3) ? 1 : theKnight.HP;
					}
					goto END;
				}
				else if (!isGuinevere)
				{
					theKnight.HP = int(theKnight.HP / 3.0);
					theKnight.HP = (theKnight.HP < 3) ? 1 : theKnight.HP;
				}

				break;
			}

			// Mythril armor
			if (hasArmor)
			{
				if (minHP < theKnight.HP || isPoisoned)
					minHP = theKnight.HP;
				theKnight.HP = minHP;
			}

			// Call Phoenix
			if (theKnight.HP <= 0)
			{
				callPhoenix(theKnight, maxHP);
				isPoisoned = 0;
				minHP = theKnight.HP;
			}

			// Poison
			if (isPoisoned && theKnight.antidote > 0)
			{
				isPoisoned = 0;
				theKnight.antidote -= 1;
			}

			// Restrictions
			if (maxHP > 999)
				maxHP = 999;
			if (nPetal > 99)
				nPetal = 99;
			if (theKnight.level > 10)
				theKnight.level = 10;
			if (theKnight.HP > maxHP)
				theKnight.HP = maxHP;
			if (theKnight.antidote > 99)
				theKnight.antidote = 99;
			if (theKnight.gil > 999)
				theKnight.gil = 999;

			baseDamage = 10.0;
		}

		// End of castle
		theKnight.level += 1;
		maxHP += 100;
		if (n < nCastle - 1)
			n += 1;
		else
			n = 0;
	}

END:
	actCastle[pIndex][0] = nPetal;
}

// Mode 2: setting up
void SetUp(knight theKnight, castle arrCastle[], int nCastle, int nPetal)
{
	int maxPetal = 0;
	int pIndex = 0; // Path index
	int nPath = Factorial(nCastle);
	int rCastle[nCastle]; // Will be used to reorder castles
	castle tmpCastle;
	int **actCastle;
	actCastle = new int *[nPath];

	// Enumerate castles
	for (int i = 0; i < nCastle; i += 1)
	{
		rCastle[i] = i;
	}

	// Create array of castles path index
	for (int i = 0; i < nPath; i += 1)
	{
		actCastle[i] = new int[nPetal + 1];
		actCastle[i][0] = nPetal; // Index 0 will be used to store number of remaining petals
	}

	//Randomize castles
	std::sort(rCastle, rCastle + nCastle);
	do
	{
		for (int i = 0; i < nCastle; i += 1)
			actCastle[pIndex][i + 1] = rCastle[i];
		pIndex += 1;
	} while (std::next_permutation(rCastle, rCastle + nCastle));

	// Iterate through all castles one time
	for (int i = 0; i < nPath; i += 1)
		BackTrack(theKnight, arrCastle, actCastle, nCastle, i, nPetal);

	// Find optimal path
	for (int i = 0; i < nPath; i += 1)
		maxPetal = (maxPetal < actCastle[i][0]) ? actCastle[i][0] : maxPetal;

	// Get index of optimal path
	for (int i = 0; i < nPath; i += 1)
		if (maxPetal == actCastle[i][0])
		{
			pIndex = i;
			break;
		}

	// Switch to optimal path
	for (int i = 0; i < nCastle; i += 1)
		for (int j = i; j < nCastle; j += 1)
			if (j == actCastle[pIndex][i + 1])
			{
				tmpCastle = arrCastle[i];
				arrCastle[i] = arrCastle[j];
				arrCastle[j] = tmpCastle;
				break;
			}
}

/*
// Mode 2
void OptimizePath(castle arrCastle[], int &nCastle, int nPetal)
{
	int check = 1, check1 = 1, check2 = 1, n = 0;
	castle tempCastle;

	// Mark meaningless paths
	for (int i = 0; i < nCastle; i += 1)
	{
		check = 0;

		for (int j = 0; j < arrCastle[i].nEvent; j += 1)
			if (arrCastle[i].arrEvent[j] == 95 ||
				arrCastle[i].arrEvent[j] == 96 ||
				arrCastle[i].arrEvent[j] == 97 ||
				arrCastle[i].arrEvent[j] == 98 ||
				arrCastle[i].arrEvent[j] == 99)
			{
				check = 1;
				break;
			}

		if (!check)
			arrCastle[i].arrEvent[0] = -1;
	}

	// Move said castles out of index
	while (n < nCastle)
	{
		if (arrCastle[n].arrEvent[0] == -1)
		{
			nCastle -= 1;

			for (int j = n; j < nCastle; j += 1)
			{
				tempCastle = arrCastle[j];
				arrCastle[j] = arrCastle[j + 1];
				arrCastle[j + 1] = tempCastle;
			}

			continue;
		}

		n += 1;
	}

	// Sort castles by events
	for (int i = 0; i < nCastle && (check1 || check2); i += 1)
		for (int j = 0; j < arrCastle[i].nEvent && (check1 || check2); j += 1)
		{
			if (arrCastle[i].arrEvent[j] == 98)
			{
				tempCastle = arrCastle[i];
				arrCastle[i] = arrCastle[nCastle - 2];
				arrCastle[nCastle - 2] = tempCastle;
				check1 = 0;
			}
			if (arrCastle[i].arrEvent[j] == 99)
			{
				tempCastle = arrCastle[i];
				arrCastle[i] = arrCastle[nCastle - 1];
				arrCastle[nCastle - 1] = tempCastle;
				check2 = 0;
			}
		}
}
*/

report *walkthrough(knight &theKnight, castle arrCastle[], int nCastle, int mode, int nPetal)
{
	report *pReturn;
	// fighting for the existence of mankind here
	int bFlag = 1,
		maxHP = theKnight.HP,
		minHP = 0,
		isKnight = canKnight(maxHP),
		isKing = maxHP == 999,
		isLancelot = maxHP == 888,
		isGuinevere = maxHP == 777,
		isPaladin = isPrime(maxHP),
		currCastle = 0,
		nWin = 0,
		nLose = 0,
		hasHakama = 0,
		hasArmor = 0,
		hasShield = 0,
		hasSpear = 0,
		hasHair = 0,
		hasTreasures = 0,
		hasExcalibur = 0,
		hasLionheart = 0,
		cldLionheart = 0,
		hasLove = 0,
		isPoisoned = 0,
		meetOdin = 0,
		cldOdin = 0,
		metOmega = 0,
		x = hash(95),
		y = hash(96),
		z = hash(97),
		hashCount = 10;
	double baseDamage = 10.0;
	std::pair<int, int> rt;

	if (mode == 1)
		TripletOrder(x, y, z);
	if (mode == 2)
		//OptimizePath(arrCastle, nCastle, nPetal);
		SetUp(theKnight, arrCastle, nCastle, nPetal);

	if (isLancelot)
		hasSpear = 1;
	if (isGuinevere)
		hasHair = 1;
	if (isPaladin)
		hasShield = 1;

	while (nCastle)
	{
		for (int i = 0; i < arrCastle[currCastle].nEvent; i += 1)
		{
			if (nPetal - 1 < 0 && !isKing)
			{
				bFlag = 0;
				goto END;
			}

			if (isPoisoned > 0)
				isPoisoned -= 1;
			if (hasLionheart > 0)
				hasLionheart -= 1;
			if (cldLionheart > 0)
				cldLionheart -= 1;
			if (meetOdin > 0)
				meetOdin -= 1;
			if (cldOdin > 0)
				cldOdin -= 1;
			if (nPetal > 0)
				nPetal -= 1;

			hasTreasures = hasShield && hasSpear && hasHair;
			hasLove = hasSpear && hasHair && !hasExcalibur ||
					  isKing && hasHair ||
					  isLancelot && hasHair ||
					  isGuinevere && hasSpear;

			switch (arrCastle[currCastle].arrEvent[i])
			{
			case 1: // Meet MadBear
				baseDamage = (baseDamage > 1.0) ? 1.0 : baseDamage;
			case 2: // Meet Amazon female warrior MoonBringer
				baseDamage = (baseDamage > 1.5) ? 1.5 : baseDamage;
			case 3: // Meet Elf
				baseDamage = (baseDamage > 4.5) ? 4.5 : baseDamage;
			case 4: // Meet Saxon warrior
				baseDamage = (baseDamage > 6.5) ? 6.5 : baseDamage;
			case 5: // Meet Troll
				baseDamage = (baseDamage > 8.5) ? 8.5 : baseDamage;

				rt = Opponent(i, baseDamage, theKnight);

				if (rt.first || hasLionheart ||
					meetOdin || isKing || isLancelot || isPaladin)
				{
					nWin += 1;
					theKnight.gil += int(baseDamage * 100);
				}
				else
				{
					nLose += 1;
					if (!(isGuinevere && baseDamage == 1.5))
						theKnight.HP -= rt.second;
				}

				if (isPoisoned)
					theKnight.HP -= rt.second;
				break;

			case 6: // Meet Tornbery
				if (isPoisoned)
					break;

				rt = Opponent(i, baseDamage, theKnight);

				if (rt.first || hasLionheart ||
					meetOdin || isKing || isLancelot)
				{
					nWin += 1;
					theKnight.level += 1;
				}
				else
				{
					nLose += 1;
					if (!isPaladin && !isKnight)
						isPoisoned = 6;
				}
				break;

			case 7: // Meet Queen of Cards
				rt = Opponent(i, baseDamage, theKnight);

				if (rt.first || hasLionheart ||
					meetOdin || isKing || isLancelot)
				{
					nWin += 1;
					theKnight.gil *= 2;
				}
				else
				{
					nLose += 1;
					if (!hasHakama && !isGuinevere)
						theKnight.gil = int(theKnight.gil / 2.0);
				}
				break;

			case 8: // Meet the merry merchant Nina de Rings
				if (cldLionheart)
					break;

				if (isFriendly(theKnight.HP, theKnight.gil))
				{
					theKnight.HP = maxHP;
					isPoisoned = 0;
					hasLionheart = 6;
					cldLionheart = 7;

					if (isPaladin)
					{
						hasLionheart = -1;
						cldLionheart = -1;
					}
					break;
				}

				if (hasHakama || isGuinevere || isPaladin)
				{
					theKnight.HP = maxHP; // Updated from formal classes
					isPoisoned = 0;
					if (isGuinevere)
						theKnight.gil += 50;
					break;
				}

				if (theKnight.gil < 50)
					break;

				if (isPoisoned)
				{
					theKnight.gil -= 50;
					isPoisoned = 0;
				}

				if (theKnight.gil)
				{
					theKnight.HP += theKnight.gil;
					theKnight.gil = 0;
				}

				if (theKnight.HP > maxHP)
				{
					theKnight.gil += theKnight.HP - maxHP;
					theKnight.HP = maxHP;
				}
				break;

			case 9: // Lost into the Durian Garden
				isPoisoned = 0;
				theKnight.HP = maxHP;
				nPetal += 5;
				if (!hasHakama)
					nPetal = 99;
				break;

			case 10: // Obtain antidote
				theKnight.antidote += 1;
				break;

			case 11: // Meet Odin
				if (cldOdin || meetOdin < 0)
					break;

				meetOdin = 6;
				cldOdin = 7;
				break;

			case 12: // Meet Merlin the Wizard
				isPoisoned = 0;
				theKnight.level += 1;
				maxHP += 100;
				theKnight.HP = maxHP;
				break;

			case 13: // Meet Omega Weapon
				if (metOmega)
					break;

				if (theKnight.level == 10 && hasExcalibur ||
					isKnight && hasLionheart)
				{
					nWin += 1;
					maxHP += (10 - theKnight.level) * 100;
					theKnight.level = 10;
					theKnight.gil = 999;
					metOmega += 1;
				}
				else
				{
					nLose += 1;
					theKnight.HP = 0;
				}
				break;

			case 14: // Meet Hades
				rt = Opponent(i, baseDamage, theKnight);

				if (isKnight && meetOdin)
				{
					nWin += 1;
					hasArmor = 1;
					break;
				}

				meetOdin = 0;

				if (rt.first || hasLionheart || hasLove)
				{
					nWin += 1;
					hasArmor = 1;
				}
				else
				{
					nLose += 1;
					theKnight.HP = 0;
				}
				break;

			case 15: // Obtain Scarlet Hakama
				hasHakama = true;
				break;

			case 16: // Meet LockedDoor
				if (isLancelot && isKnight)
					break;

				if (theKnight.level <= ((i + 1) % 10))
					i = arrCastle[currCastle].nEvent;
				break;

			case 95: // Obtain Paladin shield
				if (mode == 1 && !(hashCount == x))
					break;

				hasShield = true;
				if (mode == 1)
					hashCount += 10;
				break;

			case 96: // Obtain Lancelot's spear
				if (mode == 1 && !(hashCount == y))
					break;

				hasSpear = true;
				if (mode == 1)
					hashCount += 10;
				break;

			case 97: // Obtain Guinevere's hair
				if (mode == 1 && !(hashCount == z))
					break;

				hasHair = true;
				if (mode == 1)
					hashCount += 10;
				break;

			case 98: // Obtain Excalibur sword
				if (!hasTreasures && !isKing)
					break;
				hasExcalibur = true;
				break;

			case 99: // Encounter Ultimecia
				if (hasExcalibur || hasLionheart)
				{
					nWin += 1;
					if (isPoisoned)
					{
						theKnight.HP = int(theKnight.HP / 3.0);
						theKnight.HP = (theKnight.HP < 3) ? 1 : theKnight.HP;
					}
					goto END;
				}
				else
				{
					nLose += 1;
					if (!isGuinevere)
					{
						theKnight.HP = int(theKnight.HP / 3.0);
						theKnight.HP = (theKnight.HP < 3) ? 1 : theKnight.HP;
					}
				}
				break;
			}

			// Mythril armor
			if (hasArmor)
			{
				if (minHP < theKnight.HP || isPoisoned)
					minHP = theKnight.HP;
				theKnight.HP = minHP;
			}

			// Call Phoenix
			if (theKnight.HP <= 0)
			{
				callPhoenix(theKnight, maxHP);
				isPoisoned = 0;
				minHP = theKnight.HP;
			}

			// Poison
			if (isPoisoned && theKnight.antidote > 0)
			{
				isPoisoned = 0;
				theKnight.antidote -= 1;
			}

			// Restrictions
			if (maxHP > 999)
				maxHP = 999;
			if (nPetal > 99)
				nPetal = 99;
			if (theKnight.level > 10)
				theKnight.level = 10;
			if (theKnight.HP > maxHP)
				theKnight.HP = maxHP;
			if (theKnight.antidote > 99)
				theKnight.antidote = 99;
			if (theKnight.gil > 999)
				theKnight.gil = 999;

			baseDamage = 10.0;
		}

		// End of castle
		theKnight.level += 1;
		maxHP += 100;
		if (currCastle < nCastle - 1)
			currCastle += 1;
		else
			currCastle = 0;
	}

END:
	bFlag = (bFlag == 0) ? 0 : 1;

	// success or failure?
	pReturn = (bFlag) ? new report : NULL;

	if (pReturn != nullptr)
	{
		pReturn->nPetal = nPetal;
		pReturn->nWin = nWin;
		pReturn->nLose = nLose;
	}
	return pReturn;
}
