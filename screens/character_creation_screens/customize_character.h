#ifndef CUSTOMIZE_CHARACTER_H
#define CUSTOMIZE_CHARACTER_H

void openCustomizeCharacter(Player* pPlayer);
void processCustomizeCharacterInput(int nInput, Player* pPlayer);

void openEditHair(Player* pPlayer);
void processEditHair(int nInput, Player* pPlayer);
void openEditEyeColor(Player* pPlayer);
void processEditEyeColor(int nInput, Player* pPlayer);
void openEditShirtColor(Player* pPlayer);
void processEditShirtColor(int nInput, Player* pPlayer);

#endif