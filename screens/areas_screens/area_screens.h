#ifndef AREA_SCREENS_H 
#define AREA_SCREEN_H

#define UP    1
#define DOWN  2
#define LEFT  3
#define RIGHT 4

void openAreaScreen(int nAreaIndex, Player* pPlayer);

void determineAreaRowsColumns(int nAreaIndex, int nFloorNumber, int* pRows, int* pColumns);
void findPlayerSpawn(int nAreaIndex, int nFloorNumber, int nRows, int nColumns, AreaDetails* pPlayerAreaDetails);

void processAreaScreenInput(char cInput, int nAreaIndex, int nFloorNumber, 
							int nRows, int nColumns, AreaDetails* pPlayerAreaDetails);

void movePlayer(int nDirection, int nAreaIndex, int nFloorNumber, 
				int nRows, int nColumns, AreaDetails* pPlayerAreaDetails);


#endif