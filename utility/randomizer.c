#include "randomizer.h"

int randomNumberBetween(int nUpper, int nLower) {
	int nRange;
	int nRandom;

	nRange = nUpper - nLower + 1;
	
	nRandom = rand() % nRange + nLower;
  	
  	return nRandom;
}

