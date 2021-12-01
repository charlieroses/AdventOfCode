#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, n;
	int vallen;
	int *vals;
	int inc;
	int A, B;

	i = 0;
	vallen = 10;
	vals = (int*)malloc(vallen*sizeof(int));
	inc = 0;

	scanf("%d \n", &n);
	vals[i] = n;
	i++;
	scanf("%d \n", &n);
	vals[i] = n;
	i++;
	scanf("%d \n", &n);
	vals[i] = n;
	i++;

	A = 0;
	B = 0;
	while( scanf("%d \n", &n) != EOF ) {
		vals[i] = n;
		A = vals[i-0] + vals[i-1] + vals[i-2];
		B = vals[i-1] + vals[i-2] + vals[i-3];

		if( A > B ) inc++;

		i += 1;
		if( i == vallen ) {
			vallen *= 2;
			vals = (int*)realloc(vals, vallen * sizeof(int));
		}

	}

	printf("%d\n", inc);

	free(vals);
}
