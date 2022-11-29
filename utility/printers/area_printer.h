#ifndef AREA_PRINTER_H 
#define AREA_PRINTER_H 

#define TOP    0
#define MIDDLE 1
#define BOTTOM 2

void printAreaMap(int nAreaIndex, int* pRows, int* pColumns, Player* pPlayer);

void printTileParts(int nTileType, int nTilePosition);

#endif