#include "area_screens.h"

void openAreaScreen(int nAreaIndex, Player* pPlayer) {
	char cInput = 'Q'; // initialize to random char in valid commands 
	char aPlayerCommands[] = {'W', 'A', 'S', 'D', 'E', 'Q',
						      'w', 'a', 's', 'd', 'e', 'q'};
	int nFloorNumber = 1;
	int nRows;
	int nColumns;
	determineAreaRowsColumns(nAreaIndex, nFloorNumber, &nRows, &nColumns);
	findPlayerSpawn(nAreaIndex, nFloorNumber, nRows, nColumns, &pPlayer->sPlayerAreaDetails);

	do {
		system("cls");

		// change to printHeader (ascii header)
		printMultiple("\n", SCREEN_PADDING_TOP);
		printAreaName(nAreaIndex);
		printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT);
		printMultiple("─", SCREEN_WIDTH);
		printf("\n\n");

		determineAreaRowsColumns(nAreaIndex, nFloorNumber, &nRows, &nColumns);
		printAreaMap(nAreaIndex, nFloorNumber, nRows, nColumns, &pPlayer->sPlayerAreaDetails);
		printf("\n");

		printFooter();
		printInputDivider();

		getCharAreaInput(&cInput, aPlayerCommands, 12);
		processAreaScreenInput(cInput, nAreaIndex, &nFloorNumber, nRows, nColumns, pPlayer);
	} while (cInput != 'Q' && cInput != 'q');
}

void determineAreaRowsColumns(int nAreaIndex, int nFloorNumber, int* pRows, int* pColumns) {
	switch(nAreaIndex){
		case STORMVEIL_CASTLE:
			switch (nFloorNumber){
				case 1:
					*pRows = 7; 
					*pColumns = 3;
					break;
				case 2:
					*pRows = 7; 
					*pColumns = 7;
					break;
				case 3:
					*pRows = 7; 
					*pColumns = 5;
					break;
			}
			break;

		case RAYA_LUCARIA_ACADEMY:
			switch (nFloorNumber){
				case 1:
					*pRows = 5; 
					*pColumns = 5;
					break;
				case 2:
					*pRows = 7; 
					*pColumns = 3;
					break;
				case 3:
					*pRows = 7; 
					*pColumns = 5;
					break;
				case 4:
					*pRows = 5; 
					*pColumns = 6;
					break;
				case 5:
					*pRows = 8; 
					*pColumns = 7;
					break;
			}
			break;

		case REDMANE_CASTLE:
			switch (nFloorNumber){
				case 1:
					*pRows = 3; 
					*pColumns = 5;
					break;
				case 2:
					*pRows = 3; 
					*pColumns = 7;
					break;
				case 3:
					*pRows = 5; 
					*pColumns = 5;
					break;
				case 4:
					*pRows = 5; 
					*pColumns = 7;
					break;
				case 5:
					*pRows = 3; 
					*pColumns = 5;
					break;
				case 6:
					*pRows = 9; 
					*pColumns = 4;
					break;
				case 7:
					*pRows = 5; 
					*pColumns = 7;
					break;
			}
			break;

		case VOLCANO_MANOR:
			switch (nFloorNumber){
				case 1:
					*pRows = 5; 
					*pColumns = 5;
					break;
				case 2:
					*pRows = 7; 
					*pColumns = 7;
					break;
				case 3:
					*pRows = 5; 
					*pColumns = 5;
					break;
				case 4:
					*pRows = 5; 
					*pColumns = 7;
					break;
				case 5:
					*pRows = 4; 
					*pColumns = 3;
					break;
				case 6:
					*pRows = 8; 
					*pColumns = 3;
					break;
				case 7:
					*pRows = 7; 
					*pColumns = 5;
					break;
			}
			break;

		case LEYNDELL_ROYAL_CAPITAL:
			switch (nFloorNumber){
				case 1:
					*pRows = 4; 
					*pColumns = 3;
					break;
				case 2:
					*pRows = 7; 
					*pColumns = 3;
					break;
				case 3:
					*pRows = 5; 
					*pColumns = 5;
					break;
				case 4:
					*pRows = 3; 
					*pColumns = 5;
					break;
				case 5:
					*pRows = 4; 
					*pColumns = 15;
					break;
				case 6:
					*pRows = 3; 
					*pColumns = 3;
					break;
				case 7:
					*pRows = 7; 
					*pColumns = 3;
					break;
				case 8:
					*pRows = 7; 
					*pColumns = 3;
					break;
				case 9:
					*pRows = 7; 
					*pColumns = 3;
					break;
				case 10:
					*pRows = 4; 
					*pColumns = 15;
					break;
				case 11:
					*pRows = 13; 
					*pColumns = 13;
					break;
				case 12:
					*pRows = 3; 
					*pColumns = 3;
					break;
				case 13:
					*pRows = 3; 
					*pColumns = 3;
					break;
				case 14:
					*pRows = 7; 
					*pColumns = 5;
					break;
			}
			break;

		case THE_ELDEN_THRONE:
			switch (nFloorNumber){
				case 1:
					*pRows = 9; 
					*pColumns = 3;
					break;
				case 2:
					*pRows = 7; 
					*pColumns = 7;
					break;
				case 3:
					*pRows = 9; 
					*pColumns = 3;
					break;
			}
			break;
	}
}

void findPlayerSpawn(int nAreaIndex, int nFloorNumber, int nRows, int nColumns, 
					 AreaDetails* pPlayerAreaDetails) {
	int nRowCounter;
	int nColumnCounter;

	int* pFloor = generateArea(nAreaIndex, nFloorNumber, nRows, nColumns);
	int nTileType;

	for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
		for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
			nTileType = *(pFloor + (nRowCounter * nColumns) + nColumnCounter);
			if (nTileType == TILE_FAST_TRAVEL) {
				pPlayerAreaDetails->nRowLocation = nRowCounter;
				pPlayerAreaDetails->nColumnLocation = nColumnCounter;
			}
		}
	}

	free(pFloor);
}

void processAreaScreenInput(char cInput, int nAreaIndex, int* pFloorNumber, 
							int nRows, int nColumns, Player* pPlayer) {
	switch(cInput) {
		case 'W':
		case 'w':
			movePlayer(UP, nAreaIndex, *pFloorNumber, nRows, nColumns, &pPlayer->sPlayerAreaDetails);
			break;

		case 'A':
		case 'a':
			movePlayer(LEFT, nAreaIndex, *pFloorNumber, nRows, nColumns, &pPlayer->sPlayerAreaDetails);
			break;

		case 'S':
		case 's':
			movePlayer(DOWN, nAreaIndex, *pFloorNumber, nRows, nColumns, &pPlayer->sPlayerAreaDetails);
			break;

		case 'D':
		case 'd':
			movePlayer(RIGHT, nAreaIndex, *pFloorNumber, nRows, nColumns, &pPlayer->sPlayerAreaDetails);
			break;

		case 'E':
		case 'e':
			interactTile(nAreaIndex, pFloorNumber, nRows, nColumns, pPlayer);
	}
}

void movePlayer(int nDirection, int nAreaIndex, int nFloorNumber, 
				int nRows, int nColumns, AreaDetails* pPlayerAreaDetails) {
	int *pFloor = generateArea(nAreaIndex, nFloorNumber, nRows, nColumns);

	switch(nDirection) {
		case UP:
			if (pPlayerAreaDetails->nRowLocation > 0 && 
				*(pFloor + ((pPlayerAreaDetails->nRowLocation - 1) * nColumns) + pPlayerAreaDetails->nColumnLocation) != TILE_INVALID) {
				pPlayerAreaDetails->nRowLocation--;
			}
			break;

		case DOWN:
			if (pPlayerAreaDetails->nRowLocation < nRows - 1 && 
				*(pFloor + ((pPlayerAreaDetails->nRowLocation + 1) * nColumns) + pPlayerAreaDetails->nColumnLocation) != TILE_INVALID) {
				pPlayerAreaDetails->nRowLocation++;
			}
			break;

		case LEFT:
			if (pPlayerAreaDetails->nColumnLocation > 0 && 
				*(pFloor + (pPlayerAreaDetails->nRowLocation * nColumns) + (pPlayerAreaDetails->nColumnLocation - 1)) != TILE_INVALID) {
				pPlayerAreaDetails->nColumnLocation--;
			}
			break;

		case RIGHT:
			if (pPlayerAreaDetails->nColumnLocation < nColumns - 1 && 
				*(pFloor + (pPlayerAreaDetails->nRowLocation * nColumns) + (pPlayerAreaDetails->nColumnLocation + 1)) != TILE_INVALID) {
				pPlayerAreaDetails->nColumnLocation++;
			}
	}

	free(pFloor);
}

void interactTile(int nAreaIndex, int* pFloorNumber, int nRows, int nColumns,
				  Player* pPlayer) {
	int *pFloor = generateArea(nAreaIndex, *pFloorNumber, nRows, nColumns);

	int nTileType = *(pFloor + (pPlayer->sPlayerAreaDetails.nRowLocation * nColumns) +
					pPlayer->sPlayerAreaDetails.nColumnLocation);

	switch (nTileType) {
		case TILE_EMPTY:
		case TILE_PLAYER:
			break;
			
		case TILE_DOOR_UP:
		case TILE_DOOR_DOWN:
			interactTileDoor(nAreaIndex, pFloorNumber, &pPlayer->sPlayerAreaDetails);
			break;

		case TILE_SPAWN:
			interactTileSpawn(nAreaIndex, pPlayer);
			break;

		case TILE_BOSS:
		case TILE_FAST_TRAVEL:
		case TILE_CREDITS:
			break;
	}

	free(pFloor);
}

void interactTileSpawn(int nAreaIndex, Player* pPlayer) {
	int nSpawnRate = randomNumberBetween(100, 1);

	if (nSpawnRate > 100 - ENEMY_YIELD) {
		printf("BATTLE ENEMY\n");
	}

	else {
		printf("YOU RECEIVE RUNES\n");
	}
	pressEnter();
}

void interactTileDoor(int nAreaIndex, int *pFloorNumber, AreaDetails* pPlayerAreaDetails) {
	int nNumberOfDoors = determineNumberOfDoors(nAreaIndex);

	Door* pAreaDoors[nNumberOfDoors / 2]; 
	Door* pInteractedDoor;

	int nArrayIndex;

	for (nArrayIndex = 0; nArrayIndex < nNumberOfDoors / 2; nArrayIndex++) {
		pAreaDoors[nArrayIndex] = NULL;
	} 

	loadDoors(nAreaIndex, pAreaDoors);

	pInteractedDoor = findDoor(pAreaDoors, nNumberOfDoors, pPlayerAreaDetails, pFloorNumber);

	if (pInteractedDoor->pPrev == NULL) {
		pPlayerAreaDetails->nRowLocation = pInteractedDoor->pNext->nRowLocation;
		pPlayerAreaDetails->nColumnLocation = pInteractedDoor->pNext->nColumnLocation;
		*pFloorNumber = pInteractedDoor->pNext->nFloorNumber;
	}
	else {
		pPlayerAreaDetails->nRowLocation = pInteractedDoor->pPrev->nRowLocation;
		pPlayerAreaDetails->nColumnLocation = pInteractedDoor->pPrev->nColumnLocation;
		*pFloorNumber = pInteractedDoor->pPrev->nFloorNumber;
	}
} 


