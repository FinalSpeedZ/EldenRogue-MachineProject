/****************************************
File Name: character_creation_screen.c

Opens the character creation screen
****************************************/

#include "character_creation_screen.h"
#include "job_class_creation.h"
#include "customize_character.h"

#include "../roundtable_hold_screens/roundtable_hold.h"

/*
	openCharacterCreationScreen   Opens the battle screen where player battles against an enemy

	@param sPlayer                The player structure to be created 
	Pre-condition:                sPlayer was already decleared and initialized to initial values
*/
void openCharacterCreationScreen(Player sPlayer) {
	int nInput = 0;

	do {
		system("cls");

		printCharacterCreationHeader();

		printFieldedOption(1, "NAME");
		printf("%s\n", sPlayer.strPlayerName);
		printFieldedOption(2, "JOB CLASS");
		printf("%s\n\n", sPlayer.strPlayerJobClass);
		printJobClassStats(sPlayer);

		printTwoOptions(0, OPTION_BACK, 3, OPTION_CONFIRM);

		printFooter();
		printInputDivider();

		getIntInput(&nInput, 0, 3);
		processCharacterCreationScreenInput(nInput, &sPlayer);
	} while (nInput != 0 && (nInput != 3 || (strlen(sPlayer.strPlayerName) == 0) || strlen(sPlayer.strPlayerJobClass) == 0));
}

/*
	processCharacterCreationScreenInput  Process the character creation screen Input

	@param pPlayer A pointer to the player structure that will be altered
*/
void processCharacterCreationScreenInput(int nInput, Player* pPlayer) {
	switch (nInput) {
		case 1:
			getNameInput(pPlayer->strPlayerName);
			break;	
		case 2: 
			openJobClassSelection(pPlayer);
			break;
		case 3: 
			openCustomizeCharacter(pPlayer);
			if (checkCharacterCreation(*pPlayer) == TRUE) {
				openRoundTableHold(*pPlayer);
			}
			break;
	}
}

/*
	checkCharacterCreation   Opens the battle screen where player battles against an enemy

	@param sPlayer    The player structure created
	@return           an int determining if player is done choosing name and job class
*/
int checkCharacterCreation(Player sPlayer) {
	if (strlen(sPlayer.strPlayerName) == 0) {
		printMessage(SYSTEM_MESSAGE, "ENTER YOUR CHOSEN NAME");
		printMessage(SYSTEM_MESSAGE, PRESS_ENTER);
		while ((getchar()) != '\n');
		return FALSE; 	
	}

	else if (strlen(sPlayer.strPlayerJobClass) == 0) {
		printMessage(SYSTEM_MESSAGE, "CHOOSE A DESIRED JOB CLASS");
		printMessage(SYSTEM_MESSAGE, PRESS_ENTER);
		while ((getchar()) != '\n'); 	
		return FALSE;
	}
	else {
		return TRUE;
	}
}

/*
	printJobClassStats   Prints the job class stats

	@param sPlayer    The player structure created
*/
void printJobClassStats(Player sPlayer) {
	if (strlen(sPlayer.strPlayerJobClass) != 0) {
		printStats(sPlayer);
	}
}


