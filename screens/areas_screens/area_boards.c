#include "area_boards.h"

int* generateStromveilCastle(int nFloor, int nRows, int nColumns) {
	int *pFloor = malloc(sizeof(int) * nRows * nColumns);

	int nRowCounter;
	int nColumnCounter;

	int aStormveilFloor1[][3] = {{0, 2, 0},
								 {4, 0, 4}, 
								 {0, 0, 0},
								 {0, 0, 0},
								 {0, 0, 0},
								 {0, 0, 0},
								 {0, 6, 0}};

	int aStormveilFloor2[][7] = {{0, 0, 0, 2, 0, 0, 0},
								 {0, 0, 0, 4, 0, 0, 0}, 
								 {0, 0, 0, 0, 0, 0, 0},
								 {4, 0, 4, 4, 4, 0, 4},
								 {0, 0, 0, 0, 0, 0, 0},
								 {0, 0, 4, 0, 4, 0, 0},
								 {0, 0, 0, 3, 0, 0, 0}};

	int aStormveilFloor3[][5] = {{0, 0, 6, 0, 0}, 
								 {0, 0, 0, 0, 0},  
								 {0, 0, 0, 0, 0},
					 			 {0, 0, 5, 0, 0}, 
						  		 {0, 0, 0, 0, 0}, 
						  		 {0, 0, 0, 0, 0}, 
						  		 {0, 0, 3, 0, 0}};


	switch(nFloor) {
		case 1:
			for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * nColumns) + nColumnCounter) = aStormveilFloor1[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 2:
			for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * nColumns) + nColumnCounter) = aStormveilFloor2[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 3:
			for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * nColumns) + nColumnCounter) = aStormveilFloor3[nRowCounter][nColumnCounter];
				}
			}
			break;
	}

	return pFloor;
}

int* generateRayaLucaria(int nFloor, int nRows, int nColumns) {
	int *pFloor = malloc(sizeof(int) * nRows * nColumns);

	int nRowCounter;
	int nColumnCounter;

	int aRayaLucariaFloor1[][5] = {{0, 0, 6, 0, 0}, 
								   {0, 0, 0, 0, 0},
								   {0, 0, 0, 0, 0},
								   {0, 4, 0, 4, 0},
				    			   {0, 0, 2, 0, 0}};	

	int aRayaLucariaFloor2[][3] = {{0, 3, 0},
								   {4, 0, 0}, 
						   		   {0, 0, 0}, 
						   		   {4, 0, 2}, 
						   		   {0, 0, 0}, 
						   		   {4, 0, 0}, 
						   		   {0, 0, 0}};

	int aRayaLucariaFloor3[][5] = {{8, 0, 2, 0, 8},
								   {8, 0, 4, 0, 8}, 
								   {0, 0, 0, 0, 0}, 
								   {3, 0, 0, 0, 2}, 
								   {0, 0, 0, 0, 0},
								   {8, 0, 4, 0, 8},
								   {8, 0, 0, 0, 8}};

	int aRayaLucariaFloor4[][6] = {{8, 0, 0, 0, 0, 0}, 
								   {0, 0, 4, 0, 4, 0},
								   {3, 0, 0, 0, 0, 0},
								   {0, 0, 4, 0, 4, 0},
								   {8, 0, 0, 0, 0, 0}};		

	int aRayaLucariaFloor5[][7] = {{8, 8, 0, 6, 0, 8, 8},
								   {0, 0, 0, 0, 0, 0, 0}, 
								   {0, 4, 0, 4, 0, 4, 0},
								   {0, 0, 0, 0, 0, 0, 0},
								   {0, 4, 0, 5, 0, 4, 0},
								   {0, 0, 0, 0, 0, 0, 0},
								   {0, 4, 0, 0, 0, 4, 0},
								   {0, 0, 0, 3, 0, 0, 0}};

	switch(nFloor) {
		case 1:
			for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * nColumns) + nColumnCounter) = aRayaLucariaFloor1[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 2:
			for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * nColumns) + nColumnCounter) = aRayaLucariaFloor2[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 3:
			for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * nColumns) + nColumnCounter) = aRayaLucariaFloor3[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 4:
			for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * nColumns) + nColumnCounter) = aRayaLucariaFloor4[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 5:
			for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * nColumns) + nColumnCounter) = aRayaLucariaFloor5[nRowCounter][nColumnCounter];
				}
			}
			break;
	}	

	return pFloor;
}

int* generateRedmaneCastle(int nFloor, int nRows, int nColumns) {
	int *pFloor = malloc(sizeof(int) * nRows * nColumns);

	int nRowCounter;
	int nColumnCounter;

	int aRedManeCastleFloor1[][7] = {{0, 0, 0, 0, 0, 0, 0},
									 {6, 0, 0, 4, 0, 0, 2},
									 {0, 0, 0, 0, 0, 0, 0}};	

	int aRedManeCastleFloor2[][7] = {{0, 4, 0, 4, 0, 4, 0},
                                     {3, 0, 0, 0, 0, 0, 2},
                                     {0, 4, 0, 4, 0, 4, 0}};

	int aRedManeCastleFloor3[][5] = {{0, 0, 2, 0, 0}, 
									 {0, 0, 0, 0, 4},
								     {3, 0, 0, 0, 0}, 
								     {0, 0, 0, 0, 4}, 
								     {0, 4, 0, 4, 0}};

	int aRedManeCastleFloor4[][7] = {{0, 0, 0, 4, 0, 0, 0}, 
									 {0, 4, 0, 0, 0, 4, 0},
									 {2, 4, 0, 4, 0, 4, 0},
									 {0, 4, 0, 0, 0, 4, 0},
									 {0, 0, 0, 3, 0, 0, 0}};

	int aRedManeCastleFloor5[][5] = {{0, 0, 0, 0, 0},
									 {2, 0, 4, 0, 3}, 
									 {0, 0, 0, 0, 0}};	

	int aRedManeCastleFloor6[][4] = {{0, 0, 0, 0}, 
									 {0, 4, 0, 2}, 
									 {0, 0, 0, 0},  
									 {4, 0, 4, 8}, 
									 {0, 0, 0, 8}, 
									 {4, 0, 4, 8}, 
									 {0, 0, 0, 0}, 
									 {0, 4, 0, 3}, 
									 {0, 0, 0, 0}};

	int aRedManeCastleFloor7[][7] = {{0, 0, 0, 0, 0, 0, 0}, 
									 {0, 4, 0, 0, 0, 4, 0},
									 {3, 0, 0, 5, 0, 0, 6},
									 {0, 4, 0, 0, 0, 4, 0},
									 {0, 0, 0, 0, 0, 0, 0}};

    switch(nFloor) {
		case 1:
			for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * nColumns) + nColumnCounter) = aRedManeCastleFloor1[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 2:
			for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * nColumns) + nColumnCounter) = aRedManeCastleFloor2[nRowCounter][nColumnCounter];
				}
			}
			break;


		case 3:
			for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * nColumns) + nColumnCounter) = aRedManeCastleFloor3[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 4:
			for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * nColumns) + nColumnCounter) = aRedManeCastleFloor4[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 5:
			for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * nColumns) + nColumnCounter) = aRedManeCastleFloor5[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 6:
			for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * nColumns) + nColumnCounter) = aRedManeCastleFloor6[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 7:
			for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * nColumns) + nColumnCounter) = aRedManeCastleFloor7[nRowCounter][nColumnCounter];
				}
			}
			break;
    }

    return pFloor;
}

int* generateVolcanoManor(int nFloor, int nRows, int nColumns) {
	int *pFloor = malloc(sizeof(int) * nRows * nColumns);

	int nRowCounter;
	int nColumnCounter;

	int aVolcanoManorFloor1[][5] = {{0, 0, 2, 0, 0}, 
									{0, 0, 0, 0, 0}, 
									{0, 4, 4, 4, 0},
							    	{0, 0, 0, 0, 0},
									{0, 0, 6, 0, 0}};

	int aVolcanoManorFloor2[][7] = {{0, 0, 0, 2, 0, 0, 0},
								    {0, 0, 0, 4, 0, 0, 0}, 
								   	{0, 0, 0, 0, 0, 0, 0},
									{2, 4, 0, 4, 0, 4, 2},
							    	{0, 0, 0, 0, 0, 0, 0},
									{0, 0, 0, 0, 0, 0, 0},
									{0, 0, 0, 3, 0, 0, 0}}; 


	int aVolcanoManorFloor3[][5] = {{8, 0, 4, 0, 0},  
									{0, 0, 0, 0, 0}, 
									{4, 0, 4, 0, 3}, 
									{0, 0, 0, 0, 0}, 
									{8, 0, 4, 0, 0}}; 

	int aVolcanoManorFloor4[][7] = {{8, 0, 0, 2, 0, 0, 8}, 
									{0, 0, 4, 0, 4, 0, 0},
									{3, 0, 0, 0, 0, 0, 4},
									{0, 0, 4, 0, 4, 0, 0},
									{8, 0, 0, 0, 0, 0, 8}}; 

	int aVolcanoManorFloor5[][3] = {{0, 0, 0},
									{0, 4, 0}, 
									{0, 0, 0},
									{8, 3, 8}}; 

	int aVolcanoManorFloor6[][3] = {{0, 2, 0}, 
									{0, 4, 0}, 
									{4, 0, 4},  
									{0, 0, 0}, 
									{0, 0, 0}, 
									{4, 0, 4}, 
									{0, 0, 0}, 
									{0, 3, 0}}; 

	int aVolcanoManorFloor7[][5] = {{0, 0, 6, 0, 0}, 
									{0, 0, 0, 0, 0},  
									{4, 0, 0, 0, 4},
									{4, 0, 5, 0, 4}, 
									{4, 0, 0, 0, 4}, 
									{0, 0, 0, 0, 0},
									{0, 0, 3, 0, 0}}; 

    switch(nFloor) {
		case 1:
			for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * nColumns) + nColumnCounter) = aVolcanoManorFloor1[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 2:
			for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * nColumns) + nColumnCounter) = aVolcanoManorFloor2[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 3:
			for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * nColumns) + nColumnCounter) = aVolcanoManorFloor3[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 4:
			for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * nColumns) + nColumnCounter) = aVolcanoManorFloor4[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 5:
			for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * nColumns) + nColumnCounter) = aVolcanoManorFloor5[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 6:
			for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * nColumns) + nColumnCounter) = aVolcanoManorFloor6[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 7:
			for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * nColumns) + nColumnCounter) = aVolcanoManorFloor7[nRowCounter][nColumnCounter];
				}
			}
			break;
    }		

    return pFloor;
}

int* generateLeyndellRoyalCapital(int nFloor, int nRows, int nColumns) {
	int *pFloor = malloc(sizeof(int) * nRows * nColumns);

	int nRowCounter;
	int nColumnCounter;

	int aLeyndellCapitalFloor1[][3] = {{0, 2, 0}, 
									   {0, 0, 0}, 
									   {0, 0, 0}, 
									   {0, 6, 0}}; 

	int aLeyndellCapitalFloor2[][3] = {{0, 2, 0}, 
									   {4, 0, 4},  
					    			   {0, 0, 0}, 
									   {4, 0, 4}, 
									   {0, 0, 0}, 
								       {4, 0, 4},
									   {0, 3, 0}}; 

	int aLeyndellCapitalFloor3[][5] = {{0, 0, 4, 0, 0},  
									   {0, 8, 8, 8, 0},
									   {4, 8, 8, 8, 2}, 
									   {0, 8, 8, 8, 0}, 
									   {0, 0, 3, 0, 0}}; 

	int aLeyndellCapitalFloor4[][5] = {{0, 0, 2, 0, 0}, 
									   {3, 0, 0, 0, 0}, 
									   {0, 4, 0, 4, 0}}; 

	int aLeyndellCapitalFloor5[][15] = {{4, 2, 4, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 2, 0},
										{0, 4, 0, 0, 4, 0, 4, 0, 4, 0, 4, 0, 0, 0, 0},
										{0, 0, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 0, 0},
										{0, 2, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 3, 0}};

	int aLeyndellCapitalFloor6[][3] = {{0, 3, 0},
									   {0, 0 ,0},
						    		   {4, 4, 4}};													  

	int aLeyndellCapitalFloor7[][3] = {{8, 2, 8}, 
									   {4, 4, 4},  
									   {0, 0, 0}, 
									   {0, 0, 3}, 
									   {0, 0, 0}, 
									   {4, 4, 4}, 
									   {8, 3, 8}};

	int aLeyndellCapitalFloor8[][3] = {{8, 2, 8}, 
									   {4, 0, 4},  
									   {4, 0, 4}, 
									   {2, 0, 2}, 
									   {4, 0, 4}, 
									   {4, 0, 4}, 
									   {8, 3, 8}};

	int aLeyndellCapitalFloor9[][3] = {{8, 2, 8}, 
									   {4, 4, 4},  
									   {0, 0, 0}, 
									   {3, 0, 0}, 
									   {0, 0, 0},
									   {4, 4, 4}, 
									   {8, 3, 8}};

	int aLeyndellCapitalFloor10[][15] = {{0, 0, 0, 4, 0, 0, 0, 2, 0, 0, 0, 4, 0, 0, 0},
									     {0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0},
									     {0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0},
									     {0, 3, 0, 4, 0, 0, 0, 3, 0, 0, 0, 4, 0, 3, 0}};

	int aLeyndellCapitalFloor11[][13] = {{4, 0, 0, 4, 0, 0, 0, 0, 8, 8, 8, 8, 8},
										 {0, 0, 0, 3, 0, 0, 2, 0, 8, 8, 8, 8, 8},
										 {4, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
										 {0, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
										 {4, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
										 {0, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
										 {4, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
										 {0, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
										 {4, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 4},
										 {2, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 2},
										 {4, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 0, 4},
										 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
										 {4, 0, 0, 0, 0, 4, 3, 4, 0, 0, 0, 0, 4}};

	int aLeyndellCapitalFloor12[][3] = {{0, 0, 0}, 
									    {4, 0, 3},
										{0, 0, 0}}; 

	int aLeyndellCapitalFloor13[][3] = {{0, 0, 0}, 
										{3, 0, 4},
										{0, 0, 0}}; 

	int aLeyndellCapitalFloor14[][5] = {{8, 0, 3, 0, 8}, 
										{4, 0, 0, 0, 4},  
										{0, 0, 0, 0, 0}, 
										{4, 0, 5, 0, 4}, 
										{0, 0, 0, 0, 0}, 
										{4, 0, 0, 0, 4}, 
										{8, 0, 6, 0, 8}}; 	

	switch(nFloor) {
		case 1:
			for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * nColumns) + nColumnCounter) = aLeyndellCapitalFloor1[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 2:
			for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * nColumns) + nColumnCounter) = aLeyndellCapitalFloor2[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 3:
			for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * nColumns) + nColumnCounter) = aLeyndellCapitalFloor3[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 4:
			for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * nColumns) + nColumnCounter) = aLeyndellCapitalFloor4[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 5:
			for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * nColumns) + nColumnCounter) = aLeyndellCapitalFloor5[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 6:
			for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * nColumns) + nColumnCounter) = aLeyndellCapitalFloor6[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 7:
			for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * nColumns) + nColumnCounter) = aLeyndellCapitalFloor7[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 8:
			for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * nColumns) + nColumnCounter) = aLeyndellCapitalFloor8[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 9:
			for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * nColumns) + nColumnCounter) = aLeyndellCapitalFloor9[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 10:
			for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * nColumns) + nColumnCounter) = aLeyndellCapitalFloor10[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 11:
			for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * nColumns) + nColumnCounter) = aLeyndellCapitalFloor11[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 12:
			for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * nColumns) + nColumnCounter) = aLeyndellCapitalFloor12[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 13:
			for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * nColumns) + nColumnCounter) = aLeyndellCapitalFloor13[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 14:
			for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * nColumns) + nColumnCounter) = aLeyndellCapitalFloor14[nRowCounter][nColumnCounter];
				}
			}
			break;
	}	

	return pFloor;
}

int* generateEldenThrone(int nFloor, int nRows, int nColumns) {
	int *pFloor = malloc(sizeof(int) * nRows * nColumns);

	int nRowCounter;
	int nColumnCounter;

	int aEldenThroneFloor1[][3] =  {{0, 2, 0}, 
									{0, 0, 0},  
									{0, 0, 0}, 
									{0, 0, 0}, 
									{0, 4, 0}, 
									{0, 0, 0},
									{0, 0, 0},
									{0, 0, 0},
									{0, 6, 0}};

	int aEldenThroneFloor2[][7] =  {{8, 0, 0, 2, 0, 0, 8}, 
									{0, 0, 0, 0, 0, 0, 0},
									{0, 0, 0, 0, 0, 0, 0},
								    {0, 0, 0, 5, 0, 0, 0},
									{0, 0, 0, 0, 0, 0, 0},
									{0, 0, 0, 0, 0, 0, 0},
									{8, 0, 0, 3, 0, 0, 8}}; 

	int aEldenThroneFloor3[][3] =  {{0, 7, 0}, 
									{4, 0, 4},  
									{0, 0, 0}, 
								    {4, 0, 4}, 
									{0, 0, 0}, 
									{4, 0, 4}, 
									{0, 0, 0}, 
									{4, 0, 4}, 
									{0, 6, 0}};	

	switch(nFloor) {
		case 1:
			for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * nColumns) + nColumnCounter) = aEldenThroneFloor1[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 2:
			for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * nColumns) + nColumnCounter) = aEldenThroneFloor2[nRowCounter][nColumnCounter];
				}
			}
			break;

		case 3:
			for (nRowCounter = 0; nRowCounter < nRows; nRowCounter++) {
				for (nColumnCounter = 0; nColumnCounter < nColumns; nColumnCounter++) {
					*(pFloor + (nRowCounter * nColumns) + nColumnCounter) = aEldenThroneFloor3[nRowCounter][nColumnCounter];
				}
			}
			break;
	}

	return pFloor;
}

int* generateArea(int nAreaIndex, int nFloor, int nRows, int nColumns) {
	int* pFloor;

	switch(nAreaIndex) {
			case STORMVEIL_CASTLE:
				pFloor = generateStromveilCastle(nFloor, nRows, nColumn);
				break;

			case RAYA_LUCARIA_ACADEMY:
				pFloor =  generateRayaLucaria(nFloor, nRows, nColumn);
				break;

			case REDMANE_CASTLE:
				pFloor = generateRedmaneCastle(nFloor, nRows, nColumn);
				break;

			case VOLCANO_MANOR:
				pFloor = generateVolcanoManor(nFloor, nRows, nColumn);
				break;

			case LEYNDELL_ROYAL_CAPITAL:
				pFloor = generateLeyndellRoyalCapital(nFloor, nRows, nColumn);
				break;

			case THE_ELDEN_THRONE:
				pFloor = generateEldenThrone(nFloor, nRows, nColumn);
	}

	return pFloor;
}