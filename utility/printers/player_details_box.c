#include "player_details_box.h"

void printNavEnd(int nLine, int nOffset) {
	printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT + nOffset);
	printf(" ");

	if (nLine == 1) {
		printf("╔");
	}
	else {
		printf("╚");
	}

	printMultiple("═", SPRITE_WIDTH + 2);

	if (nLine == 1) {
		printf("╦");
	}
	else {
		printf("╩");
	}

	printMultiple("═", 28);

	if (nLine == 1) {
		printf("╦");
	}
	else {
		printf("╩");
	}

	printMultiple("═", 19);

	if (nLine == 1) {
		printf("╗");
	}
	else {
		printf("╝");
	}

	printf("\n");
}

void printRoundtableNav(Player sPlayer, int nPrompt) {
	int nLine;
	int nOffset = (SCREEN_WIDTH - NAV_WIDTH) / 2;
	int nDialogueNum = randomNumberBetween(5, 1);

	for (nLine = 0; nLine < NAV_HEIGHT; nLine++) {
		printRoundtableNavLine(nLine, nOffset, sPlayer, nPrompt, nDialogueNum);
	}
}

void printRoundtableNavLine(int nLine, int nOffset, Player sPlayer, int nPrompt, int nDialogueNum) {
	switch (nLine) {
		case 0:
			printf("\n");
			break;

		case 1:
			printNavEnd(nLine, nOffset);
			break;

		case 2:
			printNameAndJobClass(nLine, sPlayer, nOffset);
			break;

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
			printRoundtableNavUI(nLine, sPlayer, nOffset, nPrompt, nDialogueNum);
			break;

		case 13:
			printNavEnd(nLine, nOffset);
			printf("\n");
			break;
	}
}	

void printRoundtableNavUI(int nLine, Player sPlayer, int nOffset, int nPrompt, int nDialogueNum) {
	printPlayerSpritePerLineNav(nLine, nOffset, sPlayer);

	if (nLine == 12) {
		printTopBottomSpriteBorders(nLine);
	}

	if (nPrompt) {
		printDialoguePerLine(nLine, nPrompt, nDialogueNum);
	}
	else {
		printRoundtablePlayerStatsPerLine(nLine, sPlayer);
	}

	printPlayerStats(nLine, sPlayer);	
}

void printRoundtablePlayerStatsPerLine(int nLine, Player sPlayer) {
	int nPrintShard; 
	int nMissingShard;

	switch (nLine - 3) {
		case 0:
			printMultiple("─", 28);
			printf("┼");
			break;

		case 1:
			printf(" SHARDS: ");
			for (nPrintShard = 0; nPrintShard < sPlayer.nShards; nPrintShard++) {
				printf("█ ");
			}

			for (nMissingShard = nPrintShard; nMissingShard < 6; nMissingShard++) {
				printf("░ ");
			}
			printMultiple(" ", 7);
			printf("│");
			break;

		case 2:
			printMultiple(" ", 28);
			printf("│");
			break;

		case 3:
			printf(" PLAYER STATS:");
			printMultiple(" ", 14);
			printf("│");
			break;

		case 4:
			printf(" HEALTH LEVEL: ");
			printf("%-2d", sPlayer.sPlayerStats.nHealth);
			printMultiple(" ", 28 - strlen(" HEALTH LEVEL: ") - 2);
			printf("│");
			break;	
			
		case 5:
			printf(" ENDURANCE LEVEL: ");
			printf("%-2d", sPlayer.sPlayerStats.nEndurance);
			printMultiple(" ", 28 - strlen(" ENDURANCE LEVEL: ") - 2);
			printf("│");
			break;	

		case 6:
			printf(" DEXTERITY LEVEL: ");
			printf("%-2d", sPlayer.sPlayerStats.nDexterity);
			printMultiple(" ", 28 - strlen(" DEXTERITY LEVEL: ") - 2);
			printf("│");
			break;									

		case 7:
			printf(" STRENGTH LEVEL: ");
			printf("%-2d", sPlayer.sPlayerStats.nStrength);
			printMultiple(" ", 28 - strlen(" STRENGTH LEVEL: ") - 2);
			printf("│");
			break;	

		case 8:
			printf(" INTELLIGENCE LEVEL: ");
			printf("%-2d", sPlayer.sPlayerStats.nIntelligence);
			printMultiple(" ", 28 - strlen(" INTELLIGENCE LEVEL: ") - 2);
			printf("│");
			break;	

		case 9:
			printf(" FAITH LEVEL: ");
			printf("%-2d", sPlayer.sPlayerStats.nFaith);
			printMultiple(" ", 28 - strlen(" FAITH LEVEL: ") - 2);
			printf("│");
			break;				
	}	
}

void printAreaNav(Player sPlayer, int nPrompt) {
	int nLine;
	int nOffset = (SCREEN_WIDTH - NAV_WIDTH) / 2;
	int nDialogueNum = randomNumberBetween(5, 1);

	for (nLine = 0; nLine < NAV_HEIGHT; nLine++) {
		printAreaNavLine(nLine, nOffset, sPlayer, nPrompt, nDialogueNum);
	}
}

void printAreaNavLine(int nLine, int nOffset, Player sPlayer, int nPrompt, int nDialogueNum) {
	switch (nLine) {
		case 0:
			printf("\n");
			break;

		case 1:
			printNavEnd(nLine, nOffset);
			break;

		case 2:
			printNameAndJobClass(nLine, sPlayer, nOffset);
			break;

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
			printAreaNavUI(nLine, sPlayer, nOffset, nPrompt, nDialogueNum);
			break;

		case 13:
			printNavEnd(nLine, nOffset);
			printf("\n");
			break;
	}
}

void printNameAndJobClass(int nLine, Player sPlayer, int nOffset) {
	printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT + nOffset);
	printf(" ");
	printTopBottomSpriteBorders(nLine);

	printf("%s", sPlayer.strPlayerName);
	printMultiple(" ", 27 - strlen(sPlayer.strPlayerName));
	printf("│ ");
	printf("%s", sPlayer.strPlayerJobClass);
	printMultiple(" ", 18 - strlen(sPlayer.strPlayerJobClass));
	printf("│");
	printf("\n");
}

void printAreaNavUI(int nLine, Player sPlayer, int nOffset, int nPrompt, int nDialogueNum) {
	printPlayerSpritePerLineNav(nLine, nOffset, sPlayer);

	if (nLine == 12) {
		printTopBottomSpriteBorders(nLine);
	}

	if (nPrompt) {
		printDialoguePerLine(nLine, nPrompt, nDialogueNum);
	}
	else {
		printNavOptionsPerLine(nLine);
	}

	printPlayerStats(nLine, sPlayer);
}

void printPlayerSpritePerLineNav(int nLine, int nOffset, Player sPlayer) {
	printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT + nOffset);
	printf(" ");

	if (nLine != 12) {
		printf("│█");
	}

	printPlayerSprite(nLine - 2, sPlayer);

	if (nLine == 3) {
		printf("█├");
	}
	else if (nLine != 12) {
		printf("█│");
	}
}

void printNavOptionsPerLine(int nLine) {
	switch (nLine - 3) {
		case 0:
			printMultiple("─", 28);
			printf("┼");
			break;

		case 1:
			printMultiple(" ", 28);
			printf("│");
			break;

		case 2:
			printMultiple(" ", 8);
			printf("╔─W─╗");
			printMultiple(" ", 7);
			printf("╔─E─╗");
			printMultiple(" ", 3);
			printf("│");
			break;

		case 3:
			printMultiple(" ", 8);
			printf("│ ▲ │");
			printMultiple(" ", 7);
			printf("│ ¤ │");
			printMultiple(" ", 3);
			printf("│");
			break;	
			
		case 4:
			printMultiple(" ", 2);
			printf("╔─A─╗");
			printMultiple(" ", 1);
			printf("╚───╝");
			printMultiple(" ", 1);
			printf("╔─D─╗");
			printMultiple(" ", 1);
			printf("╚───╝");
			printMultiple(" ", 3);
			printf("│");
			break;	

		case 5:
			printMultiple(" ", 2);
			printf("│ ◄ │");
			printMultiple(" ", 7);
			printf("│ ► │");
			printMultiple(" ", 9);
			printf("│");
			break;									

		case 6:
			printMultiple(" ", 2);
			printf("╚───╝");
			printMultiple(" ", 1);
			printf("╔─S─╗");
			printMultiple(" ", 1);
			printf("╚───╝");
			printMultiple(" ", 9);
			printf("│");
			break;	

		case 7:
			printMultiple(" ", 8);
			printf("│ ▼ │");
			printMultiple(" ", 15);
			printf("│");
			break;	

		case 8:
			printMultiple(" ", 8);
			printf("╚───╝");
			printMultiple(" ", 15);
			printf("│");
			break;	

		case 9:
			printMultiple(" ", 28);
			printf("│");
			break;
	}
}

void printPlayerStats(int nLine, Player sPlayer) {
	switch (nLine - 3) {
		case 0:
			printMultiple("─", 19);
			printf("┤");
			break;

		case 1:
			printMultiple(" ", 1);
			printf("LEVEL: ");
			printf("%-10d", sPlayer.nLevel);
			printMultiple(" ", 1);
			printf("│");
			break;	
			
		case 2:
		case 4:
		case 7:
			printMultiple(" ", 19);
			printf("│");
			break;	

		case 3:
			printMultiple(" ", 1);
			printf("RUNES: ");
			if (sPlayer.nRunes < 999999999) {
				printf("%-9d ", sPlayer.nRunes);
			}
			else {
				printf("999999999+");
			}
			printMultiple(" ", 1);
			printf("│");
			break;		

		case 5:
			printMultiple(" ", 1);
			printf("HEALTH: ");
			if (sPlayer.sPlayerAreaDetails.nCurrentHealth < 99999999) {
				printf("%-8d ", sPlayer.sPlayerAreaDetails.nCurrentHealth);
			}
			else {
				printf("99999999+");
			}
			printMultiple(" ", 1);
			printf("│");
			break;	

		case 6:
			printPlayerHealthBar(sPlayer.sPlayerAreaDetails, 15);
			printMultiple(" ", 2);	
			printf("│");
			break;	

		case 8:
			printMultiple(" ", 1);
			printf("POTIONS");
			printMultiple(" ", 11);
			printf("│");
			break;

		case 9:
			printPlayerPotions(sPlayer.nPotions); 
			printMultiple(" ", 2);
			printf("│");
			break;
	}
	printf("\n");
}

void printDialoguePerLine(int nLine, int nPrompt, int nDialogueNum) {
	StringFullDialogue strFullDialogue;

	switch (nLine - 3) {
		case 0:
			printMultiple("─", 28);
			printf("┼");
			break;

		default:
			switch (nPrompt) {
			case EMPTY_TILE_PROMPT:
				loadDialogueEmptyTile(strFullDialogue, nDialogueNum); 
				break;

			case TREASURE_TILE_PROMPT:
				loadDialogueTreasureTile(strFullDialogue, nDialogueNum);
				break;

			case ENEMY_TILE_PROMPT:
				loadDialogueEnemyTile(strFullDialogue, nDialogueNum);
				break;

			case NEW_UNLOCKED_TILE_PROMPT:
				loadDialogueNewUnlockedTile(strFullDialogue, nDialogueNum);
				break;

			case BOSS_TILE_PROMPT:
				loadDialogueBossTile(strFullDialogue, nDialogueNum);
				break;

			case LOCKED_TILE_PROMPT:
				loadDialogueLockedTile(strFullDialogue, nDialogueNum);
				break;

			case FINISHED_ELDEN_THRONE_PROMPT:
				loadDialogueFinishedEldenThrone(strFullDialogue, nDialogueNum);
				break;

			case RH_FAST_TRAVEL_PROMPT:
				loadDialogueFastTravel(strFullDialogue, nDialogueNum);
				break;

			case RH_FAST_TRAVEL_LOCKED_PROMPT:
				loadDialogueFastTravelLocked(strFullDialogue, nDialogueNum);
				break;				
	}
      		printDialogueLineText(nLine - 4, strFullDialogue);

     			printf("│");
	}
}

/*
      ──────────────────────────────────────────────────────────────────────
       ╔═════════════════╦════════════════════════════╦═══════════════════╗
       │█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█│ 1234567890123456789012345  | ASTROLOGER        |
       │█     █████     █├────────────────────────────┼───────────────────┤
       │█    █     █    █│                            │ LEVEL: 8          │
       │█   █       █   █│        ╔─W─╗       ╔─E─╗   │                   │
       │█   █      ██   █│        │ ▲ │       │ ¤ │   │ RUNES: 1000000000 │
       │█  █  █████  █  █│  ╔─A─╗ ╚───╝ ╔─D─╗ ╚───╝   │                   │
       │█  ███       █  █│  │ ◄ │       │ ► │         │ HEALTH            │
       │█   █  █  █ █   █│  ╚───╝ ╔─S─╗ ╚───╝         │ ██████████        │
       │█  ███     ███  █│        │ ▼ │               │                   │
       │█ █   █████   █ █│        ╚───╝               │ POTIONS           │
       │█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█│                            │ █ █ █ █ █ █ █ █   │
       ╚═════════════════╩════════════════════════════╩═══════════════════╝
*/