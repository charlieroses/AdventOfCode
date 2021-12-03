#include <stdio.h>
#include <stdlib.h>

#define TEST 12

int main() {
	int i, j, n;
	int vallen;
	int *vals, *oxy, *co2;
	int inc;
	int bits[TEST];
	char buf[TEST];
	int bo, bc;
	int L, nL;

	L = 0;
	vallen = 10;
	vals = (int*)malloc(vallen*sizeof(int));
//	vals[0] = malloc(6 * sizeof(char));


	for( i = 0; i < TEST; i ++ ) {
		bits[i] = 0;
	}

	j = 0;
	while( scanf("%s \n", buf) != EOF ) {
		vals[L] = 0;
		for( j = 0; j < TEST; j++) {
			vals[L] += (buf[j] == '1') * ( 1 << (TEST - 1 - j) );
			bits[j] += (buf[j] == '1');
		}
		L++;
		if( L == vallen ) {
			vallen *= 2;
			vals = (int*)realloc(vals, vallen * sizeof(int));
		}

	}


	for( i = 0; i < TEST; i++) {
		printf("%d", (bits[i] > L/2));
	}

	printf("\n");
	
	for( i = 0; i < TEST; i++) {
		printf("%d", (bits[i] < L/2));
	}

	printf("\n");

	oxy = malloc(sizeof(int) * L);
	co2 = malloc(sizeof(int) * L);
	bo = 0;
	bc = L;
	
	for( i = 0; i < L; i++) {
		oxy[i] = vals[i];
		co2[i] = vals[i];
	}

	for( j = 0; j < TEST; j++ ) {
		bits[j] = 0;
		for( i = 0; i < L; i++ ) {
			n = (oxy[i] & (1 << (TEST - 1 - j)));
			if( n != 0 )
				bits[j]++;
		}

		if( bits[j] > L/2 || ((bits[j] == L/2) && (L % 2 == 0)))
			bo = 1;
		else
			bo = 0;
		nL = 0;
		for( i = 0; i < L; i++ ) {
			n = (oxy[i] & (1 << (TEST - 1 - j)));
			if( n == (bo << (TEST - 1 - j))) {
				oxy[nL] = oxy[i];
				nL++;
			}
		}
		L = nL;
	}

	L = bc;

	for( j = 0; j < TEST; j++ ) {
		bits[j] = 0;
		for( i = 0; i < L; i++ ) {
			n = (co2[i] & (1 << (TEST - 1 - j)));
			if( n != 0 )
				bits[j]++;
		}

		printf("%d %d\n", bits[j], L/2);
		if( bits[j] > L/2 || ((bits[j] == L/2) && (L % 2 == 0)))
			bo = 0;
		else
			bo = 1;
		nL = 0;
		printf("L %d bit %d\n", L, bo);
		for( i = 0; i < L; i++ ) {
			n = (co2[i] & (1 << (TEST - 1 - j)));
			if( n == (bo << (TEST - 1 - j))) {
				co2[nL] = co2[i];
				nL++;
			}
		}
		L = nL;
	}


	printf("%d %d %d\n", oxy[0], co2[0], oxy[0] * co2[0]);
	free(vals);
	free(oxy);
	free(co2);
}
