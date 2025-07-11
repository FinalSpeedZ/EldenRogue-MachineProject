/****************************************
File Name: string_definitions.h

Contains the string definitions for 
Elden Rougue MP
****************************************/

#ifndef STRING_DEFINITIONS_H
#define STRING_DEFINITIONS_H

#define OPTIONS_TEXT_LENGTH        20
#define OPTIONS_LONG_TEXT_LENGTH   30

#define PLAYER_NAME_LENGTH  25 
#define JOB_CLASS_LENGTH    10
#define WEAPON_NAME_LENGTH  25

#define DIALOGUE_MAX_LENGTH        234
#define DIALOGUE_LINE_MAX_LENGTH	26

typedef char StringPlayerName[PLAYER_NAME_LENGTH + 1];
typedef char StringJobClass[JOB_CLASS_LENGTH + 1];
typedef char StringFullDialogue[DIALOGUE_MAX_LENGTH + 1];
typedef char StringWeaponName[WEAPON_NAME_LENGTH + 1];

#endif