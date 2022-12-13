#include "shop_printer.h"

void generateShopSlots (int* pPage){
	int nRowCounter;
	int nColumnCounter;
	int nLine; 
	//int nIndex;
	int nShopIndex;
	int aShopSlot[24] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};

	int nPadding = SCREEN_PADDING_LEFT + (SCREEN_WIDTH - 14*4)/2;
	// the for loop will print 4 instances of slots per page //

	for (nRowCounter = 0; nRowCounter < 1; nRowCounter++) {
		// prints lines
		for (nLine = 0; nLine < 14; nLine++){
			printMultiple(" ", nPadding);
			// prints columns
			for (nColumnCounter = 0; nColumnCounter <  4; nColumnCounter++) {
					nShopIndex = aShopSlot[nColumnCounter] + (4 * (*pPage - 1));
					getWeaponSprites(nShopIndex, nLine);
			}
			printf("\n");
		}
		printf("\n");
	}
}

void printSelectWeaponToBuy (){
	printf("\n\t\tWhich Weapon do you wish to purchase?\n");
}

void printShopCommands (){
	printf("\n\t\t[1] BUY WEAPONS");
	printf("\n\t\t[2] NEXT PAGE");
	printf("\n\t\t[3] PREVIOUS PAGE\n\n");
}

void ShopBox (int nSpriteLine, Item* pPurchasedWeapon) {
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
			printf("COST: %.5d", pPurchasedWeapon->pWeaponStats->nCost);
			printMultiple(" ", 9);
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

void printShopBox(Item* pPurchasedWeapon) {
	int nCounter;
	int nPadding = SCREEN_PADDING_LEFT + (SCREEN_WIDTH - 15*4)/2;

	for (nCounter = 0; nCounter < 13; nCounter++){
		printMultiple(" ", nPadding);
		ShopBox(nCounter, pPurchasedWeapon);
		printf("\n");
	}
	printf("\n");
}