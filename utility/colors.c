#include "colors.h"
#include "../config/settings.h"

void resetColors() {
    if(ENABLE_COLORS) {
        printf("\x1b[0m");
    }
}

void colorText(int nColor) {
    if(ENABLE_COLORS) {
        printf("\x1b[38;5;%dm", nColor);
    }
}

void colorBackground(int nColor) {
    if(ENABLE_COLORS) {
        printf("\x1b[48;5;%dm", nColor);
    }
}

void twoColorText(int nColor, int nBackground) {
    if(ENABLE_COLORS) {
        colorText(nColor);
        colorBackground(nBackground);
    }
}
