#include "scanner.h"
#include "printer.h"

void getIntInput(int *pInput, int nMin, int nMax) {
	if (*pInput < nMin || *pInput > nMax){
		printInvalidInputMsg();
	}

	printInputTag(STD_INPUT_TAG);
	scanf("%d", pInput);
	while ((getchar()) != '\n'); // to clear input buffer
} 


void getNameInput(StringPlayerName strPlayerName) {
	StringPlayerName strTempPlayerName;
	int nStart = 0;

	printf("\n");
	printInputTag(NAME_INPUT_TAG);
	
	scanf("%25[^\n]s", strTempPlayerName);
	while ((getchar()) != '\n'); // to clear input buffer

	while (strTempPlayerName[nStart] == ' ') {
		nStart++;
	}

	strncpy(strPlayerName, strTempPlayerName + nStart, PLAYER_NAME_LENGTH);
}