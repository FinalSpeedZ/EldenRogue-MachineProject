#ifndef AREA_PRINTER_H 
#define AREA_PRINTER_H 

#define TOP    0
#define MIDDLE 1
#define BOTTOM 2

void printAreaMap(AreaFloor sAreaFloor, AreaDetails* pPlayerAreaDetails);

void printTileParts(int nTileType, int nTilePosition);

void printAreaName(int nAreaIndex);

#endif