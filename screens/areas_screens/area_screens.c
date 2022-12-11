#include "area_screens.h"

#include "battle.h"

void openAreaScreen(int nAreaIndex, int nFloorNumber, Player* pPlayer) {
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
	sAreaFloor.nFloorNumber = nFloorNumber;
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

		printAreaNav(*pPlayer);
		printFooter();
		printInputDivider();

		getCharAreaInput(&cInput, aPlayerCommands, 10);
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
			break;
			
		case TILE_DOOR_UP:
		case TILE_DOOR_DOWN:
		case TILE_DOOR_LEFT:
		case TILE_DOOR_RIGHT:
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
	int nRunesGained = 0;

	if (nSpawnRate > 100 - ENEMY_YIELD) {
		openBattleScreen(nAreaIndex, pPlayer);
	}

	else {
		nRunesGained = receiveRunes(nAreaIndex);
		printf("YOU FOUND %d RUNES\n", nRunesGained);
		pPlayer->nRunes = pPlayer->nRunes + nRunesGained;
		pressEnter();
	}
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
