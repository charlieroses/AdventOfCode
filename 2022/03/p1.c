#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort( char *arr, int l ) {
	int		i, j, min;
	int		t;

	for( i = 0; i < l; i++ ) {
		min = i;

		for( j = i + 1; j < l; j++ ) {
			if( arr[j] < arr[min] )
				min = j;
		}
		t = arr[min];
		arr[min] = arr[i];
		arr[i] = t;
	}
}


int main() {
	int i, j, n, x;
	int einput[2500];
	int minput[2500];
	int ilen = 2500;
	char buf[128];
	char elf, me;
	int score;

	i = 0;
	score = 0;

	while( scanf("%s\n", buf) != EOF ) {
		x = strlen(buf);
		n = x/2;

		sort( buf, n );
		sort( &buf[n], n );

		i = 0;
		j = n;
		while( (i < n) && (j < x) ) {
			if( buf[i] == buf[j] ) {
				break;
			}
			
			if( buf[i] < buf[j] ) {
				i++;
			}
			else {
				j++;
			}
		}

		if( buf[j] >= 'a' )
			score += buf[j] - 'a' + 1;
		else
			score += buf[j] - 'A' + 27;

		printf("%d %c %s\n", strlen(buf), buf[j], buf);

	}

	printf("%d\n", score);

}
