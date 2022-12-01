#include <stdio.h>
#include <stdlib.h>

int find(int val, int ada[], int adaL);

int main() {
	FILE *fp;
	char buf[256], mask[36];
	int i;
	int memC, memM, memL;
	int *memLoc;
	long *memVal;
	long n, memV, t;

	memL = 0;
	memM = 1;
	memLoc = malloc(memM * sizeof(int));
	memVal= malloc(memM * sizeof(long));

	fp = fopen("input.txt", "r");

	while( fgets(buf, 256, fp) != NULL ) {
		if( buf[1] == 'a' ){
			// MASK LINE
			sscanf(buf, "mask = %s\n", mask);
		}
		else {
			// MEM LINE
			sscanf(buf, "mem[%d] = %ld\n", &memC, &memV);

			n = 1;
			for(i = 35; i >= 0; i--) {
				if( mask[i] == '1' ) {
					memV = memV | n;
				}
				else if( mask[i] == '0' ) {
					t = memV & n;
					if( t == n ) {
						memV -= n;
					}
				}

				n *= 2;
			}

			i = find(memC, memLoc, memL);
			if( i == -1 ) {
				memLoc[memL] = memC;
				memVal[memL] = memV;

				memL += 1;
				if( memL == memM ){
					memM *= 2;
					memLoc = realloc(memLoc, memM * sizeof(int));
					memVal = realloc(memVal, memM * sizeof(long));
				}
			}
			else {
				memVal[i] = memV;
			}
		}
	}

	t = 0;
	for(i = 0; i < memL; i++) {
		t += memVal[i];
		printf("%d : %ld\n", memLoc[i], memVal[i]);
	}

	printf("%ld\n", t);

	fclose(fp);
	free(memLoc);
	free(memVal);
}

int find(int val, int arr[], int arrL) {
	int i;

	for( i = 0; i < arrL; i++) {
		if( val == arr[i] ) {
			return i;
		}
	}

	return -1;
}


