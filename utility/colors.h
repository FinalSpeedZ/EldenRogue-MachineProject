#ifndef COLORS_H
#define COLORS_H

#define COLOR_TILE_EMPTY       231
#define COLOR_TILE_PLAYER      10
#define COLOR_TILE_DOOR_UP     208
#define COLOR_TILE_DOOR_DOWN   208
#define COLOR_TILE_DOOR_LEFT   208
#define COLOR_TILE_DOOR_RIGHT  208
#define COLOR_TILE_SPAWN       75
#define COLOR_TILE_BOSS        160
#define COLOR_TILE_FAST_TRAVEL 82
#define COLOR_TILE_CREDITS     91
#define COLOR_TILE_INVALID     235

void resetColors();
void colorText(int nColor);
void colorBackground(int nColor);
void twoColorText(int nColor, int nBackground);

#endif