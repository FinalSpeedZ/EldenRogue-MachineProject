#ifndef INVENTORY_H
#define INVENTORY_H

void openInventory (Player* pPlayerInfo);


void openSelectScreen (Player* pPlayerInfo, int* pPage, int* pMinIndex, int* pMaxIndex);

void processInventoryInput(Player* pPlayerInfo, int nInput, int* pPage, int* pMinIndex, int* pMaxIndex);
void processSellEquipInput(Player* pPlayerInfo, int* pSelectedWeapon, int* pInput);

void checkNextPage (Player* pPlayerInfo, int* pPage, int* pMaxIndex);
int countTotalWeapons(Player* pPlayerInfo);
int countFilledSlots (Player *pPlayerInfo, int* pMinIndex, int* pMaxIndex);

Item* findSelectWeapon (Player* pPlayerInfo, int* pIndex);

void openSellEquipScreen (Player* pPlayerInfo, int* pSelectedWeapon);


void equipWeapon (Player* pPlayerInfo, int* pSelectedWeapon);
void unequipWeapon (Player* pPlayerInfo);

void sellWeapon (Player* pPlayerInfo, int* pSelectedWeapon);
void removeWeapon (Item* pSelectedWeapon, Item** pInventoryHead);


#endif