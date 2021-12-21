#include <stdio.h>
#include <stdlib.h>
#include "fns.h"
#include "dat.h"

// map
//  0 : ( ) 3
//  1 : [ ] 57
//  2 : { } 1197
//  3 : < > 25137


int main() {
	int		i, j, k, m, n;
	int		inpA, inpL;
	char	*inp;
	struct Stack *S;
	int ans;
	int		err;
	int		counts[4];

	inpL = 0;
	inpA = 10;
	inp = (char*)malloc( inpA *sizeof(char));

	S = newStack(10);

	for( i = 0; i < 4; i++ )
		counts[i] = 0;

	err = 0;
	n = fgetc(stdin);
	while( n != EOF ) {
		inp[inpL] = n;

		if( n == '(' ) {
			push( 3, S );
		}
		else if( n == ')' ) {
			m = pop( S );
			if( (! err) && m != 3 ) {
				err++;
				counts[0]++;
			}
		}
		else if( n == '[' ) {
			push( 57, S );
		}
		else if( n == ']' ) {
			m = pop( S );
			if( (! err) && m != 57 ) {
				err++;
				counts[1]++;
			}
		}
		else if( n == '{' ) {
			push( 1197, S );
		}
		else if( n == '}' ) {
			m = pop( S );
			if( (! err) && m != 1197 ) {
				err++;
				counts[2]++;
			}
		}
		else if( n == '<' ) {
			push( 25137, S );
		}
		else if( n == '>' ) {
			m = pop( S );
			if( (! err) && m != 25137 ) {
				err++;
				counts[3]++;
			}
		}
		else if( n == '\n' ) {
			m = pop(S);
			while( m != NULL )
				m = pop(S);
			err = 0;
		}

		inpL += 1;
		if( inpL == inpA ) {
			inpA *= 2;
			inp = (char*)realloc(inp, inpA * sizeof(char));
		}
		n = fgetc(stdin);
	}

	for( i = 0; i < 4; i++ )
		printf("%d ", counts[i]);
	printf("\n");

	ans = (counts[0] * 3) + (counts[1] * 57) + (counts[2] * 1197) + (counts[3] * 25137);

	printf("%d\n", ans);

	freeStack(S);
	free(inp);
}
