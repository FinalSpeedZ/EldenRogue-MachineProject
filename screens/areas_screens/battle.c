#include "battle.h"

int openBattleScreen(int nAreaIndex, Player* pPlayer, Enemy* pEnemy, int nBoss) {
	int nMoveType = 1;
	int nAttackType = 0;
	int nShowAttackTypes = 0;
	int nBattleFinished = 0;
	int nEnemyTurn = 0;
	int nSuccessfulDodge = 0;

	do {
		checkBattleOver(*pPlayer, *pEnemy, &nBattleFinished);

		system("cls");

		printBattleHeader();

		printBattleDisplay(*pPlayer, *pEnemy, nEnemyTurn, nBoss);

		if (!nEnemyTurn && !nBattleFinished) {
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

		if (!nEnemyTurn && !nBattleFinished) {
			printInputDivider();
			if (!nShowAttackTypes) {
				getIntInput(&nMoveType, 1, 3);
			}
			else {
				getIntInput(&nAttackType, 0, 3);
			}
		}

		if (!nBattleFinished) {
			processBattleScreenInput(nAreaIndex, nMoveType, nAttackType, pPlayer, pEnemy, 
				 					 &nEnemyTurn, nBattleFinished, &nShowAttackTypes, &nSuccessfulDodge);
		}

	} while (!nBattleFinished);

	Sleep(3000);

	if (nBattleFinished == 1) { 
		openLostScreen(pPlayer);
		return 0;
	}

	else {
		openWinScreen(pPlayer, *pEnemy, nBoss);
		return 1;
	}
}

void processBattleScreenInput(int nAreaIndex, int nMoveType, int nAttackType, Player* pPlayer, Enemy* pEnemy, 
							  int* pEnemyTurn, int nBattleFinished, int* pShowAttackTypes, int* pSuccessfulDodge) {

	if (*pEnemyTurn) {
		if (*pSuccessfulDodge == 0) {
			enemyAttack(pPlayer, *pEnemy);
		}
		else {
			printMessage("PROMPT", "YOU DODGED THE ENEMY'S ATTACK");
			pressEnter();
		}
		getIncomingDmg(nAreaIndex, pEnemy);
		Sleep(2000);
		*pShowAttackTypes = 0;	
		*pEnemyTurn = 0;	
	}

	else if (!*pShowAttackTypes) {
		switch (nMoveType) {
			case 1: 
				*pShowAttackTypes = 1;
				break;

			case 2:
				*pSuccessfulDodge = useDodge(*pPlayer);
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

void openWinScreen(Player* pPlayer, Enemy sEnemy, int nBoss) {
	int nRunesGained = computeGainedRunes(sEnemy, nBoss);

	system("cls");

	printBattleHeader();

	printRunesGained(*pPlayer, nRunesGained);

	pPlayer->nRunes += nRunesGained;

	printFooter();
	printInputDivider();

	pressEnter();
}

void openLostScreen(Player *pPlayer) {
	system("cls");

	printBattleHeader();

	printRunesLost();

	resetRunes(&pPlayer->nRunes);

	printFooter();
	printInputDivider();

	pressEnter();	
}

