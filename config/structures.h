/****************************************
File Name: structures.h

Contains the structures to be used for 
Elden Rougue MP
****************************************/

#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "string_definitions.h"
#include "constant_definitions.h"

// For player Area Details
struct areadetailsTag {
	int nRowLocation;
	int nColumnLocation;

	int nCurrentHealth;
	int nMaxHealth;
};
typedef struct areadetailsTag AreaDetails;

// For player Stats
struct statsTag {
	int nHealth;
	int nEndurance;
	int nDexterity;
	int nStrength;
	int nIntelligence;
	int nFaith;
};
typedef struct statsTag Statistics;

// To know if Second Fast Travel Tile is locked/unlocked
struct unlockedTag {
	int nStormveilFastTravel;
	int nRayaLucariaFastTravel;
	int nRedmaneFastTravel;
	int nVolcanoFastTravel;
	int nLeyndellFastTravel;
	int nEldenThroneCredits;
}; 
typedef struct unlockedTag UnlockedAreas;

// For colors
struct tintTag {
	int nColor1;
	int nColor2;
	int nColor3;
};
typedef struct tintTag Tint;

// for weaponstats
struct weaponStatsTag {
	StringWeaponName strWeaponName;
	int nWeaponHealth;
	int nWeaponEndurance;
	int nWeaponDexterity;
	int nWeaponStrength;
	int nWeaponIntelligence;
	int nWeaponFaith;
	int nCost;
	int nWeaponType;
	int nInventoryIndex;
};
typedef struct weaponStatsTag WeaponStats;

// for inventory
struct inventoryTag {
	WeaponStats* pWeaponStats;
	struct inventoryTag* pPrev;
	struct inventoryTag* pNext;
};
typedef struct inventoryTag Item;

// equipment
struct equipTag {
	Item* pCurrentWeapon;
	int nPotions;
};
typedef struct equipTag Equipment;


// Main player structure
struct playerTag {
	StringPlayerName strPlayerName;
	StringJobClass strPlayerJobClass;  

	int nLevel;
	int nRunes;
	int nShards;
	Item* pInventory;
	Equipment sPlayerEquipment;
	
	Statistics sPlayerStats;
	AreaDetails sPlayerAreaDetails;
	UnlockedAreas sPlayerUnlockedAreas;
	Tint sTint;
};
typedef struct playerTag Player;

// Main enemy structure
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

// For area doors linked list
struct doorTag {
	int nFloorNumber;
	int nRowLocation;
	int nColumnLocation;

	struct doorTag* pNext;
	struct doorTag* pPrev;
};
typedef struct doorTag Door;


// for area floors
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
