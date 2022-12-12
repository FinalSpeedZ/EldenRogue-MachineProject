#include "scanner.h"

void pressEnter() {
	printMessage(SYSTEM_MESSAGE, PRESS_ENTER);
	while ((getchar()) != '\n'); 
}

void getIntInput(int *pInput, int nMin, int nMax) {
	if (*pInput < nMin || *pInput > nMax) {
		printInvalidInputMsg("ENTER THE NUMBER OF YOUR SELECTION");
	}

	printInputTag(STD_INPUT_TAG);
	scanf("%d", pInput);
	while ((getchar()) != '\n');
} 

char* getStringInput(char strInputTag[]) {
	char* pUnknownLength = malloc(sizeof(char));
	int nReadCharacter;
	int nIndex = 0;

	printf("\n");
	printInputTag(strInputTag); 

	while ((nReadCharacter = getchar()) != '\n') {
		pUnknownLength[nIndex++] = nReadCharacter;
		pUnknownLength = realloc(pUnknownLength, nIndex + 1);
	}
	
	pUnknownLength[nIndex] = '\0';
	return pUnknownLength;
}

void getNameInput(StringPlayerName strPlayerName) {
	char* pTempPlayerName = getStringInput(NAME_INPUT_TAG);
	int nLength = strlen(pTempPlayerName);
	int nStart = 0;
	int nIndex = 0;

	while (pTempPlayerName[nStart] == ' ') {
		nStart++;
		nLength--;
	}

	for (nIndex = PLAYER_NAME_LENGTH; nIndex < strlen(pTempPlayerName); nIndex++) {
		if (pTempPlayerName[nIndex] == ' ') {
			nLength--;
		}
	}

	if (nLength > PLAYER_NAME_LENGTH) {
		printMessage(SYSTEM_MESSAGE, "YOUR CHOSEN NAME IS TOO LONG");	
		pressEnter();
	}

	strncpy(strPlayerName, pTempPlayerName + nStart, PLAYER_NAME_LENGTH);

	strPlayerName = strupr(strPlayerName);
	free(pTempPlayerName);

	strPlayerName[PLAYER_NAME_LENGTH] = '\0';
}

void getCharAreaInput(char* pInput, char aValidCharInputs[], int nLength) {
	if (!hasCharMatch(*pInput, aValidCharInputs, nLength)) {
		printInvalidInputMsg("ENTER THE CHARACTER OF YOUR SELECTION");
	}

	printInputTag(STD_INPUT_TAG);
	scanf("%c", pInput);
	while ((getchar()) != '\n'); // to clear input buffer
}

int hasCharMatch(char cKey, char aValidCharInputs[], int nLength) {
	int nIndex; 
	int nMatch = 0;

	for (nIndex = 0; nIndex < nLength; nIndex++) {
		if (aValidCharInputs[nIndex] == cKey) {
			nMatch = 1;
		}
	}

	return nMatch;
}