#ifndef BATTLE_SCREEN_HELPER_H
#define BATTLE_SCREEN_HELPER_H

void setEnemyStats(int nAreaIndex, Enemy* pEnemy);

void setEnemyType(int* pEnemyType);
void setEnemyHealthRange(Enemy* pEnemy);
void setEnemyBaseHealth(Enemy* pEnemy);
void setEnemyFinalHealth(int nAreaIndex, Enemy* pEnemy);

void setEnemyAttackRange(Enemy* pEnemy);
void setEnemyBaseAttack(Enemy* pEnemy);
void setEnemyFinalAttack(int nAreaIndex, Enemy* pEnemy);
void setEnemyDefense(Enemy* pEnemy);

int getEnemyNameLength(int nAreaIndex, int nEnemyType);
void setEnemyName(int nAreaIndex, Enemy* pEnemy);

void checkBattleOver(Player sPlayer, Enemy sEnemy, int* pBattleFinished);

int getPlayerPhysicalDmg(Player sPlayer, Enemy sEnemy);
int getPlayerSorceryDmg(Player sPlayer, Enemy sEnemy);
int getPlayerIncantationDmg(Player sPlayer, Enemy sEnemy);

void usePhysicalAttack(Player sPlayer, Enemy* pEnemy);
void useSorceryAttack(Player sPlayer, Enemy* pEnemy);
void useIncantationAttack(Player sPlayer, Enemy* pEnemy);

float getDodgeRate(Player sPlayer);
int useDodge(Player sPlayer);

int healthToBeAdded(Player* pPlayer);
void drinkPotion(Player* pPlayer, int nHealthGained);

void enemyAttack(Player* pPlayer, Enemy sEnemy);
void getIncomingDmg(int nAreaIndex, Enemy* pEnemy);

int computeGainedRunes(Enemy sEnemy, int nBoss);

void setBossStats(int nAreaIndex, Enemy* pEnemy, int nEldenThroneBossNum);
int getBossNameLength(int nAreaIndex, int nEldenThroneBossNum);
void setBossName(int nAreaIndex, int nEldenThroneBossNum, Enemy* pEnemy);
void setBossHealth(int nAreaIndex, int nEldenThroneBossNum, Enemy* pEnemy);
void setBossAttackRange(int nAreaIndex, int nEldenThroneBossNum, Enemy* pEnemy);
void setBossDefense(int nAreaIndex, int nEldenThroneBossNum, Enemy* pEnemy);
void setBossFinalAttack(Enemy* pEnemy);

#endif
