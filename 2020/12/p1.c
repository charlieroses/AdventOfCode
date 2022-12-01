// Because  I dont know directions
//  N
// W E
//  S
//
//    90
// 180   0
//    270

#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *fp;
	int val;
	char dir;
	int x, y, f;

	fp = fopen("input.txt", "r");

	x = 0;
	y = 0;
	f = 0;
	while( fscanf(fp, "%c%d\n", &dir, &val) != EOF ) {

		if( dir == 'F' ) {
			if( f == 0 ) {
				dir = 'E';
			}
			else if( f == 90 ) {
				dir = 'N';
			}
			else if( f == 180 ) {
				dir = 'W';
			}
			else if( f == 270 ) {
				dir = 'S';
			}
		}

		if( dir == 'N' ) {
			y += val;
		}
		else if( dir == 'S' ) {
			y -= val;
		}
		else if( dir == 'E' ) {
			x += val;
		}
		else if( dir == 'W' ) {
			x -= val;
		}

		if( dir == 'L' ) {
			f += val;
			f = f % 360;
		}
		else if( dir == 'R' ) {
			f-= val;
			if( f < 0 ) {
				f += 360;
			}
		}
	}

	printf("%d %d %d\n", x, y, abs(x)+abs(y));

	fclose(fp);
}
