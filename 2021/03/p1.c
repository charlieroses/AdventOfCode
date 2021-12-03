#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, j, n;
	int vallen;
	int *vals;
	int inc;
	int bits[12];
	char buf[12];

	i = 0;
	vallen = 10;
	vals = (int*)malloc(vallen*sizeof(int));
//	vals[0] = malloc(6 * sizeof(char));


	for( i = 0; i < 12; i ++ ) {
		bits[i] = 0;
	}

	j = 0;
	while( scanf("%s \n", buf) != EOF ) {
		for( i= 0; i < 12; i++) {
			bits[i] += ( buf[i] == '1' );
		}

		j += 1;
		if( i == vallen ) {
			vallen *= 2;
			vals = (int*)realloc(vals, vallen * sizeof(int));
		}

	}

	for( i = 0; i < 12; i++) {
		printf("%d", (bits[i] > j/2));
	}

	printf("\n");
	
	for( i = 0; i < 12; i++) {
		printf("%d", (bits[i] < j/2));
	}
	free(vals);
}
