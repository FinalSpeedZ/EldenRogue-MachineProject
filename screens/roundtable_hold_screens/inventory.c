#include "inventory.h"

void openInventory(Player* pPlayerInfo) {
	int nInput = 0;
	int nPage = 1;
	int nMinIndex = 1;
	int nMaxIndex = 9;

	do {
		system("cls");
		printMultiple("\n", SCREEN_PADDING_TOP);
		printMiddleText("INVENTORY", "", "");
		printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT);
		printMultiple("─", SCREEN_WIDTH);
		printf("\n\n");
		printInventoryList (&nPage, pPlayerInfo);
		printf("\n\t\tRUNES: %d", pPlayerInfo->nRunes);
		if (pPlayerInfo->sPlayerEquipment.pCurrentWeapon != NULL){
			printf("\n\t\tEquipped Weapon: %s", pPlayerInfo->sPlayerEquipment.pCurrentWeapon->pWeaponStats->strWeaponName);
		}
		else{
			printf("\n\t\tYou have nothing equipped");
		}
		nMaxIndex = 9 * (nPage);
		nMinIndex = nMaxIndex - 8;
		printInventoryCommands();

		printFooter();
		printInputDivider();

		getIntInput(&nInput, 0, 4);
		processInventoryInput(pPlayerInfo, nInput, &nPage, &nMinIndex, &nMaxIndex);

	} while (nInput != 0);
}

void openSelectScreen (Player* pPlayerInfo, int* pPage, int* pMinIndex, int* pMaxIndex){
	int nInput = 1;
	int nValidIndex = countFilledSlots(pPlayerInfo, pMinIndex, pMaxIndex);

	do {
		system("cls");
		printMultiple("\n", SCREEN_PADDING_TOP);
		printMiddleText("INVENTORY", "", "");
		printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT);
		printMultiple("─", SCREEN_WIDTH);
		printf("\n\n");
		printInventoryList (pPage, pPlayerInfo);
		printf("\n\t\tRUNES: %d", pPlayerInfo->nRunes);

		if (pPlayerInfo->sPlayerEquipment.pCurrentWeapon != NULL){
			printf("\n\t\tEquipped Weapon: %s\n\n", pPlayerInfo->sPlayerEquipment.pCurrentWeapon->pWeaponStats->strWeaponName);
		}
		else{
			printf("\n\t\tYou have nothing equipped.\n\n");
		}

		printFooter();
		printInputDivider();

		printf("\n\t\tChoose a Weapon from Your Inventory.\n\n");
		getIntInput(&nInput, *pMinIndex, *pMaxIndex);

		if (nInput <= nValidIndex && nInput >= *pMinIndex){
			openSellEquipScreen(pPlayerInfo, &nInput);
		}
		else if ((nInput > nValidIndex || nInput < *pMinIndex) && nInput != 0){
			printf("\n\t\tThere's nothing there..\n");
			pressEnter();
		}
	} while (nInput > 0);
}

void openSellEquipScreen(Player* pPlayerInfo, int* pSelectedWeapon) {
	int nInput = 0;
	do {

			system("cls");
			Item* pSelectWeapon = findSelectWeapon(pPlayerInfo, pSelectedWeapon);
			printEquipBox(pSelectWeapon);
			printSellEquipmentPopUp();
			getIntInput(&nInput, 0, 2);

			printFooter();
			printInputDivider();
			processSellEquipInput(pPlayerInfo, pSelectedWeapon, &nInput);
		

	} while (nInput < 0 || nInput > 2);
}

void processInventoryInput(Player* pPlayerInfo, int nInput, int* pPage, int* pMinIndex, int* pMaxIndex) {	
	switch (nInput){
		case 1:
			openSelectScreen (pPlayerInfo, pPage, pMinIndex, pMaxIndex);
			break;
		case 2:
			unequipWeapon(pPlayerInfo);
			break;
		case 3:
			checkNextPage(pPlayerInfo, pPage, pMaxIndex);
			break;
		case 4:
			if (*pPage - 1 > 0){
				*pPage = *pPage - 1;
			}
			break;
	}
}

void processSellEquipInput(Player* pPlayerInfo, int* pSelectedWeapon, int* pInput) {
	switch (*pInput){
		case 1: 
			if (pPlayerInfo->sPlayerEquipment.pCurrentWeapon == NULL){
				equipWeapon(pPlayerInfo, pSelectedWeapon);
			}
			else{
				printf("\n\t\tYou already have a weapon equipped!\n");
				pressEnter();
			}
			break;
		case 2:
			sellWeapon(pPlayerInfo, pSelectedWeapon);
			break;
	}
}

void checkNextPage(Player* pPlayerInfo, int* pPage, int* pMaxIndex) {
	int nTotalWeapon = countTotalWeapons(pPlayerInfo);
	if (nTotalWeapon - *pMaxIndex > 0){
		*pPage = *pPage + 1;
	}
	else {
		*pPage = *pPage + 0;
	}
}

int countTotalWeapons(Player* pPlayerInfo){
	Item* pWeaponSlot = pPlayerInfo->pInventory;
	int nWeaponCount = 0;
	while (pWeaponSlot != NULL){
		pWeaponSlot = pWeaponSlot->pNext;
		nWeaponCount++;
	}
	return nWeaponCount;
}

int countFilledSlots(Player *pPlayerInfo, int* pMinIndex, int* pMaxIndex) {
	Item* pWeaponSlot = pPlayerInfo->pInventory;
	int nFilledSlots = *pMinIndex - 1; 
	while (pWeaponSlot != NULL && nFilledSlots < *pMaxIndex){
		pWeaponSlot = pWeaponSlot->pNext;
		nFilledSlots++;
	}
	return nFilledSlots;
}

Item* findSelectWeapon(Player* pPlayerInfo, int* pIndex) { 
	Item* pSelectedWeapon = pPlayerInfo->pInventory;
	while (pSelectedWeapon->pWeaponStats->nInventoryIndex != *pIndex){
		pSelectedWeapon = pSelectedWeapon->pNext;
	}
	return pSelectedWeapon;
}


void equipWeapon(Player* pPlayerInfo, int* pSelectedWeapon) {
	//find weapon to be equipped and transfer its contents into 
	Item* pToBeRemovedWeapon =  findSelectWeapon(pPlayerInfo, pSelectedWeapon);
	Item* pEquippedWeapon = setWeapon(pToBeRemovedWeapon->pWeaponStats->nWeaponType);
	if (pPlayerInfo->sPlayerStats.nDexterity >= pEquippedWeapon->pWeaponStats->nWeaponDexterity){
		// if player has more or equal dexterity needed to equip weapon, transfer values of the selected weapon

		pPlayerInfo->sPlayerEquipment.pCurrentWeapon = pEquippedWeapon;
		printf("\n\t\tYou have successfully equipped %s\n", pPlayerInfo->sPlayerEquipment.pCurrentWeapon->pWeaponStats->strWeaponName);
		removeWeapon(pToBeRemovedWeapon, &pPlayerInfo->pInventory);
		pressEnter();
	}
	else{
		printf("\n\t\tYou don't have enough Dexterity to equip this!\n");
		pressEnter();
	}
}


void unequipWeapon(Player* pPlayerInfo) {
	Item* pEquippedWeapon;
	if (pPlayerInfo->sPlayerEquipment.pCurrentWeapon != NULL){
		pPlayerInfo->sPlayerEquipment.pCurrentWeapon->pWeaponStats->nInventoryIndex = 0;
		pEquippedWeapon = pPlayerInfo->sPlayerEquipment.pCurrentWeapon;

		pPlayerInfo->sPlayerEquipment.pCurrentWeapon = NULL;

		addWeapon(pEquippedWeapon, &pPlayerInfo->pInventory);
	}
	else {
		printf("\n\t\tYou don't have any weapons!\n");
		pressEnter();
	}
}

void sellWeapon(Player* pPlayerInfo, int* pSelectedWeapon) {
	Item* pRemovedWeapon = findSelectWeapon(pPlayerInfo, pSelectedWeapon);
	pPlayerInfo->nRunes = pPlayerInfo->nRunes + (pRemovedWeapon->pWeaponStats->nCost/2);
	removeWeapon(pRemovedWeapon, &pPlayerInfo->pInventory);
}

void removeWeapon(Item* pSelectedWeapon, Item** pInventoryHead) {
	//condition for if the selected weapon to be removed is the head
	if (pSelectedWeapon == *pInventoryHead){
		if (pSelectedWeapon->pNext != NULL){
			// assogn pInventoryHead to the next Node of the selected item to be removed
			*pInventoryHead = pSelectedWeapon->pNext;
			(*pInventoryHead)->pPrev = NULL;
			while (pSelectedWeapon != NULL){
				pSelectedWeapon->pWeaponStats->nInventoryIndex--;
				pSelectedWeapon = pSelectedWeapon->pNext;
			}
		}
		else {
			*pInventoryHead = NULL;
		}
	}
	//condition for if the selected weapon to be removed isn't the head
	else {
		if (pSelectedWeapon->pNext != NULL){
			pSelectedWeapon->pPrev->pNext = pSelectedWeapon->pNext; 
			pSelectedWeapon->pNext->pPrev = pSelectedWeapon->pPrev;
			while(pSelectedWeapon != NULL){
				pSelectedWeapon->pWeaponStats->nInventoryIndex--;
				pSelectedWeapon = pSelectedWeapon->pNext;

			}
		}
		else if (pSelectedWeapon->pPrev != NULL){
			pSelectedWeapon->pPrev->pNext = NULL;
		}

	}		
	free (pSelectedWeapon);
}
