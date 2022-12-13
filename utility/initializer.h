#ifndef INITIALIZER_H
#define INITIALIZER_H

void initializePlayer(Player* pPlayer);

void initializeJobClassStats(Player* pPlayer);
void resetRunes(int* pRunes);
void initializeShards(Player* pPlayer);
void resetPotions(int* pPotions);
void initializeAreaDetails(AreaDetails* pPlayerAreaDetails);
void initializeUnlockedAreas(UnlockedAreas* pPlayerUnlockedAreas);
void initializePlayerHealth(AreaDetails* pPlayerAreaDetails);

#endif