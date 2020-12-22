#include <stdio.h>
#include <stdlib.h>

long *memo;
int memoL;

int compare(const void *a, const void *b);
int find(int val, int ada[], int adaL);
long permu(int x);

int main() {
	FILE *fp;
	int *ada;
	int adaL, adaM;
	int val, i, s;
	long ans;

	fp = fopen("input.txt", "r");

	adaM = 1;
	ada = malloc(adaM * sizeof(int));
	adaL = 0;

//	Load Adapters into array and sort
	while( fscanf(fp, "%d\n", &val) != EOF ) {
		ada[adaL] = val;

		adaL += 1;
		if( adaL == adaM ) {
			adaM *= 2;
			ada = realloc(ada, adaM * sizeof(int));
		}
	}

	qsort(ada, adaL, sizeof(int), compare);

//	Do the puzzle
	memoL = ada[adaL - 1] + 3;
	memo = malloc( memoL * sizeof(long));

	for( i = 1; i < memoL; i++) {
		if( find(i, ada, adaL) > -1 ) {
			memo[i] = 0;
		}
		else {
			memo[i] = -1;
		}
	}

	memo[ada[adaL - 1]] = 1;

	ans = permu(0);
	printf("%ld\n", ans);

//	for(i = 1; i < memoL; i++) {
//		printf("%d %ld\n",i, memo[i]);
//	}

	free(memo);
	free(ada);
	fclose(fp);
}

int compare(const void *a, const void *b) {
	return ( *(int*)a - *(int*)b );
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

long permu(int x) {
	long t;
	t = 0;
	if( memo[x] == -1 ) {
		return 0;
	}
	
	if( memo[x] != 0 ) {
		return memo[x];
	}
	else {
		t = permu(x+1) + permu(x+2) + permu(x+3);
		memo[x] = t;
		return t;
	}
}
