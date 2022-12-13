#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "string_definitions.h"
#include "constant_definitions.h"

struct areadetailsTag {
	int nRowLocation;
	int nColumnLocation;

	int nCurrentHealth;
	int nMaxHealth;
};
typedef struct areadetailsTag AreaDetails;

struct statsTag {
	int nHealth;
	int nEndurance;
	int nDexterity;
	int nStrength;
	int nIntelligence;
	int nFaith;
};
typedef struct statsTag Statistics;

struct unlockedTag {
	int nStormveilFastTravel;
	int nRayaLucariaFastTravel;
	int nRedmaneFastTravel;
	int nVolcanoFastTravel;
	int nLeyndellFastTravel;
	int nEldenThroneCredits;
}; 
typedef struct unlockedTag UnlockedAreas;

struct tintTag {
	int nColor1;
	int nColor2;
	int nColor3;
};
typedef struct tintTag Tint;

struct playerTag {
	StringPlayerName strPlayerName;
	StringJobClass strPlayerJobClass;  

	int nLevel;
	int nRunes;
	int nShards;
	int nPotions;
	
	Statistics sPlayerStats;
	AreaDetails sPlayerAreaDetails;
	UnlockedAreas sPlayerUnlockedAreas;
	Tint sTint;
};
typedef struct playerTag Player;

struct enemyTag {
	char* pEnemyName;
	int nEnemyType;

	int nHealthUpper;
	int nHealthLower;
	int nBaseHealth;
	int nFinalHealth;
	int nCurrentHealth;

	int nAttackUpper;
	int nAttackLower;
	int nBaseAttack;
	int nFinalAttack;

	float fPhysicalDef;
	float fSorceryDef;
	float fIncantationDef;

	Tint sTint;
};
typedef struct enemyTag Enemy;

struct doorTag {
	int nFloorNumber;
	int nRowLocation;
	int nColumnLocation;

	struct doorTag* pNext;
	struct doorTag* pPrev;
};
typedef struct doorTag Door;

struct floorTag {
	int nAreaIndex;
	int nFloorNumber;

	int nRows;
	int nColumns;

	int** pFloorBoardArray;
	Door** pAreaDoorArray;
};
typedef struct floorTag AreaFloor;

#endif