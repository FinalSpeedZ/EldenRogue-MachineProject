#include "sprites.h"

void printPlayerSprite(int nSpriteLine) {
	switch (nSpriteLine) {
		case 1:
			printMultiple(" ", 5);
			colorText(COLOR_PLAYER_HAIR);
			printMultiple("█", 5);
			resetColors();
			printMultiple(" ", 5);
			break;

		case 2:
			printMultiple(" ", 4);
			colorText(COLOR_PLAYER_HAIR);
			printMultiple("█", 1);
			colorBackground(COLOR_PLAYER_HAIR);
			printMultiple(" ", 5);
			printMultiple("█", 1);
			resetColors();
			printMultiple(" ", 4);
			break;

		case 3:
			printMultiple(" ", 3);
			colorText(COLOR_PLAYER_HAIR);
			printMultiple("█", 1);
			colorBackground(COLOR_PLAYER_HAIR);
			printMultiple(" ", 7);
			printMultiple("█", 1);
			resetColors();
			printMultiple(" ", 3);
			break;

		case 4:
			printMultiple(" ", 3);
			colorText(COLOR_PLAYER_HAIR);
			printMultiple("█", 1);
			colorBackground(COLOR_PLAYER_HAIR);
			printMultiple(" ", 6);
			printMultiple("█", 2);
			resetColors();
			printMultiple(" ", 3);
			break;

		case 5:
			printMultiple(" ", 2);
			colorText(COLOR_PLAYER_HAIR);
			printMultiple("█", 1);
			colorBackground(COLOR_PLAYER_HAIR);
			printMultiple(" ", 2);
			printMultiple("█", 5);
			colorBackground(COLOR_PLAYER_SKIN);
			printMultiple(" ", 2);
			resetColors();
			printMultiple(" ", 3);
			break;

		case 6:
			printMultiple(" ", 2);
			colorText(COLOR_PLAYER_HAIR);
			printMultiple("█", 3);
			colorBackground(COLOR_PLAYER_SKIN);
			printMultiple(" ", 1);
			colorText(COLOR_PLAYER_EYES);
			printMultiple("█", 1);
			printMultiple(" ", 2);
			printMultiple("█", 1);
			printMultiple(" ", 2);
			resetColors();
			printMultiple(" ", 3);
			break;

		case 7:
			printMultiple(" ", 4);
			colorText(COLOR_SPRITE_OUTLINE);
			colorBackground(COLOR_PLAYER_SKIN);
			printMultiple(" ", 2);
			colorText(COLOR_PLAYER_EYES);
			printMultiple("█", 1);
			printMultiple(" ", 2);
			printMultiple("█", 1);
			printMultiple(" ", 1);
			colorText(COLOR_PLAYER_SKIN);
			printMultiple("█", 1);
			resetColors();
			printMultiple(" ", 3);
			break;

		case 8:
			printMultiple(" ", 2);
			colorText(COLOR_PLAYER_SHIRT);
			printMultiple("█", 3);
			colorBackground(COLOR_PLAYER_SKIN);
			printMultiple(" ", 5);
			printMultiple("█", 3);
			resetColors();
			printMultiple(" ", 2);
			break;

		case 9:
			printMultiple(" ", 1);
			colorText(COLOR_PLAYER_SHIRT);
			printMultiple("█", 1);
			colorBackground(COLOR_PLAYER_SHIRT);
			printMultiple(" ", 3);
			printMultiple("█", 5);
			printMultiple(" ", 3);
			printMultiple("█", 1);
			resetColors();
			printMultiple(" ", 1);
	}
}

void printEnemySprite(int nSpriteLine, int nAreaIndex, Enemy sEnemy) {
	
	switch(nAreaIndex) {
		case STORMVEIL_CASTLE:
		case RAYA_LUCARIA_ACADEMY:
		case REDMANE_CASTLE:
		case VOLCANO_MANOR:
		case LEYNDELL_ROYAL_CAPITAL:
		case THE_ELDEN_THRONE:
			switch (nSpriteLine) {
				case 1:
					printMultiple(" ", 5);
					colorText(COLOR_SPRITE_OUTLINE);
					printMultiple("█", 5);
					printMultiple(" ", 5);
					resetColors();
					break;

				case 2:
					printMultiple(" ", 3);
					colorText(COLOR_SPRITE_OUTLINE);
					printMultiple("█", 2);
					colorBackground(sEnemy.sTint.nColor2);
					printMultiple(" ", 5);
					colorText(COLOR_SPRITE_OUTLINE);
					printMultiple("█", 2);
					resetColors();
					printMultiple(" ", 3);
					break;

				case 3:
					printMultiple(" ", 2);
					colorText(COLOR_SPRITE_OUTLINE);
					printMultiple("█", 1);
					colorBackground(sEnemy.sTint.nColor2);
					printMultiple(" ", 9);
					colorText(COLOR_SPRITE_OUTLINE);
					printMultiple("█", 1);
					resetColors();
					printMultiple(" ", 2);
					break;

				case 4:
					printMultiple(" ", 2);
					colorText(COLOR_SPRITE_OUTLINE);
					printMultiple("█", 1);
					colorBackground(sEnemy.sTint.nColor2);
					printMultiple(" ", 2);
					printMultiple("█", 5);
					printMultiple(" ", 2);
					printMultiple("█", 1);
					resetColors();
					printMultiple(" ", 2);
					break;

				case 5:
					printMultiple(" ", 1);
					colorText(COLOR_SPRITE_OUTLINE);
					printMultiple("█", 1);
					colorBackground(sEnemy.sTint.nColor2);
					printMultiple(" ", 2);
					printMultiple("█", 1);

					colorText(sEnemy.sTint.nColor1);
					printMultiple("█", 5);

					colorText(COLOR_SPRITE_OUTLINE);
					printMultiple("█", 1);
					printMultiple(" ", 2);
					printMultiple("█", 1);
					resetColors();
					printMultiple(" ", 1);
					break;

				case 6:
					printMultiple(" ", 2);
					colorText(COLOR_SPRITE_OUTLINE);
					printMultiple("█", 1);
					colorBackground(sEnemy.sTint.nColor2);
					printMultiple(" ", 2);
					printMultiple("█", 1);

					colorText(sEnemy.sTint.nColor1);
					printMultiple("█", 1);

					colorText(COLOR_SPRITE_OUTLINE);
					printMultiple("█", 1);

					colorText(sEnemy.sTint.nColor1);
					printMultiple("█", 1);

					colorText(COLOR_SPRITE_OUTLINE);
					printMultiple("█", 1);
					printMultiple(" ", 2);
					printMultiple("█", 1);
					resetColors();
					printMultiple(" ", 2);
					break;

				case 7:
					printMultiple(" ", 2);
					colorText(COLOR_SPRITE_OUTLINE);
					printMultiple("█", 1);
					colorBackground(sEnemy.sTint.nColor2);
					printMultiple(" ", 3);
					printMultiple("█", 1);
					printMultiple(" ", 1);
					printMultiple("█", 1);
					printMultiple(" ", 3);
					printMultiple("█", 1);
					resetColors();
					printMultiple(" ", 2);
					break;

				case 8:
					printMultiple(" ", 3);
					colorText(COLOR_SPRITE_OUTLINE);
					printMultiple("█", 2);
					colorBackground(sEnemy.sTint.nColor2);
					printMultiple(" ", 5);
					printMultiple("█", 2);
					resetColors();
					printMultiple(" ", 3);
					break;

				case 9:
					printMultiple(" ", 2);
					colorText(COLOR_SPRITE_OUTLINE);
					printMultiple("█", 1);
					colorBackground(sEnemy.sTint.nColor3);
					printMultiple(" ", 2);
					printMultiple("█", 5);
					printMultiple(" ", 2);
					printMultiple("█", 1);
					resetColors();
					printMultiple(" ", 2);
					break;
			}
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
			colorText(COLOR_RUNE_DARK);
			printMultiple("█", 3);
			resetColors();
			printMultiple(" ", 6);
			break;

		case 2:
		case 6:
			printMultiple(" ", 5);
			colorText(COLOR_RUNE_DARK);
			printMultiple("█", 1);
			colorBackground(COLOR_RUNE_LIGHT);
			printMultiple(" ", 3);
			printMultiple("█", 1);
			resetColors();
			printMultiple(" ", 5);
			break;

		case 3: 
		case 5:
			printMultiple(" ", 4);
			colorText(COLOR_RUNE_DARK);
			printMultiple("█", 1);
			colorBackground(COLOR_RUNE_LIGHT);
			printMultiple(" ", 5);
			printMultiple("█", 1);
			resetColors();
			printMultiple(" ", 4);
			break;

		case 4:
			printMultiple(" ", 3);
			colorText(COLOR_RUNE_DARK);
			printMultiple("█", 1);
			colorBackground(COLOR_RUNE_LIGHT);
			printMultiple(" ", 7);
			printMultiple("█", 1);
			resetColors();
			printMultiple(" ", 3);
			break;
	}
}

void printLoseSprite(int nLine) {
	switch (nLine) {
		case 1: 
			printMultiple(" ", 6);
			colorText(COLOR_LOSE_DARK);
			printMultiple("█", 3);
			resetColors();
			printMultiple(" ", 6);
			break;

		case 2:
			printMultiple(" ", 5);
			colorText(COLOR_LOSE_DARK);
			printMultiple("█", 1);
			colorBackground(COLOR_LOSE_LIGHT);
			printMultiple(" ", 3);
			printMultiple("█", 1);
			resetColors();
			printMultiple(" ", 5);
			break;

		case 3:
			printMultiple(" ", 4);
			colorText(COLOR_LOSE_DARK);
			printMultiple("█", 1);
			colorBackground(COLOR_LOSE_LIGHT);
			printMultiple(" ", 5);
			printMultiple("█", 1);
			resetColors();
			printMultiple(" ", 4);
			break;

		case 4:
			printMultiple(" ", 3);
			colorText(COLOR_LOSE_DARK);
			printMultiple("█", 1);
			colorBackground(COLOR_LOSE_LIGHT);
			printMultiple(" ", 2);
			resetColors();
			printMultiple("█", 1);
			colorBackground(COLOR_LOSE_LIGHT);
			printMultiple(" ", 1);
			resetColors();
			printMultiple("█", 1);
			colorBackground(COLOR_LOSE_LIGHT);
			printMultiple(" ", 2);
			colorText(COLOR_LOSE_DARK);
			printMultiple("█", 1);
			resetColors();
			printMultiple(" ", 3);
			break;

		case 5:
			printMultiple(" ", 2);
			colorText(COLOR_LOSE_DARK);
			printMultiple("█", 1);
			colorBackground(COLOR_LOSE_LIGHT);
			printMultiple(" ", 4);
			resetColors();
			printMultiple("█", 1);
			colorBackground(COLOR_LOSE_LIGHT);
			printMultiple(" ", 4);
			colorText(COLOR_LOSE_DARK);
			printMultiple("█", 1);
			resetColors();
			printMultiple(" ", 2);
			break;

		case 6:
			printMultiple(" ", 1);
			colorText(COLOR_LOSE_DARK);
			printMultiple("█", 1);
			colorBackground(COLOR_LOSE_LIGHT);
			printMultiple(" ", 4);
			resetColors();
			printMultiple("█", 1);
			colorBackground(COLOR_LOSE_LIGHT);
			printMultiple(" ", 1);
			resetColors();
			printMultiple("█", 1);
			colorBackground(COLOR_LOSE_LIGHT);
			printMultiple(" ", 4);
			colorText(COLOR_LOSE_DARK);
			printMultiple("█", 1);
			resetColors();
			printMultiple(" ", 1);
			break;

		case 7:
			printMultiple(" ", 1);
			colorText(COLOR_LOSE_DARK);
			printMultiple("█", 1);
			colorBackground(COLOR_LOSE_LIGHT);
			printMultiple(" ", 11);
			printMultiple("█", 1);
			resetColors();
			printMultiple(" ", 1);
			break;

		case 8:
			printMultiple(" ", 2);
			colorText(COLOR_LOSE_DARK);
			printMultiple("█", 11);
			resetColors();
			printMultiple(" ", 2);
			break;
	}
}