#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **bitmaps;
int bmL, bi;

int find(long val, long ada[], int adaL);
int fillBitMaps(char *mask, int i);

int main() {
	FILE *fp;
	char buf[256];
	char *mask;
	int i, j, obmL;
	int memM, memL;
	long *memLoc, *memVal;
	long n, memV, t, memC, nmemC, v;

	memL = 0;
	memM = 1;
	memLoc = malloc(memM * sizeof(long));
	memVal= malloc(memM * sizeof(long));

	bmL = 1;
	obmL = 1;
	bitmaps = malloc( sizeof(char*) );

	mask = malloc(36 * sizeof(char));

	fp = fopen("input.txt", "r");

	while( fgets(buf, 256, fp) != NULL ) {
		if( buf[1] == 'a' ){
			// MASK LINE

			sscanf(buf, "mask = %s\n", mask);

			obmL = bmL;
			bmL = 1;
			for( i = 0; i < 36; i++) {
				if (mask[i] == 'X') {
					bmL *= 2;
				}
			}

			if( bmL > obmL ) {
				fprintf(stderr, "No seg fault here %d\n", bmL);
				bitmaps = realloc(bitmaps, bmL * sizeof(char*));
				fprintf(stderr, "No seg fault here either\n");
			}
			bi = 0;
		}
		else {
			// MEM LINE
			sscanf(buf, "mem[%ld] = %ld\n", &memC, &memV);

			n = 1;
			for( i = 35; i >= 0; i-- ) {
				t = memC & n;
				if( t == n && mask[i] == '0') {
					mask[i] = '1';
				}
				n *= 2;
			}

			fillBitMaps(mask, 0);

			for( j = 0; j < bmL; j++) {
				v = 0;
				n = 1;
				for(i = 35; i >= 0; i--) {
					v += ( n * (bitmaps[j][i] == '1'));
					n *= 2;
				}

				i = find(v, memLoc, memL);
				if( i == -1 ) {
					memLoc[memL] = v;
					memVal[memL] = memV;

					memL += 1;
					if( memL == memM ){
						memM *= 2;
						memLoc = realloc(memLoc, memM * sizeof(long));
						memVal = realloc(memVal, memM * sizeof(long));
					}
				}
				else {
					memVal[i] = memV;
				}
			}
		}
	}

	t = 0;
	for(i = 0; i < memL; i++) {
		t += memVal[i];
		printf("%ld : %ld\n", memLoc[i], memVal[i]);
	}

	printf("%ld\n", t);

	fclose(fp);
	free(memLoc);
	free(memVal);
	free(mask);
	free(bitmaps);
}

int find(long val, long arr[], int arrL) {
	int i;

	for( i = 0; i < arrL; i++) {
		if( val == arr[i] ) {
			return i;
		}
	}

	return -1;
}

int fillBitMaps(char* mask, int i) {
	char *c;
	if( i == 36 ) {
		bitmaps[bi] = mask;
		bi += 1;
	}
	else {
		if ( mask[i] != 'X' ) {
			fillBitMaps(mask, i+1);
		}
		else {
			c = malloc( 36 * sizeof(char) );
			strcpy(c, mask);
			c[i] = '0';
			mask[i] = '1';
			fillBitMaps(c, i + 1);
			fillBitMaps(mask, i + 1);
			free(c);
		}
	}
}

