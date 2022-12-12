#include "fast_travel.h"

#include "../areas_screens/area_screens.h"
#include "../../utility/area_utility/area_screen_helper.h"

void openFastTravel(Player* pPlayer) {
	int nInput = 0;
	
	do {
		initializePlayerHealth(&pPlayer->sPlayerAreaDetails);

		system("cls");

		printFastTravelHeader();

		printTwoLongOptions(STORMVEIL_CASTLE, "STORMVEIL CASTLE", RAYA_LUCARIA_ACADEMY, "RAYA LUCARIA ACADEMY");
		printTwoLongOptions(REDMANE_CASTLE, "REDMANE CASTLE", VOLCANO_MANOR, "VOLCANO MANOR");
		printTwoLongOptions(LEYNDELL_ROYAL_CAPITAL, "LEYNDELL ROYAL CAPITAL", THE_ELDEN_THRONE, "THE ELDEN THRONE");
		printCenterOption(0, OPTION_BACK);

		printFooter();
		printInputDivider();

		getIntInput(&nInput, 0, 6);
		processFastTravelInput(nInput, pPlayer);	
	} while (nInput < 0 || nInput > 6);
}

void processFastTravelInput(int nInput, Player* pPlayer) {
	int nFloorNumber = 1;
	int nUnlocked = 0;
	switch (nInput) {
		case STORMVEIL_CASTLE:
		case RAYA_LUCARIA_ACADEMY:
		case REDMANE_CASTLE:
		case VOLCANO_MANOR:
		case LEYNDELL_ROYAL_CAPITAL:
		case THE_ELDEN_THRONE:
			nUnlocked = checkFastTravelStatus(nInput, &pPlayer->sPlayerUnlockedAreas);
			if (nUnlocked == 0){
				openAreaScreen(nInput, nFloorNumber, pPlayer);
			}
			else {
				openFastTravelToFloor(nInput, pPlayer);
			}
	}
}

void openFastTravelToFloor(int nAreaIndex, Player* pPlayer) {
	int nInput = 0;
	int nFloorNumber = 1;

	do {
		system("cls");

		printFastTravelHeader();

		switch (nAreaIndex) {
			case STORMVEIL_CASTLE:
			case RAYA_LUCARIA_ACADEMY:
			case REDMANE_CASTLE:
			case VOLCANO_MANOR:
			case LEYNDELL_ROYAL_CAPITAL:
				printTwoOptions(1, "FLOOR 1", 2, "BOSS FLOOR");
				printCenterOption(0, "BACK");
				break;
			case THE_ELDEN_THRONE:
				printTwoOptions(1, "FLOOR 1", 2, "CREDITS TILE");
				printCenterOption(0, "BACK");
				break;
		}

		printFooter();
		printInputDivider();

		getIntInput(&nInput, 0, 2);
	} while (nInput < 0 || nInput > 2);

	if (nInput == 0) {
		openFastTravel(pPlayer);
	}

	else if (nInput == 1) {
		nFloorNumber = 1;
	}

	else {
		switch (nAreaIndex) {
			case STORMVEIL_CASTLE:
				nFloorNumber = 3;
				break;
				
			case RAYA_LUCARIA_ACADEMY:
				nFloorNumber = 5;
				break;

			case REDMANE_CASTLE:
				nFloorNumber = 7;
				break;

			case VOLCANO_MANOR:
				nFloorNumber = 7;
				break;

			case LEYNDELL_ROYAL_CAPITAL:
				nFloorNumber = 14;
				break;

			case THE_ELDEN_THRONE:
				nFloorNumber = 3;
				break;		
		}
	}

	if (nInput != 0) {
		openAreaScreen(nAreaIndex, nFloorNumber, pPlayer);
	}
}

