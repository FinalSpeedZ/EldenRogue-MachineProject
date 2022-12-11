#include "battle_screen_helper.h"

void getEnemyStats(int nAreaIndex, Enemy* pEnemy) {
	getEnemyType(&pEnemy->nEnemyType);

	getEnemyHealthRange(pEnemy);
	getEnemyBaseHealth(pEnemy);
	getEnemyFinalHealth(nAreaIndex, pEnemy);

	getEnemyAttackRange(pEnemy);
	getEnemyBaseAttack(pEnemy);
	getEnemyFinalAttack(nAreaIndex, pEnemy);

	getEnemyDefense(pEnemy);
	getEnemyName(nAreaIndex, pEnemy);
}

void getEnemyType(int* pEnemyType) {
	*pEnemyType = randomNumberBetween(3, 1);	
}

void getEnemyHealthRange(Enemy* pEnemy) {
	switch (pEnemy->nEnemyType) {
		case 1:
			pEnemy->nHealthUpper = 30;
			pEnemy->nHealthLower = 20;
			break;

		case 2:
			pEnemy->nHealthUpper = 35;
			pEnemy->nHealthLower = 25;
			break;

		case 3:
			pEnemy->nHealthUpper = 80;
			pEnemy->nHealthLower = 70;
			break;
	}
}

void getEnemyBaseHealth(Enemy* pEnemy) {
	pEnemy->nBaseHealth = randomNumberBetween(pEnemy->nHealthUpper, pEnemy->nHealthLower);
}

void getEnemyFinalHealth(int nAreaIndex, Enemy* pEnemy) {
	pEnemy->nFinalHealth = nAreaIndex * pEnemy->nBaseHealth;
	pEnemy->nCurrentHealth = pEnemy->nFinalHealth;
}

void getEnemyAttackRange(Enemy* pEnemy) {
	switch (pEnemy->nEnemyType) {
		case 1:
			pEnemy->nAttackUpper = 80;
			pEnemy->nAttackLower = 70;
			break;

		case 2:
			pEnemy->nAttackUpper = 120;
			pEnemy->nAttackLower = 110;
			break;

		case 3:
			pEnemy->nAttackUpper = 130;
			pEnemy->nAttackLower = 120;
			break;
	}	
}

void getEnemyBaseAttack(Enemy* pEnemy) {
	pEnemy->nBaseAttack = randomNumberBetween(pEnemy->nAttackUpper, pEnemy->nAttackLower);
}

void getEnemyFinalAttack(int nAreaIndex, Enemy* pEnemy) {
	pEnemy->nFinalAttack = nAreaIndex * pEnemy->nBaseAttack;
}

void getEnemyDefense(Enemy* pEnemy) {
	switch (pEnemy->nEnemyType) {
		case 1:
			pEnemy->fPhysicalDef = 0.20;
			pEnemy->fSorceryDef = 0.15;
			pEnemy->fIncantationDef = 0.10;
			break;

		case 2:
			pEnemy->fPhysicalDef = 0.50;
			pEnemy->fSorceryDef = 0.15;
			pEnemy->fIncantationDef = 0.20;
			break;

		case 3:
			pEnemy->fPhysicalDef = 0.25;
			pEnemy->fSorceryDef = 0.25;
			pEnemy->fIncantationDef = 0.20;
			break;
	}
}

int getEnemyNameLength(int nAreaIndex, int nEnemyType) {
	int nLength;

	switch (nAreaIndex) {
		case STORMVEIL_CASTLE:
			switch(nEnemyType) {
				case 1:
					nLength = strlen("GODRICK SOLDIER");
					break;

				case 2:
					nLength = strlen("GODRICK ARCHER");
					break;

				case 3:
					nLength = strlen("GODRICK KNIGHT");
					break;
			}
		break;

		case RAYA_LUCARIA_ACADEMY:
			switch (nEnemyType) {
				case 1:
					nLength = strlen("LIVING JAR");
					break;

				case 2:
					nLength = strlen("GLINSTONE SORCERER");
					break;

				case 3:
					nLength = strlen("BATTLEMAGE");
					break;
			}
		break;

		case REDMANE_CASTLE:
			switch(nEnemyType) {
				case 1:
					nLength = strlen("RADAHN SOLDIER");
					break;

				case 2:
					nLength = strlen("RADAHN ARCHER");
					break;

				case 3:
					nLength = strlen("RADAHN KNIGHT");
					break;
			}
		break;

		case VOLCANO_MANOR:
			switch (nEnemyType) {
				case 1:
					nLength = strlen("MAN-SERPENT");
					break;

				case 2:
					nLength = strlen("MAGE-SERPENT");
					break;

				case 3:
					nLength = strlen("ABDUCTOR VIRGIN");
					break;
			}
		break;

		case LEYNDELL_ROYAL_CAPITAL: 
			switch (nEnemyType) {
				case 1:
					nLength = strlen("LEYNDELL SOLDIER");
					break;

				case 2:
					nLength = strlen("LEYNDELL ARCHER");
					break;

				case 3:
					nLength = strlen("LEYNDELL KNIGHT");
					break;
			}
		break;
	}

	return nLength;
}

void getEnemyName(int nAreaIndex, Enemy* pEnemy) {
	int nLength = getEnemyNameLength(nAreaIndex, pEnemy->nEnemyType);
	char* pEnemyName = malloc(sizeof(char) * nLength + 1);

	switch (nAreaIndex) {
		case STORMVEIL_CASTLE:
			switch (pEnemy->nEnemyType) {
				case 1:
					strcpy(pEnemyName, "GODRICK SOLDIER");
					break;

				case 2:
					strcpy(pEnemyName, "GODRICK ARCHER");
					break;

				case 3:
					strcpy(pEnemyName, "GODRICK KNIGHT");
					break;
			}
		break;

		case RAYA_LUCARIA_ACADEMY:
			switch (pEnemy->nEnemyType) {
				case 1:
					strcpy(pEnemyName, "LIVING JAR");
					break;

				case 2:
					strcpy(pEnemyName, "GLINSTONE SORCERER");
					break;

				case 3:
					strcpy(pEnemyName, "BATTLEMAGE");
					break;
			}
		break;

		case REDMANE_CASTLE:
			switch (pEnemy->nEnemyType) {
				case 1:
					strcpy(pEnemyName, "RADAHN SOLDIER");
					break;

				case 2:
					strcpy(pEnemyName, "RADAHN ARCHER");
					break;

				case 3:
					strcpy(pEnemyName, "RADAHN KNIGHT");
					break;
			}
		break;

		case VOLCANO_MANOR:
			switch (pEnemy->nEnemyType) {
				case 1:
					strcpy(pEnemyName, "MAN-SERPENT");
					break;

				case 2:
					strcpy(pEnemyName, "MAGE-SERPENT");
					break;

				case 3:
					strcpy(pEnemyName, "ABDUCTOR VIRGIN");
					break;
			}
		break;

		case LEYNDELL_ROYAL_CAPITAL: 
			switch (pEnemy->nEnemyType) {
				case 1:
					strcpy(pEnemyName, "LEYNDELL SOLDIER");
					break;

				case 2:
					strcpy(pEnemyName, "LEYNDELL ARCHER");
					break;

				case 3:
					strcpy(pEnemyName, "LEYNDELL KNIGHT");
					break;
			}
		break;
	}

	pEnemy->pEnemyName = pEnemyName;
}

void checkGameOver(Player sPlayer, Enemy sEnemy, int* pBattleFinished) {
	if (sPlayer.sPlayerAreaDetails.nCurrentHealth == 0) {
		*pBattleFinished = 1;
	}

	else if (sEnemy.nCurrentHealth == 0) {
		*pBattleFinished = 1;
	}
}

int getPlayerPhysicalDmg(Player sPlayer, Enemy sEnemy) {
	int nDamageToBeDealt = (sPlayer.sPlayerStats.nStrength) * (1 - sEnemy.fPhysicalDef);
	return nDamageToBeDealt;
}

int getPlayerSorceryDmg(Player sPlayer, Enemy sEnemy) {
	int nDamageToBeDealt = (sPlayer.sPlayerStats.nIntelligence) * (1 - sEnemy.fSorceryDef);
	return nDamageToBeDealt;
}

int getPlayerIncantationDmg(Player sPlayer, Enemy sEnemy) {
	int nDamageToBeDealt = (sPlayer.sPlayerStats.nFaith) * (1 - sEnemy.fIncantationDef);
	return nDamageToBeDealt;
}

void usePhysicalAttack(Player sPlayer, Enemy* pEnemy) {
	int nDamageToBeDealt = getPlayerPhysicalDmg(sPlayer, *pEnemy);

	pEnemy->nCurrentHealth = pEnemy->nCurrentHealth - nDamageToBeDealt;

	if (pEnemy->nCurrentHealth <= 0) {
		pEnemy->nCurrentHealth = 0;
	}
}

void useSorceryAttack(Player sPlayer, Enemy* pEnemy) {
	int nDamageToBeDealt = getPlayerSorceryDmg(sPlayer, *pEnemy);

	pEnemy->nCurrentHealth = pEnemy->nCurrentHealth - nDamageToBeDealt;

	if (pEnemy->nCurrentHealth <= 0) {
		pEnemy->nCurrentHealth = 0;
	}
}

void useIncantationAttack(Player sPlayer, Enemy* pEnemy) {
	int nDamageToBeDealt = getPlayerIncantationDmg(sPlayer, *pEnemy);

	pEnemy->nCurrentHealth = pEnemy->nCurrentHealth - nDamageToBeDealt;

	if (pEnemy->nCurrentHealth <= 0) {
		pEnemy->nCurrentHealth = 0;
	}
}

int getDodgeRate(Player sPlayer) {
	int nDodgeRate = (20 + ((sPlayer.sPlayerStats.nEndurance) / 2)) / 100;

	return nDodgeRate;
}

int useDodge(Player sPlayer) {
	int nDodgeRate =  getDodgeRate(sPlayer) * 100;
	int nSuccess = 0;

	int nRandomNum = randomNumberBetween(100, 1);

	if (nRandomNum <= nDodgeRate) {
		nSuccess = 1;
	}

	return nSuccess;
}

void drinkPotion(Player* pPlayer) {
	float fHealingRate = randomNumberBetween(50, 25) / (float) 100;

	int nAddHealth = fHealingRate * pPlayer->sPlayerAreaDetails.nMaxHealth;


	if (pPlayer->nPotions > 0) {
		if (pPlayer->sPlayerAreaDetails.nCurrentHealth < pPlayer->sPlayerAreaDetails.nMaxHealth) {
			pPlayer->sPlayerAreaDetails.nCurrentHealth += nAddHealth;

			if (pPlayer->sPlayerAreaDetails.nCurrentHealth > pPlayer->sPlayerAreaDetails.nMaxHealth) {
				pPlayer->sPlayerAreaDetails.nCurrentHealth = pPlayer->sPlayerAreaDetails.nMaxHealth;
			}

			pPlayer->nPotions--;
		}	
	}
}

void enemyAttack(Player* pPlayer, Enemy sEnemy) {
	int nIncomingDamage = sEnemy.nFinalAttack;

	pPlayer->sPlayerAreaDetails.nCurrentHealth -= nIncomingDamage;
}

void getIncomingDmg(int nAreaIndex, Enemy* pEnemy) {
	pEnemy->nBaseAttack = randomNumberBetween(pEnemy->nAttackUpper, pEnemy->nAttackLower);
	pEnemy->nFinalAttack = nAreaIndex * pEnemy->nBaseAttack;
}