#ifndef AREA_BOARD_H 
#define AREA_BOARD_H

#define TILE_EMPTY       0
#define TILE_PLAYER      1
#define TILE_DOOR_UP     2
#define TILE_DOOR_DOWN   3
#define TILE_DOOR_LEFT   4
#define TILE_DOOR_RIGHT  5
#define TILE_SPAWN       6
#define TILE_BOSS        7
#define TILE_FAST_TRAVEL 8
#define TILE_CREDITS     9
#define TILE_INVALID     10

int* generateStromveilCastle(AreaFloor sAreaFloor);
int* generateRayaLucaria(AreaFloor sAreaFloor);
int* generateRedmaneCastle(AreaFloor sAreaFloor);
int* generateVolcanoManor(AreaFloor sAreaFloor);
int* generateLeyndellRoyalCapital(AreaFloor sAreaFloor);
int* generateEldenThrone(AreaFloor sAreaFloor);

int* generateArea(AreaFloor sAreaFloor);

#endif