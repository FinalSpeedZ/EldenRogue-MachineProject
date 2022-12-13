#include "fast_travel.h"

#include "../areas_screens/area_screens.h"
#include "../../utility/area_utility/area_screen_helper.h"


/*
	openFastTravel  allows user to fast travel to a specific area
	
	@param pPlayer    The pointer to the player structure to be altered
	@paramp pPrompt   The pointer to an int containing the prompt type
	Pre-condition:   structure that pPlayer is pointing to is already initialized
*/
void openFastTravel(Player* pPlayer, int* pPrompt) {
	int nInput = 0;
	int nSuccessfulFastTravel = 1;
	
	do {
		initializePlayerHealth(pPlayer);
		resetPotions(&pPlayer->sPlayerEquipment.nPotions);

		system("cls");

		printFastTravelHeader();

		printTwoLongOptions(STORMVEIL_CASTLE, "STORMVEIL CASTLE", RAYA_LUCARIA_ACADEMY, "RAYA LUCARIA ACADEMY");
		printTwoLongOptions(REDMANE_CASTLE, "REDMANE CASTLE", VOLCANO_MANOR, "VOLCANO MANOR");
		printTwoLongOptions(LEYNDELL_ROYAL_CAPITAL, "LEYNDELL ROYAL CAPITAL", THE_ELDEN_THRONE, "THE ELDEN THRONE");
		printCenterOption(0, OPTION_BACK);


		printRoundtableNav(*pPlayer, *pPrompt);

		printFooter();
		printInputDivider();

		getIntInput(&nInput, 0, 6);
		processFastTravelInput(nInput, pPlayer, &nSuccessfulFastTravel, pPrompt);	
	} while ((nInput < 0 || nInput > 6) || (nSuccessfulFastTravel == 0));

	*pPrompt = NO_PROMPT;
}

/*
	processFastTravelInput  processess fast travel selection input
	
	@param nInput     int containing the input of the player
	@param pPlayer    The pointer to the player structure to be altered
	@param pSuccessfulFastTravel  The pointer to an int determining if it is successful fast travel
	Pre-condition:   structure that pPlayer is pointing to is already initialized
*/
void processFastTravelInput(int nInput, Player* pPlayer, int* pSuccessfulFastTravel, int* pPrompt) {
	int nFloorNumber = 1;
	int nUnlocked = 0;

	switch (nInput) {
		case 0:
			*pSuccessfulFastTravel = 1;
			break;

		case STORMVEIL_CASTLE:
		case RAYA_LUCARIA_ACADEMY:
		case REDMANE_CASTLE:
		case VOLCANO_MANOR:
			nUnlocked = checkFastTravelStatus(nInput, &pPlayer->sPlayerUnlockedAreas);
			if (nUnlocked == 0) {
				openAreaScreen(nInput, nFloorNumber, pPlayer);
			}
			else {
				openFastTravelToFloor(nInput, pPlayer, pPrompt);
			}
			*pSuccessfulFastTravel = 1;
			break;

		case LEYNDELL_ROYAL_CAPITAL:
			if (pPlayer->nShards >= 2) {
				nUnlocked = checkFastTravelStatus(nInput, &pPlayer->sPlayerUnlockedAreas);
				if (nUnlocked == 0) {
					openAreaScreen(nInput, nFloorNumber, pPlayer);
				}
				else  {
					openFastTravelToFloor(nInput, pPlayer, pPrompt);
				}
				*pSuccessfulFastTravel = 1;
			}
			else {
				*pSuccessfulFastTravel = 0;
				*pPrompt = RH_FAST_TRAVEL_LOCKED_PROMPT;
			}
			break;

		case THE_ELDEN_THRONE:
			if (pPlayer->nShards > 2 && checkFastTravelStatus(LEYNDELL_ROYAL_CAPITAL, &pPlayer->sPlayerUnlockedAreas)) {
				if (nUnlocked == 0) {
					openAreaScreen(nInput, nFloorNumber, pPlayer);
				}
			}
			else {
				*pSuccessfulFastTravel = 0;
				*pPrompt = RH_FAST_TRAVEL_LOCKED_PROMPT;
			}
	}
}

/*
	openFastTravelToFloor  allows user to fast travel to a specific area floor
	
	@param nAreaIndex an int to the area index to travel to
	@param pPlayer    The pointer to the player structure to be altered
	@paramp pPrompt   The pointer to an int containing the prompt type
	Pre-condition:   structure that pPlayer is pointing to is already initialized
*/
void openFastTravelToFloor(int nAreaIndex, Player* pPlayer, int* pPrompt) {
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
		openFastTravel(pPlayer, pPrompt);
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

