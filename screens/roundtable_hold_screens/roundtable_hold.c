#include "roundtable_hold.h"
#include "fast_travel.h"
#include "level_up.h"

void openRoundTableHold(Player sPlayer) {
	int nInput = 0;
	
	do {
		system("cls");

		// change to printHeader (ascii header)
		printMultiple("\n", SCREEN_PADDING_TOP);
		printMiddleText("ROUNDTABLE HOLD", "", "");
		printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT);
		printMultiple("─", SCREEN_WIDTH);
		printf("\n\n");

		//fix UI of this
		printOneBoxedStats("RUNES", sPlayer.nRunes);
		printMultiple(" ", SCREEN_PADDING_LEFT + TWO_OPTION_PADDING);
		printf("NAME: %s | %s\n", sPlayer.strPlayerName, sPlayer.strPlayerJobClass);
		printMultiple(" ", SCREEN_PADDING_LEFT + TWO_OPTION_PADDING);
		printf("LEVEL: %d\n", sPlayer.nLevel);
		printMultiple(" ", SCREEN_PADDING_LEFT + TWO_OPTION_PADDING);
		printf("SHARDS: %d\n\n", sPlayer.nShards);

		printTwoOptions(1, "FAST TRAVEL", 2, "LEVEL UP");
		printTwoOptions(3, "INVENTORY", 4, "SHOP");
		printTwoOptions(5, "SAVE", 0, "QUIT GAME");

		printFooter();
		printInputDivider();

		getIntInput(&nInput, 0, 5);
		processRoundTableHoldInput(nInput, &sPlayer);	
	} while (nInput != 0);
}

void processRoundTableHoldInput(int nInput, Player* pPlayer) {
	switch (nInput) {
		case FAST_TRAVEL:
			openFastTravel(pPlayer);
			break;
		case LEVEL_UP:
			openLevelUp(pPlayer);
			break;
	}
}
