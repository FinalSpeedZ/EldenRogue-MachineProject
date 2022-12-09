#include "area_screen_helper.h"

int determineNumberOfFloors(int nAreaIndex) {
	int nNumberOfFloors = 0;

	switch(nAreaIndex) {
		case STORMVEIL_CASTLE:
			nNumberOfFloors = 3;
			break;

		case RAYA_LUCARIA_ACADEMY:
			nNumberOfFloors = 5;
			break;

		case REDMANE_CASTLE:
			nNumberOfFloors = 7;
			break;

		case VOLCANO_MANOR:
			nNumberOfFloors = 7;
			break;

		case LEYNDELL_ROYAL_CAPITAL:
			nNumberOfFloors = 14;
			break;

		case THE_ELDEN_THRONE:
			nNumberOfFloors = 3;
	}

	return nNumberOfFloors;
}

void determineAreaRowsColumns(AreaFloor* pAreaFloor) {
	switch(pAreaFloor->nAreaIndex){
		case STORMVEIL_CASTLE:
			switch (pAreaFloor->nFloorNumber){
				case 1:
					pAreaFloor->nRows = 7; 
					pAreaFloor->nColumns = 3;
					break;
				case 2:
					pAreaFloor->nRows = 7; 
					pAreaFloor->nColumns = 7;
					break;
				case 3:
					pAreaFloor->nRows = 7; 
					pAreaFloor->nColumns = 5;
					break;
			}
			break;

		case RAYA_LUCARIA_ACADEMY:
			switch (pAreaFloor->nFloorNumber){
				case 1:
					pAreaFloor->nRows = 5; 
					pAreaFloor->nColumns = 5;
					break;
				case 2:
					pAreaFloor->nRows = 7; 
					pAreaFloor->nColumns = 3;
					break;
				case 3:
					pAreaFloor->nRows = 7; 
					pAreaFloor->nColumns = 5;
					break;
				case 4:
					pAreaFloor->nRows = 5; 
					pAreaFloor->nColumns = 6;
					break;
				case 5:
					pAreaFloor->nRows = 8; 
					pAreaFloor->nColumns = 7;
					break;
			}
			break;

		case REDMANE_CASTLE:
			switch (pAreaFloor->nFloorNumber){
				case 1:
					pAreaFloor->nRows = 3; 
					pAreaFloor->nColumns = 5;
					break;
				case 2:
					pAreaFloor->nRows = 3; 
					pAreaFloor->nColumns = 7;
					break;
				case 3:
					pAreaFloor->nRows = 5; 
					pAreaFloor->nColumns = 5;
					break;
				case 4:
					pAreaFloor->nRows = 5; 
					pAreaFloor->nColumns = 7;
					break;
				case 5:
					pAreaFloor->nRows = 3; 
					pAreaFloor->nColumns = 5;
					break;
				case 6:
					pAreaFloor->nRows = 9; 
					pAreaFloor->nColumns = 4;
					break;
				case 7:
					pAreaFloor->nRows = 5; 
					pAreaFloor->nColumns = 7;
					break;
			}
			break;

		case VOLCANO_MANOR:
			switch (pAreaFloor->nFloorNumber){
				case 1:
					pAreaFloor->nRows = 5; 
					pAreaFloor->nColumns = 5;
					break;
				case 2:
					pAreaFloor->nRows = 7; 
					pAreaFloor->nColumns = 7;
					break;
				case 3:
					pAreaFloor->nRows = 5; 
					pAreaFloor->nColumns = 5;
					break;
				case 4:
					pAreaFloor->nRows = 5; 
					pAreaFloor->nColumns = 7;
					break;
				case 5:
					pAreaFloor->nRows = 4; 
					pAreaFloor->nColumns = 3;
					break;
				case 6:
					pAreaFloor->nRows = 8; 
					pAreaFloor->nColumns = 3;
					break;
				case 7:
					pAreaFloor->nRows = 7; 
					pAreaFloor->nColumns = 5;
					break;
			}
			break;

		case LEYNDELL_ROYAL_CAPITAL:
			switch (pAreaFloor->nFloorNumber){
				case 1:
					pAreaFloor->nRows = 4; 
					pAreaFloor->nColumns = 3;
					break;
				case 2:
					pAreaFloor->nRows = 7; 
					pAreaFloor->nColumns = 3;
					break;
				case 3:
					pAreaFloor->nRows = 5; 
					pAreaFloor->nColumns = 5;
					break;
				case 4:
					pAreaFloor->nRows = 3; 
					pAreaFloor->nColumns = 5;
					break;
				case 5:
					pAreaFloor->nRows = 4; 
					pAreaFloor->nColumns = 15;
					break;
				case 6:
					pAreaFloor->nRows = 3; 
					pAreaFloor->nColumns = 3;
					break;
				case 7:
					pAreaFloor->nRows = 7; 
					pAreaFloor->nColumns = 3;
					break;
				case 8:
					pAreaFloor->nRows = 7; 
					pAreaFloor->nColumns = 3;
					break;
				case 9:
					pAreaFloor->nRows = 7; 
					pAreaFloor->nColumns = 3;
					break;
				case 10:
					pAreaFloor->nRows = 4; 
					pAreaFloor->nColumns = 15;
					break;
				case 11:
					pAreaFloor->nRows = 13; 
					pAreaFloor->nColumns = 13;
					break;
				case 12:
					pAreaFloor->nRows = 3; 
					pAreaFloor->nColumns = 3;
					break;
				case 13:
					pAreaFloor->nRows = 3; 
					pAreaFloor->nColumns = 3;
					break;
				case 14:
					pAreaFloor->nRows = 7; 
					pAreaFloor->nColumns = 5;
					break;
			}
			break;

		case THE_ELDEN_THRONE:
			switch (pAreaFloor->nFloorNumber){
				case 1:
					pAreaFloor->nRows = 9; 
					pAreaFloor->nColumns = 3;
					break;
				case 2:
					pAreaFloor->nRows = 7; 
					pAreaFloor->nColumns = 7;
					break;
				case 3:
					pAreaFloor->nRows = 9; 
					pAreaFloor->nColumns = 3;
					break;
			}
			break;
	}
}

void findPlayerSpawn(AreaFloor sAreaFloor, AreaDetails* pPlayerAreaDetails) {
	int nRowCounter;
	int nColumnCounter;

	int* pFloor = generateArea(sAreaFloor);
	int nTileType;

	for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
		for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
			nTileType = *(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter);
			if (nTileType == TILE_FAST_TRAVEL) {
				pPlayerAreaDetails->nRowLocation = nRowCounter;
				pPlayerAreaDetails->nColumnLocation = nColumnCounter;
			}
		}
	}

	free(pFloor);
}

int receiveRunes(int nAreaIndex) {
	int nRunesGained = 0;

	nRunesGained = nAreaIndex * randomNumberBetween(150, 50);

	return nRunesGained;
}

int checkFastTravelStatus(int nAreaIndex, UnlockedAreas* pPlayerUnlockedAreas) {
	int nUnlocked = 0;

	switch (nAreaIndex) {
		case STORMVEIL_CASTLE:
			nUnlocked = pPlayerUnlockedAreas->nStormveilFastTravel;
			break;

		case RAYA_LUCARIA_ACADEMY:
			nUnlocked = pPlayerUnlockedAreas->nRayaLucariaFastTravel;
			break;

		case REDMANE_CASTLE:
			nUnlocked = pPlayerUnlockedAreas->nRedmaneFastTravel;
			break;

		case VOLCANO_MANOR:
			nUnlocked = pPlayerUnlockedAreas->nVolcanoFastTravel;
			break;

		case LEYNDELL_ROYAL_CAPITAL:
			nUnlocked = pPlayerUnlockedAreas->nLeyndellFastTravel;
			break;

		case THE_ELDEN_THRONE:
			nUnlocked = pPlayerUnlockedAreas->nEldenThroneCredits;
	}

	return nUnlocked;
}