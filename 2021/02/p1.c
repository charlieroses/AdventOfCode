#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char buf[1000];
	char buf2[64];
	int dir;
	int depth, horiz;

	depth = 0;
	horiz = 0;

	while( scanf("%s %d\n", buf, &dir) != EOF ) {
		printf("!%s!%d!\n", buf, dir);
		if( strcmp( buf, "forward" ) == 0 ) {
			printf("fowar\n");
			horiz += dir;
		}
		else if( strcmp( buf, "down" ) == 0 ) {
			printf("dn\n");
			depth += dir;
		}
		else if( strcmp( buf, "up" ) == 0 ) {
			printf("up\n");
			depth -= dir;
		}
	}

	printf("%d %d\n", depth, horiz);
}
