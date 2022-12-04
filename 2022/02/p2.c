#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, j, n, x;
	int einput[2500];
	int minput[2500];
	int ilen = 2500;
	char buf[10];
	char elf, me;
	int score;

	i = 0;
	score = 0;

	while( scanf("%c %c\n", &elf, &me) != EOF ) {
		einput[i] = elf;
		minput[i] = me;
		i++;
		printf("\t%d\n", score);

		if(( elf == 'A') && (me == 'Z')) {
			score += 6;
			score += 2;
		}
		else if(( elf == 'A') && (me == 'X')) {
			score += 0;
			score += 3;
		}
		else if(( elf == 'B') && (me == 'Y')) {
			score += 3;
			score += 2;
		}
		else if(( elf == 'C') && (me == 'Z')) {
			score += 6;
			score += 1;
		}
		else if(( elf == 'B') && (me == 'X')) {
			score += 0;
			score += 1;
		}
		else if(( elf == 'C') && (me == 'Y')) {
			score += 3;
			score += 3;
		}
		else if(( elf == 'A') && (me == 'Y')) {
			score += 3;
			score += 1;
		}
		else if(( elf == 'B') && (me == 'Z')) {
			score += 6;
			score += 3;
		}
		else if(( elf == 'C') && (me == 'X')) {
			score += 0;
			score += 2;
		}
	}

printf("%d\n", score);

}
