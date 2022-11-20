#ifndef STRUCTURES_H
#define STRUCTURES_H

#include "string_definitions.h"

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
	Statistics sPlayerStats;
};
typedef struct playerTag Player;

#endif