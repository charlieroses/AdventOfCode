#include <stdio.h>
#include <stdlib.h>


int main() {
	int i, j, n, x, a, b, c, d;
	int ainput[1000];
	int binput[1000];
	int cinput[1000];
	int dinput[1000];
	int ilen = 1000;
	char buf[128];
	char elf, me;
	int score;

	i = 0;
	score = 0;

	while( scanf("%d-%d,%d-%d\n", &a, &b, &c, &d) != EOF ) {
		printf("%d %d %d %d\n", a, b, c, d);
		i++;

		if( (a <= c) && (b >= d) ) {
			score += 1;
		}
		else if( (c <= a) && (d >= b) ) {
			score += 1;
		}
	}

	printf("%d\n", score);

}
