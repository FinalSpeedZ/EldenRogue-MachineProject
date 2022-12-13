#ifndef DIALOGUE_PRINTER_H
#define DIALOGUE_PRINTER_H

void loadDialogueEmptyTile(StringFullDialogue strFullDialogue, int nDialogueNum);
void loadDialogueTreasureTile(StringFullDialogue strFullDialogue, int nDialogueNum);
void loadDialogueEnemyTile(StringFullDialogue strFullDialogue, int nDialogueNum);
void loadDialogueNewUnlockedTile(StringFullDialogue strFullDialogue, int nDialogueNum);
void loadDialogueBossTile(StringFullDialogue strFullDialogue, int nDialogueNum);
void loadDialogueLockedTile(StringFullDialogue strFullDialogue, int nDialogueNum);
void loadDialogueFinishedEldenThrone(StringFullDialogue strFullDialogue, int nDialogueNum);

void loadDialogueFastTravel(StringFullDialogue strFullDialogue, int nDialogueNum);
void loadDialogueFastTravelLocked(StringFullDialogue strFullDialogue, int nDialogueNum);

void printDialogueLineText(int nDialogueLine, StringFullDialogue strFullDialogue);

#endif