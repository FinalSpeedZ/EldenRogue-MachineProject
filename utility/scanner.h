#ifndef SCANNER_H
#define SCANNER_H

#define STD_INPUT_TAG   "INPUT"
#define NAME_INPUT_TAG  "INPUT YOUR CHOSEN NAME"

#define PRESS_ENTER     "PRESS ENTER TO CONTINUE..."

void getIntInput(int *pInput, int nMin, int nMax);
char* getStringInput(char strInputTag[]);

void getNameInput(StringPlayerName strPlayerName);

#endif 
