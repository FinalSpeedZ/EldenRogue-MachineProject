#ifndef INITIALIZER_H
#define INITIALIZER_H

Player initializePlayer();

void initializeJobClassStats(Player* pPlayer);
void resetRunes(int* pRunes);
void initializeShards(int* pShards);
void initializeAreaDetails(AreaDetails* pPlayerAreaDetails);
void initializeUnlockedAreas(UnlockedAreas* pPlayerUnlockedAreas);

#endif