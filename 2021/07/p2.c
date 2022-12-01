#include <stdio.h>
#include <stdlib.h>
#include "fns.h"

int main() {
	int i, j, k, n;
	int iaA, iaL;
	int *ia;
	int m;
	int ni, ans;

	iaL = 0;
	iaA = 10;
	ia = (int*)malloc(iaA*sizeof(int));

	scanf("%d", &n);
	ia[iaL] = n;
	iaL++;
	m = n;
	ans = 0;

	while( scanf(",%d", &n) == 1 ) {
		ia[iaL] = n;

		ans += (abs(ia[iaL] - ia[0]) * (abs(ia[iaL] + ia[0]) - 1) ) / 2;
		if( n > m )
			m = n;

		iaL += 1;
		if( iaL == iaA ) {
			iaA *= 2;
			ia = (int*)realloc(ia, iaA * sizeof(int));
		}

	}
	ni = 0;
	for(i = 0; i < m; i++) {
		k = 0;

		for(j = 0; j < iaL; j++) {
			k += (abs(ia[j] - i) * (abs(ia[j] - i) + 1) ) / 2;
		}

		if( k < ans ) {
			ans = k;
			ni = i;
		}
	}

	printf("pos %d : %d\n", ni, ans);

	free(ia);
}
