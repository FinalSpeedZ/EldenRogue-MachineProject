#ifndef AREA_DOORS_H 
#define AREA_DOORS_H

Door* createDoor(int nFloorNumber, int nRowLocation, int nColumnLocation);
void addDoor(Door** pAreaDoorHead, int nArrayIndex, int nFloorNumber, int nRowLocation, int nColumnLocation);

void doorsStormveilCastle(Door** pAreaDoorArray);
void doorsRayaLucariaAcademy(Door** pAreaDoorArray);
void doorsRedmaneCastle(Door** pAreaDoorArray);
void doorsVolcanoManor(Door** pAreaDoorArray);
void doorsLeyndellRoyalCapital(Door** pAreaDoorArray);
void doorsTheEldenThrone(Door** pAreaDoorArray);
void loadDoors(int nAreaIndex, Door** pAreaDoorArray);

int determineNumberOfDoors(int nAreaIndex);
Door* findDoor(Door** pAreaDoorArray, int nNumberOfDoors, AreaDetails* pPlayerAreaDetails, int *pFloorNumber);

#endif