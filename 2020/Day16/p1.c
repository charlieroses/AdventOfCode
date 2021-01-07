#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char buf[256], s[256];
	FILE *fp;
	int i, j, k, l, n;
	int err, bad;
	// Parallel arrays for the input (lower lower bound) (lower upper bound)
	// (upper lower bound) (upper upper bound).
	// Then the bL and bM for bound length and bound malloc
	// bL is ALSO how many fields are in the ticket
	int *ll, *lu, *ul, *uu;
	int bL, bM;

	bL = 0;
	bM = 1;
	ll = malloc(bM * sizeof(int));
	lu = malloc(bM * sizeof(int));
	ul = malloc(bM * sizeof(int));
	uu = malloc(bM * sizeof(int));


	fp = fopen("input.txt", "r");

	while( fgets(buf, 256, fp) != NULL) {
		n = sscanf(buf, "%[^:]: %d-%d or %d-%d", s, &i, &j, &k, &l); 
		if( n == 5 ) {
			// Is a boundary line
			ll[bL] = i;
			lu[bL] = j;
			ul[bL] = k;
			uu[bL] = l;
			bL += 1;

			if( bL == bM ) {
				bM *= 2;
				ll = realloc(ll, bM * sizeof(int));
				lu = realloc(lu, bM * sizeof(int));
				ul = realloc(ul, bM * sizeof(int));
				uu = realloc(uu, bM * sizeof(int));
			}
		}
		else {
			if( strcmp(buf, "\n") == 0 ) {
				continue;
			}

			if( strcmp(buf, "your ticket:\n") == 0 ) {
				// The next line is my ticket line which I'll probably have to do
				// something with in part 2
				fgets(buf, 256, fp);
			}

			if( strcmp(buf, "nearby tickets:\n") == 0 ) {
				// The next lines are the other tickets. I think I'll do this in a
				// separate loop just to keep things clean
				break;
			}
		}
	}

	err = 0;
	while( fscanf(fp, "%d%[,\n]", &n, s) != EOF) {
		bad = 1;
		for( i = 0; i < bL; i++) {
			if( (n >= ll[i] && n <= lu[i] ) || (n >= ul[i] && n <= uu[i]) ) {
				bad = 0;
			}
		}

		if( bad ) {
			printf("%d\n", n);
			err += n;
		}
	}

	printf("%d\n", err);

	free(ll);
	free(lu);
	free(ul);
	free(uu);
	fclose(fp);
}
