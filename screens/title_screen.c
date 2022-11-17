#include "title_screen.h"

#include "../utility/printer.h"
#include "../utility/scanner.h"

void openTitleScreen() {
	int nInput = 0;
	do {
		system("cls");
		
		// change to printHeader (ascii header)
		printMultiple("\n", SCREEN_PADDING_TOP);
		printMultiple(" ", SCREEN_PADDING_LEFT + CENTER_OPTION_PADDING + HEADER_PADDING_LEFT);
		printf("ELDEN ROGUE\n");
		printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT);
		printMultiple("─", SCREEN_WIDTH);
		printf("\n\n");

		printTwoOptions(1, OPTION_START, 2, OPTION_CONTINUE);
		printCenterOption(0, OPTION_EXIT);
		
		printFooter();

		printInputDivider();

		getIntInput(&nInput, 0, 2);

	} while (nInput != 0);

}



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                            PRINTING FUNCTIONS                           *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

