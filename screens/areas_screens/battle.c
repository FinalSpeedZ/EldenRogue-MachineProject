#include "battle.h"

void openBattleScreen(int nAreaIndex, Player* pPlayer) {
	int nMoveType = 1;
	int nAttackType = 0;
	int nShowAttackTypes = 0;
	int nBattleFinished = 0;
	int nEnemyTurn = 0;

	Enemy sEnemy;

	getEnemyStats(nAreaIndex, &sEnemy);	

	do {
		checkGameOver(*pPlayer, sEnemy, &nBattleFinished);

		system("cls");

		printBattleHeader();

		printBattleDisplay(*pPlayer, sEnemy, nEnemyTurn);

		if (!nEnemyTurn) {
			if (!nShowAttackTypes) {
				printTwoOptions(1, "ATTACK", 2, "DODGE");
				printCenterOption(3, "DRINK POTION");
			}

			else {
				printTwoOptions(1, "PHYSICAL", 2, "SORCERY");
				printTwoOptions(3, "INCANTATION", 0, "BACK");
			}
		}

		printFooter();
		printInputDivider();

		if (!nEnemyTurn) {
			if (!nShowAttackTypes) {
				getIntInput(&nMoveType, 1, 3);
			}
			else {
				getIntInput(&nAttackType, 0, 3);
			}
		}

		processBattleScreenInput(nAreaIndex, nMoveType, nAttackType, pPlayer, &sEnemy, 
				 				 &nEnemyTurn, nBattleFinished, &nShowAttackTypes);
	} while (!nBattleFinished);

	pressEnter();
}

void processBattleScreenInput(int nAreaIndex, int nMoveType, int nAttackType, Player* pPlayer, Enemy* pEnemy, 
							  int* pEnemyTurn, int nBattleFinished, int* pShowAttackTypes) {
	int nSuccessfulDodge = 0;

	if (*pEnemyTurn) {
		enemyAttack(pPlayer, *pEnemy);
		getIncomingDmg(nAreaIndex, pEnemy);
		Sleep(500);
		*pShowAttackTypes = 0;	
		*pEnemyTurn = 0;	
	}

	else if (!*pShowAttackTypes) {
		switch (nMoveType) {
			case 1: 
				*pShowAttackTypes = 1;
				break;

			case 2:
				nSuccessfulDodge = useDodge(*pPlayer);
				*pEnemyTurn = 1;
				pressEnter();
				break;

			case 3:
				drinkPotion(pPlayer);
				pressEnter();
				break;
		}
	}

	else if (*pShowAttackTypes) {
		switch (nAttackType) {
			case 0: 
				*pShowAttackTypes = 0;
				break;

			case 1:
				usePhysicalAttack(*pPlayer, pEnemy);
				*pEnemyTurn = 1;
				pressEnter();
				break;

			case 2:
				useSorceryAttack(*pPlayer, pEnemy);
				*pEnemyTurn = 1;
				pressEnter();
				break;

			case 3:
				useIncantationAttack(*pPlayer, pEnemy);
				*pEnemyTurn = 1;
				pressEnter();
				break;			
		}
	}
}



