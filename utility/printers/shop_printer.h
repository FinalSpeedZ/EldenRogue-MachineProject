#ifndef SHOP_PRINTER_H
#define SHOP_PRINTER_H

void generateShopSlots(int* pPage);
void printSelectWeaponToBuy ();
void printShopCommands();
void ShopBox (int nSpriteLine, Item* pPurchasedWeapon);
void printShopBox(Item* pPurchasedWeapon) ;

#endif