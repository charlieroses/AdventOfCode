#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, j, k, n;
	int iaA, iaL;
	int *ia;
	int m;
	int *f;

	iaL = 0;
	iaA = 10;
	ia = (int*)malloc(iaA*sizeof(int));

	scanf("%d", &n);
	ia[iaL] = n;
	iaL++;
	m = n;

	while( scanf(",%d", &n) == 1 ) {
		ia[iaL] = n;

		if( n > m )
			m = n;
		iaL += 1;
		if( iaL == iaA ) {
			iaA *= 2;
			ia = (int*)realloc(ia, iaA * sizeof(int));
		}

	}

	m++;
	f = malloc( m * sizeof(int) );

	for(i = 0; i < m; i++) {
		f[i] = 0;

		for(j = 0; j < iaL; j++) {
			if( ia[j] < i )
				f[i] += (i - ia[j]);
			else
				f[i] += (ia[j] - i);
		}
	}

	n = f[0];
	k = 0;
	for(i = 1; i < (m - 1); i++) {
	printf("pos %d : %d\n", i, f[i]);
		if( f[i] < n ) {
			n = f[i];
			k = i;
		}
	}



	printf("pos %d : %d\n", k, n);

	free(f);
	free(ia);
}
