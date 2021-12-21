#include<stdio.h>

void insertionsort(long *arr, long l) {
	int i, j;
	long t;

	for( i = 1; i < l; i++ ) {
		for( j = 0; j < i; j++ ) {
			if( arr[j] > arr[i] ) {
				t = arr[j];
				arr[j] = arr[i];
				arr[i] = t;
			}
		}
	}
}
