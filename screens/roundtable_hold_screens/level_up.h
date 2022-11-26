#ifndef LEVEL_UP_H
#define LEVEL_UP_H

#define LEVEL_MAX 50

#define HEALTH       1
#define ENDURANCE    2
#define DEXTERITY    3
#define STRENGTH     4
#define INTELLIGENCE 5
#define FAITH        6

void openLevelUp(Player* pPlayer);
void processLevelUpInput(int nInput, Player* pPlayer);

int calculateRuneCost(int nPlayerLevel);

void levelUpStatChecker(char strStatName[], Player* pPlayer, int* pPlayerStat);
void levelUpStat(int* pStat, Player* pPlayer);

#endif 