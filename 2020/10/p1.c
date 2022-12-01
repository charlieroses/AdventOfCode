#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b);

int main() {
	FILE *fp;
	int *ada;
	int adaL, adaM;
	int val, i;
	int jmp[4] = {0, 0, 0, 0};


	fp = fopen("input.txt", "r");

	adaM = 1;
	ada = malloc(adaM * sizeof(int));
	adaL = 0;

	while( fscanf(fp, "%d\n", &val) != EOF ) {
		ada[adaL] = val;

		adaL += 1;
		if( adaL == adaM ) {
			adaM *= 2;
			ada = realloc(ada, adaM * sizeof(int));
		}
	}

	qsort(ada, adaL, sizeof(int), compare);

	for(i = 0; i < adaL; i++) {
		if( i == 0 ) {
			jmp[ ada[i] ] += 1;
		}
		else {
			jmp[ ada[i] - ada[i-1] ] += 1;
		}
	}

	jmp[3] += 1;

	printf("%d %d %d\n", jmp[1], jmp[3], jmp[1] * jmp[3]);

	free(ada);
	fclose(fp);
}

int compare(const void *a, const void *b) {
	return ( *(int*)a - *(int*)b );
}

