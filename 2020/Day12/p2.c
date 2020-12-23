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
	int x, y, t, wx, wy;

	fp = fopen("input.txt", "r");

	x = 0;
	y = 0;
	wx = 10;
	wy = 1;
	while( fscanf(fp, "%c%d\n", &dir, &val) != EOF ) {

		if( dir == 'F' ) {
			x += val * wx;
			y += val * wy;
		}

		if( dir == 'N' ) {
			wy += val;
		}
		else if( dir == 'S' ) {
			wy -= val;
		}
		else if( dir == 'E' ) {
			wx += val;
		}
		else if( dir == 'W' ) {
			wx -= val;
		}

		if( dir == 'L' ) {
			while( val > 0 ) {
				t = wx;
				wx = -wy;
				wy = t;
				val -= 90;
			}
		}
		else if( dir == 'R' ) {
			while( val > 0 ) {
				t = wx;
				wx = wy;
				wy = -t;
				val -= 90;
			}
		}
	}

	printf("%d %d %d\n", x, y, abs(x)+abs(y));

	fclose(fp);
}
