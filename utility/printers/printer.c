#include "printer.h"

#include "../../config/settings.h"
#include "../../config/string_definitions.h"
#include "../../config/structures.h"

void printMultiple(char strText[], int nTimes) {
	int nCounter;
	for (nCounter = 0; nCounter < nTimes; nCounter++) {
		printf("%s", strText);
	}
}

void printMiddleSubHeader(char strText[]) {
	int nOffset = (SCREEN_WIDTH - strlen(strText)) / 2;
	printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT + nOffset);
	printf("%s\n", strText);
	printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT + nOffset - 5);
	printMultiple("─", strlen(strText) + 10);
	printf("\n\n");
}

void printMiddleText(char strText[], char strDesignLeft[], char strDesignRight[]) {
	int nOffset = (SCREEN_WIDTH - strlen(strText) - 4) / 2;
	printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT + nOffset);
	printf("%s %s %s\n", strDesignLeft, strText, strDesignRight);
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

void printInvalidInputMsg(char strErrorMessage[]) {
	printMessage(SYSTEM_MESSAGE, "INVALID INPUT");
	printMultiple(" ", SCREEN_PADDING_LEFT + HEADER_PADDING_LEFT);
	printf("%s\n\n", strErrorMessage);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                            OPTIONS PRINTERS                             *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void printTwoOptions(int nNumberOption1, char strText1[], 
		 		     int nNumberOption2, char strText2[]) {
	printMultiple(" ", SCREEN_PADDING_LEFT + TWO_OPTION_PADDING );
	printf("┌");
	printMultiple("─", OPTIONS_TEXT_LENGTH);
	printf("┐"); 

	printMultiple(" ", TWO_OPTION_PADDING );

	printf("┌");
	printMultiple("─", OPTIONS_TEXT_LENGTH); 
	printf("┐\n"); 

	printMultiple(" ", SCREEN_PADDING_LEFT + TWO_OPTION_PADDING);
	printf("│ ");
	printf("[%d] %s", nNumberOption1, strText1);
	printMultiple(" ", OPTIONS_TEXT_LENGTH - (strlen(strText1) + 5));
	printf("│");

	printMultiple(" ", TWO_OPTION_PADDING);

	printf("│ ");
	printf("[%d] %s", nNumberOption2, strText2);
	printMultiple(" ", OPTIONS_TEXT_LENGTH - (strlen(strText2) + 5));
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

void printTwoLongOptions(int nNumberOption1, char strText1[], 
		 		         int nNumberOption2, char strText2[]) {
	printMultiple(" ", SCREEN_PADDING_LEFT + TWO_LONG_OPTION_PADDING);
	printf("┌");
	printMultiple("─", OPTIONS_LONG_TEXT_LENGTH);
	printf("┐"); 

	printMultiple(" ", TWO_LONG_OPTION_PADDING );

	printf("┌");
	printMultiple("─",OPTIONS_LONG_TEXT_LENGTH); 
	printf("┐\n"); 

	printMultiple(" ", SCREEN_PADDING_LEFT + TWO_LONG_OPTION_PADDING);
	printf("│ ");
	printf("[%d] %s", nNumberOption1, strText1);
	printMultiple(" ", OPTIONS_LONG_TEXT_LENGTH - (strlen(strText1) + 5));
	printf("│");

	printMultiple(" ", TWO_LONG_OPTION_PADDING);

	printf("│ ");
	printf("[%d] %s", nNumberOption2, strText2);
	printMultiple(" ", OPTIONS_LONG_TEXT_LENGTH - (strlen(strText2) + 5));
	printf("│\n");

	printMultiple(" ", SCREEN_PADDING_LEFT + TWO_LONG_OPTION_PADDING);
	printf("└");
	printMultiple("─", OPTIONS_LONG_TEXT_LENGTH);
	printf("┘");

	printMultiple(" ", TWO_LONG_OPTION_PADDING);

	printf("└");
	printMultiple("─", OPTIONS_LONG_TEXT_LENGTH);
	printf("┘\n\n");
}

void printCenterOption(int nNumberOption, char strText[]) {
	printMultiple(" ", SCREEN_PADDING_LEFT + CENTER_OPTION_PADDING);
	printf("┌");
	printMultiple("─", OPTIONS_TEXT_LENGTH); 
	printf("┐\n");

	printMultiple(" ", SCREEN_PADDING_LEFT + CENTER_OPTION_PADDING);
	printf("│ ");
	printf("[%d] %s", nNumberOption, strText);
	printMultiple(" ", OPTIONS_TEXT_LENGTH - (strlen(strText) + 5));
	printf("│\n");

	printMultiple(" ", SCREEN_PADDING_LEFT + CENTER_OPTION_PADDING);
	printf("└");
	printMultiple("─", OPTIONS_TEXT_LENGTH);
	printf("┘\n\n");
}

void printFieldedOption (int nNumberOption, char strText[]) {
	printMultiple(" ", SCREEN_PADDING_LEFT + TWO_OPTION_PADDING);
	printf("│ ");
	printf("[%d] %s", nNumberOption, strText);
	printMultiple(" ", OPTIONS_TEXT_LENGTH - (strlen(strText) + 5));
	printf("│ ");
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                        STATS VALUE PRINTERS                             *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void printMiddleStats(char strLabel[], int nValue) {
	int nOffset = (SCREEN_WIDTH - (strlen(strLabel) + 4)) / 2;
	printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT + nOffset);
	printf("%s: %d\n", strLabel, nValue);
	printf("\n");
}

void printTwoStats(char strLabel1[], int nValue1, 
	               char strLabel2[], int nValue2) {
	printMultiple(" ", SCREEN_PADDING_LEFT + TWO_OPTION_PADDING + HEADER_PADDING_LEFT - 1);
	
	printf("%s: ", strLabel1);
	printMultiple(" ", OPTIONS_TEXT_LENGTH - (strlen(strLabel1) + 1) - 3);
	printf("%3d ", nValue1);
	printf("│ ");

	printf("%s: ", strLabel2);
	printMultiple(" ", OPTIONS_TEXT_LENGTH - (strlen(strLabel2) + 1) - 3);
	printf("%3d", nValue2);
	printf(" │\n");
}

