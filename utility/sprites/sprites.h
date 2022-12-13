#ifndef SPRITES_H
#define SPRITES_H

#define SPRITE_HEIGHT  9
#define SPRITE_WIDTH  15

void printPlayerSprite(int nSpriteLine, Player sPlayer);
void printEnemySprite(int nSpriteLine, int nAreaIndex, Enemy sEnemy);

void printTopBottomSpriteBorders(int nLine);

void printRunes(int nLine);

#endif
