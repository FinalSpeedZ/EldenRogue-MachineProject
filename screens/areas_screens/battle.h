/****************************************
File Name: battle.h

The header file for battle.c
****************************************/

#ifndef BATTLE_H
#define BATTLE_H

int openBattleScreen(int nAreaIndex, Player* pPlayer, Enemy* pEnemy, int nBoss);

void processBattleScreenInput(int nAreaIndex, int nMoveType, int nAttackType, Player* pPlayer, Enemy* pEnemy, 
							  int nBoss, int* pEnemyTurn, int* pShowAttackTypes, int* pSuccessfulDodge);

void openWinScreen(Player* pPlayer, Enemy sEnemy, int nBoss);
void openLostScreen(Player *pPlayer);


#endif