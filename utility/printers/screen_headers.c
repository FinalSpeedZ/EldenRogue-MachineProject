#include "screen_headers.h"

void printTitleScreenHeader() {
	printMultiple("\n", SCREEN_PADDING_TOP);
	printMiddleText(" ___   _____ _    ______ _____ _   _  ______ _____ _____ _   _ _____   ___ ", "", "");
	printMiddleText("|  _| |  ___| |   |  _  \\  ___| \\ | | | ___ \\  _  |  __ \\ | | |  ___| |_  |", "", "");
	printMiddleText("| |   | |__ | |   | | | | |__ |  \\| | | |_/ / | | | |  \\/ | | | |__     | |", "", "");
	printMiddleText("| |   |  __|| |   | | | |  __|| . ` | |    /| | | | | __| | | |  __|    | |", "", "");
	printMiddleText("| |   | |___| |___| |/ /| |___| |\\  | | |\\ \\\\ \\_/ / |_\\ \\ |_| | |___    | |", "", "");
	printMiddleText("| |_  \\____/\\_____/___/ \\____/\\_| \\_/ \\_| \\_|\\___/ \\____/\\___/\\____/   _| |", "", "");	
	printMiddleText("|___|                                                                 |___|", "", "\n");		
	printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT);
	printMultiple("─", SCREEN_WIDTH);
	printf("\n\n");
}

void printCharacterCreationHeader() {
	printMultiple("\n", SCREEN_PADDING_TOP);
	printMiddleText("   __       _                          _                                  _   _              __   ", "", "");
	printMiddleText("  / /      | |                        | |                                | | (_)             \\ \\  ", "", "");
	printMiddleText(" / /    ___| |__   __ _ _ __ __ _  ___| |_ ___ _ __    ___ _ __ ___  __ _| |_ _  ___  _ __    \\ \\ ", "", "");
	printMiddleText("< <    / __| '_ \\ / _` | '__/ _` |/ __| __/ _ | '__|  / __| '__/ _ \\/ _` | __| |/ _ \\| '_ \\    > >", "", "");
	printMiddleText(" \\ \\  | (__| | | | (_| | | | (_| | (__| ||  __| |    | (__| | |  __| (_| | |_| | (_) | | | |  / / ", "", "");
	printMiddleText("  \\_\\  \\___|_| |_|\\__,_|_|  \\__,_|\\___|\\__\\___|_|     \\___|_|  \\___|\\__,_|\\__|_|\\___/|_| |_| /_/  ", "", "\n");		
	printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT);
	printMultiple("─", SCREEN_WIDTH);
	printf("\n\n");
}

void printRoundtableHoldHeader() {
	printMultiple("\n", SCREEN_PADDING_TOP);
	printMiddleText("   __                            _ _        _     _        _           _     _  __   ", "", "");
	printMiddleText("  / /                           | | |      | |   | |      | |         | |   | | \\ \\  ", "", "");
	printMiddleText(" / /   _ __ ___  _   _ _ __   __| | |_ __ _| |__ | | ___  | |__   ___ | | __| |  \\ \\ ", "", "");
	printMiddleText("< <   | '__/ _ \\| | | | '_ \\ / _` | __/ _` | '_ \\| |/ _ \\ | '_ \\ / _ \\| |/ _` |   > >", "", "");
	printMiddleText(" \\ \\  | | | (_) | |_| | | | | (_| | || (_| | |_) | |  __/ | | | | (_) | | (_| |  / / ", "", "");
	printMiddleText("  \\_\\ |_|  \\___/ \\__,_|_| |_|\\__,_|\\__\\__,_|_.__/|_|\\___| |_| |_|\\___/|_|\\__,_| /_/  ", "", "\n");		
	printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT);
	printMultiple("─", SCREEN_WIDTH);
	printf("\n\n");	
}

void printFastTravelHeader() {
	printMultiple("\n", SCREEN_PADDING_TOP);
	printMiddleText("   __   __          _     _                       _  __   ", "", "");
	printMiddleText("  / /  / _|        | |   | |                     | | \\ \\  ", "", "");
	printMiddleText(" / /  | |_ __ _ ___| |_  | |_ _ __ __ ___   _____| |  \\ \\ ", "", "");
	printMiddleText("< <   |  _/ _` / __| __| | __| '__/ _` \\ \\ / / _ | |   > >", "", "");
	printMiddleText(" \\ \\  | || (_| \\__ | |_  | |_| | | (_| |\\ V |  __| |  / / ", "", "");
	printMiddleText("  \\_\\ |_| \\__,_|___/\\__|  \\__|_|  \\__,_| \\_/ \\___|_| /_/  ", "", "\n");		
	printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT);
	printMultiple("─", SCREEN_WIDTH);
	printf("\n\n");	
}

void printStormveilCastleHeader() {
	printMultiple("\n", SCREEN_PADDING_TOP);
	printMiddleText(" _____ _                                _ _   _____           _   _      ", "", "");
	printMiddleText("/  ___| |                              (_| | /  __ \\         | | | |     ", "", "");
	printMiddleText("\\ `--.| |_ ___  _ __ _ __ _____   _____ _| | | /  \\/ __ _ ___| |_| | ___ ", "", "");
	printMiddleText(" `--. | __/ _ \\| '__| '_ ` _ \\ \\ / / _ | | | | |    / _` / __| __| |/ _ \\", "", "");
	printMiddleText("/\\__/ | || (_) | |  | | | | | \\ V |  __| | | | \\__/| (_| \\__ | |_| |  __/", "", "");
	printMiddleText("\\____/ \\__\\___/|_|  |_| |_| |_|\\_/ \\___|_|_|  \\____/\\__,_|___/\\__|_|\\___|", "", "\n");		
	printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT);
	printMultiple("─", SCREEN_WIDTH);
	printf("\n\n");		
}

void printRayaLucariaHeader() {
	printMultiple("\n", SCREEN_PADDING_TOP);
	printMiddleText("______                    _                          _          ___                _                      ", "", "");
	printMiddleText("| ___ \\                  | |                        (_)        / _ \\              | |                     ", "", "");
	printMiddleText("| |_/ /__ _ _   _  __ _  | |    _   _  ___ __ _ _ __ _  __ _  / /_\\ \\ ___ __ _  __| | ___ _ __ ___  _   _ ", "", "");
	printMiddleText("|    // _` | | | |/ _` | | |   | | | |/ __/ _` | '__| |/ _` | |  _  |/ __/ _` |/ _` |/ _ | '_ ` _ \\| | | |", "", "");
	printMiddleText("| |\\ | (_| | |_| | (_| | | |___| |_| | (_| (_| | |  | | (_| | | | | | (_| (_| | (_| |  __| | | | | | |_| |", "", "");
	printMiddleText("\\_| \\_\\__,_|\\__, |\\__,_| \\_____/\\__,_|\\___\\__,_|_|  |_|\\__,_| \\_| |_/\\___\\__,_|\\__,_|\\___|_| |_| |_|\\__, |", "", "");		
	printMiddleText("             __/ |                                                                                   __/ |", "", "");
	printMiddleText("            |___/                                                                                   |___/ ", "", "\n");
	printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT);
	printMultiple("─", SCREEN_WIDTH);
	printf("\n\n");		
}

void printRedmaneCastleHeader() {
	printMultiple("\n", SCREEN_PADDING_TOP);
	printMiddleText("______         _                              _____           _   _      ", "", "");
	printMiddleText("| ___ \\       | |                            /  __ \\         | | | |     ", "", "");
	printMiddleText("| |_/ /___  __| |_ __ ___   __ _ _ __   ___  | /  \\/ __ _ ___| |_| | ___ ", "", "");
	printMiddleText("|    // _ \\/ _` | '_ ` _ \\ / _` | '_ \\ / _ \\ | |    / _` / __| __| |/ _ \\", "", "");
	printMiddleText("| |\\ |  __| (_| | | | | | | (_| | | | |  __/ | \\__/| (_| \\__ | |_| |  __/", "", "");
	printMiddleText("\\_| \\_\\___|\\__,_|_| |_| |_|\\__,_|_| |_|\\___|  \\____/\\__,_|___/\\__|_|\\___|", "", "\n");		
	printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT);
	printMultiple("─", SCREEN_WIDTH);
	printf("\n\n");		
}

void printVolcanoManorHeader() {
	printMultiple("\n", SCREEN_PADDING_TOP);
	printMiddleText(" _   _       _                        ___  ___                       ", "", "");
	printMiddleText("| | | |     | |                       |  \\/  |                       ", "", "");
	printMiddleText("| | | | ___ | | ___ __ _ _ __   ___   | .  . | __ _ _ __   ___  _ __ ", "", "");
	printMiddleText("| | | |/ _ \\| |/ __/ _` | '_ \\ / _ \\  | |\\/| |/ _` | '_ \\ / _ \\| '__|", "", "");
	printMiddleText("\\ \\_/ | (_) | | (_| (_| | | | | (_) | | |  | | (_| | | | | (_) | |   ", "", "");
	printMiddleText(" \\___/ \\___/|_|\\_____,_|_| |_|\\___/  \\_|  |_/\\__,_|_| |_|\\___/|_|   ", "", "\n");		
	printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT);
	printMultiple("─", SCREEN_WIDTH);
	printf("\n\n");		
}

void printLeyndellRoyalCapitalHeader() {
	printMultiple("\n", SCREEN_PADDING_TOP);
	printMiddleText(" _                          _      _ _  ______                  _   _____             _ _        _ ", "", "");
	printMiddleText("| |                        | |    | | | | ___ \\                | | /  __ \\           (_| |      | |", "", "");
	printMiddleText("| |     ___ _   _ _ __   __| | ___| | | | |_/ /___  _   _  __ _| | | /  \\/ __ _ _ __  _| |_ __ _| |", "", "");
	printMiddleText("| |    / _ | | | | '_ \\ / _` |/ _ | | | |    // _ \\| | | |/ _` | | | |    / _` | '_ \\| | __/ _` | |", "", "");
	printMiddleText("| |___|  __| |_| | | | | (_| |  __| | | | |\\ | (_) | |_| | (_| | | | \\__/| (_| | |_) | | || (_| | |", "", "");
	printMiddleText("\\_____/\\___|\\__, |_| |_|\\__,_|\\___|_|_| \\_| \\_\\___/ \\__, |\\__,_|_|  \\____/\\__,_| .__/|_|\\__\\__,_|_|", "", "");		
	printMiddleText("             __/ |                                   __/ |                     | |                 ", "", "");
	printMiddleText("            |___/                                   |___/                      |_|                 ", "", "");
	printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT);
	printMultiple("─", SCREEN_WIDTH);
	printf("\n\n");		
}

void printTheEldenThrone() {
	printMultiple("\n", SCREEN_PADDING_TOP);
	printMiddleText(" _____ _            _____ _     _              _____ _                          ", "", "");
	printMiddleText("|_   _| |          |  ___| |   | |            |_   _| |                         ", "", "");
	printMiddleText("  | | | |__   ___  | |__ | | __| | ___ _ __     | | | |__  _ __ ___  _ __   ___ ", "", "");
	printMiddleText("  | | | '_ \\ / _ \\ |  __|| |/ _` |/ _ | '_ \\    | | | '_ \\| '__/ _ \\| '_ \\ / _ \\", "", "");
	printMiddleText("  | | | | | |  __/ | |___| | (_| |  __| | | |   | | | | | | | | (_) | | | |  __/", "", "");
	printMiddleText("  \\_/ |_| |_|\\___| \\____/|_|\\__,_|\\___|_| |_|   \\_/ |_| |_|_|  \\___/|_| |_|\\___|", "", "\n");		;
	printMultiple(" ", SCREEN_PADDING_LEFT - HEADER_PADDING_LEFT);
	printMultiple("─", SCREEN_WIDTH);
	printf("\n\n");		
}