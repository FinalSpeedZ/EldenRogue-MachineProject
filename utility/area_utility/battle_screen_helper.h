#ifndef BATTLE_SCREEN_HELPER_H
#define BATTLE_SCREEN_HELPER_H

void getEnemyStats(int nAreaIndex, Enemy* pEnemy);

void getEnemyType(int* pEnemyType);
void getEnemyHealthRange(Enemy* pEnemy);
void getEnemyBaseHealth(Enemy* pEnemy);
void getEnemyFinalHealth(int nAreaIndex, Enemy* pEnemy);

void getEnemyAttackRange(Enemy* pEnemy);
void getEnemyBaseAttack(Enemy* pEnemy);
void getEnemyFinalAttack(int nAreaIndex, Enemy* pEnemy);
void getEnemyDefense(Enemy* pEnemy);

int getEnemyNameLength(int nAreaIndex, int nEnemyType);
void getEnemyName(int nAreaIndex, Enemy* pEnemy);

void checkGameOver(Player sPlayer, Enemy sEnemy, int* pBattleFinished);

int getPlayerPhysicalDmg(Player sPlayer, Enemy sEnemy);
int getPlayerSorceryDmg(Player sPlayer, Enemy sEnemy);
int getPlayerIncantationDmg(Player sPlayer, Enemy sEnemy);

void usePhysicalAttack(Player sPlayer, Enemy* pEnemy);
void useSorceryAttack(Player sPlayer, Enemy* pEnemy);
void useIncantationAttack(Player sPlayer, Enemy* pEnemy);

int getDodgeRate(Player sPlayer);
int useDodge(Player sPlayer);

void drinkPotion(Player* pPlayer);

void enemyAttack(Player* pPlayer, Enemy sEnemy);
void getIncomingDmg(int nAreaIndex, Enemy* pEnemy);

#endif
