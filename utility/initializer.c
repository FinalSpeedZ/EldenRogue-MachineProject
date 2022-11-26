#include "initializer.h"

Player initializePlayer() {
	Player sPlayer;

	strcpy(sPlayer.strPlayerName, "");
	initializeJobClassStats(&sPlayer);
	resetRunes(&sPlayer.nRunes);
	initializeShards(&sPlayer.nShards);

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
	*pRunes = 1000;
}

void initializeShards(int* pShards) {
	*pShards = 0;
}