#include "dialogue_printer.h"

void loadDialogueEmptyTile(StringFullDialogue strFullDialogue) {
	int nLength;

	char strDialogue1[] = "I am Karen of the Elite Four. You're a challenger? How amusing. I love Dark-type";

	strcpy(strFullDialogue, strDialogue1);

	for (nLength = strlen(strFullDialogue); nLength < DIALOGUE_MAX_LENGTH; nLength++) {
		strcat(strFullDialogue, " ");
	}
}

void printDialogueLineText(int nDialogueLine, StringFullDialogue strFullDialogue) {
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