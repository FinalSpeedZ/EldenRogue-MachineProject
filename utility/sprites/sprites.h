#ifndef SPRITES_H
#define SPRITES_H

#define SPRITE_HEIGHT  9
#define SPRITE_WIDTH  15

void printPlayerSprite(int nSpriteLine, Player sPlayer);
void printEnemySprite(int nSpriteLine, int nAreaIndex, Enemy sEnemy);

void printTopBottomSpriteBorders(int nLine);

void printRunes(int nLine);

void printShortSwordSlot(int nSpriteLine, int nWeaponIndex);
void printRogierRapier (int nSpriteLine, int nWeaponIndex);
void printUchigatana(int nSpriteLine, int nWeaponIndex);
void printBasic_Whip (int nSpriteLine, int nWeaponIndex);
void printClaymore (int nSpriteLine, int nWeaponIndex);
void printAstrologerStaff(int nSpireLine, int nWeaponIndex);
void printFingerSeal(int nSpriteLine, int nWeaponIndex);
void getWeaponSprites (int nWeaponIndex, int nSpriteLine); 

#endif