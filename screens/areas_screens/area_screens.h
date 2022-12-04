#ifndef AREA_SCREENS_H 
#define AREA_SCREENS_H

#define UP    1
#define DOWN  2
#define LEFT  3
#define RIGHT 4

#define ENEMY_YIELD    75
#define TREASURE_YEILD 25

void openAreaScreen(int nAreaIndex, Player* pPlayer);

void determineAreaRowsColumns(AreaFloor* pAreaFloor);
void findPlayerSpawn(AreaFloor sAreaFloor, AreaDetails* pPlayerAreaDetails);

void processAreaScreenInput(char cInput, AreaFloor* pAreaFloor, Player* pPlayer);

void movePlayer(int nDirection, AreaFloor sAreaFloor, AreaDetails* pPlayerAreaDetails);
void interactTile(int nAreaIndex, int* pFloorNumber, int nRows, int nColumns,
				  Player* pPlayer);
void interactTileSpawn(int nAreaIndex, Player* pPlayer);


void interactTileDoor(int nAreaIndex, int *pFloorNumber, AreaDetails* pPlayerAreaDetails);

#endif