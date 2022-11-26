#ifndef CHARACTER_CREATION_SCREEN_H
#define CHARACTER_CREATION_SCREEN_H

void openCharacterCreationScreen(Player sPlayer);
void processCharacterCreationScreenInput(int nInput, Player* pPlayer);
int checkCharacterCreation(Player sPlayer);

void printJobClassStats(Player sPlayer);

#endif
