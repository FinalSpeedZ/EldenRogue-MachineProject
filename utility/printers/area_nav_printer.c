#include "area_nav_printer.h"

void printAreaNav(Player* pPlayer) {
	int nLine;
	int nOffset = (SCREEN_WIDTH - NAV_WIDTH) / 2;

	for (nLine = 0; nLine < NAV_HEIGHT; nLine++) {
		printAreaNavLine(nLine, nOffset, pPlayer);
	}
}

void printAreaNavLine(int nLine, int nOffset, Player* pPlayer) {
	switch (nLine) {
		case 0:
			printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT + nOffset);
			printMultiple("─", NAV_WIDTH);
			printf("\n");
			break;

		case 1:
			printAreaNavEnd(nLine, nOffset);
			break;

		case 2:
			printNameAndJobClass(nLine, pPlayer, nOffset);
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
			printAreaNavUI(nLine, pPlayer, nOffset);
			break;

		case 13:
			printAreaNavEnd(nLine, nOffset);
			printf("\n");
			break;
	}
}

void printAreaNavEnd(int nLine, int nOffset) {
	printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT + nOffset);
	printf(" ");

	if (nLine == 1) {
		printf("╔");
	}
	else {
		printf("╚");
	}

	printMultiple("═", 17);

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

void printNameAndJobClass(int nLine, Player* pPlayer, int nOffset) {
	printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT + nOffset);
	printf(" ");
	printTopBottomSpriteBorders(nLine);

	printf("%s", pPlayer->strPlayerName);
	printMultiple(" ", 27 - strlen(pPlayer->strPlayerName));
	printf("│ ");
	printf("%s", pPlayer->strPlayerJobClass);
	printMultiple(" ", 18 - strlen(pPlayer->strPlayerJobClass));
	printf("│");
	printf("\n");
}

void printAreaNavUI(int nLine, Player* pPlayer, int nOffset) {
	printSpritePerLine(nLine, nOffset);

	if (nLine == 12) {
		printTopBottomSpriteBorders(nLine);
	}

	printNavOptionsPerLine(nLine);

	printPlayerStats(nLine, pPlayer);
}

void printSpritePerLine(int nLine, int nOffset) {
	printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT + nOffset);
	printf(" ");

	if (nLine != 12) {
		printf("│█");
	}

	printSprite(nLine - 2);

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

void printPlayerStats(int nLine, Player* pPlayer) {
	switch (nLine - 3) {
		case 0:
			printMultiple("─", 19);
			printf("│");
			break;

		case 1:
			printMultiple(" ", 1);
			printf("LEVEL: ");
			printf("%-10d", pPlayer->nLevel);
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
			if (pPlayer->nRunes < 999999999) {
				printf("%-9d ", pPlayer->nRunes);
			}
			else {
				printf("999999999+");
			}
			printMultiple(" ", 1);
			printf("│");
			break;		

		case 5:
			printMultiple(" ", 1);
			printf("HEALTH");
			printMultiple(" ", 12);
			printf("│");
			break;	

		case 6:
			printMultiple(" ", 1);
			printMultiple("█", 10);	
			printMultiple(" ", 8);	
			printf("│");
			break;	

		case 8:
			printMultiple(" ", 1);
			printf("POTIONS");
			printMultiple(" ", 11);
			printf("│");
			break;

		case 9:
			printMultiple(" ", 1);
			printMultiple("█", 1);
			printMultiple(" ", 1);
			printMultiple("█", 1);
			printMultiple(" ", 1);
			printMultiple("█", 1);
			printMultiple(" ", 1);
			printMultiple("█", 1);
			printMultiple(" ", 1);
			printMultiple("█", 1);
			printMultiple(" ", 1);
			printMultiple("█", 1);
			printMultiple(" ", 1);
			printMultiple("█", 1);
			printMultiple(" ", 1);
			printMultiple("█", 1);
			printMultiple(" ", 3);
			printf("│");
			break;
	}
	printf("\n");
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