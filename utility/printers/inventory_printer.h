#ifndef INVENTORY_PRINTER_H
#define INVENTORY_PRINTER_H

#define MAX_ROWS 3
#define MAX_COLUMNS 3
#define MAX_LINES 13

void printEmptyInventorySlot(int nLine);
void printWeaponSlots (Item* pPurchasedWeapon, int nSpriteLine);
void printInventoryList (int* pPage, Player* pPlayerInfo);
void printInventoryCommands ();
void printSellEquipmentPopUp ();
void printOpenEquipScreen ();
void EquipBox (int nSpriteLine, Item* pPurchasedWeapon);
void printEquipBox(Item* pPurchasedWeapon);

#endif