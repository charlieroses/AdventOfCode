#include <stdio.h>
#include <stdlib.h>

#define plen 25

int main() {
	FILE *fp;
	int n, i, j, k;
	int pre[plen];
	int valid;

	fp = fopen("input.txt", "r");

	i = 0;
	while( fscanf(fp, "%d\n", &n) != EOF ) {
		if( i < plen ) {
			pre[i] = n;
		}
		else {
			valid = 0;
			for( k = 0; k < plen; k++ ) {
				for( j = k + 1; j < plen; j++ ) {
					if( pre[k] + pre[j] == n ) {
						valid = 1;
					}
				}
			}

			pre[i % plen] = n;

			if( !valid ) {
				printf("%d\n", n);
				break;
			}
		}

		i += 1;
	}

	fclose(fp);
}

