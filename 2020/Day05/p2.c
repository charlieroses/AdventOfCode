#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Gotten from
// https://www.tutorialspoint.com/c_standard_library/c_function_qsort.htm
int compare(const void * a, const void * b) {
	return ( *(int*)a - *(int*)b );
}

int main() {
	FILE *fp;
	char buf[256];
	int i;
	int nR, xR, nC, xC, c, r, id, max;
	int *ids;
	int idlen, cid;

	fp = fopen("input.txt", "r");

	cid = 0;
	idlen = 1;

	ids = (int *)malloc(idlen * sizeof(int));

	max = 0;
	while( fscanf(fp, "%s\n", buf) != EOF ) {
		nR = 0;
		xR = 128;
		nC = 0;
		xC = 8;
		c = 0;
		r = 0;
		// YOU IDIOT ITS JUST BINARY
		for( i = 0; i < 6; i++)
		{
			if( buf[i] == 'F'){
				xR = floor((xR + nR) / 2);
			}
			else if (buf[i] == 'B') {
				nR = ceil((xR + nR) / 2);
			}
		}

		if( buf[6] == 'F' ) {
			r = nR;
		}
		else {
			r = xR - 1;
		}

		for( i = 7; i < 9; i++) {
			if( buf[i] == 'L'){
				xC = floor((xC + nC) / 2);
			}
			else if (buf[i] == 'R') {
				nC = floor((xC + nC) / 2);
			}
		}

		if( buf[9] == 'L' ) {
			c = nC;
		}
		else {
			c = xC - 1;
		}

		id = (r * 8) + c;

		if( max < id ) {
			max = id;
		}

		ids[cid] = id;
		cid += 1;
		if( cid == idlen) {
			idlen *= 2;
			ids = (int *)realloc(ids, idlen*sizeof(int));
		}

	}

	qsort(ids, cid, sizeof(int), compare);

	for( i = 1; i < cid; i++) {
		if( ids[i] - ids[i-1] > 1 ) {
			printf("%d\n", (ids[i] - 1));
		}
	}

	fclose(fp);
}

