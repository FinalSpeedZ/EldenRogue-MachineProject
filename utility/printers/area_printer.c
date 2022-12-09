#include "area_printer.h"

#include "../area_utility/area_boards.h"
#include "../../screens/roundtable_hold_screens/fast_travel.h"

int* makeMapCopy(AreaFloor sAreaFloor) {
	int* pFloorBoardCopy = malloc(sizeof(int) * sAreaFloor.nRows * sAreaFloor.nColumns);
	int nRowCounter;
	int nColumnCounter;

	for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
		for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
			*(pFloorBoardCopy + nRowCounter * sAreaFloor.nColumns + nColumnCounter) = 
			*(sAreaFloor.pFloorBoard[sAreaFloor.nFloorNumber -  1] + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter);
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





