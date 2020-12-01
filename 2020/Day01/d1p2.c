#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, j, n;
	int vallen;
	int *vals;

	i = 0;
	vallen = 10;
	vals = (int*)malloc(vallen*sizeof(int));

	while( scanf("%d \n", &n) != EOF ) {
		vals[i] = n;

		for(j = 0; j < i; j++) {
			if( vals[i] + vals[j] == 2020) {
				printf("%d %d\n", vals[i], vals[j]);
				printf("%d\n", vals[i] * vals[j]);
			}
		}

		i += 1;
		if( i == vallen ) {
			vallen *= 2;
			vals = (int*)realloc(vals, vallen * sizeof(int));
		}

	}

	free(vals);
}
