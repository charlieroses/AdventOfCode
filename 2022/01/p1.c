#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, j, n, x;
	int vallen;
	int *vals;
	int inc;
	int max;
	char buf[10];

	i = 0;
	vallen = 10;
	vals = (int*)malloc(vallen*sizeof(int));

	vals[0] = 0;
	max = 0;
	while( fgets(buf, 10, stdin) != NULL ) {
		if( buf[0] == '\n' ) {
			// new elf
			if( vals[i] > max ) {
				max = vals[i];
			}
			i++;
			if( i == vallen ) {
				vallen *= 2;
				vals = (int*)realloc(vals, vallen * sizeof(int));
			}
			vals[i] = 0;
			continue;
		}

		vals[i] += atoi( buf );

	}

	printf("%d\n", max);

	free(vals);
}
