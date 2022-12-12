#ifndef PLAYER_DETAILS_BOX_H
#define PLAYER_DETAILS_BOX_H

#define NAV_HEIGHT              14
#define NAV_WIDTH   			70

void printAreaNav(Player sPlayer, int nDialogue);
void printAreaNavLine(int nLine, int nOffset, Player sPlayer, int nDialogue);
void printAreaNavEnd(int nLine, int nOffset);

void printNameAndJobClass(int nLine, Player sPlayer, int nOffset);

void printAreaNavUI(int nLine, Player sPlayer, int nOffset, int nDialogue);
void printPlayerSpritePerLineNav(int nLine, int nOffset);
void printNavOptionsPerLine(int nLine);
void printPlayerStats(int nLine, Player sPlayer);

void printPlayerStats(int nLine, Player sPlayer);
void printDialoguePerLine(int nLine);

#endif