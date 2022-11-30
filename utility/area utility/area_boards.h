#ifndef AREA_BOARD_H 
#define AREA_BOARD_H

#define TILE_EMPTY       0
#define TILE_PLAYER      1
#define TILE_DOOR_UP     2
#define TILE_DOOR_DOWN   3
#define TILE_SPAWN       4
#define TILE_BOSS        5
#define TILE_FAST_TRAVEL 6
#define TILE_CREDITS     7
#define TILE_INVALID     8

int* generateStromveilCastle(int nFloorNumber, int nRows, int nColumns);
int* generateRayaLucaria(int nFloorNumber, int nRows, int nColumns);
int* generateRedmaneCastle(int nFloorNumber, int nRows, int nColumns);
int* generateVolcanoManor(int nFloorNumber, int nRows, int nColumns);
int* generateLeyndellRoyalCapital(int nFloorNumber, int nRows, int nColumns);
int* generateEldenThrone(int nFloorNumber, int nRows, int nColumns);

int* generateArea(int nAreaIndex, int nFloorNumber, int nRows, int nColumns);

#endif