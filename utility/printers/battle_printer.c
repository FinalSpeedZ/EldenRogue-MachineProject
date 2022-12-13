#include "battle_printer.h" 

#include "../area_utility/battle_screen_helper.h"

void printBattleDisplay(Player sPlayer, Enemy sEnemy, int nAreaIndex, int nEnemyTurn, int nBoss) {
	int nLine;
	int nOffset = (SCREEN_WIDTH - HEALTH_WIDTH - SPRITE_WIDTH) / 2;

	for (nLine = 0; nLine <= SPRITE_HEIGHT + 4; nLine++) {
		printEnemyBattleDisplayLine(nLine, nOffset + 15, sEnemy, nAreaIndex, nBoss);
	}

	for (nLine = 0; nLine <= SPRITE_HEIGHT + 4; nLine++) {
		printPlayerBattleDisplayLine(nLine, nOffset - 20, sPlayer, sEnemy.nFinalAttack);
	}

	printf("\n");

	if (nEnemyTurn == 0 && sPlayer.sPlayerAreaDetails.nCurrentHealth != 0) {
		printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT + nOffset);
		printMultiple("─", HEALTH_WIDTH + SPRITE_WIDTH);
		printf("\n");
	}
}

void printEnemyBattleDisplayLine(int nLine, int nOffset, Enemy sEnemy, int nAreaIndex, int nBoss) {
	switch (nLine) {
		case 1:
			printEnemyBattleEnd(nLine, nOffset);
			break;

		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
			printEnemyBattleUI(nLine, nOffset, sEnemy, nAreaIndex, nBoss);
			break;

		case 13:
			printEnemyBattleEnd(nLine, nOffset);
			break;

	}

	printf("\n");
}

void printEnemyBattleEnd(int nLine, int nOffset) {
	printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT + nOffset + HEALTH_WIDTH);

	if (nLine == 1) {
		printf("╔");
	}
	else {
		printf("╚");
	}

	printMultiple("═", 17);

	if (nLine == 1) {
		printf("╗");
	}
	else {
		printf("╝");
	}
}

void printEnemyBattleUI(int nLine, int nOffset, Enemy sEnemy, int nAreaIndex, int nBoss) {
	if (nLine == 2) {
		printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT + nOffset + HEALTH_WIDTH);
		printTopBottomSpriteBorders(nLine);
	}

	if (nLine == 6) {
		printEnemyName(nOffset, sEnemy.pEnemyName);
	}

	if (nLine == 7) {
		printEnemyHealthBar(nOffset, sEnemy, nBoss);
	}

	if (nLine == 8) {
		printEnemyHealth(nOffset, sEnemy);
	}

	if (nLine != 2) {
		printEnemySpritePerLineBattle(nLine, nOffset, sEnemy, nAreaIndex);
	}

	if (nLine == 12) {
		printTopBottomSpriteBorders(nLine);
	}
}

void printEnemyName(int nOffset, char* pEnemyName) {
	int nLength = strlen(pEnemyName);

	printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT + nOffset + HEALTH_WIDTH - nLength - 1);	
	printf("%s ", pEnemyName);
}

void printEnemySpritePerLineBattle(int nLine, int nOffset, Enemy sEnemy, int nAreaIndex) {
	if  (nLine != 6 && nLine != 7 && nLine != 8) {
		printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT + nOffset + HEALTH_WIDTH);
	}

	if (nLine != 12) {
		printf("│█");
	}

	printEnemySprite(nLine - 2, nAreaIndex, sEnemy);

	if (nLine != 12) {
		printf("█│");
	}
}

void printEnemyHealthBar(int nOffset, Enemy sEnemy, int nBoss) {
	int nBars = HEALTH_WIDTH;
	int nDamagedBars = 0;

	int nDamagedHealth = sEnemy.nFinalHealth - sEnemy.nCurrentHealth;
	float fHealthPerBar = (float) sEnemy.nFinalHealth / nBars;
	int nNumberOfDamageBars = nDamagedHealth / fHealthPerBar;

	printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT + nOffset - 1);


	if (sEnemy.nCurrentHealth != 0) {
		for (nDamagedBars = 0; nDamagedBars < nNumberOfDamageBars; nDamagedBars++) {
			colorText(COLOR_DAMAGED_BAR);
			printf("░");
		}

		for (nBars = nDamagedBars; nBars < HEALTH_WIDTH; nBars++) {
			if (sEnemy.nCurrentHealth >= sEnemy.nFinalHealth * 0.66) {
				colorText(COLOR_HEALTH_GREEN);
				printf("█");
			}

			else if (sEnemy.nCurrentHealth <= sEnemy.nFinalHealth * 0.66 && 
					 sEnemy.nCurrentHealth >= sEnemy.nFinalHealth * 0.33) {
				colorText(COLOR_HEALTH_YELLOW);
				printf("█");
			}

			else {
				colorText(COLOR_HEALTH_RED);
				printf("█");
			}
		}

		resetColors();
	}

	else {
		colorText(COLOR_HEALTH_RED);
		if (nBoss == 0) {
			printf("%50s", "ENEMY FELLED");
		}
		else {
			printf("%50s", "GREAT ENEMY FELLED");
		}
		resetColors();
	}

	printf(" ");
}

void printEnemyHealth(int nOffset, Enemy sEnemy) {
	int nDigits1 = 0;
	int nCurrentHealthCopy = sEnemy.nCurrentHealth;
	int nDigits2 = 0;
	int nFinalHealthCopy = sEnemy.nFinalHealth;

	do {
		nCurrentHealthCopy = nCurrentHealthCopy / 10;
		nDigits1 += 1;	
	} while (nCurrentHealthCopy != 0);

	do {
		nFinalHealthCopy = nFinalHealthCopy / 10;
		nDigits2 += 1;	
	} while (nFinalHealthCopy != 0);

	printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT + nOffset + HEALTH_WIDTH - 7 - nDigits1 - nDigits2 - 1);	
	
	printf("HP: ");
	printf("%d | ", sEnemy.nCurrentHealth);
	printf("%d ", sEnemy.nFinalHealth);
}

void printPlayerBattleDisplayLine(int nLine, int nOffset, Player sPlayer, int nIncomingDamage) {
	switch (nLine) {
		case 1:
			printPlayerBattleEnd(nLine, nOffset);
			break;

		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
			printPlayerBattleUI(nLine, nOffset, sPlayer, nIncomingDamage);
			break;

		case 13:
			printPlayerBattleEnd(nLine, nOffset);
			break;

	}

	printf("\n");
}

void printPlayerBattleEnd(int nLine, int nOffset) {
	printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT + nOffset);

	if (nLine == 1) {
		printf("╔");
	}
	else {
		printf("╚");
	}

	printMultiple("═", 17);

	if (nLine == 1) {
		printf("╗");
	}
	else {
		printf("╝");
	}
}

void printPlayerBattleUI(int nLine, int nOffset, Player sPlayer, int nIncomingDamage) {
	printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT + nOffset);

	if (nLine == 2) {
		printTopBottomSpriteBorders(nLine);
	}

	if (nLine != 2) {
		printPlayerSpritePerLineBattle(nLine, sPlayer);
	}

	if (nLine == 3) {
		printIncomingDamage(nIncomingDamage, sPlayer);
	}

	if (nLine == 5) {
		printPlayerNameJob(sPlayer);
	}

	if (nLine == 6) {
		printPlayerHealthBar(sPlayer.sPlayerAreaDetails, HEALTH_WIDTH);
	}

	if (nLine == 7) {
		printPlayerHealth(sPlayer.sPlayerAreaDetails);
	}

	if (nLine == 9) {
		printf(" POTIONS");
	}

	if (nLine == 10) {
		printPlayerPotions(sPlayer.nPotions);
	} 

	if (nLine == 12) {
		printTopBottomSpriteBorders(nLine);
	}	
}

void printPlayerNameJob(Player sPlayer) {
	printf(" %s | %s", sPlayer.strPlayerName, sPlayer.strPlayerJobClass);	
}

void printIncomingDamage(int nIncomingDamage, Player sPlayer) {
	if (sPlayer.sPlayerAreaDetails.nCurrentHealth != 0) {
		printf(" INCOMING DAMAGE: ");
		printf("%d", nIncomingDamage);
	}
}

void printPlayerSpritePerLineBattle(int nLine, Player sPlayer) {
	if (nLine != 12) {
		printf("│█");
	}

	printPlayerSprite(nLine - 2, sPlayer);

	if (nLine != 12) {
		printf("█│");
	}
}

void printPlayerHealthBar(AreaDetails sPlayerAreaDetails, int nHealthBars) {
	int nBars = nHealthBars;
	int nDamagedBars = 0;

	float fHealthPerBar = (float) sPlayerAreaDetails.nMaxHealth / nBars;

	int nUndamagedBars = sPlayerAreaDetails.nCurrentHealth / fHealthPerBar;

	printf(" ");

	if (sPlayerAreaDetails.nCurrentHealth != 0) {
		for (nBars = 0; nBars < nUndamagedBars; nBars++) {
			if (sPlayerAreaDetails.nCurrentHealth >= sPlayerAreaDetails.nMaxHealth * 0.66) {
				colorText(COLOR_HEALTH_GREEN);
				printf("█");
			}

			else if (sPlayerAreaDetails.nCurrentHealth <= sPlayerAreaDetails.nMaxHealth * 0.66 && 
					 sPlayerAreaDetails.nCurrentHealth >= sPlayerAreaDetails.nMaxHealth * 0.33) {
				colorText(COLOR_HEALTH_YELLOW);
				printf("█");
			}

			else {
				colorText(COLOR_HEALTH_RED);
				printf("█");
			}
		}

		for (nDamagedBars = nBars; nDamagedBars < nHealthBars; nDamagedBars++) {
			colorText(COLOR_DAMAGED_BAR);
			printf("░");
		}

		resetColors();
	}

	else {
		colorText(COLOR_HEALTH_RED);
		printf("YOU DIED");
		resetColors();
	}

	printf(" ");
}

void printPlayerHealth(AreaDetails sPlayerAreaDetails) {
	printf(" HP: ");
	printf("%d | ", sPlayerAreaDetails.nCurrentHealth);
	printf("%d ", sPlayerAreaDetails.nMaxHealth);	
}

void printPlayerPotions(int nPotions) {
	int nPotionCount;

	int nUsedPotions;

	printf(" ");
	for (nPotionCount = 1; nPotionCount <= nPotions; nPotionCount++) {
		colorText(COLOR_POTION);
		printf("█ ");
	}

	for (nUsedPotions = 0; nUsedPotions + nPotionCount <= DEFAULT_POTION_COUNT; nUsedPotions++) {
		colorText(COLOR_DAMAGED_BAR);
		printf("░ ");
	}

	resetColors();
}

void printBattleRunesGained(Player sPlayer, int nRunesGained, int nBoss) {
	int nLine;
	int nOffset = (SCREEN_WIDTH - SPRITE_WIDTH) / 2;
	int nValueDigits = 0;
	int nValueCopy = nRunesGained;

	do {
		nValueCopy = nValueCopy / 10;
		nValueDigits += 1;	
	} while (nValueCopy != 0);

	printf("\n");
	for (nLine = 1; nLine <= SPRITE_HEIGHT - 2; nLine++) {
		printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT + nOffset);
		printRunes(nLine);
		printf("\n");
	}

	if (nBoss) {
		printf("\n");
		printMiddleText("GREAT ENEMY FELLED", "»", "«");		
	}

	else {
		printf("\n");
		printMiddleText("ENEMY FELLED", "»", "«");
	}

	nOffset = (SCREEN_WIDTH - strlen("YOU HAVE GAINED ") - nValueDigits - strlen("RUNES!") - 4) / 2;
	printf("\n");
	printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT + nOffset);

	printf("║ YOU HAVE GAINED %d RUNES! ║\n\n", nRunesGained);
}


void printRunesLost() {
	int nLine;
	int nOffset = (SCREEN_WIDTH - SPRITE_WIDTH) / 2;

	printf("\n");
	for (nLine = 1; nLine <= SPRITE_HEIGHT - 1; nLine++) {
		printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT + nOffset);
		printLoseSprite(nLine);
		printf("\n");
	}

	printf("\n");
	printMiddleText("YOU DIED", "»", "«");

	nOffset = (SCREEN_WIDTH - strlen("YOU LOST ALL YOUR RUNES! ") - 4) / 2;
	printf("\n");
	printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT + nOffset);

	printf("║ YOU LOST ALL YOUR RUNES! ║\n\n");	
}
