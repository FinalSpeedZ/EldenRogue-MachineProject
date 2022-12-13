#include "sprites.h"

void printPlayerSprite(int nSpriteLine, Player sPlayer) {
	switch (nSpriteLine) {
		case 1:
			printMultiple(" ", 5);
			colorText(sPlayer.sTint.nColor1);
			printMultiple("█", 5);
			resetColors();
			printMultiple(" ", 5);
			break;

		case 2:
			printMultiple(" ", 4);
			colorText(sPlayer.sTint.nColor1);
			printMultiple("█", 1);
			colorBackground(sPlayer.sTint.nColor1);
			printMultiple(" ", 5);
			printMultiple("█", 1);
			resetColors();
			printMultiple(" ", 4);
			break;

		case 3:
			printMultiple(" ", 3);
			colorText(sPlayer.sTint.nColor1);
			printMultiple("█", 1);
			colorBackground(sPlayer.sTint.nColor1);
			printMultiple(" ", 7);
			printMultiple("█", 1);
			resetColors();
			printMultiple(" ", 3);
			break;

		case 4:
			printMultiple(" ", 3);
			colorText(sPlayer.sTint.nColor1);
			printMultiple("█", 1);
			colorBackground(sPlayer.sTint.nColor1);
			printMultiple(" ", 6);
			printMultiple("█", 2);
			resetColors();
			printMultiple(" ", 3);
			break;

		case 5:
			printMultiple(" ", 2);
			colorText(sPlayer.sTint.nColor1);
			printMultiple("█", 1);
			colorBackground(sPlayer.sTint.nColor1);
			printMultiple(" ", 2);
			printMultiple("█", 5);
			colorBackground(COLOR_PLAYER_SKIN);
			printMultiple(" ", 2);
			resetColors();
			printMultiple(" ", 3);
			break;

		case 6:
			printMultiple(" ", 2);
			colorText(sPlayer.sTint.nColor1);
			printMultiple("█", 3);
			colorBackground(COLOR_PLAYER_SKIN);
			printMultiple(" ", 1);
			colorText(sPlayer.sTint.nColor2);
			printMultiple("█", 1);
			printMultiple(" ", 2);
			printMultiple("█", 1);
			printMultiple(" ", 2);
			resetColors();
			printMultiple(" ", 3);
			break;

		case 7:
			printMultiple(" ", 4);
			colorBackground(COLOR_PLAYER_SKIN);
			printMultiple(" ", 2);
			colorText(sPlayer.sTint.nColor2);
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
			colorText(sPlayer.sTint.nColor3);
			printMultiple("█", 3);
			colorBackground(COLOR_PLAYER_SKIN);
			printMultiple(" ", 5);
			printMultiple("█", 3);
			resetColors();
			printMultiple(" ", 2);
			break;

		case 9:
			printMultiple(" ", 1);
			colorText(sPlayer.sTint.nColor3);
			printMultiple("█", 1);
			colorBackground(sPlayer.sTint.nColor3);
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

void printShortSwordSlot(int nSpriteLine, int nWeaponIndex){
	switch (nSpriteLine){
	case 0:
		printf("╔══════════════════╗ ");
		break;
	case 1:
		printf("│");
		printMultiple(" ", 11);
		printMultiple("█", 5);
		printMultiple(" ", 2);
		printf("│ ");
		break;
	case 2:
		printf("│");
		printMultiple(" ", 10);
		printMultiple("█", 6);
		printMultiple(" ", 2);
		printf("│ ");
		break;
	case 3:
		printf("│");
		printMultiple(" ", 9);
		printMultiple("█", 6);
		printMultiple(" ", 3);
		printf("│ ");
		break;
	case 4:
		printf("│");
		printMultiple(" ", 8);
		printMultiple("█", 6);
		printMultiple(" ", 4);
		printf("│ ");
		break;
	case 5:
		printf("│");
		printMultiple(" ", 7);
		printMultiple("█", 6);
		printMultiple(" ", 5);
		printf("│ ");
		break;
	case 6:
		printf("│");
		printMultiple(" ", 3);
		printMultiple("█", 9);
		printMultiple(" ", 6);
		printf("│ ");
		break;
	case 7:
		printf("│");
		printMultiple(" ", 5);
		printMultiple("█", 6);
		printMultiple(" ", 7);
		printf("│ ");
		break;
	case 8:
		printf("│");
		printMultiple(" ", 4);
		printMultiple("█", 6);
		printMultiple(" ", 8);
		printf("│ ");
		break;
	case 9:
		printf("│");
		printMultiple(" ", 3);
		printMultiple("█", 3);
		printMultiple(" ", 2);
		printMultiple("█", 2);
		printMultiple(" ", 8);
		printf("│ ");
		break;
	case 10:
		printf("│");
		printMultiple(" ", 1);
		printMultiple("█", 4);
		printMultiple(" ", 13);
		printf("│ ");
		break;
	case 11:
		printf("│");
		printMultiple(" ", 1);
		printMultiple("█", 3);
		printMultiple(" ", 14);
		printf("│ ");
		break;
	case 12:
		printf("╚══════[ %.2d ]══════╝ ", nWeaponIndex);
		break;
	}
}

void printRogierRapier (int nSpriteLine, int nWeaponIndex){
	switch (nSpriteLine){
	case 0:
		printf("╔══════════════════╗ ");
		break;
	case 1:
		printf("│");
		printMultiple(" ", 11);
		printMultiple("█", 5);
		printMultiple(" ", 2);
		printf("│ ");
		break;
	case 2:
		printf("│");
		printMultiple(" ", 10);
		printMultiple("█", 6);
		printMultiple(" ", 2);
		printf("│ ");
		break;
	case 3:
		printf("│");
		printMultiple(" ", 9);
		printMultiple("█", 6);
		printMultiple(" ", 3);
		printf("│ ");
		break;
	case 4:
		printf("│");
		printMultiple(" ", 8);
		printMultiple("█", 6);
		printMultiple(" ", 4);
		printf("│ ");
		break;
	case 5:
		printf("│");
		printMultiple(" ", 7);
		printMultiple("█", 6);
		printMultiple(" ", 5);
		printf("│ ");
		break;
	case 6:
		printf("│");
		printMultiple(" ", 3);
		printMultiple("█", 9);
		printMultiple(" ", 6);
		printf("│ ");
		break;
	case 7:
		printf("│");
		printMultiple(" ", 5);
		printMultiple("█", 6);
		printMultiple(" ", 7);
		printf("│ ");
		break;
	case 8:
		printf("│");
		printMultiple(" ", 4);
		printMultiple("█", 6);
		printMultiple(" ", 8);
		printf("│ ");
		break;
	case 9:
		printf("│");
		printMultiple(" ", 3);
		printMultiple("█", 3);
		printMultiple(" ", 2);
		printMultiple("█", 2);
		printMultiple(" ", 8);
		printf("│ ");
		break;
	case 10:
		printf("│");
		printMultiple(" ", 1);
		printMultiple("█", 4);
		printMultiple(" ", 13);
		printf("│ ");
		break;
	case 11:
		printf("│");
		printMultiple(" ", 1);
		printMultiple("█", 3);
		printMultiple(" ", 14);
		printf("│ ");
		break;
	case 12:
		printf("╚══════[ %.2d ]══════╝ ", nWeaponIndex);
		break;
	}
}

void printUchigatana(int nSpriteLine, int nWeaponIndex){
	switch (nSpriteLine){
	case 0:
		printf("╔══════════════════╗ ");
		break;
	case 1:
		printf("│");
		printMultiple(" ", 13);
		printMultiple("█", 3);
		printMultiple(" ", 2);
		printf("│ ");
		break;
	case 2:
		printf("│");
		printMultiple(" ", 12);
		printMultiple("█", 4);
		printMultiple(" ", 2);
		printf("│ ");
		break;
	case 3:
		printf("│");
		printMultiple(" ", 11);
		printMultiple("█", 5);
		printMultiple(" ", 2);
		printf("│ ");
		break;
	case 4:
		printf("│");
		printMultiple(" ", 6);
		printMultiple("█", 9);
		printMultiple(" ", 3);
		printf("│ ");
		break;
	case 5:
		printf("│");
		printMultiple(" ", 9);
		printMultiple("█", 5);
		printMultiple(" ", 4);
		printf("│ ");
		break;
	case 6:
		printf("│");
		printMultiple(" ", 8);
		printMultiple("█", 7);
		printMultiple(" ", 3);
		printf("│ ");
		break;
	case 7:
		printf("│");
		printMultiple(" ", 7);
		printMultiple("█", 4);
		printMultiple(" ", 3);
		printMultiple("█", 1);
		printMultiple(" ", 3);
		printf("│ ");
		break;
	case 8:
		printf("│");
		printMultiple(" ", 6);
		printMultiple("█", 4);
		printMultiple(" ", 8);
		printf("│ ");
		break;
	case 9:
		printf("│");
		printMultiple(" ", 5);
		printMultiple("█", 4);
		printMultiple(" ", 9);
		printf("│ ");
		break;
	case 10:
		printf("│");
		printMultiple(" ", 4);
		printMultiple("█", 4);
		printMultiple(" ", 10);
		printf("│ ");
		break;
	case 11:
		printf("│");
		printMultiple(" ", 4);
		printMultiple("█", 3);
		printMultiple(" ", 11);
		printf("│ ");
		break;
	case 12:
		printf("╚══════[ %.2d ]══════╝ ", nWeaponIndex);
		break;
	}
}

void printBasic_Whip (int nSpriteLine, int nWeaponIndex){
 switch (nSpriteLine){
	case 0:
		printf("╔══════════════════╗ ");
		break;
	case 1:
		printf("│");
		printMultiple(" ", 18);
		printf("│ ");
		break;
	case 2:
		printf("│");
		printMultiple(" ", 7);
		printMultiple("█", 3);
		printMultiple(" ", 8);
		printf("│ ");
		break;
	case 3:
		printf("│");
		printMultiple(" ", 5);
		printMultiple("█", 2);
		printMultiple(" ", 3);
		printMultiple("█", 3);
		printMultiple(" ", 5);
		printf("│ ");
		break;
	case 4:
		printf("│");
		printMultiple(" ", 3);
		printMultiple("█", 2);
		printMultiple(" ", 8);
		printMultiple("█", 1);
		printMultiple(" ", 4);
		printf("│ ");
		break;
	case 5:
		printf("│");
		printMultiple(" ", 2);
		printMultiple("█", 1);
		printMultiple(" ", 3);
		printMultiple("█", 5);
		printMultiple(" ", 3);
		printMultiple("█", 2);
		printMultiple(" ", 2);
		printf("│ ");
		break;
	case 6:
		printf("│");
		printMultiple(" ", 2);
		printMultiple("█", 4);
		printMultiple(" ",  4);
		printMultiple("█", 1);
		printMultiple(" ", 5);
		printMultiple("█", 1);
		printMultiple(" ", 1);
		printf("│ ");
		break;
	case 7:
		printf("│");
		printMultiple(" ", 2);
		printMultiple("█", 4);
		printMultiple(" ", 5);
		printMultiple("█", 2);
		printMultiple(" ", 3);
		printMultiple("█", 1);
		printMultiple(" ", 1);
		printf("│ ");
		break;
	case 8:
		printf("│");
		printMultiple(" ", 2);
		printMultiple("█", 3);
		printMultiple(" ", 8);
		printMultiple("█", 1);
		printMultiple(" ", 3);
		printMultiple("█", 1);
		printf("│ ");
		break;
	case 9:
		printf("│");
		printMultiple(" ", 3);
		printMultiple("█", 1);
		printMultiple(" ", 10);
		printMultiple("█", 1);
		printMultiple(" ", 2);
		printMultiple("█", 1);
		printf("│ ");
		break;
	case 10:
		printf("│");
		printMultiple(" ", 14);
		printMultiple("█", 1);
		printMultiple(" ", 1);
		printMultiple("█", 1);
		printMultiple(" ", 1);
		printf("│ ");
		break;
	case 11:
		printf("│");
		printMultiple(" ", 15);
		printMultiple("█", 1);
		printMultiple(" ", 2);
		printf("│ ");
		break;
	case 12:
		printf("╚══════[ %.2d ]══════╝ ", nWeaponIndex);;
		break;
	}
}

void printClaymore (int nSpriteLine, int nWeaponIndex){
switch (nSpriteLine){
	case 0:
		printf("╔══════════════════╗ ");
		break;
	case 1:
		printf("│");
		printMultiple(" ", 11);
		printMultiple("█", 5);
		printMultiple(" ", 2);
		printf("│ ");
		break;
	case 2:
		printf("│");
		printMultiple(" ", 10);
		printMultiple("█", 6);
		printMultiple(" ", 2);
		printf("│ ");
		break;
	case 3:
		printf("│");
		printMultiple(" ", 9);
		printMultiple("█", 6);
		printMultiple(" ", 3);
		printf("│ ");
		break;
	case 4:
		printf("│");
		printMultiple(" ", 2);
		printMultiple("█", 3);
		printMultiple(" ", 3);
		printMultiple("█", 6);
		printMultiple(" ", 4);
		printf("│ ");
		break;
	case 5:
		printf("│");
		printMultiple(" ", 2);
		printMultiple("█", 2);
		printMultiple(" ", 3);
		printMultiple("█", 6);
		printMultiple(" ", 5);
		printf("│ ");
		break;
	case 6:
		printf("│");
		printMultiple(" ", 2);
		printMultiple("█", 10);
		printMultiple(" ", 6);
		printf("│ ");
		break;
	case 7:
		printf("│");
		printMultiple(" ", 5);
		printMultiple("█", 6);
		printMultiple(" ", 7);
		printf("│ ");
		break;
	case 8:
		printf("│");
		printMultiple(" ", 4);
		printMultiple("█", 6);
		printMultiple(" ", 1);
		printMultiple("█", 2);
		printMultiple(" ", 5);
		printf("│ ");
		break;
	case 9:
		printf("│");
		printMultiple(" ", 3);
		printMultiple("█", 3);
		printMultiple(" ", 2);
		printMultiple("█", 5);
		printMultiple(" ", 5);
		printf("│ ");
		break;
	case 10:
		printf("│");
		printMultiple(" ", 1);
		printMultiple("█", 4);
		printMultiple(" ", 13);
		printf("│ ");
		break;
	case 11:
		printf("│");
		printMultiple(" ", 1);
		printMultiple("█", 3);
		printMultiple(" ", 14);
		printf("│ ");
		break;
	case 12:
		printf("╚══════[ %.2d ]══════╝ ", nWeaponIndex);
		break;
	}
}

void printAstrologerStaff(int nSpriteLine, int nWeaponIndex) {
 switch (nSpriteLine){
	case 0:
		printf("╔══════════════════╗ ");
		break;
	case 1:
		printf("│");
		printMultiple(" ", 7);
		printMultiple("█", 4);
		printMultiple(" ", 7);
		printf("│ ");
		break;
	case 2:
		printf("│");
		printMultiple(" ", 6);
		printMultiple("█", 1);
		printMultiple(" ", 4);
		printMultiple("█", 1);
		printMultiple(" ", 6);
		printf("│ ");
		break;
	case 3:
		printf("│");
		printMultiple(" ", 7);
		printMultiple("█", 1);
		printMultiple(" ", 2);
		printMultiple("█", 1);
		printMultiple(" ", 7);
		printf("│ ");
		break;
	case 4:
		printf("│");
		printMultiple(" ", 6);
		printMultiple("█", 6);
		printMultiple(" ", 6);
		printf("│ ");
		break;
	case 5:
		printf("│");
		printMultiple(" ", 7);
		printMultiple("█", 4);
		printMultiple(" ", 7);
		printf("│ ");
		break;
	case 6:
		printf("│");
		printMultiple(" ", 4);
		printMultiple("█", 2);
		printMultiple(" ", 2);
		printMultiple("█", 2);
		printMultiple(" ", 2);
		printMultiple("█", 2);
		printMultiple(" ", 4);
		printf("│ ");
		break;
	case 7:
		printf("│");
		printMultiple(" ", 5);
		printMultiple("█", 8);
		printMultiple(" ", 5);
		printf("│ ");
		break;
	case 8:
		printf("│");
		printMultiple(" ", 8);
		printMultiple("█", 2);
		printMultiple(" ", 8);
		printf("│ ");
		break;
	case 9:
		printf("│");
		printMultiple(" ", 8);
		printMultiple("█", 2);
		printMultiple(" ", 8);
		printf("│ ");
		break;
	case 10:
		printf("│");
		printMultiple(" ", 8);
		printMultiple("█", 2);
		printMultiple(" ", 8);
		printf("│ ");
		break;
	case 11:
		printf("│");
		printMultiple(" ", 8);
		printMultiple("█", 2);
		printMultiple(" ", 8);
		printf("│ ");
		break;
	case 12:
		printf("╚══════[ %.2d ]══════╝ ", nWeaponIndex);
		break;
	}
}

void printFingerSeal(int nSpriteLine, int nWeaponIndex) {
 switch (nSpriteLine){
	case 0:
		printf("╔══════════════════╗ ");
		break;
	case 1:
		printf("│");
		printMultiple(" ", 9);
		printMultiple("█", 1);
		printMultiple(" ", 8);
		printf("│ ");
		break;
	case 2:
		printf("│");
		printMultiple(" ", 8);
		printMultiple("█", 1);
		printMultiple(" ", 1);
		printMultiple("█", 1);
		printMultiple(" ", 7);
		printf("│ ");
		break;
	case 3:
		printf("│");
		printMultiple(" ", 3);
		printMultiple("█", 1);
		printMultiple(" ", 3);
		printMultiple("█", 1);
		printMultiple(" ", 3);
		printMultiple("█", 1);
		printMultiple(" ", 3);
		printMultiple("█", 1);
		printMultiple(" ", 2);
		printf("│ ");
		break;
	case 4:
		printf("│");
		printMultiple(" ", 2);
		printMultiple("█", 1);
		printMultiple(" ", 1);
		printMultiple("█", 1);
		printMultiple(" ", 1);
		printMultiple("█", 1);
		printMultiple(" ", 5);
		printMultiple("█", 1);
		printMultiple(" ", 1);
		printMultiple("█", 1);
		printMultiple(" ", 1);
		printMultiple("█", 1);
		printMultiple(" ", 1);
		printf("│ ");
		break;
	case 5:
		printf("│");
		printMultiple(" ", 2);
		printMultiple("█", 1);
		printMultiple(" ", 2);
		printMultiple("█", 1);
		printMultiple(" ", 7);
		printMultiple("█", 1);
		printMultiple(" ", 2);
		printMultiple("█", 1);
		printMultiple(" ", 1);
		printf("│ ");
		break;
	case 6:
		printf("│");
		printMultiple(" ", 2);
		printMultiple("█", 1);
		printMultiple(" ", 5);
		printMultiple("█", 3);
		printMultiple(" ", 5);
		printMultiple("█", 1);
		printMultiple(" ", 1);
		printf("│ ");
		break;
	case 7:
		printf("│");
		printMultiple(" ", 2);
		printMultiple("█", 1);
		printMultiple(" ", 4);
		printMultiple("█", 5);
		printMultiple(" ", 4);
		printMultiple("█", 1);
		printMultiple(" ", 1);
		printf("│ ");
		break;
	case 8:
		printf("│");
		printMultiple(" ", 2);
		printMultiple("█", 1);
		printMultiple(" ", 5);
		printMultiple("█", 3);
		printMultiple(" ", 5);
		printMultiple("█", 1);
		printMultiple(" ", 1);
		printf("│ ");
		break;
	case 9:
		printf("│");
		printMultiple(" ", 3);
		printMultiple("█", 1);
		printMultiple(" ", 11);
		printMultiple("█", 1);
		printMultiple(" ", 2);
		printf("│ ");
		break;
	case 10:
		printf("│");
		printMultiple(" ", 4);
		printMultiple("█", 11);
		printMultiple(" ", 3);
		printf("│ ");
		break;
	case 11:
		printf("│");
		printMultiple(" ",18);
		printf("│ ");
		break;
	case 12:
		printf("╚══════[ %.2d ]══════╝ ", nWeaponIndex);
		break;
	}
}

void getWeaponSprites(int nWeaponIndex, int nSpriteLine) {
	switch (nWeaponIndex){
		case SHORT_SWORD:
		case ROGIER_RAPIER:
		case CODED_SWORD:
		case SWORD_OF_NIGHT_AND_FIRE:
			printShortSwordSlot(nSpriteLine, nWeaponIndex);
			break;
		case UCHIGATANA:
		case MOONVEIL:
		case RIVERS_OF_BLOOD:
		case HAND_OF_MALENIA:
			printUchigatana(nSpriteLine, nWeaponIndex);
			break;	
		case BASE_WHIP:
		case URUMI:
		case THORNED_WHIP:
		case HOSLOW_PETAL_WHIP:
			printBasic_Whip(nSpriteLine, nWeaponIndex);
			break;
		case CLAYMORE:
		case STARSCOURGE_GREATSWORD:
		case INSEPARABLE_SWORD:
		case MALIKETH_BLACK_BLADE:
			printClaymore(nSpriteLine, nWeaponIndex);
			break;
		case ASTROLOGER_STAFF:
		case ALBINAURIC_STAFF:
		case STAFF_OF_THE_GUILTY:
		case CARIAN_REGAL_SCEPTER:
			printAstrologerStaff(nSpriteLine, nWeaponIndex);
			break;
		case FINGER_SEAL:
		case GODSLAYER_SEAL:
		case GOLDEN_ORDEAL_SEAL:
		case DRAGON_COMMUNION_SEAL:
			printFingerSeal(nSpriteLine, nWeaponIndex);
			break;
	} 
}