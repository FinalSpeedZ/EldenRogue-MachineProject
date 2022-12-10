#ifndef FAST_TRAVEL_H
#define FAST_TRAVEL_H

#define STORMVEIL_CASTLE       1
#define RAYA_LUCARIA_ACADEMY   2
#define REDMANE_CASTLE         3
#define VOLCANO_MANOR          4
#define LEYNDELL_ROYAL_CAPITAL 5
#define THE_ELDEN_THRONE       6

void openFastTravel(Player* pPlayer);
void processFastTravelInput(int nInput, Player* pPlayer);
void openFastTravelToFloor(int nAreaIndex, Player* pPlayer);

#endif 