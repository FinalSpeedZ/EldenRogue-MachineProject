#include "level_up.h"

void openLevelUp(Player* pPlayer) {
	int nInput = 0;

	do {
		system("cls");

		printLevelUpHeader();

		//fix UI of this
		printOneBoxedStats("RUNES", pPlayer->nRunes);
		printMiddleSubHeader(pPlayer->strPlayerJobClass);

		printStats(*pPlayer);

		printMiddleStats("RUNE COST", calculateRuneCost(pPlayer->nLevel));

		printTwoLongOptions(HEALTH, "LEVEL HEALTH", ENDURANCE, "LEVEL ENDURANCE");
		printTwoLongOptions(DEXTERITY, "LEVEL DEXTERITY", STRENGTH, "LEVEL STRENGTH");
		printTwoLongOptions(INTELLIGENCE, "LEVEL INTELLIGENCE", FAITH, "LEVEL FAITH");
		printCenterOption(0, OPTION_BACK);

		printFooter();
		printInputDivider();

		getIntInput(&nInput, 0, 6);
		processLevelUpInput(nInput, pPlayer);	
	} while (nInput != 0);
}

void processLevelUpInput(int nInput, Player* pPlayer) {
	switch (nInput) {
		case HEALTH:
			levelUpStatChecker("HEALTH", pPlayer, &(pPlayer->sPlayerStats.nHealth));
			break;

		case ENDURANCE:
			levelUpStatChecker("ENDURANCE", pPlayer, &(pPlayer->sPlayerStats.nEndurance));
			break;

		case DEXTERITY:
			levelUpStatChecker("DEXTERITY", pPlayer, &(pPlayer->sPlayerStats.nDexterity));
			break;		

		case STRENGTH:
			levelUpStatChecker("STRENGTH", pPlayer, &(pPlayer->sPlayerStats.nStrength));
			break;	

		case INTELLIGENCE:
			levelUpStatChecker("INTELLIGENCE", pPlayer, &(pPlayer->sPlayerStats.nIntelligence));
			break;

		case FAITH:
			levelUpStatChecker("FAITH", pPlayer, &(pPlayer->sPlayerStats.nFaith));
	}
}

int calculateRuneCost(int nPlayerLevel) {
	int nRunes = (nPlayerLevel * 100) / 2;

	return nRunes;
}

void levelUpStatChecker(char strStatName[], Player* pPlayer, int* pPlayerStat) {
	if (pPlayer->nRunes >= calculateRuneCost(pPlayer->nLevel)) {
		if (*pPlayerStat >= LEVEL_MAX) {
			printMessage(SYSTEM_MESSAGE, "UNSUCCESSFUL UPGRADE!");
			printMultiple(" ", SCREEN_PADDING_LEFT + HEADER_PADDING_LEFT);
			printf("%s IS ALREADY MAXED OUT\n", strStatName);
		}
		else {
			levelUpStat(pPlayerStat, pPlayer);
			printMessage(SYSTEM_MESSAGE, "SUCCESSFUL UPGRADE!");
			printMultiple(" ", SCREEN_PADDING_LEFT + HEADER_PADDING_LEFT);
			printf("PLAYER'S %s LEVELLED UP BY 1\n", strStatName);
		}
	}
	else {
		printMessage(SYSTEM_MESSAGE, "UNSUCCESSFUL UPGRADE!");
		printMultiple(" ", SCREEN_PADDING_LEFT + HEADER_PADDING_LEFT);
		printf("YOU DON'T HAVE ENOUGH RUNES\n");
	}

	pressEnter();
}

void levelUpStat(int* pStat, Player* pPlayer) {
	*pStat += 1;
	pPlayer->nRunes -= calculateRuneCost(pPlayer->nLevel);
	pPlayer->nLevel += 1;
}