#ifndef AREA_NAV_PRINTER_H
#define AREA_NAV_PRINTER_H

#define NAV_HEIGHT              14
#define NAV_WIDTH   			70

void printAreaNav(Player sPlayer);
void printAreaNavLine(int nLine, int nOffset, Player sPlayer);
void printAreaNavEnd(int nLine, int nOffset);

void printNameAndJobClass(int nLine, Player sPlayer, int nOffset);

void printAreaNavUI(int nLine, Player sPlayer, int nOffset);
void printPlayerSpritePerLineNav(int nLine, int nOffset);
void printNavOptionsPerLine(int nLine);
void printPlayerStats(int nLine, Player sPlayer);

#endif