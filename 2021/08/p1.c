#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, j, k, n;
	int iaA, iaL;
	char *ia;
	int dig[7];
	int sigL, sig;
	int ans;

	iaL = 0;
	iaA = 10;
	ia = (char*)malloc( iaA *sizeof(char));


	while( scanf("%c", &n) != EOF ) {
		ia[iaL] = n;

		iaL += 1;
		if( iaL == iaA ) {
			iaA *= 2;
			ia = (char*)realloc(ia, iaA * sizeof(char));
		}

	}

	sigL = 0;
	sig = 0;
	ans = 0;
	for( j = 0; j < 8; j++)
		dig[j] = 0;

	for( i = 0; i < iaL; i ++) {
		n = ia[i];

		if( n == '|' ) {
			sig = 1;
		}
		else if( n == ' ' || n == '\n' ) {
			if( (sigL == 2 || sigL == 4 || sigL == 3 || sigL == 7) && sig  ) {
				ans += 1;
			}

			sigL = 0;
			for( j = 0; j < 8; j++)
				dig[j] = 0;

			if( n == '\n' )
				sig = 0;
		}
		else {
			sigL += 1;
			dig[n - 'a'] += 1;
		}

	}

	printf("%d\n", ans);

	free(ia);
}
