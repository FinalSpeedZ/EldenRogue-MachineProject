#include "inventory_printer.h"

void printEmptyInventorySlot(int nLine) {
	switch (nLine) {
		case 0:
			printf("╔══════════════════╗ ");
			break;
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
			printf("│                  │ ");
			break;
		case 12: 
			printf("╚══════════════════╝ ");
			break;
		
	}
}
void printWeaponSlots (Item* pPurchasedWeapon, int nSpriteLine) {
	switch (pPurchasedWeapon->pWeaponStats->nWeaponType){
		case SHORT_SWORD:
		case ROGIER_RAPIER:
		case CODED_SWORD:
		case SWORD_OF_NIGHT_AND_FIRE:
			printShortSwordSlot(nSpriteLine, pPurchasedWeapon->pWeaponStats->nInventoryIndex);
			break;
		case UCHIGATANA:
		case MOONVEIL:
		case RIVERS_OF_BLOOD:
		case HAND_OF_MALENIA:
			printUchigatana(nSpriteLine, pPurchasedWeapon->pWeaponStats->nInventoryIndex);
			break;	
		case BASE_WHIP:
		case URUMI:
		case THORNED_WHIP:
		case HOSLOW_PETAL_WHIP:
			printBasic_Whip(nSpriteLine, pPurchasedWeapon->pWeaponStats->nInventoryIndex);
			break;
		case CLAYMORE:
		case STARSCOURGE_GREATSWORD:
		case INSEPARABLE_SWORD:
		case MALIKETH_BLACK_BLADE:
			printClaymore(nSpriteLine, pPurchasedWeapon->pWeaponStats->nInventoryIndex);
			break;
		case ASTROLOGER_STAFF:
		case ALBINAURIC_STAFF:
		case STAFF_OF_THE_GUILTY:
		case CARIAN_REGAL_SCEPTER:
			printAstrologerStaff(nSpriteLine, pPurchasedWeapon->pWeaponStats->nInventoryIndex);
			break;
		case FINGER_SEAL:
		case GODSLAYER_SEAL:
		case GOLDEN_ORDEAL_SEAL:
		case DRAGON_COMMUNION_SEAL:
			printFingerSeal(nSpriteLine, pPurchasedWeapon->pWeaponStats->nInventoryIndex);
			break;
	} 
}

void printInventoryList (int* pPage, Player* pPlayerInfo){
	int nBoxNumber, nRowCount, nColumnCount, nLine;
	int nPadding = SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT + ((SCREEN_WIDTH	- 16 * MAX_COLUMNS) / 2);
	// store the inventory head in another variable
	Item* pInventoryHead = pPlayerInfo->pInventory;
	// make another variable to hold the pNext values of the linked list
	Item* pInventoryContent;

	// offsets the linked list for when Player goes to the next Page.
	for (nBoxNumber = 0; nBoxNumber < 9 * (*pPage - 1); nBoxNumber++){
		// assign the value of pInventory->pNext to pInventoryHead as the loop travels through the list
		pInventoryHead = pInventoryHead->pNext;
	}

	// print the total number of rows
	for (nRowCount = 0; nRowCount < MAX_ROWS; nRowCount++){
		// print the total number of lines for each graphic
		for (nLine = 0; nLine < MAX_LINES; nLine++){
			printMultiple(" ", nPadding);
			pInventoryContent = pInventoryHead;
			// print the total number of columns
			for (nColumnCount = 0; nColumnCount < MAX_COLUMNS; nColumnCount++){
				// if pInventoryHead doesn't contain NULL, print the contents.
				if (pInventoryHead != NULL){
					// check if pInventoryContents contains a value or not if so, print the graphic, pass the value of pInventoryContents
					if (pInventoryContent != NULL){
						printWeaponSlots(pInventoryContent, nLine);
						pInventoryContent = pInventoryContent->pNext;
					}
					// if not print the graphic for empty slot
					else {
						printEmptyInventorySlot(nLine);
					}
				}
				// if pInventoryHead contains NULL, print empty slots.
				else{
					printEmptyInventorySlot(nLine);
				}
			}
			printf("\n");
		}
		printf("\n");
		for (nColumnCount = 0; nColumnCount < MAX_COLUMNS; nColumnCount++){
			if (pInventoryHead != NULL){
				pInventoryHead = pInventoryHead->pNext;
			}
		}
	}

}


void printInventoryCommands (){
	printf("\n\t\t[1] SELECT");
	printf("\n\t\t[2] UNEQUIP EQUIPPED WEAPON");
	printf("\n\t\t[3] NEXT PAGE");
	printf("\n\t\t[4] PREVIOUS PAGE");
	printf("\n\t\t[0] BACK");
	printf("\n\n");
}

void printSellEquipmentPopUp (){
	printf("\n\t\tWhat do you wish to do with the selected weapon?");
	printf("\n\t\t[1] Equip");
	printf("\n\t\t[2] Sell");
	printf("\n\t\t[0] Back");
}


void EquipBox (int nSpriteLine, Item* pPurchasedWeapon) {
	int nOffset = (26 - strlen(pPurchasedWeapon->pWeaponStats->strWeaponName) - 1)/2;

	switch(nSpriteLine) {
		case 0:
			printf("╔════════════════════════╗ ");

			break;
		case 1:
			printMultiple(" ", nOffset);
			printf("%s", pPurchasedWeapon->pWeaponStats->strWeaponName);
			printMultiple(" ", nOffset);
			break;
		case 2: 
			printMultiple(" ", 3);
			printf("------------------");
			printMultiple(" ", 3);
			break;
		case 3:
			printMultiple(" ", 4);
			printf("SELL PRICE: %.5d", pPurchasedWeapon->pWeaponStats->nCost/2);
			printMultiple(" ", 4);
			break;
		case 4:
			printMultiple(" ", 3);
			printf("------------------");
			printMultiple(" ", 3);
			break;
		case 5:
			printMultiple(" ", 24);
			break;
		case 6:
			printMultiple(" ", 4);
			printf("DEX NEEDED: %.2d", pPurchasedWeapon->pWeaponStats->nWeaponDexterity);
			printMultiple(" ", 6);
			break;
		case 7:
			printMultiple(" ", 24);
			break;
		case 8:
			printMultiple(" ", 2);
			printf("HP: %.2d", pPurchasedWeapon->pWeaponStats->nWeaponHealth);
			printMultiple(" ", 6);
			printf("END: %.2d", pPurchasedWeapon->pWeaponStats->nWeaponEndurance);
			printMultiple(" ", 3);
			break;
		case 9:
			printMultiple(" ", 2);
			printf("DEX: %.2d", pPurchasedWeapon->pWeaponStats->nWeaponDexterity);
			printMultiple(" ", 5);
			printf("STR: %.2d", pPurchasedWeapon->pWeaponStats->nWeaponStrength);
			printMultiple(" ", 3);
			break;
		case 10: 
			printMultiple(" ", 2);
			printf("INT: %.2d",pPurchasedWeapon->pWeaponStats->nWeaponDexterity);
			printMultiple(" ", 5);
			printf("FTH: %.2d",pPurchasedWeapon->pWeaponStats->nWeaponStrength);
			printMultiple(" ", 3);
			break;
		case 11:
			printMultiple(" ", 24);
			break;
		case 12:
			printf("╚════════════════════════╝ ");
			break;
	}
}

void printEquipBox(Item* pPurchasedWeapon) {
	int nCounter;
	int nPadding = SCREEN_PADDING_LEFT + (SCREEN_WIDTH - 15*4)/2;

	for (nCounter = 0; nCounter < 13; nCounter++){
		printMultiple(" ", nPadding);
		EquipBox(nCounter, pPurchasedWeapon);
		printf("\n");
	}
	printf("\n");
}