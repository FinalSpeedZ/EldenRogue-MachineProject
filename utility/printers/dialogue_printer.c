#include "dialogue_printer.h"

void loadDialogueEmptyTile(StringFullDialogue strFullDialogue) {
	int nLength;

	char strDialogue1[] = "Hmmm... This seems to be an empty tile. Let's keep going!";

	strcpy(strFullDialogue, strDialogue1);

	for (nLength = strlen(strFullDialogue); nLength < DIALOGUE_MAX_LENGTH; nLength++) {
		strcat(strFullDialogue, " ");
	}
}

void loadDialogueTreasureTile(StringFullDialogue strFullDialogue) {
	int nLength;

	char strDialogue1[] = "Oh look there! Somebody left a treasure for us to find!";

	strcpy(strFullDialogue, strDialogue1);

	for (nLength = strlen(strFullDialogue); nLength < DIALOGUE_MAX_LENGTH; nLength++) {
		strcat(strFullDialogue, " ");
	}
}

void loadDialogueEnemyTile(StringFullDialogue strFullDialogue) {
	int nLength;

	char strDialogue1[] = "Oops... I think we were spotted by something or should I say someone...";

	strcpy(strFullDialogue, strDialogue1);

	for (nLength = strlen(strFullDialogue); nLength < DIALOGUE_MAX_LENGTH; nLength++) {
		strcat(strFullDialogue, " ");
	}
}

void printTileDialogueLineText(int nDialogueLine, StringFullDialogue strFullDialogue) {
	char strSingleLine[DIALOGUE_PAGE_LINE_MAX_LENGTH + 1];

	int nLength;

	strncpy(strSingleLine, strFullDialogue + (nDialogueLine * DIALOGUE_PAGE_LINE_MAX_LENGTH), DIALOGUE_PAGE_LINE_MAX_LENGTH);

	if (strSingleLine[0] == ' ') {
		strncpy(strSingleLine, strFullDialogue + (nDialogueLine * DIALOGUE_PAGE_LINE_MAX_LENGTH) + 1, DIALOGUE_PAGE_LINE_MAX_LENGTH - 1);
		strSingleLine[DIALOGUE_PAGE_LINE_MAX_LENGTH - 1] = ' '; 
	}	

	for (nLength = strlen(strSingleLine); nLength < DIALOGUE_PAGE_LINE_MAX_LENGTH; nLength++) {
		strcat(strSingleLine, " ");
	}

	strSingleLine[DIALOGUE_PAGE_LINE_MAX_LENGTH] = '\0';

	printf(" %s ", strSingleLine);
}