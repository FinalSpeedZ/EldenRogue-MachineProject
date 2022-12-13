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

#define COLOR_SPRITE_OUTLINE 237

#define COLOR_RUNE_DARK    171
#define COLOR_RUNE_LIGHT   207

#define COLOR_LOSE_DARK    124
#define COLOR_LOSE_LIGHT   196

#define COLOR_PLAYER_HAIR  221
#define COLOR_PLAYER_SHIRT 203
#define COLOR_PLAYER_EYES  33
#define COLOR_PLAYER_SKIN  216

#define COLOR_HEALTH_GREEN   2
#define COLOR_HEALTH_YELLOW  3
#define COLOR_HEALTH_RED     1

#define COLOR_DAMAGED_BAR   8 

#define COLOR_POTION 213

#define COLOR_SHARD  33

void resetColors();
void colorText(int nColor);
void colorBackground(int nColor);
void twoColorText(int nColor, int nBackground);

#endif