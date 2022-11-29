#include "title_screen.h"

#include "character_creation_screens/character_creation_screen.h"

void openTitleScreen(Player sPlayer) {
	int nInput = 0;

	do {
		system("cls");
		
		// change to printHeader (ascii header)
		printMultiple("\n", SCREEN_PADDING_TOP);
		printMiddleText("ELDEN ROGUE", "", "");
		printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT);
		printMultiple("─", SCREEN_WIDTH);
		printf("\n\n");

		printTwoOptions(1, OPTION_START, 2, OPTION_CONTINUE);
		printCenterOption(0, OPTION_EXIT);
		
		printFooter();
		printInputDivider();

		getIntInput(&nInput, 0, 2);
		processTitleScreenInput(nInput, sPlayer);
	} while (nInput != 0);
}

void processTitleScreenInput(int nInput, Player sPlayer) {
	switch (nInput) {
		case 1:
			openCharacterCreationScreen(sPlayer);
			break;
	}
}

