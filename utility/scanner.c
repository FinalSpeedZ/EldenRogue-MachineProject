#include "scanner.h"
#include "printer.h"

void getIntInput(int *pInput, int nMin, int nMax) {
	if (*pInput < nMin || *pInput > nMax){
		printInvalidInputMsg();
	}

	printInputTag();
	scanf("%d", pInput);
	while ((getchar()) != '\n'); // to clear input buffer
} 
