#include "initializer.h"

void initializePlayer(Player* pPlayer) {

	strcpy(pPlayer->strPlayerName, "");
	initializeJobClassStats(pPlayer);
	resetRunes(&pPlayer->nRunes);
	initializeShards(&pPlayer->nShards);
	resetPotions(&pPlayer->nPotions);
	initializeAreaDetails(&pPlayer->sPlayerAreaDetails);
	initializeUnlockedAreas(&pPlayer->sPlayerUnlockedAreas);
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
	*pRunes = 0;
}

void initializeShards(int* pShards) {
	*pShards = 0;
}

void resetPotions(int* pPotions) {
	*pPotions = 8;
}

void initializeAreaDetails(AreaDetails* pPlayerAreaDetails) {
	pPlayerAreaDetails->nRowLocation = 1;
	pPlayerAreaDetails->nColumnLocation = 1;
}

void initializeUnlockedAreas(UnlockedAreas* pPlayerUnlockedAreas) {
	pPlayerUnlockedAreas->nStormveilFastTravel = 1;
	pPlayerUnlockedAreas->nRayaLucariaFastTravel = 1;
	pPlayerUnlockedAreas->nRedmaneFastTravel = 1;
	pPlayerUnlockedAreas->nVolcanoFastTravel = 1;
	pPlayerUnlockedAreas->nLeyndellFastTravel = 1;
	pPlayerUnlockedAreas->nEldenThroneCredits = 1;
}