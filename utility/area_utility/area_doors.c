Door* createDoorLocation(int nFloorNumber, int nRowLocation, int nColumnLocation) {
	Door* pDoor = malloc(sizeof(Door));

	pDoor->nFloorNumber = nFloorNumber;
	pDoor->nRowLocation = nRowLocation;
	pDoor->nColumnLocation = nColumnLocation;
	pDoor->pPrev = NULL;
	pDoor->pNext = NULL;

	return pDoor;
}

void doorsStormveilCastle(int nNumberOfDoors) {
	Door* StormveilCastle[nNumberOfDoors / 2]; 
	int nArrayIndex;

	for (nArrayIndex = 0; nArrayIndex < (nNumberOfDoors / 2); nArrayIndex++) {
		StormveilCastle[nArrayIndex] = NULL;
	}

	StormveilCastle[0] = createDoorLocation(1, 0, 1);

}