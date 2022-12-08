#include "fast_travel.h"

#include "../areas_screens/area_screens.h"

void openFastTravel(Player* pPlayer) {
	int nInput = 0;
	
	do {
		system("cls");

		printFastTravelHeader();

		//fix UI of this
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
	switch (nInput) {
		case STORMVEIL_CASTLE:
		case RAYA_LUCARIA_ACADEMY:
		case REDMANE_CASTLE:
		case VOLCANO_MANOR:
		case LEYNDELL_ROYAL_CAPITAL:
		case THE_ELDEN_THRONE:
			openAreaScreen(nInput, pPlayer);
	}
}