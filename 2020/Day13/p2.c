#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *fp;
	int val, off, i, f, fid, t, j, k;
	char c;
	int *buses, *offset;
	int busL, busM;
	long time, M, Mi, a, b;

	fp = fopen("input.txt", "r");

	busL = 0;
	busM = 1;
	buses = malloc(busM * sizeof(int));
	offset = malloc(busM * sizeof(int));


	fscanf(fp, "%d\n", &val);
	val = 0;
	off = 0;
	M = 1;

	c = fgetc(fp);
	while( c != EOF ) {
		if( c == 'x' ) {
			off += 1;
			c = fgetc(fp); // get the extra comma
		}
		else if( c == ',' ) {
			buses[busL] = val;
			offset[busL] = off;
			M *= val;
			val = 0;
			off += 1;

			busL += 1;
			if( busL == busM ) {
				busM *= 2;
				buses = realloc(buses, busM * sizeof(int));
				offset = realloc(offset, busM * sizeof(int));
			}
		}
		else {
			val = (val * 10) + atoi(&c);
		}

		c = fgetc(fp);
	}

	fclose(fp);

	// Now you can code king ((:E
	time = 0;
	for( i = 0; i < busL; i++ ) {
		Mi = M / buses[i];
		a = buses[i] - offset[i];
		b = Mi % buses[i];

		// To solve for the modulo
		j = 1;
		k = 1;
		while( (b * k) != ((buses[i] * j) + 1) ) {
			if( (b * k) > ((buses[i] * j) + 1) ) {
				j += 1;
			}
			k += 1;
		}

		time += (a * (k % buses[i]) * Mi);
	}

	time = time % M;

	printf("%ld\n", time);

	free(buses);
}
