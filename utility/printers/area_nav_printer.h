#ifndef AREA_NAV_PRINTER_H
#define AREA_NAV_PRINTER_H

#define NAV_HEIGHT  14
#define NAV_WIDTH   70

void printAreaNav(Player* pPlayer);
void printAreaNavLine(int nLine, int nOffset, Player* pPlayer);
void printAreaNavEnd(int nLine, int nOffset);
void printTopBottomSpriteBorders(int nLine);

void printNameAndJobClass(int nLine, Player* pPlayer, int nOffset);

void printAreaNavUI(int nLine, Player* pPlayer, int nOffset);
void printSpritePerLine(int nLine, int nOffset);
void printNavOptionsPerLine(int nLine);
void printPlayerStats(int nLine, Player* pPlayer);

#endif