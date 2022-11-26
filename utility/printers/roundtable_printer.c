#include "roundtable_printer.h"

void printOneBoxedStats(char strLabel[], int nValue) {
	int nValueDigits = 1;
	int nValueCopy = nValue;
	int nLeftPadding = SCREEN_WIDTH - (strlen(strLabel) + nValueDigits);

	while (nValueCopy != 0) {
		nValueCopy = nValueCopy / 10;
		nValueDigits++;
	}

	printMultiple(" ", nLeftPadding);
	printf("┌");
	printMultiple("─", strlen(strLabel) + 5 + nValueDigits); 
	printf("┐\n");

	printMultiple(" ", nLeftPadding);
	printf("│");
	printf(" %s | %d", strLabel, nValue);
	printf("  │\n");	

	printMultiple(" ", nLeftPadding);
	printf("└");
	printMultiple("─", strlen(strLabel) + 5 + nValueDigits);
	printf("┘\n\n");
}
