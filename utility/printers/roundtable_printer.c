#include "roundtable_printer.h"

void printShards(int nShards) {
	int nPrintShard; 
	int nMissingShard;

	printf("SHARDS: ");
	for (nPrintShard = 0; nPrintShard < nShards; nPrintShard++) {
		colorText(COLOR_SHARD);
		printf("█ ");
	}

	for (nMissingShard = nPrintShard; nMissingShard < 6; nMissingShard++) {
		colorText(COLOR_DAMAGED_BAR);
		printf("░ ");
	}

	printf("\n");
}