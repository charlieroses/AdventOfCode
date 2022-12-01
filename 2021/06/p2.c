#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, j, k, n;
	int iaA, iaL;
	int *ia;
	int popL;
	long pop[10];
	long t[10];
	long sum;

	iaL = 0;
	iaA = 10;
	ia = (int*)malloc(iaA*sizeof(int));


	scanf("%d", &n);
	ia[iaL] = n;
	iaL++;

	//Read input
	while( scanf(",%d", &n) == 1 ) {
		ia[iaL] = n;
		iaL += 1;
		if( iaL == iaA ) {
			iaA *= 2;
			ia = (int*)realloc(ia, iaA * sizeof(int));
		}

	}

	for( i = 0; i < 9; i++ )
		pop[i] = 0;

	for( i = 0; i < iaL; i++ )
		pop[ia[i]]++;

	for( i = 0; i < 9; i++ )
		printf("%d : %d\n", i, pop[i]);

	// Start time
	for( i = 0; i < 256; i++) {
		for( j = 8; j >= 0; j-- ) {
			t[j] = pop[j];
		}
		for( j = 7; j >= 0; j-- ) {
			pop[j] = t[j+1];
		}

		pop[8] = t[0];
		pop[6] += t[0];

		sum = 0;
		for( j = 0; j < 9; j++ ) {
			sum += pop[j];
		}

		printf("After %d day: %ld\n", i, sum);
	
	}

	free(ia);
}
