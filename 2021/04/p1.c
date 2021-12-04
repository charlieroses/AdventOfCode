#include <stdio.h>
#include <stdlib.h>

int checkbingo( int *board ) {
	int win;
	int cntr, cntc;
	int i, j;

	win = 0;

	for( i = 0; i < 5; i++ ) {
		cntr = 0;
		cntc = 0;
		for( j = 0; j < 5; j++ ) {
			cntr += board[(i*5) + j];
			cntc += board[(j*5) + i];
		}
		win += (cntr == 5);
		win += (cntc == 5);
	}

	return win;
}


int main() {
	int i, j, k, n;
	int vallen, VL;
	int *vals;
	int brdlen, BL;
	int *boards;
	int *boardC;
	int bi, bn;
	int winner;
	int winval;

	i = 0;
	vallen = 10;
	vals = (int*)malloc(vallen*sizeof(int));
	scanf("%d", &vals[0]);
	i++;

	while( scanf(",%d", &n) == 1 ) {
		if( n < 0 )
			break;
		vals[i] = n;

		i += 1;
		if( i == vallen ) {
			vallen *= 2;
			vals = (int*)realloc(vals, vallen * sizeof(int));
		}
	}
	VL = i;


	i = 0;
	brdlen = 10;
	boards = (int*)malloc(vallen*sizeof(int));
	boardC = (int*)malloc(vallen*sizeof(int));
	while( scanf("%d", &n) == 1 ) {
		boards[i] = n;
		boardC[i] = 0;

		i += 1;
		if( i == brdlen ) {
			brdlen *= 2;
			boards = (int*)realloc(boards, brdlen * sizeof(int));
			boardC = (int*)realloc(boardC, brdlen * sizeof(int));
		}
	}
	BL = i;
	bn = BL / 25;

	winner = -1;
	for( i = 0; i < VL; i++) {
		for( j = 0; j < BL; j++) {
			if( boards[j] == vals[i] )
				boardC[j] = 1;
		}

		for( j = 0; j < bn; j++ ) {
			n = checkbingo( &boardC[j*25] );
			
			if( n > 0 ) {
				winval = vals[i];
				winner = j;
				break;
			}
		}

		if( winner > -1 )
			break;
	}

	n = 0;
	for( i = 0; i < 25; i++ ) {
		if( boardC[(winner * 25) + i] == 0 )
			n += boards[(winner * 25) + i];
	}

	printf("%d %d %d\n", winner, n, winval);
	printf("%d\n", n * winval);

	free(vals);
	free(boards);
	free(boardC);
}
