#ifndef AREA_SCREEN_HELPER_H
#define AREA_SCREEN_HELPER_H

int determineNumberOfFloors(int nAreaIndex);
void determineAreaRowsColumns(AreaFloor* pAreaFloor);
void findPlayerSpawn(AreaFloor sAreaFloor, AreaDetails* pPlayerAreaDetails);

int receiveRunes(int nAreaIndex);

int checkFastTravelStatus(int nAreaIndex, UnlockedAreas* pPlayerUnlockedAreas);

#endif