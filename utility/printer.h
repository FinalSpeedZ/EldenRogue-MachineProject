#ifndef PRINTER_H
#define PRINTER_H

void printMultiple(char strText[], int nTimes);

void printInputDivider();
void printInputTag();

void printMessage(char strMessageType[], char strMessage[]);
void printInvalidInputMsg();

void printFooter();

void printTwoOptions(int nNumberOption1, char strText1[], 
				     int nNumberOption2, char strText2[]);
void printCenterOption(int nNumberOption, char strText[]);

#endif 
