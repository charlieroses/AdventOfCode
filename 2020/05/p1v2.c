#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE *fp;
	char buf[256];
	int i;
	int nR, xR, nC, xC, c, r, id, max;

	fp = fopen("input.txt", "r");

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

		printf("%s %d %d %d \n", buf, r, c, id);

		if( max < id ) {
			max = id;
		}

	}

	printf("%d\n", max);

	fclose(fp);
}
