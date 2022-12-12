#include "area_screens.h"

#include "battle.h"

void openAreaScreen(int nAreaIndex, int nFloorNumber, Player* pPlayer) {
	char cInput = 'A'; // initialize to random char in valid commands 
	char aPlayerCommands[] = {'W', 'A', 'S', 'D', 'E',
						      'w', 'a', 's', 'd', 'e'};
	int nLeaveArea = 0;

	int nPrompt = NO_PROMPT;
	int nTileSpawnType = NO_SPAWN_YET;

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
	sAreaFloor.pFloorBoardArray = pAreaBoard;
	sAreaFloor.pAreaDoorArray = pAreaDoors;

	determineAreaRowsColumns(&sAreaFloor);
	sAreaFloor.pFloorBoardArray[sAreaFloor.nFloorNumber - 1] = generateArea(sAreaFloor);
	loadDoors(sAreaFloor.nAreaIndex, sAreaFloor.pAreaDoorArray);
	findPlayerSpawn(sAreaFloor, &pPlayer->sPlayerAreaDetails);

	do {
		system("cls");

		printAreaName(nAreaIndex);

		printAreaMap(sAreaFloor, &pPlayer->sPlayerAreaDetails);
		printf("\n");

		printAreaNav(*pPlayer, nPrompt);
		printFooter();

		if (nPrompt == NO_PROMPT || nPrompt == EMPTY_TILE_PROMPT || nPrompt == LOCKED_TILE_PROMPT) {
			printInputDivider();
			getCharAreaInput(&cInput, aPlayerCommands, 10);
		}
		processAreaScreenInput(cInput, &sAreaFloor, pPlayer, &nLeaveArea, &nPrompt, &nTileSpawnType);
	} while (!nLeaveArea);

	for (nArrayIndex = nNumberOfFloors - 1; nArrayIndex >= 0; nArrayIndex--) {
		if (sAreaFloor.pFloorBoardArray[nArrayIndex] != NULL) {
			free (sAreaFloor.pFloorBoardArray[nArrayIndex]);
		}
	}

	for (nArrayIndex = nNumberOfDoors / 2 - 1; nArrayIndex >= 0; nArrayIndex--) {
		if (sAreaFloor.pAreaDoorArray[nArrayIndex] != NULL) {
			free (sAreaFloor.pAreaDoorArray[nArrayIndex]->pNext);
			free (sAreaFloor.pAreaDoorArray[nArrayIndex]);
		}
	}
}

void processAreaScreenInput(char cInput, AreaFloor* pAreaFloor, Player* pPlayer, int* pLeaveArea, 
						    int* pPrompt, int* pTileSpawnType) {
	switch(cInput) {
		case 'W':
		case 'w':
			movePlayer(UP, *pAreaFloor, &pPlayer->sPlayerAreaDetails);
			*pPrompt = NO_PROMPT;
			break;

		case 'A':
		case 'a':
			movePlayer(LEFT, *pAreaFloor, &pPlayer->sPlayerAreaDetails);
			*pPrompt = NO_PROMPT;
			break;

		case 'S':
		case 's':
			movePlayer(DOWN, *pAreaFloor, &pPlayer->sPlayerAreaDetails);
			*pPrompt = NO_PROMPT;
			break;

		case 'D':
		case 'd':
			movePlayer(RIGHT, *pAreaFloor, &pPlayer->sPlayerAreaDetails);
			*pPrompt = NO_PROMPT;
			break;

		case 'E':
		case 'e':
			interactTile(pAreaFloor, pPlayer, pLeaveArea, pPrompt, pTileSpawnType);
			break;
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

void interactTile(AreaFloor* pAreaFloor, Player* pPlayer, int *pLeaveArea, int *pPrompt, int* pTileSpawnType) {
	int nTileType = *(pAreaFloor->pFloorBoardArray[pAreaFloor->nFloorNumber - 1] + (pPlayer->sPlayerAreaDetails.nRowLocation * pAreaFloor->nColumns) +
					pPlayer->sPlayerAreaDetails.nColumnLocation);
	int nResult;
	Enemy sEnemy;

	switch (nTileType) {
		case TILE_EMPTY:
			*pPrompt = 1;
			break;
			
		case TILE_DOOR_UP:
		case TILE_DOOR_DOWN:
		case TILE_DOOR_LEFT:
		case TILE_DOOR_RIGHT:
			interactTileDoor(pAreaFloor, &pPlayer->sPlayerAreaDetails);
			break;

		case TILE_SPAWN:
			interactTileSpawn(pAreaFloor, pPlayer, pLeaveArea, pPrompt, pTileSpawnType);
			break;

		case TILE_BOSS:
			switch (pAreaFloor->nAreaIndex) {
				case THE_ELDEN_THRONE:
					openEnemySpawn(pAreaFloor->nAreaIndex, pPlayer, &sEnemy, BOSS_BATTLE, 1);
					nResult = openBattleScreen(pAreaFloor->nAreaIndex, pPlayer, &sEnemy, BOSS_BATTLE);
					if (nResult == 1) {
					openEnemySpawn(pAreaFloor->nAreaIndex, pPlayer, &sEnemy, BOSS_BATTLE, 2);
					nResult = openBattleScreen(pAreaFloor->nAreaIndex, pPlayer, &sEnemy, BOSS_BATTLE);						
					}
					break;

				default: 
					openEnemySpawn(pAreaFloor->nAreaIndex, pPlayer, &sEnemy, BOSS_BATTLE, 0);
					nResult = openBattleScreen(pAreaFloor->nAreaIndex, pPlayer, &sEnemy, BOSS_BATTLE);
			}
			if (nResult == 0) {
				*pLeaveArea = 1;
			}
			else {
				openNewFastTravel(pAreaFloor->nAreaIndex, pPlayer);
			}

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

void interactTileSpawn(AreaFloor* pAreaFloor, Player* pPlayer, int* pLeaveArea, int* pPrompt, int* pTileSpawnType) {
	int nSpawnRate;
	int nRunesGained = 0;
	int nResult;
	Enemy sEnemy;

	if (*pTileSpawnType == NO_SPAWN_YET) {
		nSpawnRate = randomNumberBetween(100, 1);
		printf("%d\n", nSpawnRate);
		pressEnter();
	}

	if (*pTileSpawnType == ENEMY_SPAWN) {
		pressEnter();
		openEnemySpawn(pAreaFloor->nAreaIndex, pPlayer, &sEnemy, NORMAL_BATTLE, 0);
		nResult = openBattleScreen(pAreaFloor->nAreaIndex, pPlayer, &sEnemy, NORMAL_BATTLE);
		if (nResult == 0) {
			*pLeaveArea = 1;
		}

		*pPrompt = EMPTY_TILE_PROMPT;
		*(pAreaFloor->pFloorBoardArray[pAreaFloor->nFloorNumber - 1] + (pPlayer->sPlayerAreaDetails.nRowLocation * pAreaFloor->nColumns) +
		pPlayer->sPlayerAreaDetails.nColumnLocation) = TILE_EMPTY;
		*pTileSpawnType = NO_SPAWN_YET;
	}

	if (*pTileSpawnType == TREASURE_SPAWN) {
		pressEnter();
		nRunesGained = receiveRunes(pAreaFloor->nAreaIndex);
 		openTreasureSpawn(pAreaFloor->nAreaIndex, *pPlayer, nRunesGained);
 		pPlayer->nRunes += nRunesGained;

 		*pPrompt = EMPTY_TILE_PROMPT;
 		*(pAreaFloor->pFloorBoardArray[pAreaFloor->nFloorNumber - 1] + (pPlayer->sPlayerAreaDetails.nRowLocation * pAreaFloor->nColumns) +
		pPlayer->sPlayerAreaDetails.nColumnLocation) = TILE_EMPTY;
		*pTileSpawnType = NO_SPAWN_YET;	
	}
	
	// nSpawnRate <= 75; 1 - 75					
	if ((nSpawnRate <= ENEMY_YIELD) && (*pPrompt == NO_PROMPT)) {
		*pPrompt = ENEMY_TILE_PROMPT;
		*pTileSpawnType = ENEMY_SPAWN;
	}			
	
	// nSpawnRate <= 75; 76 - 100						 	
	else if ((nSpawnRate > 100 - TREASURE_YIELD) && (*pPrompt == NO_PROMPT)) {
		*pPrompt = TREASURE_TILE_PROMPT;
		*pTileSpawnType = TREASURE_SPAWN;
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

	if (pAreaFloor->pFloorBoardArray[pAreaFloor->nFloorNumber - 1] == NULL) {
		pAreaFloor->pFloorBoardArray[pAreaFloor->nFloorNumber - 1] = generateArea(*pAreaFloor);
	}
} 
