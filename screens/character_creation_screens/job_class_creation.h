#ifndef JOB_CLASS_CREATION_H
#define JOB_CLASS_CREATION_H

#define VAGABOND   1
#define SAMURAI    2
#define WARRIOR    3
#define HERO       4
#define ASTROLOGER 5
#define PROPHET    6

void openJobClassSelection(Player* pPlayer);
void processJobSelectionInput(int nInput, Player* pPlayer);

void openJobClassStats(int nJobClass, Player* pPlayer);
void processJobClassStatsInput(int nInput, Player* pPlayer);

void loadJobClassStats(int nJobClass, Player* pPlayer);
void loadVagabondStats(Player* pPlayer);
void loadSamuraiStats(Player* pPlayer);
void loadWarriorStats(Player* pPlayer);
void loadHeroStats(Player* pPlayer);
void loadAstrologerStats(Player* pPlayer);
void loadProphetStats(Player* pPlayer);

void printStats(Player sPlayer);
void printPlayerLevel(int nLevel);

#endif
