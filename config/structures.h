#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "string_definitions.h"

struct areadetailsTag {
	int nRowLocation;
	int nColumnLocation;
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

struct playerTag {
	StringPlayerName strPlayerName;
	StringJobClass strPlayerJobClass;  
	int nLevel;
	int nRunes;
	int nShards;
	Statistics sPlayerStats;
	AreaDetails sPlayerAreaDetails;
};
typedef struct playerTag Player;

struct doorTag{
	int nFloorNumber;
	int nRowLocation;
	int nColumnLocation;

	struct doorTag* pNext;
	struct doorTag* pPrev;
};
typedef struct doorTag Door;

#endif