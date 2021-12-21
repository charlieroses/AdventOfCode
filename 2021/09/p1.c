#include <stdio.h>
#include <stdlib.h>
#include "fns.h"
#include "dat.h"

int main() {
	char	inputT[] = "%c";
	int		i, j, k, r, c, n;
	int		inpA, inpL;
	char	*inp;
	int		ans;
	int		wid, hgt;
	int		low;

	inpL = 0;
	inpA = 10;
	inp = (char*)malloc( inpA *sizeof(char));
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

		inp[inpL] = n;

		inpL += 1;
		if( inpL == inpA ) {
			inpA *= 2;
			inp = (char*)realloc(inp, inpA * sizeof(char));
		}
		n = fgetc(stdin);
	}
	hgt = inpL / wid;

	for( r = 0; r < hgt; r++ ) {
		for( c = 0; c < wid; c++ ) {
			low = 1;

			// Bottom Left
			if( (r < (hgt - 1)) && (c > 0) ) {
				if( inp[(wid*(r+1))+(c-1)] < inp[(wid*r)+c] )
					low = 0;
			}

			// Bottom
			if( r < (hgt - 1) ) {
				if( inp[(wid*(r+1))+c] < inp[(wid*r)+c] )
					low = 0;
			}

			// Bottom Right
			if( (r < (hgt - 1)) && (c < (wid - 1)) ) {
				if( inp[(wid*(r+1))+(c+1)] < inp[(wid*r)+c] )
					low = 0;
			}

			// Left
			if( c > 0 ) {
				if( inp[(wid*r)+(c-1)] < inp[(wid*r)+c] )
					low = 0;
			}

			// Right
			if( c < (wid - 1) ) {
				if( inp[(wid*r)+(c+1)] < inp[(wid*r)+c] )
					low = 0;
			}

			// Top Left
			if( (r > 0) && (c > 0) ) {
				if( inp[(wid*(r-1))+(c-1)] < inp[(wid*r)+c] )
					low = 0;
			}

			// Top
			if( r > 0 ) {
				if( inp[(wid*(r-1))+c] < inp[(wid*r)+c] )
					low = 0;
			}

			// Top Right
			if( (r > 0) && (c < (wid - 1)) ) {
				if( inp[(wid*(r-1))+(c+1)] < inp[(wid*r)+c] )
					low = 0;
			}

			if( low )
				ans += (inp[(wid*r) + c] - '0' + 1);

		}
	}


	printf("%d\n", ans);


	free(inp);
}
