#ifndef FAST_TRAVEL_H
#define FAST_TRAVEL_H

void openFastTravel(Player* pPlayer, int* pPrompt);
void processFastTravelInput(int nInput, Player* pPlayer, int* pSuccessfulFastTravel, int* pPrompt);
void openFastTravelToFloor(int nAreaIndex, Player* pPlayer, int* pPrompt);

#endif 