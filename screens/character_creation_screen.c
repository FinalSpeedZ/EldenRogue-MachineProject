#include "character_creation_screen.h"

#include "../config/structures.h"

void openCharacterCreationScreen() {
	int nInput = 0;
	
	Player sPlayer = initializePlayer();
	do {
		system("cls");

		// change to printHeader (ascii header)
		printMultiple("\n", SCREEN_PADDING_TOP);
		printMultiple(" ", SCREEN_PADDING_LEFT + CENTER_OPTION_PADDING + HEADER_PADDING_LEFT);
		printf("CHARACTER CREATION\n");
		printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT);
		printMultiple("─", SCREEN_WIDTH);
		printf("\n\n");

		printFieldedOption(1, TAG_NAME);
		printf("%s\n", sPlayer.strPlayerName);
		printFieldedOption(2, TAG_JOB_CLASS);
		printf("\n\n");

		printTwoOptions(0, OPTION_BACK, 3, OPTION_CONFIRM);

		printFooter();

		printInputDivider();

		getIntInput(&nInput, 0, 2);

		processCharacterCreationScreenInput(nInput, &sPlayer);
	} while (nInput != 0);
}

void processCharacterCreationScreenInput(int nInput, Player* pPlayer) {
	switch (nInput) {
		case 1:
			getNameInput(pPlayer->strPlayerName);
			break;	
	}
}

Player initializePlayer() {
	Player sPlayer;

	strcpy(sPlayer.strPlayerName, "");

	return sPlayer;
}



