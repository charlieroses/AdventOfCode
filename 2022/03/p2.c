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
	int i, j, k, n, x1, x2, x3;
	char buf1[128];
	char buf1c[128];
	char buf2[128];
	char buf2c[128];
	char buf3[128];
	char buf3c[128];
	int score;

	i = 0;
	score = 0;

	while( scanf("%s\n", buf1) != EOF ) {
		scanf("%s\n", buf2);
		scanf("%s\n", buf3);

		x1 = strlen(buf1);
		x2 = strlen(buf2);
		x3 = strlen(buf3);

		sort( buf1, x1 );
		sort( buf2, x2 );
		sort( buf3, x3 );

		j = 0;
		i = 0;
		j = 0;
		k = 0;
		while( (i <  x1) && (j < x2) && (k < x3) ) {
			if( (buf1[i] == buf2[j]) && (buf2[j] == buf3[k]) ) {
				break;
			}
			
			if( (buf1[i] < buf2[j]) && (buf1[i] < buf3[k]) ) {
				i++;
			}
			else if( (buf2[j] < buf1[i]) && (buf2[j] < buf3[k]) ) {
				j++;
			}
			else if( (buf3[k] < buf1[i]) && (buf3[k] < buf2[j]) ) {
				k++;
			}
			else if( (buf1[i] == buf2[j]) && (buf1[i] < buf3[k]) ) {
				i++;
			}
			else if( (buf3[k] == buf2[j]) && (buf3[k] < buf1[i]) ) {
				j++;
			}
			else
				k++;
		}

		if( buf2[j] >= 'a' )
			score += buf2[j] - 'a' + 1;
		else
			score += buf2[j] - 'A' + 27;

		printf("%d %d %d %c %s %s %s\n", i, j, k, buf2[j], buf1, buf2, buf3);

	}

	printf("%d\n", score);

}
