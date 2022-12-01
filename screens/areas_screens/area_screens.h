#ifndef AREA_SCREENS_H 
#define AREA_SCREENS_H

#define UP    1
#define DOWN  2
#define LEFT  3
#define RIGHT 4

#define ENEMY_YIELD    75
#define TREASURE_YEILD 25

void openAreaScreen(int nAreaIndex, Player* pPlayer);

void determineAreaRowsColumns(int nAreaIndex, int nFloorNumber, int* pRows, int* pColumns);
void findPlayerSpawn(int nAreaIndex, int nFloorNumber, int nRows, int nColumns, AreaDetails* pPlayerAreaDetails);

void processAreaScreenInput(char cInput, int nAreaIndex, int* pFloorNumber, 
							int nRows, int nColumns, Player* pPlayer);

void movePlayer(int nDirection, int nAreaIndex, int nFloorNumber, 
				int nRows, int nColumns, AreaDetails* pPlayerAreaDetails);
void interactTile(int nAreaIndex, int* pFloorNumber, int nRows, int nColumns,
				  Player* pPlayer);
void interactTileSpawn(int nAreaIndex, Player* pPlayer);


void interactTileDoorUp(int nAreaIndex, int *pFloorNumber, AreaDetails* pPlayerAreaDetails);

#endif