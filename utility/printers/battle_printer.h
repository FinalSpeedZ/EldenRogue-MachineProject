#ifndef BATTLE_PRINTER_H
#define BATTLE_PRINTER_H

#define HEALTH_WIDTH  50

void printBattleDisplay(Player sPlayer, Enemy sEnemy, int nEnemyTurn, int nBoss);

void printEnemyBattleDisplayLine(int nLine, int nOffset, Enemy sEnemy, int nBoss);

void printEnemyBattleEnd(int nLine, int nOffset);
void printEnemyBattleUI(int nLine, int nOffset, Enemy sEnemy, int nBoss);
void printEnemyName(int nOffset, char* pEnemyName);
void printEnemySpritePerLineBattle(int nLine, int nOffset);
void printEnemyHealthBar(int nOffset, Enemy sEnemy, int nBoss);
void printEnemyHealth(int nOffset, Enemy sEnemy);

void printPlayerBattleDisplayLine(int nLine, int nOffset, Player sPlayer, int nIncomingDamage);
void printPlayerBattleEnd(int nLine, int nOffset);
void printPlayerBattleUI(int nLine, int nOffset, Player sPlayer, int nIncomingDamage);
void printPlayerNameJob(Player sPlayer);
void printIncomingDamage(int nIncomingDamage, Player sPlayer);
void printPlayerSpritePerLineBattle(int nLine);
void printPlayerHealthBar(AreaDetails sPlayerAreaDetails, int nHealthBars);
void printPlayerHealth(AreaDetails sPlayerAreaDetails);
void printPlayerPotions(int nPotions);

void printRunesLost();

#endif