#include "area_printer.h"


void printAreaMap(int nAreaIndex, int* pRows, int* pColumns, Player* pPlayer) {
	int nRowCounter;
	int nColumnCounter;

	int nFloor = 1;

	int nPadding = SCREEN_PADDING_LEFT + ((SCREEN_WIDTH	- 7 * *pColumns) / 2);

	int* pFloor = generateArea(nAreaIndex, nFloor, *pRows, *pColumns);

	*(pFloor + (pPlayer->sPlayerAreaDetails.nRowLocation * *pColumns) + 
		pPlayer->sPlayerAreaDetails.nColumnLocation) = TILE_PLAYER;

	for (nRowCounter = 0; nRowCounter < *pRows; nRowCounter++) {

		printMultiple(" ", nPadding);
		for(nColumnCounter = 0; nColumnCounter< *pColumns; nColumnCounter++) {
			printTileParts(*(pFloor + (nRowCounter * *pColumns) + nColumnCounter), TOP);
		}
		printf("\n");

		printMultiple(" ", nPadding);
		for(nColumnCounter = 0; nColumnCounter< *pColumns; nColumnCounter++) {
			printTileParts(*(pFloor + (nRowCounter * *pColumns) + nColumnCounter), MIDDLE);
		}
		printf("\n");

		printMultiple(" ", nPadding);
		for(nColumnCounter = 0; nColumnCounter< *pColumns; nColumnCounter++) {
			printTileParts(*(pFloor + (nRowCounter * *pColumns) + nColumnCounter), BOTTOM);
		}
		printf("\n");
	}

	free(pFloor);
}

void printTileParts(int nTileType, int nTilePosition) {
	switch (nTilePosition) {
		case TOP:
			switch (nTileType) {
				case TILE_EMPTY: 
					printf("┌───┐ ");
					break;

				case TILE_PLAYER: 
					printf("╔═══╗ ");
					break;

				case TILE_DOOR_UP: 
					printf("┌───┐ ");
					break;

				case TILE_DOOR_DOWN: 
					printf("┌───┐ ");
					break;

				case TILE_SPAWN: 
					printf("┌───┐ ");
					break;

				case TILE_BOSS: 
					printf("┌───┐ ");
					break;

				case TILE_FAST_TRAVEL: 
					printf("┌───┐ ");
					break;

				case TILE_CREDITS: 
					printf("┌───┐ ");
					break;

				case TILE_INVALID: 
					printf("┌┬┬┬┐ ");
					break;
			}
			break;

		case MIDDLE: 
			switch (nTileType) {
				case TILE_EMPTY: 
					printf("│   │ ");
					break;

				case TILE_PLAYER: 
					printf("║ ■ ║ ");
					break;

				case TILE_DOOR_UP: 
					printf("│   │ ");
					break;

				case TILE_DOOR_DOWN: 
					printf("│   │ ");
					break;

				case TILE_SPAWN: 
					printf("│ ? │ ");
					break;

				case TILE_BOSS: 
					printf("│ B │ ");
					break;

				case TILE_FAST_TRAVEL: 
					printf("│   │ ");
					break;

				case TILE_CREDITS: 
					printf("│   │ ");
					break;

				case TILE_INVALID: 
					printf("│││││ ");
					break;
			}
			break;

		case BOTTOM: 	
			switch (nTileType) {
				case TILE_EMPTY: 
					printf("└───┘ ");
					break;

				case TILE_PLAYER: 
					printf("╚═══╝ ");
					break;

				case TILE_DOOR_UP: 
					printf("└───┘ ");
					break;

				case TILE_DOOR_DOWN: 
					printf("└───┘ ");
					break;

				case TILE_SPAWN: 
					printf("└───┘ ");
					break;

				case TILE_BOSS: 
					printf("└───┘ ");
					break;

				case TILE_FAST_TRAVEL: 
					printf("└───┘ ");
					break;

				case TILE_CREDITS: 
					printf("└───┘ ");
					break;

				case TILE_INVALID: 
					printf("└┴┴┴┘ ");
					break;
			}		
	}
}