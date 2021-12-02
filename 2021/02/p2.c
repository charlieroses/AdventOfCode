#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char buf[1000];
	char buf2[64];
	int dir;
	int depth, horiz, aim;

	depth = 0;
	horiz = 0;
	aim = 0;

	while( scanf("%s %d\n", buf, &dir) != EOF ) {
		printf("!%s!%d!\n", buf, dir);
		if( strcmp( buf, "forward" ) == 0 ) {
			horiz += dir;
			depth += (aim * dir);
		}
		else if( strcmp( buf, "down" ) == 0 ) {
			aim += dir;
		}
		else if( strcmp( buf, "up" ) == 0 ) {
			aim -= dir;
		}
	}

	printf("%d %d\n", depth, horiz);
}
