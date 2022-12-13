#include "customize_character.h"


/*
	openCustomizeCharacter  Opens the customize character screen to edit player sprite

	@param pPlayer    The pointer to the player structure to be altered
	Pre-condition:   structure that pPlayer is pointing to is already initialized
*/
void openCustomizeCharacter(Player* pPlayer) {
	int nInput = 1;

	do {
		system("cls");

		printCharacterCreationHeader();

		printMiddleSubHeader("CUSTOMIZE CHARACTER");

		printTwoLongOptions(1, "CHANGE HAIR COLOR", 2, "CHANGE EYE COLOR");
		printTwoLongOptions(3, "CHANGE SHIRT COLOR", 4, "CONFIRM CUSTOMIZATION");

		printRoundtableNav(*pPlayer, NO_PROMPT);

		printFooter();
		printInputDivider();

		getIntInput(&nInput, 1, 4);
		processCustomizeCharacterInput(nInput, pPlayer);
	} while (nInput != 4);
}

/*
	processCustomizeCharacterInput  Processes the customize character input
	
	@param nInout     The input of the user
	@param pPlayer    The pointer to the player structure to be altered
	Pre-condition:   structure that pPlayer is pointing to is already initialized
*/
void processCustomizeCharacterInput(int nInput, Player* pPlayer) {
	switch (nInput) {
		case 1:
			openEditHair(pPlayer);
			break;

		case 2:
			openEditEyeColor(pPlayer);
			break;	

		case 3:
			openEditShirtColor(pPlayer);
			break;		
	}
}

/*
	 openEditHair Edits the hair color of player sprite

	@param pPlayer    The pointer to the player structure to be altered
	Pre-condition:   structure that pPlayer is pointing to is already initialized
*/
void openEditHair(Player* pPlayer) {
	int nInput = 1;

	do {
		system("cls");

		printCharacterCreationHeader();

		printMiddleSubHeader("EDIT HAIR COLOR");

		printTwoOptions(1, "RED", 2, "BLACK");
		printTwoOptions(3, "BLONDE", 4, "CONFIRM");

		printRoundtableNav(*pPlayer, NO_PROMPT);

		printFooter();
		printInputDivider();

		getIntInput(&nInput, 1, 4);
		processEditHair(nInput, pPlayer);
	} while (nInput != 4);
}

/*
	processEditHair  Processes the edit hair input
	
	@param nInout     The input of the user
	@param pPlayer    The pointer to the player structure to be altered
	Pre-condition:   structure that pPlayer is pointing to is already initialized
*/
void processEditHair(int nInput, Player* pPlayer) {
	switch (nInput) {
		case 1: 
			pPlayer->sTint.nColor1 = 88;
			break;
		
		case 2:
			pPlayer->sTint.nColor1 = 235;
			break;	

		case 3:
			pPlayer->sTint.nColor1 = 221;
			break;			
	}
}

/*
	openEditEyeCOlor Edits the eye color of player sprite

	@param pPlayer    The pointer to the player structure to be altered
	Pre-condition:   structure that pPlayer is pointing to is already initialized
*/
void openEditEyeColor(Player* pPlayer) {
	int nInput = 1;

	do {
		system("cls");

		printCharacterCreationHeader();

		printMiddleSubHeader("EDIT EYE COLOR");

		printTwoOptions(1, "BLACK", 2, "GREEN");
		printTwoOptions(3, "BLUE", 4, "CONFIRM");

		printRoundtableNav(*pPlayer, NO_PROMPT);

		printFooter();
		printInputDivider();

		getIntInput(&nInput, 1, 4);
		processEditEyeColor(nInput, pPlayer);
	} while (nInput != 4);
}

/*
	processEditEyeColor  Processes the edit eye color input
	
	@param nInout     The input of the user
	@param pPlayer    The pointer to the player structure to be altered
	Pre-condition:   structure that pPlayer is pointing to is already initialized
*/
void processEditEyeColor(int nInput, Player* pPlayer) {
	switch (nInput) {
		case 1: 
			pPlayer->sTint.nColor2 = 232;
			break;
		
		case 2:
			pPlayer->sTint.nColor2 = 2;
			break;	

		case 3:
			pPlayer->sTint.nColor2 = 33;
			break;			
	}	
}


/*
	openEditShirtColor Edits the hair color of player sprite

	@param pPlayer    The pointer to the player structure to be altered
	Pre-condition:   structure that pPlayer is pointing to is already initialized
*/
void openEditShirtColor(Player* pPlayer) {
	int nInput = 1;

	do {
		system("cls");

		printCharacterCreationHeader();

		printMiddleSubHeader("EDIT EYE COLOR");

		printTwoOptions(1, "ORANGE", 2, "GREEN");
		printTwoOptions(3, "PINK", 4, "CONFIRM");

		printRoundtableNav(*pPlayer, NO_PROMPT);

		printFooter();
		printInputDivider();

		getIntInput(&nInput, 1, 4);
		processEditShirtColor(nInput, pPlayer);
	} while (nInput != 4);
}

/*
	processEditShirtColor  Processes the edit shirt color input
	
	@param nInout     The input of the user
	@param pPlayer    The pointer to the player structure to be altered
	Pre-condition:   structure that pPlayer is pointing to is already initialized
*/
void processEditShirtColor(int nInput, Player* pPlayer) {
	switch (nInput) {
		case 1: 
			pPlayer->sTint.nColor3 = 202;
			break;
		
		case 2:
			pPlayer->sTint.nColor3 = 34;
			break;	

		case 3:
			pPlayer->sTint.nColor3 = 204;
			break;			
	}	
}