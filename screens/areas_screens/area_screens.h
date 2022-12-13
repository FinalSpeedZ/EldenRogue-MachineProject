/****************************************
File Name: area_screens.h

The header file for area_screen.c
****************************************/

#ifndef AREA_SCREENS_H 
#define AREA_SCREENS_H


void openAreaScreen(int nAreaIndex, int nFloorNumber, Player* pPlayer);

void processAreaScreenInput(char cInput, AreaFloor* pAreaFloor, Player* pPlayer, int* pLeaveArea, 
						    int* pPrompt, int* pTileSpawnType, int* pBBattleFinished);

void movePlayer(int nDirection, AreaFloor sAreaFloor, AreaDetails* pPlayerAreaDetails);

void interactTile(AreaFloor* pAreaFloor, Player* pPlayer, int *pLeaveArea, 
				  int *pPrompt, int* pTileSpawnType, int* pBBattleFinished);

void interactTileSpawn(AreaFloor* pAreaFloor, Player* pPlayer, int* pLeaveArea, int* pPrompt, int* pTileSpawnType);

void interactTileDoor(AreaFloor* pAreaFloor, AreaDetails* pPlayerAreaDetails);

#endif