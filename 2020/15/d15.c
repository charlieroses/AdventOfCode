#include <stdio.h>
#include <stdlib.h>

int main() {
	int *lastTurn;
	int puzzleIn[7] = {13, 0, 10, 12, 1, 5, 8};
	int i, j, piL, ltL, num, nnum;

	piL = 7;

	ltL = 14;
	lastTurn = malloc(ltL * sizeof(int));

	num = puzzleIn[0];
	for( i = 1; i <= 30000000; i++ ) {

		printf("%d %d\n", i, num);
		if( i < piL ) {
			nnum = puzzleIn[i];
		}
		else {
			if( lastTurn[num] > 0 ) {
				nnum = i - lastTurn[num];
			}
			else {
				nnum = 0;
			}
		}

		if( nnum >= ltL ) {
			printf("realloc: o%d n%d \n", ltL, nnum*2);
			lastTurn = realloc(lastTurn, (nnum*2) * sizeof(int));

			for( j = ltL; j < (nnum*2); j++) {
				lastTurn[j] = 0;
			}

			ltL = (nnum*2);
		}

		lastTurn[num] = i;
		num = nnum;
	}

	free(lastTurn);
}

