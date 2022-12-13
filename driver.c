#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"
#include "Windows.h"

#include "utility/colors.c"
#include "utility/printers/printer.c"
#include "utility/sprites/sprites.c"
#include "utility/scanner.c"
#include "utility/initializer.c"
#include "utility/randomizer.c"
#include "utility/area_utility/weapon_stats.c"

#include "utility/printers/roundtable_printer.c"
#include "utility/printers/screen_headers.c"
#include "utility/printers/area_printer.c"
#include "utility/printers/battle_printer.c"
#include "utility/printers/dialogue_printer.c"
#include "utility/printers/player_details_box.c"
#include "utility/printers/inventory_printer.c"
#include "utility/printers/shop_printer.c"

#include "utility/area_utility/area_boards.c"
#include "utility/area_utility/area_doors.c"
#include "utility/area_utility/area_screen_helper.c"
#include "utility/area_utility/battle_screen_helper.c"

#include "screens/title_screen.c"

#include "screens/character_creation_screens/character_creation_screen.c"
#include "screens/character_creation_screens/job_class_creation.c"
#include "screens/character_creation_screens/customize_character.c"

#include "screens/roundtable_hold_screens/roundtable_hold.c"
#include "screens/roundtable_hold_screens/fast_travel.c"
#include "screens/roundtable_hold_screens/level_up.c"
#include "screens/roundtable_hold_screens/shop.c"
#include "screens/roundtable_hold_screens/inventory.c"

#include "screens/areas_screens/area_screens.c"
#include "screens/areas_screens/battle.c"
#include "screens/areas_screens/credits.c"

int main() {
	Player sPlayer;
	initializePlayer(&sPlayer); 
	
	resetColors();
	srand(time(NULL));	

	openTitleScreen(sPlayer);
	return 0;
}