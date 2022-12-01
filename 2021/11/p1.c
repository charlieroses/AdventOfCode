#include <stdio.h>
#include <stdlib.h>
#include "fns.h"
#include "dat.h"

int main() {
	char	inputT[] = "%c";
	int		i, j, k, n;
	int		inpA, inpL;
	char	*inp;

	inpL = 0;
	inpA = 10;
	inp = (char*)malloc( inpA *sizeof(char));


	while( scanf(inputT, &n) != EOF ) {
		inp[inpL] = n;


		inpL += 1;
		if( inpL == inpA ) {
			inpA *= 2;
			inp = (char*)realloc(inp, inpA * sizeof(char));
		}

	}

	free(inp);
}
