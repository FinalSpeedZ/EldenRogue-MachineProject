#ifndef SHOP_H
#define SHOP_H

void openShop ();
void processShopInput (Player* pPlayerInfo, int nShopInput, int* pPage, int* pMinIndex, int* pMaxIndex);
void selectbuyWeapon (Player* pPlayerInfo, int* pPage, int* pMinIndex, int* pMaxIndex);
void openBuyScreen (Player* pPlayerInfo, Item* pPurchasedWeapon, int* pSelectedWeapon);
void processBuyScreenInput(int* pInput, Player* pPlayerInfo, Item* pPurchasedWeapon, int* pSelectedWeapon);
Item* setWeapon (int nWeaponIndex);
void addWeapon (Item* pPurchasedWeapon, Item** pInventoryHead);

#endif