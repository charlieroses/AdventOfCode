#include <stdio.h>
#include <stdlib.h>

#define plen 25

int main() {
	FILE *fp;
	int n, i, j, k;
	int *pre;
	int sum, min, max, valid, preM;

	fp = fopen("input.txt", "r");

	preM = plen;
	pre = malloc(preM * sizeof(int));

	i = 0;
	while( fscanf(fp, "%d\n", &n) != EOF ) {
		if( i < plen ) {
			pre[i] = n;
		}
		else {
			valid = 0;
			for( k = i - plen; k < i; k++ ) {
				for( j = k + 1; j < i; j++ ) {
					if( pre[k] + pre[j] == n ) {
						valid = 1;
					}
				}
			}

			if( !valid ) {
				printf("%d\n", n);

				for( j = 0; j < i; j++) {
					sum = pre[j];
					min = pre[j];
					max = pre[j];

					for( k = j + 1; k < i; k++ ) {
						sum += pre[k];

						if( min > pre[k] ) {
							min = pre[k];
						}
						if( max < pre[k] ) {
							max = pre[k];
						}

						if( sum == n ) {
							printf("%d %d %d\n", min, max, min + max);
							return 0;
						}
						else if ( sum > n ) {
							break;
						}
					}
				}
				break;
			}
		}

		pre[i] = n;
		i += 1;
		if( i == preM ) {
			preM *= 2;
			pre = realloc(pre, preM * sizeof(int));
		}
	}

	fclose(fp);
}

