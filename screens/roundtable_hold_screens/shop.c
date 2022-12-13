#include "shop.h"

void openShop(Player* pPlayerInfo) {
	int nPage = 1;
	int nMinIndex = 1;
	int nMaxIndex = 4;
	int nInput = 0;
	do {
		system("cls");
		printMultiple("\n", SCREEN_PADDING_TOP);
		printMiddleText("SHOP", "", "");
		printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT);
		printMultiple("─", SCREEN_WIDTH);
		printf("\n\n");
		generateShopSlots(&nPage);
		printf("\n\t\tRUNES: %d", pPlayerInfo->nRunes);

		nMaxIndex = 4 * (nPage);
		nMinIndex = nMaxIndex - 3;
		
		printShopCommands();

		printFooter();
		printInputDivider();

		getIntInput(&nInput, 0, 3);
		processShopInput(pPlayerInfo, nInput, &nPage, &nMinIndex, &nMaxIndex);

	} while (nInput != 0);
}

void processShopInput(Player* pPlayerInfo, int nShopInput, int* pPage, int* pMinIndex, int* pMaxIndex) {
	switch (nShopInput){
		case 1:
			selectbuyWeapon(pPlayerInfo, pPage, pMinIndex, pMaxIndex);
			break;
		case 2:
			if (*pPage + 1 < 7){
				*pPage = *pPage + 1;
			}
			break;
		case 3:
			if (*pPage - 1 > 0){
				*pPage = *pPage - 1;
			}
			break;
	}
}
void selectbuyWeapon(Player* pPlayerInfo, int* pPage, int* pMinIndex, int* pMaxIndex) {
	int nInput = *pMinIndex;
	Item* pIdentifyWeapon;
	do {
		system("cls");
		printMultiple("\n", SCREEN_PADDING_TOP);
		printMiddleText("SHOP", "", "");
		printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT);
		printMultiple("─", SCREEN_WIDTH);
		printf("\n\n");
		generateShopSlots(pPage);
		printf("\n\t\tRUNES: %d", pPlayerInfo->nRunes);
		printSelectWeaponToBuy();

		printFooter();
		printInputDivider();

		getIntInput(&nInput, *pMinIndex, *pMaxIndex);

		if (nInput <= *pMaxIndex && nInput >= *pMinIndex){
			pIdentifyWeapon = setWeapon(nInput);
			openBuyScreen (pPlayerInfo, pIdentifyWeapon, &nInput);
		}

	} while (nInput > 0 &&nInput < 24);
}



void openBuyScreen (Player* pPlayerInfo, Item* pPurchasedWeapon, int* pSelectedWeapon){
	int nInput = 0;
	do {
			system("cls");
			printMultiple("\n", SCREEN_PADDING_TOP);
			printMiddleText("SHOP", "", "");
			printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT);
			printMultiple("─", SCREEN_WIDTH);
			printf("\n\n");
			printShopBox(pPurchasedWeapon);
			printTwoLongOptions(1, "Confirm Purchase", 0, "Back");
			getIntInput(&nInput, 0, 1);

			printFooter();
			printInputDivider();

			processBuyScreenInput(&nInput, pPlayerInfo, pPurchasedWeapon, pSelectedWeapon);
	}while (nInput < 0 || nInput > 1);
}

void processBuyScreenInput(int* pInput, Player* pPlayerInfo, Item* pPurchasedWeapon, int* pSelectedWeapon) {
	switch (*pInput){
		case 1:
			if (pPlayerInfo->nRunes - pPurchasedWeapon->pWeaponStats->nCost >= 0){ 
				Item* pPlayerBoughtWeapon;
				pPlayerBoughtWeapon = setWeapon(*pSelectedWeapon);   
				pPlayerInfo->nRunes = pPlayerInfo->nRunes - pPlayerBoughtWeapon->pWeaponStats->nCost;
				printf("\n\t\tYou have successfully purchased %s\n", pPlayerBoughtWeapon->pWeaponStats->strWeaponName);
				addWeapon(pPlayerBoughtWeapon, &pPlayerInfo->pInventory);
				pressEnter();  
			}
			else{
				printf("\n\t\tYou don't have enough RUNES to purchase this weapon.\n");
				pressEnter();
			}
			break;
		case 0:
			printf("\n\t\tNothing was bought.\n");
			pressEnter();
	}
	 
}

Item* setWeapon (int nWeaponIndex){
	Item* pPurchasedWeapon = malloc(sizeof(Item));
	pPurchasedWeapon->pWeaponStats = loadWeapon(nWeaponIndex);
	pPurchasedWeapon->pPrev = NULL;
	pPurchasedWeapon->pNext = NULL;
	return pPurchasedWeapon;
}

/* Let pInventoryHead be the inventory head of the inventory list
   Let pPurchasedWeapon be the newly purchased weapon to be added
   to the Inventory list. */

void addWeapon (Item* pPurchasedWeapon, Item** pInventoryHead){
	// make a variable to store the Head or ACCESS point of the linked list
	Item* pLatestEntry;

	// check if pInventoryHead is NULL, if so, we should assign it a value.
	// This value will be the first purchased item by the player
	if (*pInventoryHead == NULL){
		*pInventoryHead = pPurchasedWeapon;
		// make the index of the InventoryHead to 1;
		(*pInventoryHead)->pWeaponStats->nInventoryIndex = 1;
	}
	// If pInventoryHead already has a value or content, we then place this value inside a variable. 
	// This is so that we may be able to access the list.
	else {
		// we assign pInventoryHead to pLatestEntry
		pLatestEntry = *pInventoryHead;
		// we then travel through the list to find the end point
		while (pLatestEntry->pNext != NULL){
			//once we find the end point, the we assign the value of pLatestEntry->pNext to the list that is pLatestEntry 
			pLatestEntry = pLatestEntry->pNext;
		}
		// adds the Inventory index of pLatest entry by 1 and passes this to pPurchasedWeapon or the newly bought weapon
		pPurchasedWeapon->pWeaponStats->nInventoryIndex = pLatestEntry->pWeaponStats->nInventoryIndex + 1;
		// we then assign pLatestEntry's pNext link to the pPurchasedWeapon Node
		pLatestEntry->pNext = pPurchasedWeapon;

		// we then assign pPurchasedWeapon's pPrev link to pLatestEntry Node
		pPurchasedWeapon->pPrev = pLatestEntry;
	}
}