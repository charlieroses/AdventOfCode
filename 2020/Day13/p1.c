#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *fp;
	int val, i, f, fid, t;
	char c;
	int *buses;
	int busL, busM;
	int time;

	fp = fopen("input.txt", "r");

	busL = 0;
	busM = 1;
	buses = malloc(busM * sizeof(int));

	val = 0;

	fscanf(fp, "%d\n", &time);
	c = fgetc(fp);
	while( c != EOF ) {
		if( c == 'x' ) {
			c = fgetc(fp); // get the extra comma
		}
		else if( c == ',' ) {
			buses[busL] = val;
			printf("%d\n", val);
			val = 0;

			busL += 1;
			if( busL == busM ) {
				busM *= 2;
				buses = realloc(buses, busM * sizeof(int));
			}
		}
		else {
			val = (val * 10) + atoi(&c);
		}

		c = fgetc(fp);
	}

	fclose(fp);

	// Now you can code king ((:E

	for( i = 0; i < busL; i++ ) {
		t = floor(time / buses[i]);
		t = buses[i] * (t + 1);

		if( i == 0 ) {
			f = t - time;
			fid = buses[0];
		}
		else {
			if( t - time < f ) {
				f = t - time;
				fid = buses[i];
			}
		}
	}

	printf("%d %d %d\n", f, fid, f * fid);

	free(buses);
}
