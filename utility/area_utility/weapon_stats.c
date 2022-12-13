#include "weapon_stats.h"

WeaponStats* loadSwords (int nWeaponIndex){
	WeaponStats* pStats = malloc(sizeof(WeaponStats));
	WeaponStats aSword[4] =  {{"Short Sword", 0, 15, 13, 15, 15, 15, 1000, SHORT_SWORD, 0},
							 {"Rogier's Reaper", 10, 25, 18, 35, 35, 35, 2000, ROGIER_RAPIER, 0},
							 {"Coded Sword", 20, 35, 21, 40, 40, 40, 4000, CODED_SWORD, 0},
							 {"Sword of Night and Flame", 30, 45, 25, 55, 55, 55, 8000, SWORD_OF_NIGHT_AND_FIRE, 0}};
	switch (nWeaponIndex){
		case SHORT_SWORD:
			*(pStats) = aSword[0];
			break;
		case ROGIER_RAPIER:
			*(pStats) = aSword[1];
			break;
		case CODED_SWORD:
			*(pStats) = aSword[2];
			break;
		case SWORD_OF_NIGHT_AND_FIRE:
			*(pStats) = aSword[3];
			break;
	}

	return pStats;
}

WeaponStats* loadKatanas (int nWeaponIndex){
	WeaponStats* pStats = malloc(sizeof(WeaponStats));
	WeaponStats aKatana[4] = {{"Uchigatana", 20, 35, 15, 30, 0, 0, 1875, UCHIGATANA, 0},
							 {"Moonveil", 30, 40, 20, 45, 0, 0, 3750, MOONVEIL, 0},
							 {"Rivers of Blood", 40, 45, 25, 60, 0, 0, 7500, RIVERS_OF_BLOOD, 0},
							 {"Hand of Malenia", 50, 50, 30, 75, 0, 0, 15000, HAND_OF_MALENIA, 0}};
	switch (nWeaponIndex){
		case UCHIGATANA:
			*(pStats) = aKatana[0];
			break;
		case MOONVEIL:
			*(pStats) = aKatana[1];
			break;
		case RIVERS_OF_BLOOD:
			*(pStats) = aKatana[2];
			break;
		case HAND_OF_MALENIA:
			*(pStats) = aKatana[3];
			break;
	}
	return pStats;
}

WeaponStats* loadWhips (int nWeaponIndex){
	WeaponStats* pStats = malloc(sizeof(WeaponStats));
	WeaponStats aWhip[4] =  {{"Whip", 15, 60, 20, 20, 0, 0, 1500, BASE_WHIP, 0},
							 {"Urumi", 20, 70, 25, 40, 10, 0, 3000, URUMI, 0},
							 {"Thorned Whip", 30, 80, 30, 50, 0, 40, 5000, THORNED_WHIP, 0},
							 {"Hoslow's Petal Whip", 35, 90, 35, 55, 20, 20, 10000, HOSLOW_PETAL_WHIP, 0}};
	switch (nWeaponIndex){
		case BASE_WHIP:
			*(pStats)  = aWhip[0];
			break;
		case URUMI:
			*(pStats)  = aWhip[1];
			break;
		case THORNED_WHIP:
			*(pStats) = aWhip[2];
			break;
		case HOSLOW_PETAL_WHIP:
			*(pStats)  = aWhip[3];
			break;
	}
	return pStats;
}

WeaponStats* loadGreatSwords (int nWeaponIndex){
	WeaponStats* pStats = malloc(sizeof(WeaponStats));
	WeaponStats aGreatSword[4] =  {{"Claymore", 15, 10, 9, 20, 0, 0, 3000, CLAYMORE, 0},
							 	   {"Starscourge Greatsword", 20, 15, 14, 40, 0, 20, 6000, STARSCOURGE_GREATSWORD, 0},
							 	   {"Inseparable Sword", 25, 20, 19, 70, 60, 60, 12000, INSEPARABLE_SWORD, 0},
							 	   {"Maliketh's Black Blade", 30, 25, 24, 80, 40, 60, 24000, MALIKETH_BLACK_BLADE, 0}};
	switch (nWeaponIndex){
		case CLAYMORE:
			*(pStats) = aGreatSword[0];
			break;
		case STARSCOURGE_GREATSWORD:
			*(pStats)  = aGreatSword[1];
			break;
		case INSEPARABLE_SWORD:
			*(pStats) = aGreatSword[2];
			break;
		case MALIKETH_BLACK_BLADE:
			*(pStats) = aGreatSword[3];
			break;
	}
	return pStats;	
}

WeaponStats* loadStaffs (int nWeaponIndex){
	WeaponStats* pStats = malloc(sizeof(WeaponStats));
	WeaponStats aStaff[4] =  {{"Astrologer's Staff", 5, 20, 12, 5, 25, 15, 2000, ASTROLOGER_STAFF, 0},
							  {"Albinauric Staff", 10, 30, 14, 10, 45, 35, 4000, ALBINAURIC_STAFF, 0},
							  {"Staff of the Guilty", 15, 40, 16, 15, 65, 60, 8000, STAFF_OF_THE_GUILTY, 0},
							  {"Carian Regal Scepter", 25, 50, 18, 20, 85, 75, 16000, CARIAN_REGAL_SCEPTER, 0}};
	switch (nWeaponIndex){
		case ASTROLOGER_STAFF:
			*(pStats)  = aStaff[0];
			break;
		case ALBINAURIC_STAFF:
			*(pStats) = aStaff[1];
			break;
		case STAFF_OF_THE_GUILTY:
			*(pStats)  = aStaff[2];
			break;
		case CARIAN_REGAL_SCEPTER:
			*(pStats)  = aStaff[3];
			break;
	}
	return pStats;	
}

WeaponStats* loadSeals (int nWeaponIndex){
	WeaponStats* pStats = malloc(sizeof(WeaponStats));
	WeaponStats aSeal[4] =  {{"Finger Seal", 10, 45, 10, 0, 15, 20, 2500, FINGER_SEAL, 0},
							{"Godslayer's Seal", 15, 50, 12, 0, 35, 40, 5000, GODSLAYER_SEAL, 0},
							{"Golden Ordeal Seal", 20, 55, 14, 0, 65, 65, 10000, GOLDEN_ORDEAL_SEAL, 0},
						    {"Dragon Communion Seal", 25, 60, 18, 0, 75, 80, 15000, DRAGON_COMMUNION_SEAL, 0}};
	switch (nWeaponIndex){
		case FINGER_SEAL:
			*(pStats)  = aSeal[0];
			break;
		case GODSLAYER_SEAL:
			*(pStats)  = aSeal[1];
			break;
		case GOLDEN_ORDEAL_SEAL:
			*(pStats)  = aSeal[2];
			break;
		case DRAGON_COMMUNION_SEAL:
			*(pStats)  = aSeal[3];
			break;
	}
	return pStats;	
}

WeaponStats* loadWeapon (int nWeaponIndex){
	WeaponStats* pItemStats;
	switch (nWeaponIndex){
		case SHORT_SWORD:
		case ROGIER_RAPIER:
		case CODED_SWORD:
		case SWORD_OF_NIGHT_AND_FIRE:
			pItemStats = loadSwords(nWeaponIndex);
			break;
		case UCHIGATANA:
		case MOONVEIL:
		case RIVERS_OF_BLOOD:
		case HAND_OF_MALENIA:
			pItemStats = loadKatanas(nWeaponIndex);
			break;	
		case BASE_WHIP:
		case URUMI:
		case THORNED_WHIP:
		case HOSLOW_PETAL_WHIP:
			pItemStats = loadWhips(nWeaponIndex);
			break;
		case CLAYMORE:
		case STARSCOURGE_GREATSWORD:
		case INSEPARABLE_SWORD:
		case MALIKETH_BLACK_BLADE:
			pItemStats = loadGreatSwords(nWeaponIndex);
			break;
		case ASTROLOGER_STAFF:
		case ALBINAURIC_STAFF:
		case STAFF_OF_THE_GUILTY:
		case CARIAN_REGAL_SCEPTER:
			pItemStats = loadStaffs(nWeaponIndex);
			break;
		case FINGER_SEAL:
		case GODSLAYER_SEAL:
		case GOLDEN_ORDEAL_SEAL:
		case DRAGON_COMMUNION_SEAL:
			pItemStats = loadSeals(nWeaponIndex);
			break;
	} 
	return pItemStats;
}