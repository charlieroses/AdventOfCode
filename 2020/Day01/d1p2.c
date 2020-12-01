#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, j, k, l, n;
	int vallen;
	int *vals;

	i = 0;
	vallen = 10;
	vals = (int*)malloc(vallen*sizeof(int));

	while( scanf("%d \n", &n) != EOF ) {
		vals[i] = n;

		i += 1;
		if( i == vallen ) {
			vallen *= 2;
			vals = (int*)realloc(vals, vallen * sizeof(int));
		}

	}

	for(j = 0; j < i; j++) {
		for(k = 0; k < i; k++) {
			for(l = 0; l < i; l++ ){
				if( vals[j] + vals[k] + vals[l] == 2020) {
					printf("%d %d %d \n", vals[j], vals[k], vals[l]);
					printf("%d\n", vals[j] * vals[k] * vals[l]);
				}
			}
		}
	}

	free(vals);
}
