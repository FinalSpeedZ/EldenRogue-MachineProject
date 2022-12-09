#include "area_boards.h"

int* generateStromveilCastle(AreaFloor sAreaFloor) {
	int *pFloor = malloc(sizeof(int) * sAreaFloor.nRows * sAreaFloor.nColumns);

	int nRowCounter;
	int nColumnCounter;

	int aStormveilFloor1[][3] = {{0, 2, 0},
								 {6, 0, 6}, 
								 {0, 0, 0},
								 {0, 0, 0},
								 {0, 0, 0},
								 {0, 0, 0},
								 {0, 8, 0}};

	int aStormveilFloor2[][7] = {{0, 0, 0, 2, 0, 0, 0},
								 {0, 0, 0, 6, 0, 0, 0}, 
								 {0, 0, 0, 0, 0, 0, 0},
								 {6, 0, 6, 6, 6, 0, 6},
								 {0, 0, 0, 0, 0, 0, 0},
								 {0, 0, 6, 0, 6, 0, 0},
								 {0, 0, 0, 3, 0, 0, 0}};

	int aStormveilFloor3[][5] = {{0, 0, 8, 0, 0}, 
								 {0, 0, 0, 0, 0},  
								 {0, 0, 0, 0, 0},
					 			 {0, 0, 7, 0, 0}, 
						  		 {0, 0, 0, 0, 0}, 
						  		 {0, 0, 0, 0, 0}, 
						  		 {0, 0, 3, 0, 0}};


	switch(sAreaFloor.nFloorNumber) {
		case 1:
			for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter) = aStormveilFloor1[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 2:
			for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter) = aStormveilFloor2[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 3:
			for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter) = aStormveilFloor3[nRowCounter][nColumnCounter];
				}
			}
			break;
	}

	return pFloor;
}

int* generateRayaLucaria(AreaFloor sAreaFloor) {
	int *pFloor = malloc(sizeof(int) * sAreaFloor.nRows * sAreaFloor.nColumns);

	int nRowCounter;
	int nColumnCounter;

	int aRayaLucariaFloor1[][5] = {{0, 0, 8, 0, 0}, 
								   {0, 0, 0, 0, 0},
								   {0, 0, 0, 0, 0},
								   {0, 6, 0, 6, 0},
				    			   {0, 0, 3, 0, 0}};	

	int aRayaLucariaFloor2[][3] = {{0, 2, 0},
								   {6, 0, 0}, 
						   		   {0, 0, 0}, 
						   		   {6, 0, 5}, 
						   		   {0, 0, 0}, 
						   		   {6, 0, 0}, 
						   		   {0, 0, 0}};

	int aRayaLucariaFloor3[][5] = {{10, 0, 2, 0, 10},
								   {10, 0, 6, 0, 10}, 
								   {0, 0, 0, 0, 0}, 
								   {4, 0, 0, 0, 5}, 
								   {0, 0, 0, 0, 0},
								   {10, 0, 6, 0, 10},
								   {10, 0, 0, 0, 10}};

	int aRayaLucariaFloor4[][6] = {{10, 0, 0, 0, 0, 0}, 
								   {0, 0, 6, 0, 6, 0},
								   {4, 0, 0, 0, 0, 0},
								   {0, 0, 6, 0, 6, 0},
								   {10, 0, 0, 0, 0, 0}};		

	int aRayaLucariaFloor5[][7] = {{10, 10, 0, 8, 0, 10, 10},
								   {0, 0, 0, 0, 0, 0, 0}, 
								   {0, 6, 0, 6, 0, 6, 0},
								   {0, 0, 0, 0, 0, 0, 0},
								   {0, 6, 0, 7, 0, 6, 0},
								   {0, 0, 0, 0, 0, 0, 0},
								   {0, 6, 0, 0, 0, 6, 0},
								   {0, 0, 0, 3, 0, 0, 0}};

	switch(sAreaFloor.nFloorNumber) {
		case 1:
			for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter) = aRayaLucariaFloor1[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 2:
			for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter) = aRayaLucariaFloor2[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 3:
			for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter) = aRayaLucariaFloor3[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 4:
			for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter) = aRayaLucariaFloor4[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 5:
			for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter) = aRayaLucariaFloor5[nRowCounter][nColumnCounter];
				}
			}
			break;
	}	

	return pFloor;
}

int* generateRedmaneCastle(AreaFloor sAreaFloor) {
	int *pFloor = malloc(sizeof(int) * sAreaFloor.nRows * sAreaFloor.nColumns);

	int nRowCounter;
	int nColumnCounter;

	int aRedManeCastleFloor1[][5] = {{0, 0, 0, 0, 0},
									 {8, 0, 6, 0, 5},
									 {0, 0, 0, 0, 0}};	

	int aRedManeCastleFloor2[][7] = {{0, 6, 0, 6, 0, 6, 0},
                                     {4, 0, 0, 0, 0, 0, 5},
                                     {0, 6, 0, 6, 0, 6, 0}};

	int aRedManeCastleFloor3[][5] = {{0, 0, 2, 0, 0}, 
									 {0, 0, 0, 0, 6},
								     {4, 0, 0, 0, 0}, 
								     {0, 0, 0, 0, 6}, 
								     {0, 6, 0, 6, 0}};

	int aRedManeCastleFloor4[][7] = {{0, 0, 0, 6, 0, 0, 0}, 
									 {0, 6, 0, 0, 0, 6, 0},
									 {4, 6, 0, 6, 0, 6, 0},
									 {0, 6, 0, 0, 0, 6, 0},
									 {0, 0, 0, 3, 0, 0, 0}};

	int aRedManeCastleFloor5[][5] = {{0, 0, 0, 0, 0},
									 {4, 0, 6, 0, 5}, 
									 {0, 0, 0, 0, 0}};	

	int aRedManeCastleFloor6[][4] = {{0, 0, 0, 0}, 
									 {0, 6, 0, 5}, 
									 {0, 0, 0, 0},  
									 {6, 0, 6, 10}, 
									 {0, 0, 0, 10}, 
									 {6, 0, 6, 10}, 
									 {0, 0, 0, 0}, 
									 {0, 6, 0, 5}, 
									 {0, 0, 0, 0}};

	int aRedManeCastleFloor7[][7] = {{0, 0, 0, 0, 0, 0, 0}, 
									 {0, 6, 0, 0, 0, 6, 0},
									 {4, 0, 0, 7, 0, 0, 8},
									 {0, 6, 0, 0, 0, 6, 0},
									 {0, 0, 0, 0, 0, 0, 0}};

    switch(sAreaFloor.nFloorNumber) {
		case 1:
			for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter) = aRedManeCastleFloor1[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 2:
			for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter) = aRedManeCastleFloor2[nRowCounter][nColumnCounter];
				}
			}
			break;


		case 3:
			for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter) = aRedManeCastleFloor3[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 4:
			for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter) = aRedManeCastleFloor4[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 5:
			for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter) = aRedManeCastleFloor5[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 6:
			for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter) = aRedManeCastleFloor6[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 7:
			for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter) = aRedManeCastleFloor7[nRowCounter][nColumnCounter];
				}
			}
			break;
    }

    return pFloor;
}

int* generateVolcanoManor(AreaFloor sAreaFloor) {
	int *pFloor = malloc(sizeof(int) * sAreaFloor.nRows * sAreaFloor.nColumns);

	int nRowCounter;
	int nColumnCounter;

	int aVolcanoManorFloor1[][5] = {{0, 0, 2, 0, 0}, 
									{0, 0, 0, 0, 0}, 
									{0, 6, 6, 6, 0},
							    	{0, 0, 0, 0, 0},
									{0, 0, 8, 0, 0}};

	int aVolcanoManorFloor2[][7] = {{0, 0, 0, 2, 0, 0, 0},
								    {0, 0, 0, 6, 0, 0, 0}, 
								   	{0, 0, 0, 0, 0, 0, 0},
									{4, 6, 0, 6, 0, 6, 5},
							    	{0, 0, 0, 0, 0, 0, 0},
									{0, 0, 0, 0, 0, 0, 0},
									{0, 0, 0, 3, 0, 0, 0}}; 


	int aVolcanoManorFloor3[][5] = {{10, 0, 6, 0, 0},  
									{0, 0, 0, 0, 0}, 
									{6, 0, 6, 0, 5}, 
									{0, 0, 0, 0, 0}, 
									{10, 0, 6, 0, 0}}; 

	int aVolcanoManorFloor4[][7] = {{10, 0, 0, 2, 0, 0, 10}, 
									{0, 0, 6, 0, 6, 0, 0},
									{4, 0, 0, 0, 0, 0, 6},
									{0, 0, 6, 0, 6, 0, 0},
									{10, 0, 0, 0, 0, 0, 10}}; 

	int aVolcanoManorFloor5[][3] = {{0, 0, 0},
									{0, 6, 0}, 
									{0, 0, 0},
									{10, 3, 10}}; 

	int aVolcanoManorFloor6[][3] = {{0, 2, 0}, 
									{0, 6, 0}, 
									{6, 0, 6},  
									{0, 0, 0}, 
									{0, 0, 0}, 
									{6, 0, 6}, 
									{0, 0, 0}, 
									{0, 3, 0}}; 

	int aVolcanoManorFloor7[][5] = {{0, 0, 8, 0, 0}, 
									{0, 0, 0, 0, 0},  
									{6, 0, 0, 0, 6},
									{6, 0, 7, 0, 6}, 
									{6, 0, 0, 0, 6}, 
									{0, 0, 0, 0, 0},
									{0, 0, 3, 0, 0}}; 

    switch(sAreaFloor.nFloorNumber) {
		case 1:
			for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter) = aVolcanoManorFloor1[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 2:
			for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter) = aVolcanoManorFloor2[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 3:
			for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter) = aVolcanoManorFloor3[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 4:
			for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter) = aVolcanoManorFloor4[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 5:
			for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter) = aVolcanoManorFloor5[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 6:
			for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter) = aVolcanoManorFloor6[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 7:
			for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter) = aVolcanoManorFloor7[nRowCounter][nColumnCounter];
				}
			}
			break;
    }		

    return pFloor;
}

int* generateLeyndellRoyalCapital(AreaFloor sAreaFloor) {
	int *pFloor = malloc(sizeof(int) * sAreaFloor.nRows * sAreaFloor.nColumns);

	int nRowCounter;
	int nColumnCounter;

	int aLeyndellCapitalFloor1[][3] = {{0, 2, 0}, 
									   {0, 0, 0}, 
									   {0, 0, 0}, 
									   {0, 8, 0}}; 

	int aLeyndellCapitalFloor2[][3] = {{0, 2, 0}, 
									   {6, 0, 6},  
					    			   {0, 0, 0}, 
									   {6, 0, 6}, 
									   {0, 0, 0}, 
								       {6, 0, 6},
									   {0, 3, 0}}; 

	int aLeyndellCapitalFloor3[][5] = {{0, 0, 6, 0, 0},  
									   {0, 10, 10, 10, 0},
									   {6, 10, 10, 10, 5}, 
									   {0, 10, 10, 10, 0}, 
									   {0, 0, 3, 0, 0}}; 

	int aLeyndellCapitalFloor4[][5] = {{0, 0, 2, 0, 0}, 
									   {4, 0, 0, 0, 0}, 
									   {0, 6, 0, 6, 0}}; 

	int aLeyndellCapitalFloor5[][15] = {{6, 2, 6, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0},
										{0, 6, 0, 0, 6, 0, 6, 0, 6, 0, 6, 0, 0, 0, 0},
										{0, 0, 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0, 0, 0},
										{0, 3, 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0, 3, 0}};

	int aLeyndellCapitalFloor6[][3] = {{0, 2, 0},
									   {0, 0 ,0},
						    		   {6, 6, 6}};													  

	int aLeyndellCapitalFloor7[][3] = {{10, 2, 10}, 
									   {6, 6, 6},  
									   {0, 0, 0}, 
									   {0, 0, 5}, 
									   {0, 0, 0}, 
									   {6, 6, 6}, 
									   {10, 3, 10}};

	int aLeyndellCapitalFloor8[][3] = {{10, 2, 10}, 
									   {6, 0, 6},  
									   {6, 0, 6}, 
									   {4, 0, 5}, 
									   {6, 0, 6}, 
									   {6, 0, 6}, 
									   {10, 3, 10}};

	int aLeyndellCapitalFloor9[][3] = {{10, 2, 10}, 
									   {6, 6, 6},  
									   {0, 0, 0}, 
									   {4, 0, 0}, 
									   {0, 0, 0},
									   {6, 6, 6}, 
									   {10, 3, 10}};

	int aLeyndellCapitalFloor10[][15] = {{0, 0, 0, 6, 0, 0, 0, 2, 0, 0, 0, 6, 0, 0, 0},
									     {0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0},
									     {0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0},
									     {0, 3, 0, 6, 0, 0, 0, 3, 0, 0, 0, 6, 0, 3, 0}};

	int aLeyndellCapitalFloor11[][13] = {{6, 0, 0, 6, 0, 0, 0, 0, 10, 10, 10, 10, 10},
										 {0, 0, 0, 6, 0, 0, 3, 0, 10, 10, 10, 10, 10},
										 {6, 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
										 {0, 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
										 {6, 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
										 {0, 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
										 {6, 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
										 {0, 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
										 {6, 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0, 6},
										 {4, 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0, 5},
										 {6, 0, 10, 10, 10, 10, 10, 10, 10, 10, 10, 0, 6},
										 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
										 {6, 0, 0, 0, 0, 6, 3, 6, 0, 0, 0, 0, 6}};

	int aLeyndellCapitalFloor12[][3] = {{0, 0, 0}, 
									    {6, 0, 5},
										{0, 0, 0}}; 

	int aLeyndellCapitalFloor13[][3] = {{0, 0, 0}, 
										{4, 0, 6},
										{0, 0, 0}}; 

	int aLeyndellCapitalFloor14[][5] = {{10, 0, 2, 0, 10}, 
										{6, 0, 0, 0, 6},  
										{0, 0, 0, 0, 0}, 
										{6, 0, 7, 0, 6}, 
										{0, 0, 0, 0, 0}, 
										{6, 0, 0, 0, 6}, 
										{10, 0, 8, 0, 10}}; 	

	switch(sAreaFloor.nFloorNumber) {
		case 1:
			for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter) = aLeyndellCapitalFloor1[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 2:
			for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter) = aLeyndellCapitalFloor2[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 3:
			for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter) = aLeyndellCapitalFloor3[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 4:
			for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter) = aLeyndellCapitalFloor4[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 5:
			for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter) = aLeyndellCapitalFloor5[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 6:
			for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter) = aLeyndellCapitalFloor6[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 7:
			for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter) = aLeyndellCapitalFloor7[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 8:
			for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter) = aLeyndellCapitalFloor8[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 9:
			for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter) = aLeyndellCapitalFloor9[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 10:
			for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter) = aLeyndellCapitalFloor10[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 11:
			for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter) = aLeyndellCapitalFloor11[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 12:
			for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter) = aLeyndellCapitalFloor12[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 13:
			for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter) = aLeyndellCapitalFloor13[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 14:
			for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter) = aLeyndellCapitalFloor14[nRowCounter][nColumnCounter];
				}
			}
			break;
	}	

	return pFloor;
}

int* generateEldenThrone(AreaFloor sAreaFloor) {
	int *pFloor = malloc(sizeof(int) * sAreaFloor.nRows * sAreaFloor.nColumns);

	int nRowCounter;
	int nColumnCounter;

	int aEldenThroneFloor1[][3] =  {{0, 2, 0}, 
									{0, 0, 0},  
									{0, 0, 0}, 
									{0, 0, 0}, 
									{0, 6, 0}, 
									{0, 0, 0},
									{0, 0, 0},
									{0, 0, 0},
									{0, 8, 0}};

	int aEldenThroneFloor2[][7] =  {{10, 0, 0, 2, 0, 0, 10}, 
									{0, 0, 0, 0, 0, 0, 0},
									{0, 0, 0, 0, 0, 0, 0},
								    {0, 0, 0, 7, 0, 0, 0},
									{0, 0, 0, 0, 0, 0, 0},
									{0, 0, 0, 0, 0, 0, 0},
									{10, 0, 0, 3, 0, 0, 10}}; 

	int aEldenThroneFloor3[][3] =  {{0, 9, 0}, 
									{6, 0, 6},  
									{0, 0, 0}, 
								    {6, 0, 6}, 
									{0, 0, 0}, 
									{6, 0, 6}, 
									{0, 0, 0}, 
									{6, 0, 6}, 
									{0, 3, 0}};	

	switch(sAreaFloor.nFloorNumber) {
		case 1:
			for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter) = aEldenThroneFloor1[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 2:
			for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter) = aEldenThroneFloor2[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 3:
			for (nRowCounter = 0; nRowCounter < sAreaFloor.nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < sAreaFloor.nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * sAreaFloor.nColumns) + nColumnCounter) = aEldenThroneFloor3[nRowCounter][nColumnCounter];
				}
			}
			break;
	}

	return pFloor;
}

int* generateArea(AreaFloor sAreaFloor) {
	int* pFloor;

	switch(sAreaFloor.nAreaIndex) {
			case STORMVEIL_CASTLE:
				pFloor = generateStromveilCastle(sAreaFloor);
				break;

			case RAYA_LUCARIA_ACADEMY:
				pFloor =  generateRayaLucaria(sAreaFloor);
				break;

			case REDMANE_CASTLE:
				pFloor = generateRedmaneCastle(sAreaFloor);
				break;

			case VOLCANO_MANOR:
				pFloor = generateVolcanoManor(sAreaFloor);
				break;

			case LEYNDELL_ROYAL_CAPITAL:
				pFloor = generateLeyndellRoyalCapital(sAreaFloor);
				break;

			case THE_ELDEN_THRONE:
				pFloor = generateEldenThrone(sAreaFloor);
	}

	return pFloor;
}