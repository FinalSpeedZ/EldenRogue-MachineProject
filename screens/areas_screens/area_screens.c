#include "area_screens.h"

void openAreaScreen(int nAreaIndex, Player* pPlayer) {
	char cInput = 'Q'; // initialize to random char in valid commands 
	char aPlayerCommands[] = {'W', 'A', 'S', 'D', 'E', 'Q',
						      'w', 'a', 's', 'd', 'e', 'q'};
	AreaFloor sAreaFloor;
	sAreaFloor.nFloorNumber = 1;
	sAreaFloor.nRows = 0;
	sAreaFloor.nColumns = 0;
	sAreaFloor.nAreaIndex = nAreaIndex;
	sAreaFloor.pFloorBoard = NULL; 

	determineAreaRowsColumns(&sAreaFloor);
	sAreaFloor.pFloorBoard = generateArea(sAreaFloor);
	findPlayerSpawn(sAreaFloor, &pPlayer->sPlayerAreaDetails);

	do {
		system("cls");

		// change to printHeader (ascii header)
		printMultiple("\n", SCREEN_PADDING_TOP);
		printAreaName(nAreaIndex);
		printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT);
		printMultiple("─", SCREEN_WIDTH);
		printf("\n\n");

		determineAreaRowsColumns(&sAreaFloor);
		printAreaMap(sAreaFloor, &pPlayer->sPlayerAreaDetails);
		printf("\n");

		printFooter();
		printInputDivider();

		getCharAreaInput(&cInput, aPlayerCommands, 12);
		processAreaScreenInput(cInput, &sAreaFloor, pPlayer);
	} while (cInput != 'Q' && cInput != 'q');

	free(sAreaFloor.pFloorBoard);
}

void determineAreaRowsColumns(AreaFloor* pAreaFloor) {
	switch(pAreaFloor->nAreaIndex){
		case STORMVEIL_CASTLE:
			switch (pAreaFloor->nFloorNumber){
				case 1:
					pAreaFloor->nRows = 7; 
					pAreaFloor->nColumns = 3;
					break;
				case 2:
					pAreaFloor->nRows = 7; 
					pAreaFloor->nColumns = 7;
					break;
				case 3:
					pAreaFloor->nRows = 7; 
					pAreaFloor->nColumns = 5;
					break;
			}
			break;

		case RAYA_LUCARIA_ACADEMY:
			switch (pAreaFloor->nFloorNumber){
				case 1:
					pAreaFloor->nRows = 5; 
					pAreaFloor->nColumns = 5;
					break;
				case 2:
					pAreaFloor->nRows = 7; 
					pAreaFloor->nColumns = 3;
					break;
				case 3:
					pAreaFloor->nRows = 7; 
					pAreaFloor->nColumns = 5;
					break;
				case 4:
					pAreaFloor->nRows = 5; 
					pAreaFloor->nColumns = 6;
					break;
				case 5:
					pAreaFloor->nRows = 8; 
					pAreaFloor->nColumns = 7;
					break;
			}
			break;

		case REDMANE_CASTLE:
			switch (pAreaFloor->nFloorNumber){
				case 1:
					pAreaFloor->nRows = 3; 
					pAreaFloor->nColumns = 5;
					break;
				case 2:
					pAreaFloor->nRows = 3; 
					pAreaFloor->nColumns = 7;
					break;
				case 3:
					pAreaFloor->nRows = 5; 
					pAreaFloor->nColumns = 5;
					break;
				case 4:
					pAreaFloor->nRows = 5; 
					pAreaFloor->nColumns = 7;
					break;
				case 5:
					pAreaFloor->nRows = 3; 
					pAreaFloor->nColumns = 5;
					break;
				case 6:
					pAreaFloor->nRows = 9; 
					pAreaFloor->nColumns = 4;
					break;
				case 7:
					pAreaFloor->nRows = 5; 
					pAreaFloor->nColumns = 7;
					break;
			}
			break;

		case VOLCANO_MANOR:
			switch (pAreaFloor->nFloorNumber){
				case 1:
					pAreaFloor->nRows = 5; 
					pAreaFloor->nColumns = 5;
					break;
				case 2:
					pAreaFloor->nRows = 7; 
					pAreaFloor->nColumns = 7;
					break;
				case 3:
					pAreaFloor->nRows = 5; 
					pAreaFloor->nColumns = 5;
					break;
				case 4:
					pAreaFloor->nRows = 5; 
					pAreaFloor->nColumns = 7;
					break;
				case 5:
					pAreaFloor->nRows = 4; 
					pAreaFloor->nColumns = 3;
					break;
				case 6:
					pAreaFloor->nRows = 8; 
					pAreaFloor->nColumns = 3;
					break;
				case 7:
					pAreaFloor->nRows = 7; 
					pAreaFloor->nColumns = 5;
					break;
			}
			break;

		case LEYNDELL_ROYAL_CAPITAL:
			switch (pAreaFloor->nFloorNumber){
				case 1:
					pAreaFloor->nRows = 4; 
					pAreaFloor->nColumns = 3;
					break;
				case 2:
					pAreaFloor->nRows = 7; 
					pAreaFloor->nColumns = 3;
					break;
				case 3:
					pAreaFloor->nRows = 5; 
					pAreaFloor->nColumns = 5;
					break;
				case 4:
					pAreaFloor->nRows = 3; 
					pAreaFloor->nColumns = 5;
					break;
				case 5:
					pAreaFloor->nRows = 4; 
					pAreaFloor->nColumns = 15;
					break;
				case 6:
					pAreaFloor->nRows = 3; 
					pAreaFloor->nColumns = 3;
					break;
				case 7:
					pAreaFloor->nRows = 7; 
					pAreaFloor->nColumns = 3;
					break;
				case 8:
					pAreaFloor->nRows = 7; 
					pAreaFloor->nColumns = 3;
					break;
				case 9:
					pAreaFloor->nRows = 7; 
					pAreaFloor->nColumns = 3;
					break;
				case 10:
					pAreaFloor->nRows = 4; 
					pAreaFloor->nColumns = 15;
					break;
				case 11:
					pAreaFloor->nRows = 13; 
					pAreaFloor->nColumns = 13;
					break;
				case 12:
					pAreaFloor->nRows = 3; 
					pAreaFloor->nColumns = 3;
					break;
				case 13:
					pAreaFloor->nRows = 3; 
					pAreaFloor->nColumns = 3;
					break;
				case 14:
					pAreaFloor->nRows = 7; 
					pAreaFloor->nColumns = 5;
					break;
			}
			break;

		case THE_ELDEN_THRONE:
			switch (pAreaFloor->nFloorNumber){
				case 1:
					pAreaFloor->nRows = 9; 
					pAreaFloor->nColumns = 3;
					break;
				case 2:
					pAreaFloor->nRows = 7; 
					pAreaFloor->nColumns = 7;
					break;
				case 3:
					pAreaFloor->nRows = 9; 
					pAreaFloor->nColumns = 3;
					break;
			}
			break;
	}
}

void findPlayerSpawn(AreaFloor sAreaFloor, AreaDetails* pPlayerAreaDetails) {
	int nRowCounter;
	int nColumnCounter;

	int* pFloor = generateArea(sAreaFloor);
	int nTileType;

	for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
		for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
			nTileType = *(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter);
			if (nTileType == TILE_FAST_TRAVEL) {
				pPlayerAreaDetails->nRowLocation = nRowCounter;
				pPlayerAreaDetails->nColumnLocation = nColumnCounter;
			}
		}
	}

	free(pFloor);
}

void processAreaScreenInput(char cInput, AreaFloor* pAreaFloor, Player* pPlayer) {
	switch(cInput) {
		case 'W':
		case 'w':
			movePlayer(UP, *pAreaFloor, &pPlayer->sPlayerAreaDetails);
			break;

		case 'A':
		case 'a':
			movePlayer(LEFT, *pAreaFloor, &pPlayer->sPlayerAreaDetails);
			break;

		case 'S':
		case 's':
			movePlayer(DOWN, *pAreaFloor, &pPlayer->sPlayerAreaDetails);
			break;

		case 'D':
		case 'd':
			movePlayer(RIGHT, *pAreaFloor, &pPlayer->sPlayerAreaDetails);
			break;

		case 'E':
		case 'e':
			interactTile(pAreaFloor, pPlayer);
	}
}

void movePlayer(int nDirection, AreaFloor sAreaFloor, AreaDetails* pPlayerAreaDetails) {
	int *pFloor = generateArea(sAreaFloor);

	switch(nDirection) {
		case UP:
			if (pPlayerAreaDetails->nRowLocation > 0 && 
				*(pFloor + ((pPlayerAreaDetails->nRowLocation - 1) * sAreaFloor.nColumns) + pPlayerAreaDetails->nColumnLocation) != TILE_INVALID) {
				pPlayerAreaDetails->nRowLocation--;
			}
			break;

		case DOWN:
			if (pPlayerAreaDetails->nRowLocation < sAreaFloor.nRows - 1 && 
				*(pFloor + ((pPlayerAreaDetails->nRowLocation + 1) * sAreaFloor.nColumns) + pPlayerAreaDetails->nColumnLocation) != TILE_INVALID) {
				pPlayerAreaDetails->nRowLocation++;
			}
			break;

		case LEFT:
			if (pPlayerAreaDetails->nColumnLocation > 0 && 
				*(pFloor + (pPlayerAreaDetails->nRowLocation * sAreaFloor.nColumns) + (pPlayerAreaDetails->nColumnLocation - 1)) != TILE_INVALID) {
				pPlayerAreaDetails->nColumnLocation--;
			}
			break;

		case RIGHT:
			if (pPlayerAreaDetails->nColumnLocation < sAreaFloor.nColumns - 1 && 
				*(pFloor + (pPlayerAreaDetails->nRowLocation * sAreaFloor.nColumns) + (pPlayerAreaDetails->nColumnLocation + 1)) != TILE_INVALID) {
				pPlayerAreaDetails->nColumnLocation++;
			}
	}

	free(pFloor);
}

void interactTile(AreaFloor* pAreaFloor, Player* pPlayer) {
	int nTileType = *(pAreaFloor->pFloorBoard + (pPlayer->sPlayerAreaDetails.nRowLocation * pAreaFloor->nColumns) +
					pPlayer->sPlayerAreaDetails.nColumnLocation);

	switch (nTileType) {
		case TILE_EMPTY:
			pressEnter();
			break;

		case TILE_PLAYER:
			break;
			
		case TILE_DOOR_UP:
		case TILE_DOOR_DOWN:
			// interactTileDoor(nAreaIndex, pFloorNumber, &pPlayer->sPlayerAreaDetails);
			break;

		case TILE_SPAWN:
			interactTileSpawn(pAreaFloor->nAreaIndex, pPlayer);
			*(pAreaFloor->pFloorBoard + (pPlayer->sPlayerAreaDetails.nRowLocation * pAreaFloor->nColumns) +
			pPlayer->sPlayerAreaDetails.nColumnLocation) = TILE_EMPTY;
			break;

		case TILE_BOSS:
		case TILE_FAST_TRAVEL:
		case TILE_CREDITS:
			break;
	}
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

// void interactTileDoor(int nAreaIndex, int *pFloorNumber, AreaDetails* pPlayerAreaDetails) {
// 	int nNumberOfDoors = determineNumberOfDoors(nAreaIndex);

// 	Door* pAreaDoors[nNumberOfDoors / 2]; 
// 	Door* pInteractedDoor;

// 	int nArrayIndex;

// 	for (nArrayIndex = 0; nArrayIndex < nNumberOfDoors / 2; nArrayIndex++) {
// 		pAreaDoors[nArrayIndex] = NULL;
// 	} 

// 	loadDoors(nAreaIndex, pAreaDoors);

// 	pInteractedDoor = findDoor(pAreaDoors, nNumberOfDoors, pPlayerAreaDetails, pFloorNumber);

// 	if (pInteractedDoor->pPrev == NULL) {
// 		pPlayerAreaDetails->nRowLocation = pInteractedDoor->pNext->nRowLocation;
// 		pPlayerAreaDetails->nColumnLocation = pInteractedDoor->pNext->nColumnLocation;
// 		*pFloorNumber = pInteractedDoor->pNext->nFloorNumber;
// 	}
// 	else {
// 		pPlayerAreaDetails->nRowLocation = pInteractedDoor->pPrev->nRowLocation;
// 		pPlayerAreaDetails->nColumnLocation = pInteractedDoor->pPrev->nColumnLocation;
// 		*pFloorNumber = pInteractedDoor->pPrev->nFloorNumber;
// 	}
// } 


