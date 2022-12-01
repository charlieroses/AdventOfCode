#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char buf[256], s[256];
	int ansI[6] = {14, 0, 12, 6, 19, 18};
	FILE *fp;
	int i, j, k, l, n;
	int err, bad, badT;
	long ans;
	// Parallel arrays for the input (lower lower bound) (lower upper bound)
	// (upper lower bound) (upper upper bound).
	// Then the bL and bM for bound length and bound malloc
	// bL is ALSO how many fields are in the ticket
	int *ll, *lu, *ul, *uu;
	int bL, bM;
	int *myTic, *cTic;
	int **nbTics;
	int tL, tM;

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
				myTic = malloc(bL * sizeof(int));
				j = 0;
				k = 0;
				for( i = 0; buf[i] != '\0'; i++ ) {
					if( buf[i] == ',' || buf[i] == '\n' ) {
						myTic[k] = j;
						k++;
						j = 0;
					}
					else {
						j *= 10;
						j += ((int)buf[i] - 48); //convert ascii char to int ;)
					}
				}
			}

			if( strcmp(buf, "nearby tickets:\n") == 0 ) {
				// The next lines are the other tickets. I think I'll do this in a
				// separate loop just to keep things clean
				break;
			}
		}
	}

	err = 0;
	cTic = malloc(bL * sizeof(int));
	tL = 0;
	tM = 10;
	nbTics = malloc(tM * sizeof(int*));
	badT = 0;
	i = 0;
	while( fscanf(fp, "%d%[,\n]", &n, s) != EOF) {
		if( i == bL ) {
			if( badT == 0 ) {
				nbTics[tL] = cTic;
				cTic = malloc( bL * sizeof(int));

				tL += 1;
				if( tM == tL ) {
					tM *= 2;
					nbTics = realloc(nbTics, tM * sizeof(int *));
				}
			}
			badT = 0;
			i = 0;
		}
		
		bad = 1;
		for( k = 0; k < bL; k++) {
			if( (n >= ll[k] && n <= lu[k] ) || (n >= ul[k] && n <= uu[k]) ) {
				bad = 0;
			}
		}
		badT += bad;

		cTic[i] = n;
		i++;
	}

	if( badT == 0 ) {
		nbTics[tL] = cTic;
		tL += 1;
	}

	for(i = 0; i < bL; i++) { // i is the field we're looking for the index for
		printf("%d : ", i);
		for( j = 0; j < bL; j++ ) { // j is the index we're testing
			for( k = 0; k < tL; k++) { // then we need to make sure all k in j apply otherwise move on
				n = nbTics[k][j];
				if( !((n >= ll[i] && n <= lu[i] ) || (n >= ul[i] && n <= uu[i])) ) {
					break;
				}
			}
			if( k == tL ) {
				printf("%d ", j);
			}
		}

		printf("\n");
	}

	ans = 1;
	for( i = 0; i < 6; i++) {
		ans *= myTic[ansI[i]];
	}
	printf("\n%ld\n", ans);

	free(cTic);
	free(myTic);
	free(nbTics);
	free(ll);
	free(lu);
	free(ul);
	free(uu);
	fclose(fp);
}
