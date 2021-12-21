#include <stdio.h>
#include <stdlib.h>
#include "fns.h"
#include "dat.h"

int *basins;

int basinSize( int, int, int*, int, int );

int main() {
	char	inputT[] = "%c";
	int		i, j, k, r, c, n;
	int		inpA, inpL;
	int		*inp;
	int		ans;
	int		wid, hgt;
	int		maxA, maxB, maxC;

	inpL = 0;
	inpA = 10;
	inp = malloc( inpA * sizeof(int));
	ans = 0;

	wid = 0;
	hgt = 0;
	n = fgetc(stdin);
	while( n != EOF ) {
		if( n == '\n' ) {
			if( wid == 0 )
				wid = inpL;
			n = fgetc(stdin);
			continue;
		}

		inp[inpL] = n - '0';

		inpL += 1;
		if( inpL == inpA ) {
			inpA *= 2;
			inp = realloc(inp, inpA * sizeof(int));
		}
		n = fgetc(stdin);
	}
	hgt = inpL / wid;

	basins = malloc(inpL * sizeof(int));
	maxA = 0;
	maxB = 0;
	maxC = 0;
	for( r = 0; r < hgt; r++ ) {
		for( c = 0; c < wid; c++ ) {
			for( i = 0; i < inpL; i++)
				basins[i] = 0;

			n = basinSize( r, c, inp, wid, hgt );


			if( n > maxA ) {
				maxC = maxB;
				maxB = maxA;
				maxA = n;
				continue;
			}

			if( n > maxB ) {
				maxC = maxB;
				maxB = n;
				continue;
			}

			if( n > maxC )
				maxC = n;

		}
	}

	ans = maxA * maxB * maxC;
	printf("%d\n", ans);


	free(basins);
	free(inp);
}

int basinSize( int r, int c, int *arr, int w, int h ) {
	int low;
	int n;
	low = 1;
	
	n = arr[(w*r)+c];
	
	if( basins[(w*r)+c] > 0 )
		return 0;

	if( n == 9 )
		return 0;

	// Bottom
	if( r < (h - 1) ) {
		if( n < arr[(w*(r+1))+c] )
			low += basinSize(r+1, c, arr, w, h);
	}

	// Left
	if( c > 0 ) {
		if( n < arr[(w*r)+(c-1)] )
			low += basinSize(r, c-1, arr, w, h);
	}

	// Right
	if( c < (w - 1) ) {
		if( n < arr[(w*r)+(c+1)] )
			low += basinSize(r, c+1, arr, w, h);
	}

	// Top
	if( r > 0 ) {
		if( n < arr[(w*(r-1))+c] )
			low += basinSize(r-1, c, arr, w, h);
	}

	basins[(w*r)+c] = low;
	return low;
}


