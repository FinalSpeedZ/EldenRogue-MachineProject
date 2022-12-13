#ifndef PLAYER_DETAILS_BOX_H
#define PLAYER_DETAILS_BOX_H

#define NAV_HEIGHT              14
#define NAV_WIDTH   			70

void printNavEnd(int nLine, int nOffset);

void printRoundtableNav(Player sPlayer, int nPrompt);
void printRoundtableNavLine(int nLine, int nOffset, Player sPlayer, int nPrompt, int nDialogueNum);
void printRoundtableNavUI(int nLine, Player sPlayer, int nOffset, int nPrompt, int nDialogueNum);
void printRoundtablePlayerStatsPerLine(int nLine, Player sPlayer);

void printAreaNav(Player sPlayer, int nPrompt);
void printAreaNavLine(int nLine, int nOffset, Player sPlayer, int nPrompt, int nDialogueNum);

void printNameAndJobClass(int nLine, Player sPlayer, int nOffset);

void printAreaNavUI(int nLine, Player sPlayer, int nOffset, int nPrompt, int nDialogueNum);
void printPlayerSpritePerLineNav(int nLine, int nOffset);
void printNavOptionsPerLine(int nLine);
void printPlayerStats(int nLine, Player sPlayer);

void printPlayerStats(int nLine, Player sPlayer);

void printDialoguePerLine(int nLine, int nPrompt, int nDialogueNum);

#endif