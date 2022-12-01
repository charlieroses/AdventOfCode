#include <stdio.h>
#include <stdlib.h>

#define INPL 1000

void printgrid( int r, int c, int *arr) {
	int i, j;
	for( i = 0; i < r; i++ ) {
		for( j = 0; j < c; j++ ) {
			printf("%d ", arr[(i*r)+j]);
		}
		printf("\n");
	}
}

int main() {
	int i, j, k, n, sx, lx, dy, s, l;
	int iaA, iaL;
	int *x0a, *y0a, *x1a, *y1a;
	int a0, a1, b0, b1;
	int *points;
	int pL;

	iaL = 0;
	iaA = 10;
	x0a = (int*)malloc(iaA * sizeof(int));
	y0a = (int*)malloc(iaA * sizeof(int));
	x1a = (int*)malloc(iaA * sizeof(int));
	y1a = (int*)malloc(iaA * sizeof(int));


	while( scanf("%d,%d -> %d,%d\n", &a0, &b0, &a1, &b1) != EOF ) {
		x0a[iaL] = a0;
		x1a[iaL] = a1;
		y0a[iaL] = b0;
		y1a[iaL] = b1;

		iaL += 1;
		if( iaL == iaA ) {
			iaA *= 2;
			x0a = (int*)realloc(x0a, iaA * sizeof(int));
			y0a = (int*)realloc(y0a, iaA * sizeof(int));
			x1a = (int*)realloc(x1a, iaA * sizeof(int));
			y1a = (int*)realloc(y1a, iaA * sizeof(int));
		}

	}

	pL = INPL * INPL;
	points = malloc( pL * sizeof(int) );
	for( i = 0; i < pL; i++ )
		points[i] = 0;

	for( i = 0; i < iaL; i++ ) {
		printf("%d %d %d %d\n", x0a[i], y0a[i], x1a[i], y1a[i]);
		// horizontal line

		if( y0a[i] == y1a[i]) {
			printf("horiz\n");
			if( x0a[i] < x1a[i] ) {
				s = x0a[i];
				l = x1a[i];
			}
			else {
				s = x1a[i];
				l = x0a[i];
			}
			for( j = s; j <= l; j++) {
				a0 = j;
				b0 = y0a[i];
				points[(b0 * INPL) + a0 ] += 1;
			}
		}
		else if( x0a[i] == x1a[i]) { //vertical line
			if( y0a[i] < y1a[i] ) {
				s = y0a[i];
				l = y1a[i];
			}
			else {
				s = y1a[i];
				l = y0a[i];
			}

			printf("vert\n");
			for( j = s; j <= l; j++) {
				a0 = x0a[i];
				b0 = j;
				points[(b0 * INPL) + a0 ] += 1;
			}
		}
		else {
			dy = 0;
			if( x0a[i] < x1a[i] ) {
				sx = x0a[i];
				k = y0a[i];
				lx = x1a[i];

				if( y0a[i] < y1a[i] )
					dy = 1;
				else
					dy = -1;
			}
			else {
				sx = x1a[i];
				lx = x0a[i];
				k = y1a[i];
				if( y0a[i] < y1a[i] )
					dy = -1;
				else
					dy = 1;
			}


			for( j = sx; j <= lx; j++) {
				points[( k * INPL) + j ] += 1;
				k += dy;
			}

		}
	}

printgrid(INPL, INPL, points);

	n = 0;
	for( i = 0; i < pL; i++ ) {
		if( points[i] >= 2 )
			n++;
	}


	printf("\n%d\n", n);

	free(x0a);
	free(y0a);
	free(x1a);
	free(y1a);
}
