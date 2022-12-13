/****************************************
File Name: area_screens.c

Opens the specific area screen (i.e Stormveil) 
based on player input
****************************************/

#include "area_screens.h"

#include "battle.h"
#include "credits.h"

/*
	openAreaScreen      Opens a specific area screen as well as the 
					    area board, floor number, and player position

	@param nAreaIndex   Contains the specific area that will be opened
	@param nFloorNumber Contains the specific floor number of the certain 
					    area
	@pPlayer            A pointer to the Player structure
*/
void openAreaScreen(int nAreaIndex, int nFloorNumber, Player* pPlayer) {
	
	// VARIABLE DECLARATIONS
	char cInput = 'A'; // initialize to random char in valid commands 
	char aPlayerCommands[] = {'W', 'A', 'S', 'D', 'E',
						      'w', 'a', 's', 'd', 'e'};
	int nLeaveArea = FALSE;

	int nPrompt = NO_PROMPT;
	int nTileSpawnType = NO_SPAWN_YET;
	int nBBattleFinished = FALSE;

	int nNumberOfFloors = determineNumberOfFloors(nAreaIndex);
	int nNumberOfDoors = determineNumberOfDoors(nAreaIndex);
	int* pAreaBoard[nNumberOfFloors];
	Door* pAreaDoors[nNumberOfDoors / 2];
	int nArrayIndex;

	AreaFloor sAreaFloor;

	// set all indices of pAreaBoard to NULL, this is a preparation for
	// loading the floors of the area
	for (nArrayIndex = 0; nArrayIndex < nNumberOfFloors; nArrayIndex++) {
		pAreaBoard[nArrayIndex] = NULL;
	}

	// set all indices of pAreaDoors to NULL, this is a preparation for
	// loading the doors of the area
	for (nArrayIndex = 0; nArrayIndex < nNumberOfDoors / 2; nArrayIndex++) {
		pAreaDoors[nArrayIndex] = NULL;
	} 

	// initiliaze contents of the structure
	sAreaFloor.nFloorNumber = nFloorNumber;
	sAreaFloor.nAreaIndex = nAreaIndex;
	sAreaFloor.pFloorBoardArray = pAreaBoard;
	sAreaFloor.pAreaDoorArray = pAreaDoors;

	// determine how many rows and columns the current
	// area floor number has
	determineAreaRowsColumns(&sAreaFloor);  

	// generate the current area floor number and store it at pFloorBoardArray
	sAreaFloor.pFloorBoardArray[sAreaFloor.nFloorNumber - 1] = generateArea(sAreaFloor);

	// load all the doors for that area
	loadDoors(sAreaFloor.nAreaIndex, sAreaFloor.pAreaDoorArray);

	// identify player starting tile
	findPlayerSpawn(sAreaFloor, &pPlayer->sPlayerAreaDetails);

	// main UI of this function
	do {
		system("cls");

		// prints the Area Name as a Header
		printAreaName(nAreaIndex);

		// prints the Area Map
		printAreaMap(sAreaFloor, &pPlayer->sPlayerAreaDetails);
		printf("\n");

		// prints player navigation/dialogue box
		printAreaNav(*pPlayer, nPrompt);

		printFooter();

		// checker if there is a current prompt that needs to be printed only and not ask for input
		if (nPrompt == NO_PROMPT || nPrompt == EMPTY_TILE_PROMPT || nPrompt == LOCKED_TILE_PROMPT) {
			printInputDivider();
			getCharAreaInput(&cInput, aPlayerCommands, 10);
		}

		// process the input from the user
		processAreaScreenInput(cInput, &sAreaFloor, pPlayer, &nLeaveArea, &nPrompt, &nTileSpawnType, &nBBattleFinished);
	
	// only exit the area screen if nLeaveArea is TRUE
	} while (!nLeaveArea); 

	// free the allocated floors for the area
	for (nArrayIndex = nNumberOfFloors - 1; nArrayIndex >= 0; nArrayIndex--) {
		if (sAreaFloor.pFloorBoardArray[nArrayIndex] != NULL) {
			free (sAreaFloor.pFloorBoardArray[nArrayIndex]);
		}
	}

	// free the allocated doors for the area
	for (nArrayIndex = nNumberOfDoors / 2 - 1; nArrayIndex >= 0; nArrayIndex--) {
		if (sAreaFloor.pAreaDoorArray[nArrayIndex] != NULL) {
			free (sAreaFloor.pAreaDoorArray[nArrayIndex]->pNext);
			free (sAreaFloor.pAreaDoorArray[nArrayIndex]);
		}
	}
}


/*
	processAreaScreenInput   Processes the Input of the User and does desired functions 

	@param cInput            Contains the input of the user
	@param pAreaFloor        A pointer to the AreaFloor structure 
	@param pPlayer           A pointer to the Player structure
	@param pLeaveArea        A pointer to an int that determines if player wishes to leave the area screen

	@param pPrompt           A pointer to an int that determines what kind of prompt to be printed
	@param pTileSpawnType    A pointer to an int that determines what kind of Spawn Tile Treasure/Enemy
							 the player triggered. This is a helper for prompts.
	@param pBBattleFinished  A pointer to an int that determines whether the Boss Battle is finished or not.
	                         This is also a helper for prompts

*/
void processAreaScreenInput(char cInput, AreaFloor* pAreaFloor, Player* pPlayer, int* pLeaveArea, 
						    int* pPrompt, int* pTileSpawnType, int* pBBattleFinished) {
	switch(cInput) {
		// if player inputs 'w'
		case 'W':
		case 'w':
			// call movePlayer with UP as first param (player wishes to move UP)
			movePlayer(UP, *pAreaFloor, &pPlayer->sPlayerAreaDetails);
			// no prompt shall be printed by moving UP
			*pPrompt = NO_PROMPT;
			break;

		// if player inputs 'A'
		case 'A':
		case 'a':
			// call movePlayer with DOWN as first param (player wishes to move DOWN)
			movePlayer(LEFT, *pAreaFloor, &pPlayer->sPlayerAreaDetails);
			// no prompt shall be printed by moving DOWN
			*pPrompt = NO_PROMPT;
			break;

		// if player inputs
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
			interactTile(pAreaFloor, pPlayer, pLeaveArea, pPrompt, pTileSpawnType, pBBattleFinished);
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

void interactTile(AreaFloor* pAreaFloor, Player* pPlayer, int *pLeaveArea, 
				  int *pPrompt, int* pTileSpawnType, int* pBBattleFinished) {
	
	int nTileType = *(pAreaFloor->pFloorBoardArray[pAreaFloor->nFloorNumber - 1] + (pPlayer->sPlayerAreaDetails.nRowLocation * pAreaFloor->nColumns) +
					pPlayer->sPlayerAreaDetails.nColumnLocation);
	int nResult;
	Enemy sEnemy;

	switch (nTileType) {
		case TILE_EMPTY:
			*pPrompt = EMPTY_TILE_PROMPT;
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
			if (*pBBattleFinished) {
				if (*pPrompt == NEW_UNLOCKED_TILE_PROMPT || *pPrompt == FINISHED_ELDEN_THRONE_PROMPT) {
					pressEnter();
					*pPrompt = EMPTY_TILE_PROMPT;
					*(pAreaFloor->pFloorBoardArray[pAreaFloor->nFloorNumber - 1] + (pPlayer->sPlayerAreaDetails.nRowLocation * pAreaFloor->nColumns) +
					pPlayer->sPlayerAreaDetails.nColumnLocation) = TILE_EMPTY;
				}
			}
	
			else {
				if (*pPrompt == NO_PROMPT) {
					*pPrompt = BOSS_TILE_PROMPT;
				}

				else if (*pPrompt == BOSS_TILE_PROMPT) {
					pressEnter();
				
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
						*pBBattleFinished = 1;
						if (!checkFastTravelStatus(pAreaFloor->nAreaIndex, &pPlayer->sPlayerUnlockedAreas)) {
							if (pAreaFloor->nAreaIndex != THE_ELDEN_THRONE) {
								*pPrompt = NEW_UNLOCKED_TILE_PROMPT;
							}
							else {
								*pPrompt = FINISHED_ELDEN_THRONE_PROMPT;
							}
							openNewFastTravel(pAreaFloor->nAreaIndex, pPlayer);
						}
						else {
							*pPrompt = EMPTY_TILE_PROMPT;
							*(pAreaFloor->pFloorBoardArray[pAreaFloor->nFloorNumber - 1] + (pPlayer->sPlayerAreaDetails.nRowLocation * pAreaFloor->nColumns) +
							pPlayer->sPlayerAreaDetails.nColumnLocation) = TILE_EMPTY;
						}
					}
				}
			}
			break;

		case TILE_FAST_TRAVEL:
			if (pAreaFloor->nFloorNumber != 1 && checkFastTravelStatus(pAreaFloor->nAreaIndex, &pPlayer->sPlayerUnlockedAreas)) {
				*pLeaveArea = 1;
				*pPrompt = RH_FAST_TRAVEL_PROMPT;
				openFastTravel(pPlayer, pPrompt);
			}
			else if (pAreaFloor->nFloorNumber != 1 && !checkFastTravelStatus(pAreaFloor->nAreaIndex, &pPlayer->sPlayerUnlockedAreas)) {
				*pPrompt = LOCKED_TILE_PROMPT;
			}
			else if (pAreaFloor->nFloorNumber == 1) {
				*pLeaveArea = 1;
				*pPrompt = RH_FAST_TRAVEL_PROMPT;	
				openFastTravel(pPlayer, pPrompt);
			}
			break;

		case TILE_CREDITS:
			if (!checkFastTravelStatus(pAreaFloor->nAreaIndex, &pPlayer->sPlayerUnlockedAreas)) {
				*pPrompt = LOCKED_TILE_PROMPT;
			}
			else {
				*pLeaveArea = 1;
				openCredits();
			}
			break;
	}
}

void interactTileSpawn(AreaFloor* pAreaFloor, Player* pPlayer, int* pLeaveArea, int* pPrompt, int* pTileSpawnType) {
	int nSpawnRate;
	int nRunesGained = 0;
	int nResult;
	Enemy sEnemy;

	if (*pTileSpawnType == NO_SPAWN_YET) {
		if (pAreaFloor->nAreaIndex != THE_ELDEN_THRONE) {
			nSpawnRate = randomNumberBetween(100, 1);
		}
		else {
			nSpawnRate = randomNumberBetween(100, 76);
		}
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
