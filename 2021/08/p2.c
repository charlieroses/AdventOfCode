#include <stdio.h>
#include <stdlib.h>

void print4bit7seg( int* );

int main() {
	int i, j, k, n;
	int map[7];
	int sig, sigs, ans;
	int inputsigL[14];
	int inputsigV[14];
	char buf[256];
	int nums[10] = { 63, 3, 109, 103, 83, 118, 126, 35, 127, 119 };

	ans = 0;

	// Read Each Line
	while( fgets(buf, 256, stdin) != NULL ) {
		// Count the lengths of each input signal
		i = 0;
		j = 0;
		inputsigL[j] = 0;
		inputsigV[j] = 0;
		while( buf[i] != '\0' ) {
			if( buf[i] == ' ' || buf[i] == '\n') {
				printf("%d %d \n ", inputsigV[j], inputsigL[j]);
				j++;
				inputsigL[j] = 0;
				inputsigV[j] = 0;
			}
			else if( buf[i] == '|' ) {
				i++;
			}
			else {
				inputsigV[j] = inputsigV[j] | (1 << (buf[i] - 'a')) ;
				inputsigL[j]++;
			}

			i++;
		}

		// Reset digits to 0s
		//  5
		// 4 0
		//  6
		// 3 1
		//  2
		for( i = 0; i < 8; i++ )
			map[i] = 0;

		// Find the 1
		for( i = 0; i < 10; i++ ) {
			if( inputsigL[i] == 2 ) {
				map[0] = inputsigV[i];
				map[1] = inputsigV[i];
			}
		}

		// Find the 7
		for( i = 0; i < 10; i++ ) {
			if( inputsigL[i] == 3 ) {
				map[5] = inputsigV[i] - map[0];
			}
		}

		// Find the 4
		for( i = 0; i < 10; i++ ) {
			if( inputsigL[i] == 4 ) {
				map[4] = inputsigV[i] - map[0];
				map[6] = inputsigV[i] - map[0];
			}
		}

		// Find the 3
		for( i = 0; i < 10; i++ ) {
			if( (inputsigL[i] == 5) && ((inputsigV[i] & map[0]) == map[0]) ) {
				map[6] = map[6] & (inputsigV[i] - map[5]);
				map[4] -= map[6];
				map[2] = inputsigV[i] - map[0] - map[5] - map[6];
				break;
			}
		}

		// Find the 5
		for( i = 0; i < 10; i++ ){
			if( (inputsigL[i] == 5) && ((inputsigV[i] & map[4]) == map[4]) ) {
				printf("%d\n", inputsigV[i]);
				map[1] = inputsigV[i] - map[2] - map[6] - map[5] - map[4];
				break;
			}
		}

		map[0] -= map[1];
		map[3] = 127 - map[0] - map[1] - map[2] - map[4] - map[5] - map[6];

		sigs = 0;
		// Now we know where everything is :)
		for( j = 10; j < 14; j++) {
			sig = 0;
			for( i = 0; i < 7; i++ ) {
				if( (inputsigV[j] & map[i]) == map[i] )
					sig = sig | (1 << i);
			}

			for( i = 0; i < 10; i++ ) {
				if( nums[i] == sig )
					sigs = (sigs * 10) + i;
			}
		}
		ans += sigs;
	}

	printf("%d\n", ans);
}

void print4bit7seg( int *seg ) {
	printf(" ");
	if( seg[5] ) printf("_"); else printf(" ");
	printf("\n");
	if( seg[4] ) printf("|"); else printf(" ");
	if( seg[6] ) printf("_"); else printf(" ");
	if( seg[0] ) printf("|"); else printf(" ");
	printf("\n");
	if( seg[3] ) printf("|"); else printf(" ");
	if( seg[2] ) printf("_"); else printf(" ");
	if( seg[1] ) printf("|"); else printf(" ");
	printf("\n");
}


