#ifndef DIALOGUE_PRINTER_H
#define DIALOGUE_PRINTER_H

void loadDialogueEmptyTile(StringFullDialogue strFullDialogue, int nDialogueNum);
void loadDialogueTreasureTile(StringFullDialogue strFullDialogue, int nDialogueNum);
void loadDialogueEnemyTile(StringFullDialogue strFullDialogue, int nDialogueNum);
void loadDialogueNewUnlockedTile(StringFullDialogue strFullDialogue, int nDialogueNum);
void loadDialogueBossTile(StringFullDialogue strFullDialogue, int nDialogueNum);
void loadDialogueLockedTile(StringFullDialogue strFullDialogue, int nDialogueNum);

void printTileDialogueLineText(int nDialogueLine, StringFullDialogue strFullDialogue);



#endif