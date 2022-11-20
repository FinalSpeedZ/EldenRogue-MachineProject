#ifndef CHARACTER_CREATION_SCREEN_H
#define CHARACTER_CREATION_SCREEN_H

#define OPTION_BACK     "BACK"
#define OPTION_CONFIRM  "CONFIRM"

#define TAG_NAME        "NAME"
#define TAG_JOB_CLASS   "JOB CLASS"

void openCharacterCreationScreen(Player* pPlayer);
void processCharacterCreationScreenInput(int nInput, Player* pPlayer);
Player initializePlayer();

#endif
