#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"
#include "Windows.h"

#include "utility/colors.c"
#include "utility/printers/printer.c"
#include "utility/sprites/sprites.c"
#include "utility/randomizer.c"

#include "utility/printers/roundtable_printer.c"
#include "utility/printers/screen_headers.c"
#include "utility/printers/area_printer.c"
#include "utility/printers/area_nav_printer.c"

#include "utility/area_utility/area_boards.c"
#include "utility/area_utility/area_doors.c"
#include "utility/area_utility/area_screen_helper.c"

#include "utility/scanner.c"
#include "utility/initializer.c"

#include "screens/title_screen.c"

#include "screens/character_creation_screens/character_creation_screen.c"
#include "screens/character_creation_screens/job_class_creation.c"

#include "screens/roundtable_hold_screens/roundtable_hold.c"
#include "screens/roundtable_hold_screens/fast_travel.c"
#include "screens/roundtable_hold_screens/level_up.c"

#include "screens/areas_screens/area_screens.c"

int main() {
	Player sPlayer;
	initializePlayer(&sPlayer); 
	
	resetColors();
	srand(time(NULL));	

	openTitleScreen(sPlayer);
	return 0;
}
