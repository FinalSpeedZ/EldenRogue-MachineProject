#ifndef PRINTER_H
#define PRINTER_H

#define SYSTEM_MESSAGE "SYSTEM MESSAGE"

#define OPTION_START    "START"
#define OPTION_CONTINUE "CONTINUE"
#define OPTION_EXIT     "EXIT"
#define OPTION_BACK     "BACK"
#define OPTION_CONFIRM  "CONFIRM"

void printMultiple(char strText[], int nTimes);

void printMiddleSubHeader(char strText[]);
void printMiddleText(char strText[], char strDesignLeft[], char strDesignRight[]);

void printInputDivider();
void printInputTag(char strInputTag[]);

void printFooter();

void printMessage(char strMessageType[], char strMessage[]);
void printInvalidInputMsg(char strErrorMessage[]);
void printBattleDmgPrompter(char strWhoDealtDammage[], int nDamageDealt);
void printBattleHealPrompter(int nHealthHealed);

void printTwoOptions(int nNumberOption1, char strText1[], 
		 		     int nNumberOption2, char strText2[]);
void printTwoLongOptions(int nNumberOption1, char strText1[], 
		 		         int nNumberOption2, char strText2[]);
void printCenterOption(int nNumberOption, char strText[]);
void printFieldedOption (int nNumberOption, char strText1[]);

void printMiddleStats(char strLabel[], int nValue);
void printTwoStats(char strLabel1[], int nValue1, 
	               char strLabel2[], int nValue2);

#endif 
