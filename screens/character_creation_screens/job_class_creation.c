#include "job_class_creation.h"

/*
	openJobClassSelection  allows user to select a job class
	
	@param pPlayer    The pointer to the player structure to be altered
	Pre-condition:   structure that pPlayer is pointing to is already initialized
*/
void openJobClassSelection(Player* pPlayer) {
	int nInput = 0;

	do {
		system("cls");

		printCharacterCreationHeader();

		printMiddleSubHeader("CHOOSE YOUR JOB CLASS");

		printTwoOptions(VAGABOND, "VAGABOND", SAMURAI, "SAMURAI");
		printTwoOptions(WARRIOR, "WARRIOR", HERO, "HERO");
		printTwoOptions(ASTROLOGER, "ASTROLOGER", PROPHET, "PROPHET");
		printCenterOption(0, OPTION_BACK);

		printFooter();
		printInputDivider();

		getIntInput(&nInput, 0, 6);
		processJobSelectionInput(nInput, pPlayer);
	} while (nInput < 0 || nInput > 6);
}

/*
	processJobSelectionInput  processess job class selection input
	
	@param nInput     int containing the input of the player
	@param pPlayer    The pointer to the player structure to be altered
	Pre-condition:   structure that pPlayer is pointing to is already initialized
*/
void processJobSelectionInput(int nInput, Player* pPlayer) {
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

/*
	openJobClassStats  opens the stats of the selected job class
	
	@param nJobClass     int containing the input of the player (selected job class)
	@param pPlayer    The pointer to the player structure to be altered
	Pre-condition:   structure that pPlayer is pointing to is already initialized
*/
void openJobClassStats(int nJobClass, Player* pPlayer) {
	int nInput = 0;

	do {
		system("cls");

		printCharacterCreationHeader();

		printMiddleSubHeader("CHOOSE YOUR JOB CLASS");

		printMiddleSubHeader(pPlayer->strPlayerJobClass);
		printStats(*pPlayer);

		printTwoOptions(0, OPTION_BACK, 1, OPTION_CONFIRM);

		printFooter();
		printInputDivider();

		getIntInput(&nInput, 0, 1);
		processJobClassStatsInput(nInput, pPlayer);
	} while (nInput != 0 && nInput != 1);

	initializePlayerHealth(pPlayer);
}

/*
	processJobClassStatsInput  processess job class stats input
	
	@param nInput     int containing the input of the player
	@param pPlayer    The pointer to the player structure to be altered
	Pre-condition:   structure that pPlayer is pointing to is already initialized
*/
void processJobClassStatsInput(int nInput, Player* pPlayer) {
	switch (nInput) {
		case 0:
			initializeJobClassStats(pPlayer);
			openJobClassSelection(pPlayer);
	}
}

/*
	loadJobClassStats  loads the stats of the selected job class
	
	@param nJobClass     int containing the input of the player
	@param pPlayer    The pointer to the player structure to be altered
	Pre-condition:   structure that pPlayer is pointing to is already initialized
*/
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

/*
	loadVagabondStats  loads the stats of the Vagabond job class
	
	@param pPlayer    The pointer to the player structure to be altered
	Pre-condition:   structure that pPlayer is pointing to is already initialized
*/
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

/*
	loadSamuraiStats  loads the stats of the Samurai job class
	
	@param pPlayer    The pointer to the player structure to be altered
	Pre-condition:   structure that pPlayer is pointing to is already initialized
*/
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

/*
	loadWarriorStats  loads the stats of the Warrior job class
	
	@param pPlayer    The pointer to the player structure to be altered
	Pre-condition:   structure that pPlayer is pointing to is already initialized
*/
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

/*
	loadHeroStats  loads the stats of the Hero job class
	
	@param pPlayer    The pointer to the player structure to be altered
	Pre-condition:   structure that pPlayer is pointing to is already initialized
*/
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

/*
	loadAstrologer  loads the stats of the Astrologer job class
	
	@param pPlayer    The pointer to the player structure to be altered
	Pre-condition:   structure that pPlayer is pointing to is already initialized
*/
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

/*
	loadProphetStats  loads the stats of the Prophets job class
	
	@param pPlayer    The pointer to the player structure to be altered
	Pre-condition:   structure that pPlayer is pointing to is already initialized
*/
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


 void printStats(Player sPlayer) {
 	printPlayerLevel(sPlayer.nLevel);
 	printTwoStats("HEALTH", sPlayer.sPlayerStats.nHealth, 
 				  "ENDURANCE", sPlayer.sPlayerStats.nEndurance);
 	printTwoStats("DEXTERITY", sPlayer.sPlayerStats.nDexterity,
 		          "STRENGTH", sPlayer.sPlayerStats.nStrength);
 	printTwoStats("INTELLIGENCE", sPlayer.sPlayerStats.nIntelligence,
 		          "FAITH", sPlayer.sPlayerStats.nFaith);
 	printf("\n");
 }

void printPlayerLevel(int nLevel) {
 	printMiddleStats("LEVEL", nLevel);
 }