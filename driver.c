#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "Windows.h"

#include "utility/printers/printer.c"
#include "utility/printers/roundtable_printer.c"
#include "utility/scanner.c"
#include "utility/initializer.c"

#include "screens/title_screen.c"

#include "screens/character_creation_screens/character_creation_screen.c"
#include "screens/character_creation_screens/job_class_creation.c"

#include "screens/roundtable_hold_screens/roundtable_hold.c"
#include "screens/roundtable_hold_screens/fast_travel.c"
#include "screens/roundtable_hold_screens/level_up.c"

int main() {
	Player sPlayer = initializePlayer(); 
	
	openTitleScreen(sPlayer);
	return 0;
}
