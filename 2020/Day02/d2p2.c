#include <stdio.h>
#include <stdlib.h>

int main() {
	int i;
	int min, max, count;
	char let;
	char* pass;

	count = 0;
	while( scanf("%d-%d %c: %s \n", &min, &max, &let, pass) != EOF ) {
		if((pass[(min-1)] == let || pass[(max-1)] == let) & pass[(min-1)] != pass[(max-1)]) {
			printf("%s\n", pass);
			count ++;
		}
	}

	printf("%d\n", count);
}
