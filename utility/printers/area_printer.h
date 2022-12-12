#ifndef AREA_PRINTER_H 
#define AREA_PRINTER_H 

#define TOP    0
#define MIDDLE 1
#define BOTTOM 2

int* makeMapCopy(AreaFloor sAreaFloor);

void printAreaMap(AreaFloor sAreaFloor, AreaDetails* pPlayerAreaDetails);

void printTileParts(int nTileType, int nTilePosition);

void printAreaName(int nAreaIndex);

void openTreasureSpawn(int nAreaIndex, Player sPlayer, int nRunesGained);
void printRunesGained(Player sPlayer, int nRunesGained);

void openEnemySpawn(int nAreaIndex, Player* pPlayer, Enemy* pEnemy, int nBoss, int nEldenThroneBossNum);
void printBattlingAgainst(int nAreaIndex, Enemy* pEnemy, int nBoss, int nEldenThroneBossNum);

#endif