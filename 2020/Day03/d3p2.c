#include <stdio.h>
#include <stdlib.h>

int main() {
	char s[256];
	int slen;
	int i, j, k, d, r, rcurr, tree;

	i = 0;
	j = 0;
	d = 1;
	r = 7;

	slen = 0;
	tree = 0;
	while( scanf("%s\n", s) != EOF ) {
		if( i == 0 ) {
			for(k = 0; s[k] != 0; k++) {
				slen += 1;
			}
		}

		if( i % d == 0) {
			if( s[j % slen] == '#') {
				tree++;
			}

			j += r;
		}

		i += 1;
	}

	printf("%d \n", tree);
}
