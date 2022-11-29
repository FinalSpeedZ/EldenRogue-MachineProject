#include "initializer.h"

Player initializePlayer() {
	Player sPlayer;

	strcpy(sPlayer.strPlayerName, "");
	initializeJobClassStats(&sPlayer);
	resetRunes(&sPlayer.nRunes);
	initializeShards(&sPlayer.nShards);
	initializeAreaDetails(&sPlayer.sPlayerAreaDetails);

	return sPlayer;
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

void initializeAreaDetails(AreaDetails* pPlayerAreaDetails) {
	pPlayerAreaDetails->nRowLocation = 1;
	pPlayerAreaDetails->nColumnLocation = 1;
}