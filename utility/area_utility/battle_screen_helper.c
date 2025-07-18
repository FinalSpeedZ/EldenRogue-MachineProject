#include "battle_screen_helper.h"

void setEnemyStats(int nAreaIndex, Enemy* pEnemy) {
	setEnemyType(&pEnemy->nEnemyType);

	setEnemyHealthRange(pEnemy);
	setEnemyBaseHealth(pEnemy);
	setEnemyFinalHealth(nAreaIndex, pEnemy);

	setEnemyAttackRange(pEnemy);
	setEnemyBaseAttack(pEnemy);
	setEnemyFinalAttack(nAreaIndex, pEnemy);

	setEnemyDefense(pEnemy);
	setEnemyName(nAreaIndex, pEnemy);
	setEnemyColor(nAreaIndex, pEnemy);
}

void setEnemyType(int* pEnemyType) {
	*pEnemyType = randomNumberBetween(3, 1);	
}

void setEnemyHealthRange(Enemy* pEnemy) {
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

void setEnemyBaseHealth(Enemy* pEnemy) {
	pEnemy->nBaseHealth = randomNumberBetween(pEnemy->nHealthUpper, pEnemy->nHealthLower);
}

void setEnemyFinalHealth(int nAreaIndex, Enemy* pEnemy) {
	pEnemy->nFinalHealth = nAreaIndex * pEnemy->nBaseHealth;
	pEnemy->nCurrentHealth = pEnemy->nFinalHealth;
}

void setEnemyAttackRange(Enemy* pEnemy) {
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

void setEnemyBaseAttack(Enemy* pEnemy) {
	pEnemy->nBaseAttack = randomNumberBetween(pEnemy->nAttackUpper, pEnemy->nAttackLower);
}

void setEnemyFinalAttack(int nAreaIndex, Enemy* pEnemy) {
	pEnemy->nFinalAttack = nAreaIndex * pEnemy->nBaseAttack;
}

void setEnemyDefense(Enemy* pEnemy) {
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

void setEnemyName(int nAreaIndex, Enemy* pEnemy) {
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

void setEnemyColor(int nAreaIndex, Enemy* pEnemy) {
	switch (nAreaIndex) {
		case STORMVEIL_CASTLE:
			switch (pEnemy->nEnemyType) {
				case 1:
					pEnemy->sTint.nColor1 = 46;
					pEnemy->sTint.nColor2 = 243;
					pEnemy->sTint.nColor3 = 252;
					break;

				case 2:
					pEnemy->sTint.nColor1 = 124;
					pEnemy->sTint.nColor2 = 243;
					pEnemy->sTint.nColor3 = 252;
					break;	

				case 3:
					pEnemy->sTint.nColor1 = 33;
					pEnemy->sTint.nColor2 = 243;
					pEnemy->sTint.nColor3 = 252;
					break;				
			}
		break;

		case RAYA_LUCARIA_ACADEMY:
			switch (pEnemy->nEnemyType) {
				case 1:
					pEnemy->sTint.nColor1 = 226;
					pEnemy->sTint.nColor2 = 183;
					pEnemy->sTint.nColor3 = 219;
					break;

				case 2:
					pEnemy->sTint.nColor1 = 117;
					pEnemy->sTint.nColor2 = 183;
					pEnemy->sTint.nColor3 = 219;
					break;	

				case 3:
					pEnemy->sTint.nColor1 = 225;
					pEnemy->sTint.nColor2 = 186;
					pEnemy->sTint.nColor3 = 219;
					break;				
			}
		break;

		case REDMANE_CASTLE:
			switch (pEnemy->nEnemyType) {
				case 1:
					pEnemy->sTint.nColor1 = 52;
					pEnemy->sTint.nColor2 = 22;
					pEnemy->sTint.nColor3 = 58;
					break;

				case 2:
					pEnemy->sTint.nColor1 = 100;
					pEnemy->sTint.nColor2 = 22;
					pEnemy->sTint.nColor3 = 58;
					break;	

				case 3:
					pEnemy->sTint.nColor1 = 90;
					pEnemy->sTint.nColor2 = 22;
					pEnemy->sTint.nColor3 = 58;
					break;				
			}
		break;

		case VOLCANO_MANOR:
			switch (pEnemy->nEnemyType) {
				case 1:
					pEnemy->sTint.nColor1 = 46;
					pEnemy->sTint.nColor2 = 190;
					pEnemy->sTint.nColor3 = 154;
					break;

				case 2:
					pEnemy->sTint.nColor1 = 115;
					pEnemy->sTint.nColor2 = 190;
					pEnemy->sTint.nColor3 = 154;
					break;	

				case 3:
					pEnemy->sTint.nColor1 = 184;
					pEnemy->sTint.nColor2 = 190;
					pEnemy->sTint.nColor3 = 154;
					break;				
			}
		break;

		case LEYNDELL_ROYAL_CAPITAL:
			switch (pEnemy->nEnemyType) {
				case 1:
					pEnemy->sTint.nColor1 = 39;
					pEnemy->sTint.nColor2 = 219;
					pEnemy->sTint.nColor3 = 183;
					break;

				case 2:
					pEnemy->sTint.nColor1 = 104;
					pEnemy->sTint.nColor2 = 219;
					pEnemy->sTint.nColor3 = 183;
					break;	

				case 3:
					pEnemy->sTint.nColor1 = 64;
					pEnemy->sTint.nColor2 = 219;
					pEnemy->sTint.nColor3 = 183;
					break;				
			}
		break;
	}
}

void checkBattleOver(Player sPlayer, Enemy sEnemy, int* pBattleFinished) {
	if (sPlayer.sPlayerAreaDetails.nCurrentHealth == 0) {
		*pBattleFinished = 1;
	}

	else if (sEnemy.nCurrentHealth == 0) {
		*pBattleFinished = 2;
	}
}

int getPlayerPhysicalDmg(Player sPlayer, Enemy sEnemy) {
	int nDamageToBeDealt;
	if (sPlayer.sPlayerEquipment.pCurrentWeapon == NULL) {
		nDamageToBeDealt = (sPlayer.sPlayerStats.nStrength + 0) * (1 - sEnemy.fPhysicalDef);
	}
	else {
		nDamageToBeDealt = (sPlayer.sPlayerStats.nStrength + sPlayer.sPlayerEquipment.pCurrentWeapon->pWeaponStats->nWeaponStrength) * (1 - sEnemy.fPhysicalDef);		
	}
	
	return nDamageToBeDealt;
}

int getPlayerSorceryDmg(Player sPlayer, Enemy sEnemy) {
	int nDamageToBeDealt;
	if (sPlayer.sPlayerEquipment.pCurrentWeapon == NULL) {
		nDamageToBeDealt = (sPlayer.sPlayerStats.nIntelligence + 0) * (1 - sEnemy.fPhysicalDef);
	}
	else {
		nDamageToBeDealt = (sPlayer.sPlayerStats.nStrength + sPlayer.sPlayerEquipment.pCurrentWeapon->pWeaponStats->nWeaponIntelligence) * (1 - sEnemy.fPhysicalDef);		
	}
	
	return nDamageToBeDealt;
}

int getPlayerIncantationDmg(Player sPlayer, Enemy sEnemy) {
	int nDamageToBeDealt;
	if (sPlayer.sPlayerEquipment.pCurrentWeapon == NULL) {
		nDamageToBeDealt = (sPlayer.sPlayerStats.nFaith + 0) * (1 - sEnemy.fPhysicalDef);
	}
	else {
		nDamageToBeDealt = (sPlayer.sPlayerStats.nFaith + sPlayer.sPlayerEquipment.pCurrentWeapon->pWeaponStats->nWeaponFaith) * (1 - sEnemy.fPhysicalDef);		
	}
	
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

float getDodgeRate(Player sPlayer) {
	float fDodgeRate;

	if (sPlayer.sPlayerEquipment.pCurrentWeapon == NULL) {
		fDodgeRate = (20 + ((float) (sPlayer.sPlayerStats.nEndurance + 0) / 2)) / 100;
	}
	else {
		fDodgeRate = (20 + ((float) (sPlayer.sPlayerStats.nEndurance + sPlayer.sPlayerEquipment.pCurrentWeapon->pWeaponStats->nWeaponEndurance) / 2)) / 100;		
	}
	return fDodgeRate;
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

int healthToBeAdded(Player* pPlayer) {
	float fHealingRate = randomNumberBetween(50, 25) / (float) 100;

	int nAddHealth = fHealingRate * pPlayer->sPlayerAreaDetails.nMaxHealth; 

	if (pPlayer->sPlayerAreaDetails.nCurrentHealth + nAddHealth > pPlayer->sPlayerAreaDetails.nMaxHealth) {
		nAddHealth = pPlayer->sPlayerAreaDetails.nMaxHealth - pPlayer->sPlayerAreaDetails.nCurrentHealth;
	}

	return nAddHealth;
}

void drinkPotion(Player* pPlayer, int nHealthGained) {
	int nAddHealth = nHealthGained;

	if (pPlayer->sPlayerEquipment.nPotions > 0 && nAddHealth != 0) {
		
		pPlayer->sPlayerAreaDetails.nCurrentHealth += nAddHealth;

		pPlayer->sPlayerEquipment.nPotions--;
	}	
}

void enemyAttack(Player* pPlayer, Enemy sEnemy) {
	int nIncomingDamage = sEnemy.nFinalAttack;

	pPlayer->sPlayerAreaDetails.nCurrentHealth -= nIncomingDamage;

	if (pPlayer->sPlayerAreaDetails.nCurrentHealth <= 0) {
		pPlayer->sPlayerAreaDetails.nCurrentHealth = 0;
	}
}

void getIncomingDmg(int nAreaIndex, Enemy* pEnemy, int nBoss) {
	pEnemy->nBaseAttack = randomNumberBetween(pEnemy->nAttackUpper, pEnemy->nAttackLower);
	if (!nBoss) {
		pEnemy->nFinalAttack = nAreaIndex * pEnemy->nBaseAttack;
	}
	else {
		pEnemy->nFinalAttack = pEnemy->nBaseAttack;		
	}
}

int computeGainedRunes(Enemy sEnemy, int nBoss) {
	int nMultiplier = 2;

	if (nBoss) {
		nMultiplier = 5;
	}

	int nRunesGained = sEnemy.nFinalHealth * nMultiplier;
	return nRunesGained;
}

void setBossStats(int nAreaIndex, Enemy* pEnemy, int nEldenThroneBossNum) {
	setBossColor(nAreaIndex, pEnemy, nEldenThroneBossNum);
	setBossName(nAreaIndex, nEldenThroneBossNum, pEnemy);
	setBossHealth(nAreaIndex, nEldenThroneBossNum, pEnemy);
	setBossAttackRange(nAreaIndex, nEldenThroneBossNum, pEnemy);
	setBossDefense(nAreaIndex, nEldenThroneBossNum, pEnemy);
	setBossFinalAttack(pEnemy);
}

void setBossColor(int nAreaIndex, Enemy* pEnemy, int nEldenThroneBossNum) {
	switch (nAreaIndex) {
		case STORMVEIL_CASTLE:
			pEnemy->sTint.nColor1 = 11;
			pEnemy->sTint.nColor2 = 243;
			pEnemy->sTint.nColor3 = 252;
			break;	

		case RAYA_LUCARIA_ACADEMY:
			pEnemy->sTint.nColor1 = 11;
			pEnemy->sTint.nColor2 = 183;
			pEnemy->sTint.nColor3 = 219;
			break;	

		case VOLCANO_MANOR:
			pEnemy->sTint.nColor1 = 11;
			pEnemy->sTint.nColor2 = 190;
			pEnemy->sTint.nColor3 = 154;
			break;	

		case LEYNDELL_ROYAL_CAPITAL:
			pEnemy->sTint.nColor1 = 11;
			pEnemy->sTint.nColor2 = 219;
			pEnemy->sTint.nColor3 = 183;
			break;	

		case THE_ELDEN_THRONE:
			switch (nEldenThroneBossNum) {
				case 1:
					pEnemy->sTint.nColor1 = 11;
					pEnemy->sTint.nColor2 = 228;
					pEnemy->sTint.nColor3 = 230;
					break;

				case 2:
					pEnemy->sTint.nColor1 = 226;
					pEnemy->sTint.nColor2 = 228;
					pEnemy->sTint.nColor3 = 230;
					break;
			}			
	}	
}

int getBossNameLength(int nAreaIndex, int nEldenThroneBossNum) {
	int nLength;

	switch (nAreaIndex) {
		case STORMVEIL_CASTLE:
			nLength = strlen("GODRICK THE GRAFTED");
			break;

		case RAYA_LUCARIA_ACADEMY:
			nLength = strlen("RENNALA, QUEEN OF THE FULL MOON");
			break;

		case REDMANE_CASTLE:
			nLength = strlen("STARSCOURGE RADAHN");
			break;

		case VOLCANO_MANOR:
			nLength = strlen("PRAETOR RYKARD");
			break;

		case LEYNDELL_ROYAL_CAPITAL:
			nLength = strlen("MORGOTT THE OMEN KING");
			break;

		case THE_ELDEN_THRONE:
			switch (nEldenThroneBossNum) {
				case 1:
					nLength = strlen("RADAGON OF THE GOLDEN ORDER");
					break;

				case 2: 
					nLength = strlen("THE ELDEN BEAST");
					break;
			}
	}

	return nLength;
}

void setBossName(int nAreaIndex, int nEldenThroneBossNum, Enemy* pEnemy) {
	int nLength = getBossNameLength(nAreaIndex, nEldenThroneBossNum);
	char* pEnemyName = malloc(sizeof(char) * nLength + 1);

	switch (nAreaIndex) {
		case STORMVEIL_CASTLE:
			strcpy(pEnemyName, "GODRICK THE GRAFTED");
			break;

		case RAYA_LUCARIA_ACADEMY:
			strcpy(pEnemyName, "RENNALA, QUEEN OF THE FULL MOON");
			break;

		case REDMANE_CASTLE:
			strcpy(pEnemyName, "STARSCOURGE RADAHN");
			break;

		case VOLCANO_MANOR:
			strcpy(pEnemyName, "PRAETOR RYKARD");
			break;

		case LEYNDELL_ROYAL_CAPITAL:
			strcpy(pEnemyName, "MORGOTT THE OMEN KING");
			break;

		case THE_ELDEN_THRONE:
			switch (nEldenThroneBossNum) {
				case 1:
					strcpy(pEnemyName, "RADAGON OF THE GOLDEN ORDER");
					break;

				case 2:
					strcpy(pEnemyName, "THE ELDEN BEAST");
					break;
			}

	}		

	pEnemy->pEnemyName = pEnemyName;
}

void setBossHealth(int nAreaIndex, int nEldenThroneBossNum, Enemy* pEnemy) {
	switch (nAreaIndex) {
		case STORMVEIL_CASTLE:
			pEnemy->nFinalHealth = 200;
			pEnemy->nCurrentHealth = 200;
			break;

		case RAYA_LUCARIA_ACADEMY:
			pEnemy->nFinalHealth = 400;
			pEnemy->nCurrentHealth = 400;
			break;

		case REDMANE_CASTLE:
			pEnemy->nFinalHealth = 600;
			pEnemy->nCurrentHealth = 600;
			break;

		case VOLCANO_MANOR:
			pEnemy->nFinalHealth = 600;
			pEnemy->nCurrentHealth = 600;
			break;

		case LEYNDELL_ROYAL_CAPITAL:
			pEnemy->nFinalHealth = 800;
			pEnemy->nCurrentHealth = 800;
			break;

		case THE_ELDEN_THRONE:
			switch (nEldenThroneBossNum) {
				case 1:
					pEnemy->nFinalHealth = 1000;
					pEnemy->nCurrentHealth = 1000;
					break;

				case 2:
					pEnemy->nFinalHealth = 1250;
					pEnemy->nCurrentHealth = 1250;
					break;
			}
	}
}

void setBossAttackRange(int nAreaIndex, int nEldenThroneBossNum, Enemy* pEnemy) {
	switch (nAreaIndex) {
		case STORMVEIL_CASTLE:
			pEnemy->nAttackUpper = 300;
			pEnemy->nAttackLower = 150;
			break;

		case RAYA_LUCARIA_ACADEMY:
			pEnemy->nAttackUpper = 300;
			pEnemy->nAttackLower = 200;
			break;

		case REDMANE_CASTLE:
			pEnemy->nAttackUpper = 400;
			pEnemy->nAttackLower = 200;
			break;

		case VOLCANO_MANOR:
			pEnemy->nAttackUpper = 350;
			pEnemy->nAttackLower = 250;
			break;

		case LEYNDELL_ROYAL_CAPITAL:
			pEnemy->nAttackUpper = 500;
			pEnemy->nAttackLower = 250;
			break;

		case THE_ELDEN_THRONE:
			switch (nEldenThroneBossNum) {
				case 1:
					pEnemy->nAttackUpper = 600;
					pEnemy->nAttackLower = 300;
					break;

				case 2:
					pEnemy->nAttackUpper = 900;
					pEnemy->nAttackLower = 450;
					break;
			}
	}
}

void setBossDefense(int nAreaIndex, int nEldenThroneBossNum, Enemy* pEnemy) {
	switch (nAreaIndex) {
		case STORMVEIL_CASTLE:
			pEnemy->fPhysicalDef = 0.35;
			pEnemy->fSorceryDef = 0.20;
			pEnemy->fIncantationDef = 0.15;
			break;

		case RAYA_LUCARIA_ACADEMY:
			pEnemy->fPhysicalDef = 0.15;
			pEnemy->fSorceryDef = 0.35;
			pEnemy->fIncantationDef = 0.25;
			break;

		case REDMANE_CASTLE:
			pEnemy->fPhysicalDef = 0.30;
			pEnemy->fSorceryDef = 0.20;
			pEnemy->fIncantationDef = 0.20;
			break;

		case VOLCANO_MANOR:
			pEnemy->fPhysicalDef = 0.15;
			pEnemy->fSorceryDef = 0.25;
			pEnemy->fIncantationDef = 0.30;
			break;

		case LEYNDELL_ROYAL_CAPITAL:
			pEnemy->fPhysicalDef = 0.35;
			pEnemy->fSorceryDef = 0.30;
			pEnemy->fIncantationDef = 0.20;
			break;

		case THE_ELDEN_THRONE:
			switch (nEldenThroneBossNum) {
				case 1:
					pEnemy->fPhysicalDef = 0.35;
					pEnemy->fSorceryDef = 0.25;
					pEnemy->fIncantationDef = 0.40;
					break;

				case 2:
					pEnemy->fPhysicalDef = 0.25;
					pEnemy->fSorceryDef = 0.50;
					pEnemy->fIncantationDef = 0.40;
					break;
			}
	}
}

void setBossFinalAttack(Enemy* pEnemy) {
	pEnemy->nFinalAttack = randomNumberBetween(pEnemy->nAttackUpper, pEnemy->nAttackLower);
}