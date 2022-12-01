#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *fp;
	char s[256];
	int slen, height;
	int i, j, k, d, r, rcurr, tree;
	long treemult;
	int coords[5][2] = {{1, 1}, {1, 3}, {1, 5}, {1, 7}, {2, 1}};

	fp = fopen("input.txt", "r");

	treemult = 1;
	for(i = 0; i < 5; i++) {
		slen = 0;
		tree = 0;
		height = 0;
		j = 0;

		d = coords[i][0];
		r = coords[i][1];

		while( fscanf(fp, "%s\n", s) != EOF ) {
			if( height == 0 ) {
				for(k = 0; s[k] != 0; k++) {
					slen += 1;
				}
			}

			if( height % d == 0) {
				if( s[j % slen] == '#') {
					tree++;
				}

				j += r;
			}

			height += 1;
		}

		treemult *= tree;
		printf("d=%d, r=%d, trees=%d \n", d, r, tree);
		rewind(fp);
	}

	printf("%ld\n", treemult);

	fclose(fp);
}
