#include "dialogue_printer.h"

void loadDialogueEmptyTile(StringFullDialogue strFullDialogue, int nDialogueNum) {
	int nLength;
	char strDialogue[DIALOGUE_MAX_LENGTH];

	switch (nDialogueNum) {
		case 1:
			strcpy(strDialogue, "Hmmm... This seems to be an empty tile. Let's keep going!");
			break;

		case 2:
			strcpy(strDialogue, "Well... Don't just stop here. We still have things to do!");
			break;	

		case 3:
			strcpy(strDialogue, "Just keep moving, Just keep moving, Just keep moving moving moving!");
			break;					

		case 4:
			strcpy(strDialogue, "That's it? Have you lost stamina? Continue on our journey!");
			break;		

		case 5:
			strcpy(strDialogue, "Afraid? Fear is the path to the dark side. Keep Going!");
			break;					
	}

	strcpy(strFullDialogue, strDialogue);


	for (nLength = strlen(strFullDialogue); nLength < DIALOGUE_MAX_LENGTH; nLength++) {
		strcat(strFullDialogue, " ");
	}
}

void loadDialogueTreasureTile(StringFullDialogue strFullDialogue, int nDialogueNum) {
	int nLength;
	char strDialogue[DIALOGUE_MAX_LENGTH];

	switch (nDialogueNum) {
		case 1:
			strcpy(strDialogue, "Ah! A treasure just for us! Thank the Lords!");
			break;

		case 2:
			strcpy(strDialogue, "Wow... Somebody left behind their treasure. Welp, finders keepers...");
			break;	

		case 3:
			strcpy(strDialogue, "Did my birthday come early? Thank you for this treasure!");
			break;					

		case 4:
			strcpy(strDialogue, "And at last I see the light and it's like the sky is new! Thank you for the treasure!");
			break;		

		case 5:
			strcpy(strDialogue, "Ohhh so is this the Tallano Gold? #Unity");
			break;					
	}

	strcpy(strFullDialogue, strDialogue);

	for (nLength = strlen(strFullDialogue); nLength < DIALOGUE_MAX_LENGTH; nLength++) {
		strcat(strFullDialogue, " ");
	}
}

void loadDialogueEnemyTile(StringFullDialogue strFullDialogue, int nDialogueNum) {
	int nLength;
	char strDialogue[DIALOGUE_MAX_LENGTH];

	switch (nDialogueNum) {
		case 1:
			strcpy(strDialogue, "Oh no! I think we were spotted");
			break;

		case 2:
			strcpy(strDialogue, "Ah another guard! I think we can take them head-on!");
			break;	

		case 3:
			strcpy(strDialogue, "I guess this is another sparring partner for us...");
			break;					

		case 4:
			strcpy(strDialogue, "Oh, an enemy? We can do this all day!");
			break;		

		case 5:
			strcpy(strDialogue, "Keep your guards up. There's something lurking!");
			break;					
	}


	strcpy(strFullDialogue, strDialogue);

	for (nLength = strlen(strFullDialogue); nLength < DIALOGUE_MAX_LENGTH; nLength++) {
		strcat(strFullDialogue, " ");
	}
}

void loadDialogueNewUnlockedTile(StringFullDialogue strFullDialogue, int nDialogueNum) {
	int nLength;
	char strDialogue[DIALOGUE_MAX_LENGTH];

	switch (nDialogueNum) {
		case 1:
			strcpy(strDialogue, "We got 1 shard from that battle! We can now access the fast travel tile at this floor!");
			break;

		case 2:
			strcpy(strDialogue, "Yahoo! We received 1 shard and unlocked the fast travel tile at this floor!");
			break;	

		case 3:
			strcpy(strDialogue, "Wow! What a fight! As a reward, we can now access the fast travel tile at this floor and received 1 shard!");
			break;					

		case 4:
			strcpy(strDialogue, "The enemy conceded! The fast travel tile is not blocked anymore! And we also got 1 shard!");
			break;		

		case 5:
			strcpy(strDialogue, "We can now access the fast travel at this floor! Oh by the way, we also got 1 shard");
			break;					
	}


	strcpy(strFullDialogue, strDialogue);

	for (nLength = strlen(strFullDialogue); nLength < DIALOGUE_MAX_LENGTH; nLength++) {
		strcat(strFullDialogue, " ");
	}	
}

void loadDialogueBossTile(StringFullDialogue strFullDialogue, int nDialogueNum) {
	int nLength;
	char strDialogue[DIALOGUE_MAX_LENGTH];

	switch (nDialogueNum) {
		case 1:
			strcpy(strDialogue, "Uh oh... I think that is the boss!");
			break;

		case 2:
			strcpy(strDialogue, "Even a boss is no match for us!");
			break;	

		case 3:
			strcpy(strDialogue, "Now is the time to be in the zone! A big bad boss just woke up!");
			break;					

		case 4:
			strcpy(strDialogue, "We will not back down from any fight, not even from a boss!");
			break;		

		case 5:
			strcpy(strDialogue, "We will not be bossed around by this big bad boss!");
			break;					
	}


	strcpy(strFullDialogue, strDialogue);

	for (nLength = strlen(strFullDialogue); nLength < DIALOGUE_MAX_LENGTH; nLength++) {
		strcat(strFullDialogue, " ");
	}	
}

void loadDialogueLockedTile(StringFullDialogue strFullDialogue, int nDialogueNum) {
	int nLength;
	char strDialogue[DIALOGUE_MAX_LENGTH];

	switch (nDialogueNum) {
		case 1:
			strcpy(strDialogue, "This tile seems to be locked...");
			break;

		case 2:
			strcpy(strDialogue, "The boss doesn't allow us to use this tile. We must defeat them.");
			break;	

		case 3:
			strcpy(strDialogue, "A boss is blocking this tile!");
			break;					

		case 4:
			strcpy(strDialogue, "Cannot interact with this tile... we might be missing something");
			break;		

		case 5:
			strcpy(strDialogue, "Oops... Will you really pass up a chance to defeat the boss?");
			break;					
	}


	strcpy(strFullDialogue, strDialogue);

	for (nLength = strlen(strFullDialogue); nLength < DIALOGUE_MAX_LENGTH; nLength++) {
		strcat(strFullDialogue, " ");
	}	
}

void printTileDialogueLineText(int nDialogueLine, StringFullDialogue strFullDialogue) {
	char strSingleLine[DIALOGUE_LINE_MAX_LENGTH + 1];

	strcpy(strSingleLine, ""); 

	int nLength;

	strncpy(strSingleLine, strFullDialogue + (nDialogueLine * DIALOGUE_LINE_MAX_LENGTH), DIALOGUE_LINE_MAX_LENGTH);

	
	if (strSingleLine[0] == ' ') {
		strncpy(strSingleLine, strFullDialogue + (nDialogueLine * DIALOGUE_LINE_MAX_LENGTH) + 1, DIALOGUE_LINE_MAX_LENGTH - 1);
		strSingleLine[DIALOGUE_LINE_MAX_LENGTH - 1] = ' '; 
	}	

	for (nLength = strlen(strSingleLine); nLength < DIALOGUE_LINE_MAX_LENGTH; nLength++) {
		strcat(strSingleLine, " ");
	}

	strSingleLine[DIALOGUE_LINE_MAX_LENGTH] = '\0';

	printf(" %s ", strSingleLine);
}