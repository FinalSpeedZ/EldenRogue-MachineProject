#include "screen_headers.h"

void printTitleScreenHeader() {
	printMultiple("\n", SCREEN_PADDING_TOP);
	printMiddleText(" ___   _____ _    ______ _____ _   _  ______ _____ _____ _   _ _____   ___ ", "", "");
	printMiddleText("|  _| |  ___| |   |  _  \\  ___| \\ | | | ___ \\  _  |  __ \\ | | |  ___| |_  |", "", "");
	printMiddleText("| |   | |__ | |   | | | | |__ |  \\| | | |_/ / | | | |  \\/ | | | |__     | |", "", "");
	printMiddleText("| |   |  __|| |   | | | |  __|| . ` | |    /| | | | | __| | | |  __|    | |", "", "");
	printMiddleText("| |   | |___| |___| |/ /| |___| |\\  | | |\\ \\\\ \\_/ / |_\\ \\ |_| | |___    | |", "", "");
	printMiddleText("| |_  \\____/\\_____/___/ \\____/\\_| \\_/ \\_| \\_|\\___/ \\____/\\___/\\____/   _| |", "", "");	
	printMiddleText("|___|                                                                 |___|", "", "");	
	printf("\n");	
	printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT);
	printMultiple("─", SCREEN_WIDTH);
	printf("\n\n");
}