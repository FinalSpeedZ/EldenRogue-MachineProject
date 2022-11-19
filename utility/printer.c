#include "printer.h"

#include "../config/settings.h"
#include "../config/string_definitions.h"
#include "../config/structures.h"

void printMultiple(char strText[], int nTimes) {
	int nCounter;
	for (nCounter = 0; nCounter < nTimes; nCounter++) {
		printf("%s", strText);
	}
}

void printInputDivider() {
	printMultiple(" ", SCREEN_PADDING_LEFT + INPUT_PADDING);
	printMultiple("─", INPUT_DESIGN);
	printMultiple("═", INPUT_DESIGN);
	printf("╣   ");
	printf("USER INPUT");
	printf("   ╠");
	printMultiple("═", INPUT_DESIGN);	
	printMultiple("─", INPUT_DESIGN);
	printf("\n");
}

void printInputTag(char strInputTag[]) {
	printMultiple(" ", SCREEN_PADDING_LEFT);
	printf("[%s]: ", strInputTag);
}

void printFooter() {
	printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT);
	printMultiple("─", SCREEN_WIDTH);
	printf("\n\n");
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                            MESSAGE PRINTERS                             *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void printMessage(char strMessageType[], char strMessage[]) {
	printf("\n");
	printMultiple(" ", SCREEN_PADDING_LEFT);
	printf("[%s]: %s\n", strMessageType, strMessage);
}

void printInvalidInputMsg() {
	printMessage("SYSTEM MESSAGE", "INVALID INPUT");
	printMultiple(" ", SCREEN_PADDING_LEFT + HEADER_PADDING_LEFT);
	printf("ENTER THE NUMBER OF YOUR SELECTION\n\n");
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                            OPTIONS PRINTERS                             *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void printTwoOptions(int nNumberOption1, char strText1[], 
		 		     int nNumberOption2, char strText2[]) {
	printMultiple(" ", SCREEN_PADDING_LEFT + TWO_OPTION_PADDING);
	printf("┌");
	printMultiple("─", OPTIONS_TEXT_LENGTH);
	printf("┐"); 

	printMultiple(" ", TWO_OPTION_PADDING);

	printf("┌");
	printMultiple("─", OPTIONS_TEXT_LENGTH); 
	printf("┐\n"); 

	printMultiple(" ", SCREEN_PADDING_LEFT + TWO_OPTION_PADDING);
	printf("│");
	printf("[%d] %s", nNumberOption1, strText1);
	printMultiple(" ", OPTIONS_TEXT_LENGTH - (strlen(strText1) + 4));
	printf("│");

	printMultiple(" ", TWO_OPTION_PADDING);

	printf("│");
	printf("[%d] %s", nNumberOption2, strText2);
	printMultiple(" ", OPTIONS_TEXT_LENGTH - (strlen(strText2) + 4));
	printf("│\n");

	printMultiple(" ", SCREEN_PADDING_LEFT + TWO_OPTION_PADDING);
	printf("└");
	printMultiple("─", OPTIONS_TEXT_LENGTH);
	printf("┘");

	printMultiple(" ", TWO_OPTION_PADDING);

	printf("└");
	printMultiple("─", OPTIONS_TEXT_LENGTH);
	printf("┘\n\n");
}

void printCenterOption(int nNumberOption, char strText[]) {
	printMultiple(" ", SCREEN_PADDING_LEFT + CENTER_OPTION_PADDING);
	printf("┌");
	printMultiple("─", OPTIONS_TEXT_LENGTH); 
	printf("┐\n");

	printMultiple(" ", SCREEN_PADDING_LEFT + CENTER_OPTION_PADDING);
	printf("│");
	printf("[%d] %s", nNumberOption, strText);
	printMultiple(" ", OPTIONS_TEXT_LENGTH - (strlen(strText) + 4));
	printf("│\n");

	printMultiple(" ", SCREEN_PADDING_LEFT + CENTER_OPTION_PADDING);
	printf("└");
	printMultiple("─", OPTIONS_TEXT_LENGTH);
	printf("┘\n\n");
}

void printFieldedOption (int nNumberOption, char strText[]) {
	printMultiple(" ", SCREEN_PADDING_LEFT + TWO_OPTION_PADDING);
	printf("│");
	printf("[%d] %s", nNumberOption, strText);
	printMultiple(" ", OPTIONS_TEXT_LENGTH - (strlen(strText) + 4));
	printf("│ ");
}