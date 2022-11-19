#ifndef TITLE_SCREEN_H
#define TITLE_SCREEN_H

#define OPTION_START    "START"
#define OPTION_CONTINUE "CONTINUE"
#define OPTION_EXIT     "EXIT"

void openTitleScreen();
void processTitleScreenInput(int nInput);
void processCharacterCreationScreenInput(int nInput, Player* pPlayer);

#endif