/****************************************
File Name: credits.c

Contains the opencredits fucntion
****************************************/
#include "credits.h"

/*
	openCredits   Opens the credits
*/
void openCredits() {
	system("cls");

	printTitleScreenHeader();

	printMiddleSubHeader("THANK YOU FOR PLAYING!");

	printMiddleSubHeader("DEVELOPERS");

	printMiddleText("QUE, ZACHARY GADJIEL BREINARD G.", "", "");
	printMiddleText("ONG, LANCE JERVIC D.", "", "");

	printf("\n");
	printMiddleSubHeader("SPECIAL THANKS TO");
	printMiddleText("MS. CANDY ESPULGAR", "", "\n\n");

	printFooter();
	printInputDivider();

	pressEnter();
}