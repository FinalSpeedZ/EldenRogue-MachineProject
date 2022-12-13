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
			// call movePlayer with LEFT as first param (player wishes to move LEFT)
			movePlayer(LEFT, *pAreaFloor, &pPlayer->sPlayerAreaDetails);
			// no prompt shall be printed by moving LEFT
			*pPrompt = NO_PROMPT;
			break;

		// if player inputs 'S'
		case 'S':
		case 's':
			// call movePlayer with DOWN as first param (player wishes to move DOWN)
			movePlayer(DOWN, *pAreaFloor, &pPlayer->sPlayerAreaDetails);
			// no prompt shall be printed by moving DOWN
			*pPrompt = NO_PROMPT;
			break;

		// if player inputs 'D'
		case 'D':
		case 'd':
			// call movePlayer with RIGHT as first param (player wishes to move RIGHT)
			movePlayer(RIGHT, *pAreaFloor, &pPlayer->sPlayerAreaDetails);
			// no prompt shall be printed by moving RIGHT
			*pPrompt = NO_PROMPT;
			break;

		// if player inputs 'E'
		case 'E':
		case 'e':
			// call interactTile
			interactTile(pAreaFloor, pPlayer, pLeaveArea, pPrompt, pTileSpawnType, pBBattleFinished);
			break;
	}
}

/*
	movePlayer                  This function moves the player based on the desired direction 

	@param nDirection           Contains the direction where the player wishes to move to
	@param sAreaFloor           The AreaFloor structure 
	@param pPlayerAreaDetails   A pointer to the AreaDetails structure of the player
*/
void movePlayer(int nDirection, AreaFloor sAreaFloor, AreaDetails* pPlayerAreaDetails) {
	// generate a copy of the floor
	int *pFloor = generateArea(sAreaFloor);

	switch(nDirection) {
		case UP:
			// move player up only if they are not at the top most row and the tile to be moved to is not Invalid 
			if (pPlayerAreaDetails->nRowLocation > 0 && 
				*(pFloor + ((pPlayerAreaDetails->nRowLocation - 1) * sAreaFloor.nColumns) + pPlayerAreaDetails->nColumnLocation) != TILE_INVALID) {
				
				// move up by decreasing current row location
				pPlayerAreaDetails->nRowLocation--;
			}
			break;

		case DOWN:
			// move player down only if they are not at the bottom most row and the tile to be moved to is not invalid
			if (pPlayerAreaDetails->nRowLocation < sAreaFloor.nRows - 1 && 
				*(pFloor + ((pPlayerAreaDetails->nRowLocation + 1) * sAreaFloor.nColumns) + pPlayerAreaDetails->nColumnLocation) != TILE_INVALID) {
				
				// move down by increasing current row location
				pPlayerAreaDetails->nRowLocation++;
			}
			break;

		case LEFT:
			// move player left only if they are not at left most column and the tile to be moved to is not invalid
			if (pPlayerAreaDetails->nColumnLocation > 0 && 
				*(pFloor + (pPlayerAreaDetails->nRowLocation * sAreaFloor.nColumns) + (pPlayerAreaDetails->nColumnLocation - 1)) != TILE_INVALID) {
				
				// move left by decreasing current column location
				pPlayerAreaDetails->nColumnLocation--;
			}
			break;

		case RIGHT:
			// move player right only if they are not at the right most column and the tile to be moved to is not invalid
			if (pPlayerAreaDetails->nColumnLocation < sAreaFloor.nColumns - 1 && 
				*(pFloor + (pPlayerAreaDetails->nRowLocation * sAreaFloor.nColumns) + (pPlayerAreaDetails->nColumnLocation + 1)) != TILE_INVALID) {
				
				// move right by increasing current column location
				pPlayerAreaDetails->nColumnLocation++;
			}
	}

	// free the allocated floor
	free(pFloor);
}



/*
	interactTile             This function handles a single interact command between the player 
							 and the tile they are currently on. 

	@param pAreaFloor        A pointer to the AreaFloor structure
	@param pPlayer           A pointer to the Player structure
	@param pLeaveArea        A pointer to an int that determines if player wishes to leave the area screen

	@param pPrompt           A pointer to an int that determines what kind of prompt to be printed
	@param pTileSpawnType    A pointer to an int that determines what kind of Spawn Tile Treasure/Enemy
							 the player triggered. This is a helper for prompts.
	@param pBBattleFinished  A pointer to an int that determines whether the Boss Battle is finished or not.
	                         This is also a helper for prompts
*/
void interactTile(AreaFloor* pAreaFloor, Player* pPlayer, int *pLeaveArea, 
				  int *pPrompt, int* pTileSpawnType, int* pBBattleFinished) {
	
	// get the current tile type the player is currently on
	int nTileType = *(pAreaFloor->pFloorBoardArray[pAreaFloor->nFloorNumber - 1] + (pPlayer->sPlayerAreaDetails.nRowLocation * pAreaFloor->nColumns) +
					pPlayer->sPlayerAreaDetails.nColumnLocation);

	// variable needed to know if player won or loss a battle
	int nResult;

	// declare enemy structure
	Enemy sEnemy;

	switch (nTileType) {
		case TILE_EMPTY:
			// if tile is empty, prompt tile empty
			*pPrompt = EMPTY_TILE_PROMPT;
			break;
			
		case TILE_DOOR_UP:
		case TILE_DOOR_DOWN:
		case TILE_DOOR_LEFT:
		case TILE_DOOR_RIGHT:
			// if any door is interacted call interactTileDoor
			interactTileDoor(pAreaFloor, &pPlayer->sPlayerAreaDetails);
			break;

		case TILE_SPAWN:
			// if tile spawn is interacted call interactTileSpawn
			interactTileSpawn(pAreaFloor, pPlayer, pLeaveArea, pPrompt, pTileSpawnType);
			break;

		case TILE_BOSS:
			
			// check first if Boss Battle is finished (This is for prompting)
			if (*pBBattleFinished) {
				if (*pPrompt == NEW_UNLOCKED_TILE_PROMPT || *pPrompt == FINISHED_ELDEN_THRONE_PROMPT) {
					pressEnter();
					*pPrompt = EMPTY_TILE_PROMPT;

					// change tile to empty
					*(pAreaFloor->pFloorBoardArray[pAreaFloor->nFloorNumber - 1] + (pPlayer->sPlayerAreaDetails.nRowLocation * pAreaFloor->nColumns) +
					pPlayer->sPlayerAreaDetails.nColumnLocation) = TILE_EMPTY;
				}
			}
	
			else {
				// This is for prompting 
				if (*pPrompt == NO_PROMPT) {
					// prompt that player encountered a boss
					*pPrompt = BOSS_TILE_PROMPT;
				}

				else if (*pPrompt == BOSS_TILE_PROMPT) {
					pressEnter();
					switch (pAreaFloor->nAreaIndex) {

						// if Elden Throne there are two bosses
						case THE_ELDEN_THRONE:
							// boss 1
							openEnemySpawn(pAreaFloor->nAreaIndex, pPlayer, &sEnemy, BOSS_BATTLE, 1);
							nResult = openBattleScreen(pAreaFloor->nAreaIndex, pPlayer, &sEnemy, BOSS_BATTLE);
							
							// summon boss 2 when player won against boss 1
							if (nResult == 1) {
								openEnemySpawn(pAreaFloor->nAreaIndex, pPlayer, &sEnemy, BOSS_BATTLE, 2);
								nResult = openBattleScreen(pAreaFloor->nAreaIndex, pPlayer, &sEnemy, BOSS_BATTLE);						
							}
							break;

						// if not Elden Throne only 1 boss
						default: 
							openEnemySpawn(pAreaFloor->nAreaIndex, pPlayer, &sEnemy, BOSS_BATTLE, 0);
							nResult = openBattleScreen(pAreaFloor->nAreaIndex, pPlayer, &sEnemy, BOSS_BATTLE);
					}

					// if player lost
					if (nResult == FALSE) {
						// leave the area since player lost
						*pLeaveArea = 1;
					}

					else {
						// if player won checkFastTravelStatus and openNewFastTravel if it is locked
						*pBBattleFinished = 1;
						if (!checkFastTravelStatus(pAreaFloor->nAreaIndex, &pPlayer->sPlayerUnlockedAreas)) {
							if (pAreaFloor->nAreaIndex != THE_ELDEN_THRONE) {
								// prompt that a new tile is unlocked
								*pPrompt = NEW_UNLOCKED_TILE_PROMPT;
							}
							else {
								// prompt that elden throne is finished
								*pPrompt = FINISHED_ELDEN_THRONE_PROMPT;
							}
							// open the new fast travel 
							openNewFastTravel(pAreaFloor->nAreaIndex, pPlayer);
						}
						else {
							// prompt that tile is now empty
							*pPrompt = EMPTY_TILE_PROMPT;
							// change tile to empty
							*(pAreaFloor->pFloorBoardArray[pAreaFloor->nFloorNumber - 1] + (pPlayer->sPlayerAreaDetails.nRowLocation * pAreaFloor->nColumns) +
							pPlayer->sPlayerAreaDetails.nColumnLocation) = TILE_EMPTY;
						}
					}
				}
			}
			break;

		case TILE_FAST_TRAVEL:
			// check first if fast travel tile is locked or not
			if (pAreaFloor->nFloorNumber != 1 && checkFastTravelStatus(pAreaFloor->nAreaIndex, &pPlayer->sPlayerUnlockedAreas)) {
				// leave the area since fast travel is successful
				*pLeaveArea = 1;
				*pPrompt = RH_FAST_TRAVEL_PROMPT;
				openFastTravel(pPlayer, pPrompt);
			}
			else if (pAreaFloor->nFloorNumber != 1 && !checkFastTravelStatus(pAreaFloor->nAreaIndex, &pPlayer->sPlayerUnlockedAreas)) {
				// prompt that the tile is locked
				*pPrompt = LOCKED_TILE_PROMPT;
			}
			else if (pAreaFloor->nFloorNumber == 1) {
				*pLeaveArea = 1;
				*pPrompt = RH_FAST_TRAVEL_PROMPT;	
				openFastTravel(pPlayer, pPrompt);
			}
			break;

		case TILE_CREDITS:
			// check if credits is locked
			if (!checkFastTravelStatus(pAreaFloor->nAreaIndex, &pPlayer->sPlayerUnlockedAreas)) {
				// prompt that the tile is locked
				*pPrompt = LOCKED_TILE_PROMPT;
			}
			else {
				// leave the area and open credits
				*pLeaveArea = 1;
				openCredits();
			}
			break;
	}
}

/*
	interactTileSpawn        This function handles the interact command between the player 
							 and the spawn tile 

	@param pAreaFloor        A pointer to the AreaFloor structure
	@param pPlayer           A pointer to the Player structure
	@param pLeaveArea        A pointer to an int that determines if player wishes to leave the area screen

	@param pPrompt           A pointer to an int that determines what kind of prompt to be printed
	@param pTileSpawnType    A pointer to an int that determines what kind of Spawn Tile Treasure/Enemy
							 the player triggered. This is a helper for prompts.
*/
void interactTileSpawn(AreaFloor* pAreaFloor, Player* pPlayer, int* pLeaveArea, int* pPrompt, int* pTileSpawnType) {
	// Declare variables
	int nSpawnRate;
	int nRunesGained = 0;
	int nResult;
	Enemy sEnemy;

	// if no tile spawn yet get a spawn rate
	if (*pTileSpawnType == NO_SPAWN_YET) {
		// if not elden throne
		if (pAreaFloor->nAreaIndex != THE_ELDEN_THRONE) {
			nSpawnRate = randomNumberBetween(100, 1);
		}
		// if elden throne force treasure
		else {
			nSpawnRate = randomNumberBetween(100, 76);
		}
	}

	// if it is an enemy spawn
	if (*pTileSpawnType == ENEMY_SPAWN) {
		pressEnter();
		// open enemy spawn and battle
		openEnemySpawn(pAreaFloor->nAreaIndex, pPlayer, &sEnemy, NORMAL_BATTLE, 0);
		nResult = openBattleScreen(pAreaFloor->nAreaIndex, pPlayer, &sEnemy, NORMAL_BATTLE);
		
		// if player lost
		if (nResult == 0) {
			// leave area
			*pLeaveArea = 1;
		}

		// if player won prompt empty tile
		*pPrompt = EMPTY_TILE_PROMPT;

		// make spwan tile empty
		*(pAreaFloor->pFloorBoardArray[pAreaFloor->nFloorNumber - 1] + (pPlayer->sPlayerAreaDetails.nRowLocation * pAreaFloor->nColumns) +
		pPlayer->sPlayerAreaDetails.nColumnLocation) = TILE_EMPTY;

		// revert tileSpawnTile to no spawn yet
		*pTileSpawnType = NO_SPAWN_YET;
	}

	// if it is a treasure spawn
	if (*pTileSpawnType == TREASURE_SPAWN) {
		pressEnter();
		// get runes gained
		nRunesGained = receiveRunes(pAreaFloor->nAreaIndex);
 		openTreasureSpawn(pAreaFloor->nAreaIndex, *pPlayer, nRunesGained);
 		// add runes gained to player runes
 		pPlayer->nRunes += nRunesGained;

 		// prompt empty tile
 		*pPrompt = EMPTY_TILE_PROMPT;

 		// make spawn tile empty
 		*(pAreaFloor->pFloorBoardArray[pAreaFloor->nFloorNumber - 1] + (pPlayer->sPlayerAreaDetails.nRowLocation * pAreaFloor->nColumns) +
		pPlayer->sPlayerAreaDetails.nColumnLocation) = TILE_EMPTY;

		// revert tileSpawnType to no spawn yet
		*pTileSpawnType = NO_SPAWN_YET;	
	}
	
	// nSpawnRate <= 75; 1 - 75					
	if ((nSpawnRate <= ENEMY_YIELD) && (*pPrompt == NO_PROMPT)) {
		*pPrompt = ENEMY_TILE_PROMPT;
		// it is an enemy spawn
		*pTileSpawnType = ENEMY_SPAWN;
	}			
	
	// nSpawnRate <= 75; 76 - 100						 	
	else if ((nSpawnRate > 100 - TREASURE_YIELD) && (*pPrompt == NO_PROMPT)) {
		*pPrompt = TREASURE_TILE_PROMPT;
		// it is a treasure spawn
		*pTileSpawnType = TREASURE_SPAWN;
	}
}

/*
	interactTileDoor           This function handles the interact command between the player 
							   and the door tile

	@param pAreaFloor          A pointer to the AreaFloor structure
	@param pPlayerAreaDetails  A pointer to the AreaDetails structure of Player
	
*/
void interactTileDoor(AreaFloor* pAreaFloor, AreaDetails* pPlayerAreaDetails) {
	Door* pInteractedDoor;

	// get number of doors
	int nNumberOfDoors = determineNumberOfDoors(pAreaFloor->nAreaIndex);

	// find the door that was interacted
	pInteractedDoor = findDoor(pAreaFloor->pAreaDoorArray, nNumberOfDoors, pPlayerAreaDetails, &pAreaFloor->nFloorNumber);

	// if prev of interacted door is null then it is head of the link list (player will be transported to the pNext door)
	if (pInteractedDoor->pPrev == NULL) {
		pPlayerAreaDetails->nRowLocation = pInteractedDoor->pNext->nRowLocation;
		pPlayerAreaDetails->nColumnLocation = pInteractedDoor->pNext->nColumnLocation;
		pAreaFloor->nFloorNumber = pInteractedDoor->pNext->nFloorNumber;
		determineAreaRowsColumns(pAreaFloor);
	}

	// if next of interacted door is null then it is latter part of the link list (player will be transported to the pPrev door)
	else {
		pPlayerAreaDetails->nRowLocation = pInteractedDoor->pPrev->nRowLocation;
		pPlayerAreaDetails->nColumnLocation = pInteractedDoor->pPrev->nColumnLocation;
		pAreaFloor->nFloorNumber = pInteractedDoor->pPrev->nFloorNumber;
		determineAreaRowsColumns(pAreaFloor);
	}

	// generate the new floor if it hasn't been generated yet
	if (pAreaFloor->pFloorBoardArray[pAreaFloor->nFloorNumber - 1] == NULL) {
		pAreaFloor->pFloorBoardArray[pAreaFloor->nFloorNumber - 1] = generateArea(*pAreaFloor);
	}
} 
