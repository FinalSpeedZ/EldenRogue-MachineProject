#include "job_class_creation.h"

void openJobClassSelection(Player* pPlayer) {
	int nInput = 0;

	do {
		system("cls");

		// change to printHeader (ascii header)
		printMultiple("\n", SCREEN_PADDING_TOP);
		printMultiple(" ", SCREEN_PADDING_LEFT + CENTER_OPTION_PADDING + HEADER_PADDING_LEFT);
		printf("CHARACTER CREATION\n");
		printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT);
		printMultiple("─", SCREEN_WIDTH);
		printf("\n\n");

		printMiddleSubHeader("CHOOSE YOUR JOB CLASS");

		printTwoOptions(VAGABOND, "VAGABOND", SAMURAI, "SAMURAI");
		printTwoOptions(WARRIOR, "WARRIOR", HERO, "HERO");
		printTwoOptions(ASTROLOGER, "ASTROLOGER", PROPHET, "PROPHET");
		printCenterOption(0, OPTION_BACK);

		printFooter();
		printInputDivider();

		getIntInput(&nInput, 0, 6);
		processJobCreationInput(nInput, pPlayer);
	} while (nInput < 0 || nInput > 6);
}

void processJobCreationInput(int nInput, Player* pPlayer) {
	switch (nInput) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
			loadJobClassStats(nInput, pPlayer);
			openJobClassStats(nInput, pPlayer);
	}
}

void openJobClassStats(int nJobClass, Player* pPlayer) {
	int nInput = 0;

	do {
		system("cls");

		// change to printHeader (ascii header)
		printMultiple("\n", SCREEN_PADDING_TOP);
		printMultiple(" ", SCREEN_PADDING_LEFT + CENTER_OPTION_PADDING + HEADER_PADDING_LEFT);
		printf("CHARACTER CREATION\n");
		printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT);
		printMultiple("─", SCREEN_WIDTH);
		printf("\n\n");

		printMiddleSubHeader(pPlayer->strPlayerJobClass);
		printStats(*pPlayer);

		printTwoOptions(0, OPTION_BACK, 1, OPTION_CONFIRM);

		printFooter();
		printInputDivider();

		getIntInput(&nInput, 0, 1);
		processJobClassStatsInput(nInput, pPlayer);
	} while (nInput != 0 && nInput != 1);
}

void processJobClassStatsInput(int nInput, Player* pPlayer) {
	switch (nInput) {
		case 0:
			openJobClassSelection(pPlayer);
			ResetJobClassStats(pPlayer);
	}
}

void ResetJobClassStats(Player* pPlayer) {
	pPlayer->nLevel = 0;
	strcpy(pPlayer->strPlayerJobClass, "");

	pPlayer->sPlayerStats.nHealth       = 0;
	pPlayer->sPlayerStats.nEndurance    = 0;
	pPlayer->sPlayerStats.nDexterity    = 0;
	pPlayer->sPlayerStats.nStrength     = 0;
	pPlayer->sPlayerStats.nIntelligence = 0;
	pPlayer->sPlayerStats.nFaith        = 0;
}


void loadJobClassStats(int nJobClass, Player* pPlayer) {
	switch (nJobClass) {
		case VAGABOND:
			loadVagabondStats(pPlayer);
			break;

		case SAMURAI:
			loadSamuraiStats(pPlayer);
			break;

		case WARRIOR:
			loadWarriorStats(pPlayer);
			break;

		case HERO:
			loadHeroStats(pPlayer);
			break;

		case ASTROLOGER:
			loadAstrologerStats(pPlayer);
			break;

		case PROPHET:
			loadProphetStats(pPlayer);
	}
}

void loadVagabondStats(Player* pPlayer) {
	pPlayer->nLevel = 9;
	strcpy(pPlayer->strPlayerJobClass, "VAGABOND");

	pPlayer->sPlayerStats.nHealth       = 15;
	pPlayer->sPlayerStats.nEndurance    = 11;
	pPlayer->sPlayerStats.nDexterity    = 13;
	pPlayer->sPlayerStats.nStrength     = 14;
	pPlayer->sPlayerStats.nIntelligence = 9;
	pPlayer->sPlayerStats.nFaith        = 9;
}

void loadSamuraiStats(Player* pPlayer) {
	pPlayer->nLevel = 9;
	strcpy(pPlayer->strPlayerJobClass, "SAMURAI");

	pPlayer->sPlayerStats.nHealth       = 12;
	pPlayer->sPlayerStats.nEndurance    = 13;
	pPlayer->sPlayerStats.nDexterity    = 15;
	pPlayer->sPlayerStats.nStrength     = 12;
	pPlayer->sPlayerStats.nIntelligence = 9;
	pPlayer->sPlayerStats.nFaith        = 8;
}

void loadWarriorStats(Player* pPlayer) {
	pPlayer->nLevel = 8;
	strcpy(pPlayer->strPlayerJobClass, "WARRIOR");

	pPlayer->sPlayerStats.nHealth       = 11;
	pPlayer->sPlayerStats.nEndurance    = 11;
	pPlayer->sPlayerStats.nDexterity    = 16;
	pPlayer->sPlayerStats.nStrength     = 10;
	pPlayer->sPlayerStats.nIntelligence = 10;
	pPlayer->sPlayerStats.nFaith        = 8;	
}

void loadHeroStats(Player* pPlayer) {
	pPlayer->nLevel = 7;
	strcpy(pPlayer->strPlayerJobClass, "HERO");

	pPlayer->sPlayerStats.nHealth       = 14;
	pPlayer->sPlayerStats.nEndurance    = 12;
	pPlayer->sPlayerStats.nDexterity    = 9;
	pPlayer->sPlayerStats.nStrength     = 16;
	pPlayer->sPlayerStats.nIntelligence = 7;
	pPlayer->sPlayerStats.nFaith        = 8;	
}

void loadAstrologerStats(Player* pPlayer) {
	pPlayer->nLevel = 6;
	strcpy(pPlayer->strPlayerJobClass, "ASTROLOGER");

	pPlayer->sPlayerStats.nHealth       = 9;
	pPlayer->sPlayerStats.nEndurance    = 9;
	pPlayer->sPlayerStats.nDexterity    = 12;
	pPlayer->sPlayerStats.nStrength     = 8;
	pPlayer->sPlayerStats.nIntelligence = 16;
	pPlayer->sPlayerStats.nFaith        = 7;
}

void loadProphetStats(Player* pPlayer) {
	pPlayer->nLevel = 7;
	strcpy(pPlayer->strPlayerJobClass, "PROPHET");

	pPlayer->sPlayerStats.nHealth       = 10;
	pPlayer->sPlayerStats.nEndurance    = 8;
	pPlayer->sPlayerStats.nDexterity    = 10;
	pPlayer->sPlayerStats.nStrength     = 11;
	pPlayer->sPlayerStats.nIntelligence = 7;
	pPlayer->sPlayerStats.nFaith        = 16;	
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                            PRINTER FUNCTIONS                            *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 void printStats(Player sPlayer) {
 	printMiddleStats("LEVEL", sPlayer.nLevel);
 	printTwoStats("HEALTH", sPlayer.sPlayerStats.nHealth, 
 				  "ENDURANCE", sPlayer.sPlayerStats.nEndurance);
 	printTwoStats("DEXTERITY", sPlayer.sPlayerStats.nDexterity,
 		          "STRENGTH", sPlayer.sPlayerStats.nStrength);
 	printTwoStats("INTELLIGENCE", sPlayer.sPlayerStats.nIntelligence,
 		          "FAITH", sPlayer.sPlayerStats.nFaith);
 	printf("\n\n");
 }