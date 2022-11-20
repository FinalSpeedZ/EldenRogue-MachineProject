#include "character_creation_screen.h"
#include "job_class_creation.h"

#include "../../config/structures.h"

void openCharacterCreationScreen(Player* pPlayer) {
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

		printFieldedOption(1, TAG_NAME);
		printf("%s\n", pPlayer->strPlayerName);
		printFieldedOption(2, TAG_JOB_CLASS);
		printf("%s\n", pPlayer->strPlayerJobClass);

		printf("\n");
		printTwoOptions(0, OPTION_BACK, 3, OPTION_CONFIRM);

		printFooter();
		printInputDivider();

		getIntInput(&nInput, 0, 3);
		processCharacterCreationScreenInput(nInput, pPlayer);
	} while (nInput != 0);
}

void processCharacterCreationScreenInput(int nInput, Player* pPlayer) {
	switch (nInput) {
		case 1:
			getNameInput(pPlayer->strPlayerName);
			break;	
		case 2: 
			openJobClassSelection(pPlayer);
			break;

	}
}

Player initializePlayer() {
	Player sPlayer;

	strcpy(sPlayer.strPlayerName, "");
	ResetJobClassStats(&sPlayer);

	return sPlayer;
}



