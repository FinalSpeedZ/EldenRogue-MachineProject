#include "area_printer.h"

#include "../area_utility/area_boards.h"
#include "../../screens/roundtable_hold_screens/fast_travel.h"
#include "../area_utility/battle_screen_helper.h"
#include "../../screens/areas_screens/battle.h"

int* makeMapCopy(AreaFloor sAreaFloor) {
	int* pFloorBoardCopy = malloc(sizeof(int) * sAreaFloor.nRows * sAreaFloor.nColumns);
	int nRowCounter;
	int nColumnCounter;

	for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
		for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
			*(pFloorBoardCopy + nRowCounter * sAreaFloor.nColumns + nColumnCounter) = 
			*(sAreaFloor.pFloorBoardArray[sAreaFloor.nFloorNumber -  1] + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter);
		}
	}

	return pFloorBoardCopy;
}

void printAreaMap(AreaFloor sAreaFloor, AreaDetails* pPlayerAreaDetails) {
	int nRowCounter;
	int nColumnCounter;

	int nPadding = SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT + ((SCREEN_WIDTH	- 6 * sAreaFloor.nColumns) / 2);

	int* pFloorBoardCopy = makeMapCopy(sAreaFloor);

	*(pFloorBoardCopy + (pPlayerAreaDetails->nRowLocation * sAreaFloor.nColumns) + 
		pPlayerAreaDetails->nColumnLocation) = TILE_PLAYER;

	for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {

		printMultiple(" ", nPadding);
		for(nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
			printTileParts(*(pFloorBoardCopy + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter), TOP);
		}
		printf("\n");

		printMultiple(" ", nPadding);
		for(nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
			printTileParts(*(pFloorBoardCopy + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter), MIDDLE);
		}
		printf("\n");

		printMultiple(" ", nPadding);
		for(nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
			printTileParts(*(pFloorBoardCopy + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter), BOTTOM);
		}
		printf("\n");
	}

	free(pFloorBoardCopy);
}

void printTileParts(int nTileType, int nTilePosition) {
	switch (nTilePosition) {
		case TOP:
			switch (nTileType) {
				case TILE_EMPTY:
					colorText(COLOR_TILE_EMPTY); 
					printf("┌───┐ ");
					break;

				case TILE_PLAYER: 
					colorText(COLOR_TILE_PLAYER); 
					printf("╔═══╗ ");
					break;

				case TILE_DOOR_UP: 
					colorText(COLOR_TILE_DOOR_UP); 
					printf("┌───┐ ");
					break;

				case TILE_DOOR_DOWN: 
					colorText(COLOR_TILE_DOOR_DOWN); 
					printf("┌───┐ ");
					break;

				case TILE_DOOR_LEFT: 
					colorText(COLOR_TILE_DOOR_LEFT); 
					printf("┌───┐ ");
					break;

				case TILE_DOOR_RIGHT: 
					colorText(COLOR_TILE_DOOR_RIGHT); 
					printf("┌───┐ ");
					break;

				case TILE_SPAWN: 
					colorText(COLOR_TILE_SPAWN); 
					printf("┌───┐ ");
					break;

				case TILE_BOSS: 
					colorText(COLOR_TILE_BOSS); 
					printf("╔───╗ ");
					break;

				case TILE_FAST_TRAVEL:
					colorText(COLOR_TILE_FAST_TRAVEL);  
					printf("┌───┐ ");
					break;

				case TILE_CREDITS: 
					colorText(COLOR_TILE_CREDITS); 
					printf("┌───┐ ");
					break;

				case TILE_INVALID:
					colorText(COLOR_TILE_INVALID);  
					printf("┌┬┬┬┐ ");
					break;
			}
			break;

		case MIDDLE: 
			switch (nTileType) {
				case TILE_EMPTY: 
					colorText(COLOR_TILE_EMPTY); 
					printf("│   │ ");
					break;

				case TILE_PLAYER: 
					colorText(COLOR_TILE_PLAYER); 
					printf("║ ■ ║ ");
					break;

				case TILE_DOOR_UP: 
					colorText(COLOR_TILE_DOOR_UP); 
					printf("│ ↑ │ ");
					break; 

				case TILE_DOOR_DOWN: 
					colorText(COLOR_TILE_DOOR_DOWN); 
					printf("│ ↓ │ ");
					break;

				case TILE_DOOR_LEFT:
					colorText(COLOR_TILE_DOOR_LEFT); 
					printf("│ ← │ ");
					break;

				case TILE_DOOR_RIGHT:
					colorText(COLOR_TILE_DOOR_RIGHT); 
					printf("│ → │ ");
					break;

				case TILE_SPAWN: 
					colorText(COLOR_TILE_SPAWN); 
					printf("│ ? │ ");
					break;

				case TILE_BOSS: 
					colorText(COLOR_TILE_BOSS); 
					printf("│ ‼ │ ");
					break;

				case TILE_FAST_TRAVEL: 
					colorText(COLOR_TILE_FAST_TRAVEL); 
					printf("│ ♦ │ ");
					break;

				case TILE_CREDITS: 
					colorText(COLOR_TILE_CREDITS); 
					printf("│ C │ ");
					break;

				case TILE_INVALID: 
					colorText(COLOR_TILE_INVALID); 
					printf("│││││ ");
					break;
			}
			break;

		case BOTTOM: 	
			switch (nTileType) {
				case TILE_EMPTY: 
					colorText(COLOR_TILE_EMPTY); 
					printf("└───┘ ");
					break;

				case TILE_PLAYER: 
					colorText(COLOR_TILE_PLAYER); 
					printf("╚═══╝ ");
					break;

				case TILE_DOOR_UP: 
					colorText(COLOR_TILE_DOOR_UP); 
					printf("└───┘ ");
					break;

				case TILE_DOOR_DOWN: 
					colorText(COLOR_TILE_DOOR_DOWN); 
					printf("└───┘ ");
					break;

				case TILE_DOOR_LEFT: 
					colorText(COLOR_TILE_DOOR_LEFT); 
					printf("└───┘ ");
					break;

				case TILE_DOOR_RIGHT: 
					colorText(COLOR_TILE_DOOR_RIGHT); 
					printf("└───┘ ");
					break;

				case TILE_SPAWN: 
					colorText(COLOR_TILE_SPAWN); 
					printf("└───┘ ");
					break;

				case TILE_BOSS: 
					colorText(COLOR_TILE_BOSS); 
					printf("╚───╝ ");
					break;

				case TILE_FAST_TRAVEL: 
					colorText(COLOR_TILE_FAST_TRAVEL); 
					printf("└───┘ ");
					break;

				case TILE_CREDITS: 
					colorText(COLOR_TILE_CREDITS); 
					printf("└───┘ ");
					break;

				case TILE_INVALID: 
					colorText(COLOR_TILE_INVALID); 
					printf("└┴┴┴┘ ");
					break;
			}		

			resetColors();
	}
}

void printAreaName(int nAreaIndex) {
	switch (nAreaIndex) {
		case STORMVEIL_CASTLE:
			printStormveilCastleHeader();
			break;

		case RAYA_LUCARIA_ACADEMY:
			printRayaLucariaHeader();
			break;

		case REDMANE_CASTLE:
			printRedmaneCastleHeader();
			break;

		case VOLCANO_MANOR:
			printVolcanoManorHeader();
			break;

		case LEYNDELL_ROYAL_CAPITAL:
			printLeyndellRoyalCapitalHeader();
			break;

		case THE_ELDEN_THRONE:
			printTheEldenThrone();
			break;
	}
}

void openTreasureSpawn(int nAreaIndex, Player sPlayer, int nRunesGained) {
	system("cls");

	printAreaName(nAreaIndex);

	printRunesGained(sPlayer, nRunesGained);

	printFooter();
	printInputDivider();

	pressEnter();
}

void printRunesGained(Player sPlayer, int nRunesGained) {
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

	nOffset = (SCREEN_WIDTH - strlen("YOU HAVE GAINED ") - nValueDigits - strlen("RUNES!") - 4) / 2;
	printf("\n");
	printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT + nOffset);

	printf("║ YOU HAVE GAINED %d RUNES! ║\n\n", nRunesGained);
}

void openEnemySpawn(int nAreaIndex, Player* pPlayer, Enemy* pEnemy, int nBoss, int nEldenThroneBossNum) {
	system("cls");

	printBattleHeader();

	printBattlingAgainst(nAreaIndex, pEnemy, nBoss, nEldenThroneBossNum);

	printFooter();
	printInputDivider();

	pressEnter();
}

void printBattlingAgainst(int nAreaIndex, Enemy* pEnemy, int nBoss, int nEldenThroneBossNum) {
	int nLine; 
	int nOffset = (SCREEN_WIDTH - SPRITE_WIDTH) / 2;
	int nLength;

	printf("\n");

	for (nLine = 0; nLine < SPRITE_HEIGHT; nLine++) {
		printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT + nOffset);		
		printEnemySprite(nLine + 1);
		printf("\n");
	}

	if (nBoss == 0) {
		setEnemyStats(nAreaIndex, pEnemy);
	}
	else {
		setBossStats(nAreaIndex, pEnemy, nEldenThroneBossNum);
	}

	nLength = strlen(pEnemy->pEnemyName);

	nOffset = (SCREEN_WIDTH - strlen("BATTLING ") - nLength + 3) / 2;

	printf("\n");
	printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT + nOffset);
	printMultiple("─", strlen("BATTLING ") + nLength - 3);
	printf("\n");

	nOffset = (SCREEN_WIDTH -  strlen("BATTLING ") - nLength) / 2;
	printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT + nOffset);
	printf("BATTLING %s\n", pEnemy->pEnemyName);

	nOffset = (SCREEN_WIDTH - strlen("BATTLING ") - nLength + 3) / 2;

	printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT + nOffset);
	printMultiple("─", strlen("BATTLING ") + nLength - 3);	
	printf("\n\n");
}





