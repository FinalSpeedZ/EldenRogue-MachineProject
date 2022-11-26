#ifndef ROUNDTABLE_HOLD_H
#define ROUNDTABLE_HOLD_H

#define FAST_TRAVEL   1
#define LEVEL_UP      2
#define INVENTORY     3
#define SHOP          4
#define SAVE          5
#define QUIT_GAME     0

void openRoundTableHold(Player sPlayer);
void processRoundTableHoldInput(int nInput, Player* pPlayer);

#endif 