#ifndef AREA_SCREENS_H 
#define AREA_SCREENS_H

#define UP    1
#define DOWN  2
#define LEFT  3
#define RIGHT 4

#define ENEMY_YIELD    75
#define TREASURE_YEILD 25

void openAreaScreen(int nAreaIndex, int nFloorNumber, Player* pPlayer);

void processAreaScreenInput(char cInput, AreaFloor* pAreaFloor, Player* pPlayer, int* pLeaveArea);

void movePlayer(int nDirection, AreaFloor sAreaFloor, AreaDetails* pPlayerAreaDetails);

void interactTile(AreaFloor* pAreaFloor, Player* pPlayer, int *pLeaveArea);

void interactTileSpawn(int nAreaIndex, Player* pPlayer, int* pLeaveArea);

void interactTileDoor(AreaFloor* pAreaFloor, AreaDetails* pPlayerAreaDetails);

#endif