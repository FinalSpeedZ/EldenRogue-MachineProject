#ifndef BATTLE_H
#define BATTLE_H

#define NORMAL_BATTLE 0
#define BOSS_BATTLE   1

int openBattleScreen(int nAreaIndex, Player* pPlayer, Enemy* pEnemy, int nBoss);

void processBattleScreenInput(int nAreaIndex, int nMoveType, int nAttackType, Player* pPlayer, Enemy* pEnemy, 
							  int nBoss, int* pEnemyTurn, int* pShowAttackTypes, int* pSuccessfulDodge);

void openWinScreen(Player* pPlayer, Enemy sEnemy, int nBoss);
void openLostScreen(Player *pPlayer);


#endif