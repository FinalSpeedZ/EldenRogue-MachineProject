#include "initializer.h"

void initializePlayer(Player* pPlayer) {

	strcpy(pPlayer->strPlayerName, "");
	initializeJobClassStats(pPlayer);
	resetRunes(&pPlayer->nRunes);
	resetPotions(&pPlayer->nPotions);
	initializeAreaDetails(&pPlayer->sPlayerAreaDetails);
	initializeUnlockedAreas(&pPlayer->sPlayerUnlockedAreas);
	initializeShards(pPlayer);
	initializePlayerHealth(&pPlayer->sPlayerAreaDetails);
}

void initializeJobClassStats(Player* pPlayer) {
	pPlayer->nLevel = 0;

	strcpy(pPlayer->strPlayerJobClass, "");

	pPlayer->sPlayerStats.nHealth       = 0;
	pPlayer->sPlayerStats.nEndurance    = 0;
	pPlayer->sPlayerStats.nDexterity    = 0;
	pPlayer->sPlayerStats.nStrength     = 0;
	pPlayer->sPlayerStats.nIntelligence = 0;
	pPlayer->sPlayerStats.nFaith        = 0;
}

void resetRunes(int* pRunes) {
	*pRunes = 1000;
}

void initializeShards(Player* pPlayer) {
	pPlayer->nShards = pPlayer->sPlayerUnlockedAreas.nStormveilFastTravel + pPlayer->sPlayerUnlockedAreas.nRayaLucariaFastTravel +
	 		           pPlayer->sPlayerUnlockedAreas.nRedmaneFastTravel + pPlayer->sPlayerUnlockedAreas.nVolcanoFastTravel +
	 		           pPlayer->sPlayerUnlockedAreas.nLeyndellFastTravel + pPlayer->sPlayerUnlockedAreas.nEldenThroneCredits;
}

void resetPotions(int* pPotions) {
	*pPotions = DEFAULT_POTION_COUNT;
}

void initializeAreaDetails(AreaDetails* pPlayerAreaDetails) {
	pPlayerAreaDetails->nRowLocation = 1;
	pPlayerAreaDetails->nColumnLocation = 1;
}

void initializeUnlockedAreas(UnlockedAreas* pPlayerUnlockedAreas) {
	pPlayerUnlockedAreas->nStormveilFastTravel = 0;
	pPlayerUnlockedAreas->nRayaLucariaFastTravel = 0;
	pPlayerUnlockedAreas->nRedmaneFastTravel = 0;
	pPlayerUnlockedAreas->nVolcanoFastTravel = 0;
	pPlayerUnlockedAreas->nLeyndellFastTravel = 0;
	pPlayerUnlockedAreas->nEldenThroneCredits = 0;
}

void initializePlayerHealth(AreaDetails* pPlayerAreaDetails) {
	pPlayerAreaDetails->nCurrentHealth = 30;
	pPlayerAreaDetails->nMaxHealth = 30;
}