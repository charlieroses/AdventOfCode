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
	long	*inp;
	struct Stack *S;
	long	ans;
	int		err;
	int		counts[4];
	int		*scores;

	inpL = 0;
	inpA = 10;
	inp = (long*)malloc( inpA *sizeof(long));

	S = newStack(10);

	for( i = 0; i < 4; i++ )
		counts[i] = 0;

	err = 0;
	n = fgetc(stdin);
	while( n != EOF ) {
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
			ans = 0;
			if( err != 0 ) {
				m = pop(S);
				while( m != NULL )
					m = pop(S);
				err = 0;
				n = fgetc(stdin);
				continue;
			}

			m = pop(S);
			while( m != NULL ) {
				ans *= 5;
				if( m == 3 ) {
					ans += 1;
				}
				else if( m == 57 ){
					ans += 2;
				}
				else if( m == 1197 ){
					ans += 3;
				}
				else if( m == 25137 ){
					ans += 4;
				}

				m = pop(S);
			}
			
			inp[inpL] = ans;
			inpL += 1;
			if( inpL == inpA ) {
				inpA *= 2;
				inp = (long*)realloc(inp, inpA * sizeof(long));
			}
		}

		n = fgetc(stdin);
	}

	insertionsort( inp, inpL );

	ans = inp[ inpL / 2 ];

	printf("%ld\n", ans);

	freeStack(S);
	free(inp);
}
