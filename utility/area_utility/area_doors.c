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







int doorMatch(int nDoorFloor, int nPlayerFloor) {
	int nMatch = 0;

	if (nPlayerFloor == nDoorFloor) {
		nMatch = 1;
	}

	return nMatch;
}