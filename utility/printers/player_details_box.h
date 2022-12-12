#ifndef PLAYER_DETAILS_BOX_H
#define PLAYER_DETAILS_BOX_H

#define NAV_HEIGHT              14
#define NAV_WIDTH   			70

void printAreaNav(Player sPlayer, int nPrompt);
void printAreaNavLine(int nLine, int nOffset, Player sPlayer, int nPrompt);
void printAreaNavEnd(int nLine, int nOffset);

void printNameAndJobClass(int nLine, Player sPlayer, int nOffset);

void printAreaNavUI(int nLine, Player sPlayer, int nOffset, int nPrompt);
void printPlayerSpritePerLineNav(int nLine, int nOffset);
void printNavOptionsPerLine(int nLine);
void printPlayerStats(int nLine, Player sPlayer);

void printPlayerStats(int nLine, Player sPlayer);
void printTileDialoguePerLine(int nLine, int nPrompt);

#endif