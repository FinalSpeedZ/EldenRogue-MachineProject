#ifndef AREA_DOORS_H 
#define AREA_DOORS_H

Door* createDoor(int nFloorNumber, int nRowLocation, int nColumnLocation);
void addDoor(Door** pAreaDoorHead, int nArrayIndex, int nFloorNumber, int nRowLocation, int nColumnLocation);
void doorsStormveilCastle(Door** pAreaDoorArray);


int doorMatch(int nDoorFloor, int nPlayerFloor);

#endif