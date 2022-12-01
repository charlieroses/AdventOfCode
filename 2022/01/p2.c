#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, j, n, x;
	int vallen;
	int *vals;
	int inc;
	int max[3];
	char buf[10];

	i = 0;
	vallen = 10;
	vals = (int*)malloc(vallen*sizeof(int));

	vals[0] = 0;
	max[0] = 0;
	max[1] = 0;
	max[2] = 0;
	while( fgets(buf, 10, stdin) != NULL ) {
		if( buf[0] == '\n' ) {
			// new elf
			if( vals[i] > max[0] ) {
				max[2] = max[1];
				max[1] = max[0];
				max[0] = vals[i];
			}
			else if( vals[i] > max[1] ) {
				max[2] = max[1];
				max[1] = vals[i];
			}
			else if( vals[i] > max[2] ) {
				max[2] = vals[i];
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

	if( vals[i] > max[0] ) {
		max[2] = max[1];
		max[1] = max[0];
		max[0] = vals[i];
	}
	else if( vals[i] > max[1] ) {
		max[2] = max[1];
		max[1] = vals[i];
	}
	else if( vals[i] > max[2] ) {
		max[2] = vals[i];
	}

	printf("%d, %d, %d\n", max[0], max[1], max[2]);
	printf("%d\n", max[0] + max[1] + max[2]);

	free(vals);
}
