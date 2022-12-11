#ifndef BATTLE_H
#define BATTLE_H

void openBattleScreen(int nAreaIndex, Player* pPlayer);

void processBattleScreenInput(int nAreaIndex, int nMoveType, int nAttackType, Player* pPlayer, Enemy* pEnemy, 
							  int* pEnemyTurn, int nBattleFinished, int* pShowAttackTypes);

#endif