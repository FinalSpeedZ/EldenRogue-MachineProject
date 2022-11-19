#ifndef PRINTER_H
#define PRINTER_H

#define SYSTEM_MESSAGE "SYSTEM MESSAGE"

void printMultiple(char strText[], int nTimes);

void printInputDivider();
void printInputTag(char strInputTag[]);

void printFooter();

void printMessage(char strMessageType[], char strMessage[]);
void printInvalidInputMsg(char strErrorMessage[]);

void printTwoOptions(int nNumberOption1, char strText1[], 
				     int nNumberOption2, char strText2[]);
void printCenterOption(int nNumberOption, char strText[]);
void printFieldedOption (int nNumberOption, char strText1[]);

#endif 
