#include "roundtable_hold.h"
#include "fast_travel.h"
#include "level_up.h"

void openRoundTableHold(Player sPlayer) {
	int nInput = 0;
	int nPrompt = 0;
	
	do {
		system("cls");

		printRoundtableHoldHeader();

		resetPotions(&sPlayer.nPotions);
		initializePlayerHealth(&sPlayer.sPlayerAreaDetails);

		printTwoOptions(1, "FAST TRAVEL", 2, "LEVEL UP");
		printTwoOptions(3, "INVENTORY", 4, "SHOP");
		printTwoOptions(5, "SAVE", 0, "QUIT GAME");

		printRoundtableNav(sPlayer, nPrompt);

		printFooter();
		printInputDivider();

		getIntInput(&nInput, 0, 5);
		processRoundTableHoldInput(nInput, &sPlayer, &nPrompt);	
	} while (nInput != 0);
}

void processRoundTableHoldInput(int nInput, Player* pPlayer, int* pPrompt) {
	switch (nInput) {
		case FAST_TRAVEL:
			*pPrompt = RH_FAST_TRAVEL_PROMPT;
			openFastTravel(pPlayer, pPrompt);
			break;

		case LEVEL_UP:
			openLevelUp(pPlayer);
			break;

		case SAVE: 
			printMessage("SYSTEM MESSAGE", "THIS FEATURE IS NOT AVAILABLE");
			pressEnter();
			break;
	}
}
