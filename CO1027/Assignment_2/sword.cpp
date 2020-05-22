#ifndef _definition_h_
#include "defs.h"
#define _definition_h_
#endif

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

int isFriendly(int x, int y)
{
	int fSum = 0, sSum = 0;

	for (int i = 1; i <= x; i += 1)
		if (x % i == 0)
			fSum += i;

	for (int i = 1; i <= y; i += 1)
		if (y % i == 0)
			sSum += i;

	return (fSum / x == sSum / y);
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

// Mode 2
void OptimizePath(castle arrCastle[], int nCastle)
{
	int check = 0;
	castle *tempCastle = new castle;

	while (!check)
	{
		check = true;
	}
}

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
	TripletOrder(x, y, z);

	if (isLancelot)
		hasSpear = 1;
	if (isGuinevere)
		hasHair = 1;
	if (isPaladin)
		hasShield = 1;

	while (1)
	{
		for (int i = 0; i < arrCastle[currCastle].nEvent; i += 1)
		{
			if (nPetal - 1 < 0 && !isKing)
				goto ENDNULL;

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

				if (rt.first && hasExcalibur || hasLionheart ||
					meetOdin || isKing || isLancelot || isPaladin)
				{
					nWin += 1;
					theKnight.gil += int(baseDamage * 100);
				}
				else
				{
					nLose += 1;
					if (!isGuinevere)
						theKnight.HP -= rt.second;
				}

				if (isPoisoned)
					theKnight.HP -= rt.second;
				break;

			case 6: // Meet Tornbery
				if (isPoisoned)
					break;

				rt = Opponent(i, baseDamage, theKnight);

				if (rt.first && hasExcalibur || hasLionheart ||
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

				if (rt.first && hasExcalibur || hasLionheart ||
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

				if (isFriendly(theKnight.HP, theKnight.gil) && !cldLionheart)
				{
					theKnight.HP = maxHP;
					hasLionheart = 6;
					cldLionheart = 7;

					if (isPaladin)
					{
						hasLionheart = -1;
						cldLionheart = -1;
					}
					break;
				}

				if (theKnight.gil < 50)
					break;

				if (isPoisoned)
				{
					isPoisoned = 0;
					if (!hasHakama && !isGuinevere && !isPaladin)
						theKnight.gil -= 50;
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

				if (isGuinevere)
					theKnight.gil += 50;
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
					goto ENDMODE;
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
			if (minHP < theKnight.HP || isPoisoned)
				minHP = theKnight.HP;
			if (hasArmor)
				theKnight.HP = minHP;

			// Call Phoenix
			if (theKnight.HP <= 0)
			{
				callPhoenix(theKnight, maxHP);
				isPoisoned = 0;
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

	goto ENDMODE;

ENDNULL:
	bFlag = 0;
ENDMODE:
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
