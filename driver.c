#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "Windows.h"

#include "utility/printer.c"
#include "utility/scanner.c"

#include "screens/title_screen.c"
#include "screens/character_creation_screens/character_creation_screen.c"
#include "screens/character_creation_screens/job_class_creation.c"

int main() {
	Player sPlayer = initializePlayer(); // in character_creation_screen
	Player *pPlayer = &sPlayer;
	
	openTitleScreen(&sPlayer);
	return 0;
}
