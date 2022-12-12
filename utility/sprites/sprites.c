#include "sprites.h"

void printPlayerSprite(int nSpriteLine) {
	switch (nSpriteLine) {
		case 1:
			printMultiple(" ", 5);
			printMultiple("█", 5);
			printMultiple(" ", 5);
			break;

		case 2:
			printMultiple(" ", 4);
			printMultiple("█", 1);
			printMultiple(" ", 5);
			printMultiple("█", 1);
			printMultiple(" ", 4);
			break;

		case 3:
			printMultiple(" ", 3);
			printMultiple("█", 1);
			printMultiple(" ", 7);
			printMultiple("█", 1);
			printMultiple(" ", 3);
			break;

		case 4:
			printMultiple(" ", 3);
			printMultiple("█", 1);
			printMultiple(" ", 6);
			printMultiple("█", 2);
			printMultiple(" ", 3);
			break;

		case 5:
			printMultiple(" ", 2);
			printMultiple("█", 1);
			printMultiple(" ", 2);
			printMultiple("█", 5);
			printMultiple(" ", 2);
			printMultiple("█", 1);
			printMultiple(" ", 2);
			break;

		case 6:
			printMultiple(" ", 2);
			printMultiple("█", 3);
			printMultiple(" ", 1);
			printMultiple("█", 1);
			printMultiple(" ", 2);
			printMultiple("█", 1);
			printMultiple(" ", 2);
			printMultiple("█", 1);
			printMultiple(" ", 2);
			break;

		case 7:
			printMultiple(" ", 3);
			printMultiple("█", 1);
			printMultiple(" ", 2);
			printMultiple("█", 1);
			printMultiple(" ", 2);
			printMultiple("█", 1);
			printMultiple(" ", 1);
			printMultiple("█", 1);
			printMultiple(" ", 3);
			break;

		case 8:
			printMultiple(" ", 2);
			printMultiple("█", 3);
			printMultiple(" ", 5);
			printMultiple("█", 3);
			printMultiple(" ", 2);
			break;

		case 9:
			printMultiple(" ", 1);
			printMultiple("█", 1);
			printMultiple(" ", 3);
			printMultiple("█", 5);
			printMultiple(" ", 3);
			printMultiple("█", 1);
			printMultiple(" ", 1);
	}
}

void printEnemySprite(int nSpriteLine) {
	switch (nSpriteLine) {
		case 1:
			printMultiple(" ", 5);
			printMultiple("█", 5);
			printMultiple(" ", 5);
			break;

		case 2:
			printMultiple(" ", 3);
			printMultiple("█", 2);
			printMultiple(" ", 5);
			printMultiple("█", 2);
			printMultiple(" ", 3);
			break;

		case 3:
			printMultiple(" ", 2);
			printMultiple("█", 1);
			printMultiple(" ", 9);
			printMultiple("█", 1);
			printMultiple(" ", 2);
			break;

		case 4:
			printMultiple(" ", 2);
			printMultiple("█", 1);
			printMultiple(" ", 2);
			printMultiple("█", 5);
			printMultiple(" ", 2);
			printMultiple("█", 1);
			printMultiple(" ", 2);
			break;

		case 5:
			printMultiple(" ", 1);
			printMultiple("█", 1);
			printMultiple(" ", 2);
			printMultiple("█", 1);

			printMultiple("█", 5);

			printMultiple("█", 1);
			printMultiple(" ", 2);
			printMultiple("█", 1);
			printMultiple(" ", 1);
			break;

		case 6:
			printMultiple(" ", 2);
			printMultiple("█", 1);
			printMultiple(" ", 2);
			printMultiple("█", 1);

			printMultiple("█", 1);

			printMultiple("█", 1);

			printMultiple("█", 1);

			printMultiple("█", 1);
			printMultiple(" ", 2);
			printMultiple("█", 1);
			printMultiple(" ", 2);
			break;

		case 7:
			printMultiple(" ", 2);
			printMultiple("█", 1);
			printMultiple(" ", 3);
			printMultiple("█", 1);
			printMultiple(" ", 1);
			printMultiple("█", 1);
			printMultiple(" ", 3);
			printMultiple("█", 1);
			printMultiple(" ", 2);
			break;

		case 8:
			printMultiple(" ", 3);
			printMultiple("█", 2);
			printMultiple(" ", 5);
			printMultiple("█", 2);
			printMultiple(" ", 3);
			break;

		case 9:
			printMultiple(" ", 2);
			printMultiple("█", 1);
			printMultiple(" ", 2);
			printMultiple("█", 5);
			printMultiple(" ", 2);
			printMultiple("█", 1);
			printMultiple(" ", 2);
	}
}

void printTopBottomSpriteBorders(int nLine) {
	switch (nLine) {
		case 2:
			printf("│█");
			printMultiple("▀", 15);
			printf("█│ ");
			break;

		case 12:
			printf("│█");
			printMultiple("▄", 15);
			printf("█│");
			break;			
	}
}

void printRunes(int nLine) {
	switch (nLine) {
		case 1: 
		case 7:	
			printMultiple(" ", 6);
			printMultiple("█", 3);
			printMultiple(" ", 6);
			break;

		case 2:
		case 6:
			printMultiple(" ", 5);
			printMultiple("█", 1);
			printMultiple(" ", 3);
			printMultiple("█", 1);
			printMultiple(" ", 5);
			break;

		case 3: 
		case 5:
			printMultiple(" ", 4);
			printMultiple("█", 1);
			printMultiple(" ", 5);
			printMultiple("█", 1);
			printMultiple(" ", 4);
			break;

		case 4:
			printMultiple(" ", 3);
			printMultiple("█", 1);
			printMultiple(" ", 7);
			printMultiple("█", 1);
			printMultiple(" ", 3);
			break;
	}
}

void printLoseSprite(int nLine) {
	switch (nLine) {
		case 1: 
			printMultiple(" ", 6);
			printMultiple("█", 3);
			printMultiple(" ", 6);
			break;

		case 2:
			printMultiple(" ", 5);
			printMultiple("█", 1);
			printMultiple(" ", 3);
			printMultiple("█", 1);
			printMultiple(" ", 5);
			break;

		case 3:
			printMultiple(" ", 4);
			printMultiple("█", 1);
			printMultiple(" ", 5);
			printMultiple("█", 1);
			printMultiple(" ", 4);
			break;

		case 4:
			printMultiple(" ", 3);
			printMultiple("█", 1);
			printMultiple(" ", 2);
			printMultiple("█", 1);
			printMultiple(" ", 1);
			printMultiple("█", 1);
			printMultiple(" ", 2);
			printMultiple("█", 1);
			printMultiple(" ", 3);
			break;

		case 5:
			printMultiple(" ", 2);
			printMultiple("█", 1);
			printMultiple(" ", 4);
			printMultiple("█", 1);
			printMultiple(" ", 4);
			printMultiple("█", 1);
			printMultiple(" ", 2);
			break;

		case 6:
			printMultiple(" ", 1);
			printMultiple("█", 1);
			printMultiple(" ", 4);
			printMultiple("█", 1);
			printMultiple(" ", 1);
			printMultiple("█", 1);
			printMultiple(" ", 4);
			printMultiple("█", 1);
			printMultiple(" ", 1);
			break;

		case 7:
			printMultiple(" ", 1);
			printMultiple("█", 1);
			printMultiple(" ", 11);
			printMultiple("█", 1);
			printMultiple(" ", 1);
			break;

		case 8:
			printMultiple(" ", 2);
			printMultiple("█", 11);
			printMultiple(" ", 2);
			break;
	}
}