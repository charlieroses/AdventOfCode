#include<stdio.h>
#include<stdlib.h>
#include"fns.h"

void print2D( char *arr, int w, int h ) {
	int r, c;

	for( r = 0; r < h; r++ ) {
		for( c = 0; c < w; c++ )
			printf("%c", arr[(r*w)+c]);
		printf("\n");
	}
}
