#include <stdio.h>
#include <stdlib.h>

int main() {
	int i;
	int min, max, count, lcount;
	char let;
	char* pass;

	count = 0;
	while( scanf("%d-%d %c: %s \n", &min, &max, &let, pass) != EOF ) {
		lcount = 0;
		for(i = 0; pass[i] != 0; i++) {
			if( pass[i] == let ) {
				lcount++;
			}
		}

		if( lcount >= min && lcount <= max) {
			count++;
		}
	}

	printf("%d\n", count);
}
