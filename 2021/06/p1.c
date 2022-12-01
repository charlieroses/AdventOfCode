#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, j, k, n;
	int iaA, iaL;
	int *ia;
	int popL, popA;
	int *pop;

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
	
	popA = iaL * 2;
	popL = iaL;
	pop = malloc(sizeof(int) * popA);
	for( i = 0; i < popL; i++)
		pop[i] = ia[i];

	// Start time
	for( i = 0; i < 80; i++) {
		n = 0;
		for( j = 0; j < popL; j++ ) {
			pop[j]--;

			if( pop[j] == -1 ) {
				pop[j] = 6;
				pop[popL + n] = 8;

				n += 1;
				if( (popL + n) == popA ) {
					popA *= 2;
					pop = (int*)realloc(pop, popA * sizeof(int));
				}
			}

		}

		popL += n;
		printf("\nAfter %d day: ", i);

		for( j = 0; j < popL; j++ )
			printf("%d,", pop[j]);
	
	}

	printf("\n%d\n", popL);
	free(ia);
}
