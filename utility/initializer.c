#include "initializer.h"

Player initializePlayer() {
	Player sPlayer;

	strcpy(sPlayer.strPlayerName, "");
	InitializeJobClassStats(&sPlayer);
	ResetRunes(&sPlayer.nRunes);
	InitializeShards(&sPlayer.nShards);

	return sPlayer;
}

void InitializeJobClassStats(Player* pPlayer) {
	pPlayer->nLevel = 0;

	strcpy(pPlayer->strPlayerJobClass, "");

	pPlayer->sPlayerStats.nHealth       = 0;
	pPlayer->sPlayerStats.nEndurance    = 0;
	pPlayer->sPlayerStats.nDexterity    = 0;
	pPlayer->sPlayerStats.nStrength     = 0;
	pPlayer->sPlayerStats.nIntelligence = 0;
	pPlayer->sPlayerStats.nFaith        = 0;
}

void ResetRunes(int* pRunes) {
	*pRunes = 0;
}

void InitializeShards(int* pShards) {
	*pShards = 0;
}