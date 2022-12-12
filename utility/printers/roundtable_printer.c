#include "roundtable_printer.h"

void printOneBoxedStats(char strLabel[], int nValue) {
	int nValueDigits = 0;
	int nValueCopy = nValue;
	int nLeftPadding; 

	do {
		nValueCopy = nValueCopy / 10;
		nValueDigits += 1;	
	} while (nValueCopy != 0);

	nLeftPadding = SCREEN_WIDTH - (strlen(strLabel) + nValueDigits);

	printMultiple(" ", nLeftPadding);
	printf("┌");
	printMultiple("─", strlen(strLabel) + 5 + nValueDigits); 
	printf("┐\n");

	printMultiple(" ", nLeftPadding);
	printf("│");
	printf(" %s | %d", strLabel, nValue);
	printf(" │\n");	

	printMultiple(" ", nLeftPadding);
	printf("└");
	printMultiple("─", strlen(strLabel) + 5 + nValueDigits);
	printf("┘\n\n");
}

void printShards(int nShards) {
	int nPrintShard; 
	int nMissingShard;

	printf("SHARDS: ");
	for (nPrintShard = 0; nPrintShard < nShards; nPrintShard++) {
		printf("█ ");
	}

	for (nMissingShard = nPrintShard; nMissingShard < 6; nMissingShard++) {
		printf("░ ");
	}

	printf("\n");
}