#include "area_doors.h"

Door* createDoor(int nFloorNumber, int nRowLocation, int nColumnLocation) {
	Door* pDoor = malloc(sizeof(Door));

	pDoor->nFloorNumber = nFloorNumber;
	pDoor->nRowLocation = nRowLocation;
	pDoor->nColumnLocation = nColumnLocation;
	pDoor->pPrev = NULL;
	pDoor->pNext = NULL;

	return pDoor;
}

void addDoor(Door** pAreaDoorHead, int nArrayIndex, int nFloorNumber, int nRowLocation, int nColumnLocation) {
	Door* pLastDoor = *(pAreaDoorHead + nArrayIndex);
	Door* pNewDoor = createDoor(nFloorNumber, nRowLocation, nColumnLocation);

	if (*(pAreaDoorHead + nArrayIndex) == NULL) {
		*(pAreaDoorHead + nArrayIndex) = pNewDoor;
	}

	else {
		while (pLastDoor->pNext != NULL) {
			pLastDoor = pLastDoor->pNext;
		}
		pLastDoor->pNext = pNewDoor;
		pNewDoor->pPrev = pLastDoor;
	}
}

void doorsStormveilCastle(Door** pAreaDoorArray) {
	addDoor(pAreaDoorArray, 0, 1, 0, 1);
	addDoor(pAreaDoorArray, 0, 2, 6, 3);

	addDoor(pAreaDoorArray, 1, 2, 0, 3);
	addDoor(pAreaDoorArray, 1, 3, 6, 2);
}

void doorsRayaLucariaAcademy(Door** pAreaDoorArray) {
	addDoor(pAreaDoorArray, 0, 1, 4, 2);
	addDoor(pAreaDoorArray, 0, 2, 0, 1);

	addDoor(pAreaDoorArray, 1, 2, 3, 2);
	addDoor(pAreaDoorArray, 1, 3, 3, 0);

	addDoor(pAreaDoorArray, 2, 3, 3, 4);
	addDoor(pAreaDoorArray, 2, 4, 2, 0);

	addDoor(pAreaDoorArray, 3, 3, 0, 2);
	addDoor(pAreaDoorArray, 3, 5, 7, 3);
}

void doorsRedmaneCastle(Door** pAreaDoorArray) {
	addDoor(pAreaDoorArray, 0, 1, 1, 4);
	addDoor(pAreaDoorArray, 0, 2, 1, 0);

	addDoor(pAreaDoorArray, 1, 2, 1, 6);
	addDoor(pAreaDoorArray, 1, 3, 2, 0);

	addDoor(pAreaDoorArray, 2, 3, 0, 2);
	addDoor(pAreaDoorArray, 2, 4, 4, 3);

	addDoor(pAreaDoorArray, 3, 4, 2, 0);
	addDoor(pAreaDoorArray, 3, 5, 1, 4);

	addDoor(pAreaDoorArray, 4, 5, 1, 0);
	addDoor(pAreaDoorArray, 4, 6, 7, 3);

	addDoor(pAreaDoorArray, 5, 6, 1, 3);
	addDoor(pAreaDoorArray, 5, 7, 2, 0);
}

void doorsVolcanoManor(Door** pAreaDoorArray) {
	addDoor(pAreaDoorArray, 0, 1, 0, 2);
	addDoor(pAreaDoorArray, 0, 2, 6, 3);

	addDoor(pAreaDoorArray, 1, 2, 3, 0);
	addDoor(pAreaDoorArray, 1, 3, 2, 4);

	addDoor(pAreaDoorArray, 2, 2, 3, 6);
	addDoor(pAreaDoorArray, 2, 4, 2, 0);

	addDoor(pAreaDoorArray, 3, 4, 0, 3);
	addDoor(pAreaDoorArray, 3, 5, 3, 1);

	addDoor(pAreaDoorArray, 4, 2, 0, 3);
	addDoor(pAreaDoorArray, 4, 6, 7, 1);

	addDoor(pAreaDoorArray, 5, 6, 0, 1);
	addDoor(pAreaDoorArray, 5, 7, 6, 2);
}

void doorsLeyndellRoyalCapital(Door** pAreaDoorArray) {
	addDoor(pAreaDoorArray, 0, 1, 0, 1);
	addDoor(pAreaDoorArray, 0, 2, 6, 1);

	addDoor(pAreaDoorArray, 1, 2, 0, 1);
	addDoor(pAreaDoorArray, 1, 3, 4, 2);

	addDoor(pAreaDoorArray, 2, 3, 2, 4);
	addDoor(pAreaDoorArray, 2, 4, 1, 0);

	addDoor(pAreaDoorArray, 3, 4, 0, 2);
	addDoor(pAreaDoorArray, 3, 5, 3, 13);

	addDoor(pAreaDoorArray, 4, 5, 3, 1);
	addDoor(pAreaDoorArray, 4, 6, 0, 1);

	addDoor(pAreaDoorArray, 5, 5, 0, 1);
	addDoor(pAreaDoorArray, 5, 7, 6, 1);

	addDoor(pAreaDoorArray, 6, 5, 0, 7);
	addDoor(pAreaDoorArray, 6, 8, 6, 1);

	addDoor(pAreaDoorArray, 7, 5, 0, 13);
	addDoor(pAreaDoorArray, 7, 9, 6, 1);

	addDoor(pAreaDoorArray, 8, 8, 3, 0);
	addDoor(pAreaDoorArray, 8, 7, 3, 2);

	addDoor(pAreaDoorArray, 9, 8, 3, 2);
	addDoor(pAreaDoorArray, 9, 9, 3, 0);

	addDoor(pAreaDoorArray, 10, 7, 0, 1);
	addDoor(pAreaDoorArray, 10, 10, 3, 1);

	addDoor(pAreaDoorArray, 11, 8, 0, 1);
	addDoor(pAreaDoorArray, 11, 10, 3, 7);

	addDoor(pAreaDoorArray, 12, 9, 0, 1);
	addDoor(pAreaDoorArray, 12, 10, 3, 13);

	addDoor(pAreaDoorArray, 13, 10, 0, 7);
	addDoor(pAreaDoorArray, 13, 11, 12, 6);

	addDoor(pAreaDoorArray, 14, 11, 9, 0);
	addDoor(pAreaDoorArray, 14, 12, 1, 2);

	addDoor(pAreaDoorArray, 15, 11, 9, 12);
	addDoor(pAreaDoorArray, 15, 13, 1, 0);

	addDoor(pAreaDoorArray, 16, 11, 1, 6);
	addDoor(pAreaDoorArray, 16, 14, 0, 2);
}

void doorsTheEldenThrone(Door** pAreaDoorArray) {
	addDoor(pAreaDoorArray, 0, 1, 0, 1);
	addDoor(pAreaDoorArray, 0, 2, 6, 3);

	addDoor(pAreaDoorArray, 1, 2, 0, 3);
	addDoor(pAreaDoorArray, 1, 3, 8, 1);
}

void loadDoors(int nAreaIndex, Door** pAreaDoorArray) {
	switch (nAreaIndex) {
		case STORMVEIL_CASTLE:
			doorsStormveilCastle(pAreaDoorArray);
			break;

		case RAYA_LUCARIA_ACADEMY:
			doorsRayaLucariaAcademy(pAreaDoorArray);
			break;

		case REDMANE_CASTLE:
			doorsRedmaneCastle(pAreaDoorArray);
			break;

		case VOLCANO_MANOR:
			doorsVolcanoManor(pAreaDoorArray);
			break;

		case LEYNDELL_ROYAL_CAPITAL:
			doorsLeyndellRoyalCapital(pAreaDoorArray);
			break;

		case THE_ELDEN_THRONE:
			doorsTheEldenThrone(pAreaDoorArray);
			break;
	}
}

int determineNumberOfDoors(int nAreaIndex) {
	int nNumberOfDoors = 0;

	switch (nAreaIndex) {
		case STORMVEIL_CASTLE:
			nNumberOfDoors = 4;
			break;

		case RAYA_LUCARIA_ACADEMY:
			nNumberOfDoors = 8;
			break;

		case REDMANE_CASTLE:
			nNumberOfDoors = 12;
			break;

		case VOLCANO_MANOR:
			nNumberOfDoors = 12;
			break;

		case LEYNDELL_ROYAL_CAPITAL:
			nNumberOfDoors = 34;
			break;

		case THE_ELDEN_THRONE:
			nNumberOfDoors = 4;
			break;
	}

	return nNumberOfDoors;
}

Door* findDoor(Door** pAreaDoorArray, int nNumberOfDoors, AreaDetails* pPlayerAreaDetails, int *pFloorNumber) {
	int nArrayIndex;
	int nFound = 0;

	for (nArrayIndex = 0; nArrayIndex < nNumberOfDoors / 2 && !nFound; nArrayIndex++) {
		if (*pFloorNumber == pAreaDoorArray[nArrayIndex]->nFloorNumber &&
			pPlayerAreaDetails->nRowLocation == pAreaDoorArray[nArrayIndex]->nRowLocation &&
			pPlayerAreaDetails->nColumnLocation == pAreaDoorArray[nArrayIndex]->nColumnLocation) {

			nFound = 1;
			return pAreaDoorArray[nArrayIndex];
		}
		else if (*pFloorNumber == pAreaDoorArray[nArrayIndex]->pNext->nFloorNumber &&
				 pPlayerAreaDetails->nRowLocation == pAreaDoorArray[nArrayIndex]->pNext->nRowLocation &&
				 pPlayerAreaDetails->nColumnLocation == pAreaDoorArray[nArrayIndex]->pNext->nColumnLocation) {

			nFound = 1;
			return pAreaDoorArray[nArrayIndex]->pNext;
		}
	}
	return pAreaDoorArray[nArrayIndex];
}
