#include "title_screen.h"

#include "../utility/printer.h"
#include "../utility/scanner.h"

#include "character_creation_screens/character_creation_screen.h"

void openTitleScreen(Player* pPlayer) {
	int nInput = 0;

	do {
		system("cls");
		
		// change to printHeader (ascii header)
		printMultiple("\n", SCREEN_PADDING_TOP);
		printMultiple(" ", SCREEN_PADDING_LEFT + CENTER_OPTION_PADDING + HEADER_PADDING_LEFT);
		printf("ELDEN ROGUE\n");
		printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT);
		printMultiple("─", SCREEN_WIDTH);
		printf("\n\n");

		printTwoOptions(1, OPTION_START, 2, OPTION_CONTINUE);
		printCenterOption(0, OPTION_EXIT);
		
		printFooter();
		printInputDivider();

		getIntInput(&nInput, 0, 2);
		processTitleScreenInput(nInput, pPlayer);
	} while (nInput != 0);
}

void processTitleScreenInput(int nInput, Player* pPlayer) {
	switch (nInput) {
		case 1:
			openCharacterCreationScreen(pPlayer);
			break;
	}
}

