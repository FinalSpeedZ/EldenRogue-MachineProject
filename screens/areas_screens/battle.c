/****************************************
File Name: battle.c

Contains the main battle functions
****************************************/
#include "battle.h"

/*
	openBattleScreen      Opens the battle screen where player battles against an enemy

	@param nAreaIndex     Contains the specific area that will be opened
	@param pPlayer        A pointer to the Player structure
	@param pEnemy         A pointer to the Enemy structure
	@param nBoss          An int determing whether player is fighting against boss

	return nWon           An int determining if player won or lost
*/
int openBattleScreen(int nAreaIndex, Player* pPlayer, Enemy* pEnemy, int nBoss) {
	// VARIABLE DECLARATIONS
	int nMoveType = 1;
	int nAttackType = 0;
	int nShowAttackTypes = 0;
	int nWon = 0;

	// if battle is finished
	int nBattleFinished = 0;

	// whose turn it is
	int nEnemyTurn = 0;

	// if successfully dodged
	int nSuccessfulDodge = 0;

	do {
		checkBattleOver(*pPlayer, *pEnemy, &nBattleFinished);

		system("cls");

		printBattleHeader();

		printBattleDisplay(*pPlayer, *pEnemy, nAreaIndex, nEnemyTurn, nBoss);

		// show options only if it is player turn and battle is not over
		if (!nEnemyTurn && !nBattleFinished) {
			if (!nShowAttackTypes) {
				printTwoOptions(1, "ATTACK", 2, "DODGE");
				printCenterOption(3, "DRINK POTION");
			}

			else {
				// this means player inputted attack previously and show them the attack types
				printTwoOptions(1, "PHYSICAL", 2, "SORCERY");
				printTwoOptions(3, "INCANTATION", 0, "BACK");
			}
		}

		printFooter();

		// get input only if it is player turn and battle is not over
		if (!nEnemyTurn && !nBattleFinished) {
			printInputDivider();
			if (!nShowAttackTypes) {
				getIntInput(&nMoveType, 1, 3);
			}
			else {
				getIntInput(&nAttackType, 0, 3);
			}
		}

		// only process input if battle is not over
		if (!nBattleFinished) {
			processBattleScreenInput(nAreaIndex, nMoveType, nAttackType, pPlayer, pEnemy, 
				 					 nBoss, &nEnemyTurn, &nShowAttackTypes, &nSuccessfulDodge);
		}

	} while (!nBattleFinished);


	Sleep(3000);

	// player lost
	if (nBattleFinished == 1) { 
		openLostScreen(pPlayer);
		nWon = 0;
	}

	// player won
	else {
		openWinScreen(pPlayer, *pEnemy, nBoss);
		nWon = 1;
	}

	return nWon;
}


/*
	processBattleScreenInput      Processes the input of the user from battle screen

	@param nAreaIndex             Contains the specific area that will be opened
	@param nMoveType              An int determing what move type the player used
	@param nAttackTyoe            An int determing what attack type the player used
	@param pPlayer                A pointer to the player structure
	@param pEnemy                 A pointer to the enemy structure
	@param nBoss                  An int determining whether enemy is a boss
	@param pEnemyTurn             A pointer to an int determining whose turn it is
	@param pShowAttackType        A pointer to an int determining if we should show attack types ot player
	@param pSuccessfulDodge       A pointer to an int determining if the player dodged the enemy
*/
void processBattleScreenInput(int nAreaIndex, int nMoveType, int nAttackType, Player* pPlayer, Enemy* pEnemy, 
							  int nBoss, int* pEnemyTurn, int* pShowAttackTypes, int* pSuccessfulDodge) {
	// health to be gained by player when drinking potion
	int nHealthGained;

	// if enemyturn
	if (*pEnemyTurn) {
		// and player did not successfully dodged
		if (*pSuccessfulDodge == 0) {
			// enemy attacks
			enemyAttack(pPlayer, *pEnemy);
			printBattleDmgPrompter(pEnemy->pEnemyName, pEnemy->nFinalAttack);
		}
		else {
			// if player dodged
			printMessage("PROMPT", "YOU DODGED THE ENEMY'S ATTACK");
		}
		// get new incoming damage of enemy
		getIncomingDmg(nAreaIndex, pEnemy, nBoss);
		pressEnter();
		*pShowAttackTypes = 0;
		// it is now player's turn	
		*pEnemyTurn = 0;	
	}

	// if not attack types
	else if (!*pShowAttackTypes) {
		switch (nMoveType) {
			case 1: 
				// if player chooses attack option
				*pShowAttackTypes = 1;
				break;

			case 2:
				// if player chooses dodge
				*pSuccessfulDodge = useDodge(*pPlayer);
				*pEnemyTurn = 1;
				pressEnter();
				break;

			case 3:
				// if player drinks a potion
				nHealthGained = healthToBeAdded(pPlayer);
				drinkPotion(pPlayer, nHealthGained);
				if (nHealthGained != 0) {
					printBattleHealPrompter(nHealthGained);
				}
				else {
					// if no health was gained player was full health
					printMessage("PROMPT", "YOU ARE FULLY HEALED");
				}
				pressEnter();
				break;
		}
	}

	// if show attack types
	else if (*pShowAttackTypes) {
		switch (nAttackType) {
			case 0: 
				// back to move options (attack, dodge, etc)
				*pShowAttackTypes = 0;
				break;

			case 1:
				// player physical atk
				usePhysicalAttack(*pPlayer, pEnemy);
				printBattleDmgPrompter("YOU", getPlayerPhysicalDmg(*pPlayer, *pEnemy));
				// it is now enemy's turn
				*pEnemyTurn = 1;
				pressEnter();
				break;

			case 2:
				// player sorcery atk
				useSorceryAttack(*pPlayer, pEnemy);
				printBattleDmgPrompter("YOU", getPlayerSorceryDmg(*pPlayer, *pEnemy));
				// it is now enemy's turn
				*pEnemyTurn = 1;
				pressEnter();
				break;

			case 3:
				// player incantation atk
				useIncantationAttack(*pPlayer, pEnemy);
				printBattleDmgPrompter("YOU", getPlayerIncantationDmg(*pPlayer, *pEnemy));
				// it is now enemy's turn
				*pEnemyTurn = 1;
				pressEnter();
				break;			
		}
	}
}

/*
	openWinScreen      Opens a screen signifying player won

	@param pPlayer     A pointer to the player structure
	@param sEnemy      The enemy structure that the player recently faced
	@param nBoss       Checks if it is a boss fight or not
*/
void openWinScreen(Player* pPlayer, Enemy sEnemy, int nBoss) {
	// runes to be gained by winning
	int nRunesGained = computeGainedRunes(sEnemy, nBoss);

	system("cls");

	printBattleHeader();

	printBattleRunesGained(*pPlayer, nRunesGained, nBoss);

	// add the runes to player runes
	pPlayer->nRunes += nRunesGained;

	printFooter();
	printInputDivider();

	pressEnter();
}

/*
	openLostScreen     Opens a screen signifying player lost

	@param pPlayer     A pointer to the player structure
*/
void openLostScreen(Player *pPlayer) {
	system("cls");

	printBattleHeader();

	printRunesLost();

	resetRunes(&pPlayer->nRunes);

	printFooter();
	printInputDivider();

	pressEnter();	
}

