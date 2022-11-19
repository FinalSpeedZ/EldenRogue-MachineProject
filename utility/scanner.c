#include "scanner.h"
#include "printer.h"

void getIntInput(int *pInput, int nMin, int nMax) {
	if (*pInput < nMin || *pInput > nMax){
		printInvalidInputMsg("ENTER THE NUMBER OF YOUR SELECTION");
	}

	printInputTag(STD_INPUT_TAG);
	scanf("%d", pInput);
	while ((getchar()) != '\n'); // to clear input buffer
} 

char* getStringInput(char strInputTag[]) {
	char* pUnknownLength = malloc(sizeof(char));
	int nReadCharacter;
	int nIndex = 0;

	printf("\n");
	printInputTag(strInputTag); 

	while ((nReadCharacter = getchar()) != '\n' && nReadCharacter != EOF) {
		pUnknownLength[nIndex++] = nReadCharacter;
		pUnknownLength = realloc(pUnknownLength, nIndex + 1);
	}
	
	pUnknownLength[nIndex] = '\0';
	return pUnknownLength;
}

void getNameInput(StringPlayerName strPlayerName) {
	char* pTempPlayerName = getStringInput(NAME_INPUT_TAG);
	int nStart = 0;

	while (pTempPlayerName[nStart] == ' ') {
		nStart++;
	}

	if (strlen(pTempPlayerName) > PLAYER_NAME_LENGTH) {
		printMessage(SYSTEM_MESSAGE, "YOUR CHOSEN NAME IS TOO LONG");
		printMessage(SYSTEM_MESSAGE, PRESS_ENTER);
		while ((getchar()) != '\n'); 	
	}

	strncpy(strPlayerName, pTempPlayerName + nStart, PLAYER_NAME_LENGTH);

	free(pTempPlayerName);
}
