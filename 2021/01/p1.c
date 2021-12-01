#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, j, n;
	int vallen;
	int *vals;
	int inc;

	i = 0;
	vallen = 10;
	vals = (int*)malloc(vallen*sizeof(int));
	inc = 0;


	scanf("%d \n", &n);
	vals[i] = n;
	i++;

	while( scanf("%d \n", &n) != EOF ) {
		vals[i] = n;

		if( vals[i] > vals[i-1] ) inc++;

		i += 1;
		if( i == vallen ) {
			vallen *= 2;
			vals = (int*)realloc(vals, vallen * sizeof(int));
		}

	}

	printf("%d\n", inc);

	free(vals);
}
