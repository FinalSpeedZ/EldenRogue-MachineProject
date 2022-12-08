#include "area_screens.h"

void openAreaScreen(int nAreaIndex, Player* pPlayer) {
	char cInput = 'A'; // initialize to random char in valid commands 
	char aPlayerCommands[] = {'W', 'A', 'S', 'D', 'E',
						      'w', 'a', 's', 'd', 'e'};

	int nLeaveArea = 0;

	int nNumberOfFloors = determineNumberOfFloors(nAreaIndex);
	int nNumberOfDoors = determineNumberOfDoors(nAreaIndex);
	int* pAreaBoard[nNumberOfFloors];
	Door* pAreaDoors[nNumberOfDoors / 2];
	int nArrayIndex;

	for (nArrayIndex = 0; nArrayIndex < nNumberOfFloors; nArrayIndex++) {
		pAreaBoard[nArrayIndex] = NULL;
	}

	for (nArrayIndex = 0; nArrayIndex < nNumberOfDoors / 2; nArrayIndex++) {
		pAreaDoors[nArrayIndex] = NULL;
	} 

	AreaFloor sAreaFloor;
	sAreaFloor.nFloorNumber = 1;
	sAreaFloor.nAreaIndex = nAreaIndex;
	sAreaFloor.pFloorBoard = pAreaBoard;
	sAreaFloor.pAreaDoorArray = pAreaDoors;

	determineAreaRowsColumns(&sAreaFloor);
	sAreaFloor.pFloorBoard[sAreaFloor.nFloorNumber - 1] = generateArea(sAreaFloor);
	loadDoors(sAreaFloor.nAreaIndex, sAreaFloor.pAreaDoorArray);
	findPlayerSpawn(sAreaFloor, &pPlayer->sPlayerAreaDetails);

	do {
		system("cls");

		printAreaName(nAreaIndex);

		printAreaMap(sAreaFloor, &pPlayer->sPlayerAreaDetails);
		printf("\n");

		printFooter();
		printInputDivider();

		getCharAreaInput(&cInput, aPlayerCommands, 12);
		processAreaScreenInput(cInput, &sAreaFloor, pPlayer, &nLeaveArea);
	} while (!nLeaveArea);

	for (nArrayIndex = nNumberOfFloors - 1; nArrayIndex >= 0; nArrayIndex--) {
		if (sAreaFloor.pFloorBoard[nArrayIndex] != NULL) {
			free (sAreaFloor.pFloorBoard[nArrayIndex]);
		}
	}

	for (nArrayIndex = nNumberOfDoors / 2 - 1; nArrayIndex >= 0; nArrayIndex--) {
		if (sAreaFloor.pAreaDoorArray[nArrayIndex] != NULL) {
			free (sAreaFloor.pAreaDoorArray[nArrayIndex]->pNext);
			free (sAreaFloor.pAreaDoorArray[nArrayIndex]);
		}
	}
}

void processAreaScreenInput(char cInput, AreaFloor* pAreaFloor, Player* pPlayer, int* pLeaveArea) {
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
			interactTile(pAreaFloor, pPlayer, pLeaveArea);
	}
}

int determineNumberOfFloors(int nAreaIndex) {
	int nNumberOfFloors = 0;

	switch(nAreaIndex) {
		case STORMVEIL_CASTLE:
			nNumberOfFloors = 3;
			break;

		case RAYA_LUCARIA_ACADEMY:
			nNumberOfFloors = 5;
			break;

		case REDMANE_CASTLE:
			nNumberOfFloors = 7;
			break;

		case VOLCANO_MANOR:
			nNumberOfFloors = 7;
			break;

		case LEYNDELL_ROYAL_CAPITAL:
			nNumberOfFloors = 14;
			break;

		case THE_ELDEN_THRONE:
			nNumberOfFloors = 3;
	}

	return nNumberOfFloors;
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

void interactTile(AreaFloor* pAreaFloor, Player* pPlayer, int *pLeaveArea) {
	int nTileType = *(pAreaFloor->pFloorBoard[pAreaFloor->nFloorNumber - 1] + (pPlayer->sPlayerAreaDetails.nRowLocation * pAreaFloor->nColumns) +
					pPlayer->sPlayerAreaDetails.nColumnLocation);

	switch (nTileType) {
		case TILE_EMPTY:
		case TILE_PLAYER:
			break;
			
		case TILE_DOOR_UP:
		case TILE_DOOR_DOWN:
			interactTileDoor(pAreaFloor, &pPlayer->sPlayerAreaDetails);
			break;

		case TILE_SPAWN:
			interactTileSpawn(pAreaFloor->nAreaIndex, pPlayer);
			*(pAreaFloor->pFloorBoard[pAreaFloor->nFloorNumber - 1] + (pPlayer->sPlayerAreaDetails.nRowLocation * pAreaFloor->nColumns) +
			pPlayer->sPlayerAreaDetails.nColumnLocation) = TILE_EMPTY;
			break;

		case TILE_BOSS:
			break;

		case TILE_FAST_TRAVEL:
		case TILE_CREDITS:
			if (pAreaFloor->nFloorNumber != 1 && checkFastTravelStatus(pAreaFloor->nAreaIndex, &pPlayer->sPlayerUnlockedAreas)) {
				*pLeaveArea = 1;
				openFastTravel(pPlayer);
			}
			else if (pAreaFloor->nFloorNumber == 1) {
				*pLeaveArea = 1;	
				openFastTravel(pPlayer);
			}
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

void interactTileDoor(AreaFloor* pAreaFloor, AreaDetails* pPlayerAreaDetails) {
	Door* pInteractedDoor;

	int nNumberOfDoors = determineNumberOfDoors(pAreaFloor->nAreaIndex);

	pInteractedDoor = findDoor(pAreaFloor->pAreaDoorArray, nNumberOfDoors, pPlayerAreaDetails, &pAreaFloor->nFloorNumber);

	if (pInteractedDoor->pPrev == NULL) {
		pPlayerAreaDetails->nRowLocation = pInteractedDoor->pNext->nRowLocation;
		pPlayerAreaDetails->nColumnLocation = pInteractedDoor->pNext->nColumnLocation;
		pAreaFloor->nFloorNumber = pInteractedDoor->pNext->nFloorNumber;
		determineAreaRowsColumns(pAreaFloor);
	}
	else {
		pPlayerAreaDetails->nRowLocation = pInteractedDoor->pPrev->nRowLocation;
		pPlayerAreaDetails->nColumnLocation = pInteractedDoor->pPrev->nColumnLocation;
		pAreaFloor->nFloorNumber = pInteractedDoor->pPrev->nFloorNumber;
		determineAreaRowsColumns(pAreaFloor);
	}

	if (pAreaFloor->pFloorBoard[pAreaFloor->nFloorNumber - 1] == NULL) {
		pAreaFloor->pFloorBoard[pAreaFloor->nFloorNumber - 1] = generateArea(*pAreaFloor);
	}
} 

int checkFastTravelStatus(int nAreaIndex, UnlockedAreas* pPlayerUnlockedAreas) {
	int nUnlocked = 0;

	switch (nAreaIndex) {
		case STORMVEIL_CASTLE:
			nUnlocked = pPlayerUnlockedAreas->nStormveilFastTravel;
			break;

		case RAYA_LUCARIA_ACADEMY:
			nUnlocked = pPlayerUnlockedAreas->nRayaLucariaFastTravel;
			break;

		case REDMANE_CASTLE:
			nUnlocked = pPlayerUnlockedAreas->nRedmaneFastTravel;
			break;

		case VOLCANO_MANOR:
			nUnlocked = pPlayerUnlockedAreas->nVolcanoFastTravel;
			break;

		case LEYNDELL_ROYAL_CAPITAL:
			nUnlocked = pPlayerUnlockedAreas->nLeyndellFastTravel;
			break;

		case THE_ELDEN_THRONE:
			nUnlocked = pPlayerUnlockedAreas->nEldenThroneCredits;
	}

	return nUnlocked;
}
