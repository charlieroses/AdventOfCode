#include <stdio.h>
#include <stdlib.h>

int copyBoard(char *from, char* to, int l);
int rc2i(int r, int c, int w);
int checkAlive(char* board, int r, int c, int w);
int sameBoard(char *b1, char* b2, int l);
int printBoard(char* board, int w, int l);

int main() {
	FILE *fp;
	char val;
	char *board1, *board2;
	char *input;
	int w, h, l, m;
	int i, iter, r, c, alive, r2, c2;

	fp = fopen("input.txt", "r");

//	Literally just setup
	m = 1;
	input = malloc(m * sizeof(char));

	w = 0;
	h = 0;
	l = 0;
	val = fgetc(fp);
	while( val != EOF ) {
		if( val == '\n' ){
			h += 1;
		}
		else {
			input[l] = val;
			l += 1;
		}
		if( l == m ) {
			m *= 2;
			input = realloc(input, m*sizeof(char));
		}

		val = fgetc(fp);
	}

	w = l / h;

	board1 = malloc(l * sizeof(char));
	board2 = malloc(l * sizeof(char));

	copyBoard(input, board1, l);
	copyBoard(input, board2, l);

	fclose(fp);
	free(input);

//	Now program king ((:E

	// update b1 to b2
	// check b1 and b2 for same
	//	if same stop and return iter
	//	else copy b2 to b1 and repeat

	iter = 0;
	while( 1 ) {

		for( r = 0; r < h; r++ ) {
			for( c = 0; c < w; c++ ) {
				alive = 0;
				if( board1[ rc2i(r,c,w) ] == '.' ) {
					continue;
				}

				if( r > 0 && c > 0 ){
					// Upper Left
					r2 = r - 1;
					c2 = c - 1;
					while( r2 > 0 && c2 > 0 && board1[rc2i(r2,c2,w)] == '.' ) {
						r2 -= 1;
						c2 -= 1;
					}
					alive += checkAlive(board1, r2, c2, w);
				}
				if( r > 0 ) {
					// Up
					r2 = r - 1;
					c2 = c;
					while( r2 > 0 && board1[rc2i(r2,c2,w)] == '.' ) {
						r2 -= 1;
					}
					alive += checkAlive(board1, r2, c2, w);
				}
				if( r > 0 && c < (w - 1) ) {
					// Upper Right
					r2 = r - 1;
					c2 = c + 1;
					while( r2 > 0 && c2 < w-1 && board1[rc2i(r2,c2,w)] == '.' ) {
						r2 -= 1;
						c2 += 1;
					}
					alive += checkAlive(board1, r2, c2, w);
				}
				if( c > 0 ){
					// Left
					r2 = r;
					c2 = c - 1;
					while( c2 > 0 && board1[rc2i(r2,c2,w)] == '.' ) {
						c2 -= 1;
					}
					alive += checkAlive(board1, r2, c2, w);
				}
				if( c < (w - 1) ) {
					// Right
					r2 = r;
					c2 = c + 1;
					while( c2 < w-1 && board1[rc2i(r2,c2,w)] == '.' ) {
						c2 += 1;
					}
					alive += checkAlive(board1, r2, c2, w);
				}
				if( r < (h - 1) && c > 0 ) {
					// Lower Left
					r2 = r + 1;
					c2 = c - 1;
					while( r2 < h-1 && c2 > 0 && board1[rc2i(r2,c2,w)] == '.' ) {
						r2 += 1;
						c2 -= 1;
					}
					alive += checkAlive(board1, r2, c2, w);
				}
				if( r < (h - 1) ) {
					// Down
					r2 = r + 1;
					c2  = c;
					while( r2 < h-1 && board1[rc2i(r2,c2,w)] == '.' ) {
						r2 += 1;
					}
					alive += checkAlive(board1, r2, c2, w);
				}
				if( r < (h - 1)  && c < (w - 1) ) {
					// Lower Right
					r2 = r + 1;
					c2 = c + 1;
					while( r2 < h-1 && c2 < w-1 && board1[rc2i(r2,c2,w)] == '.' ) {
						r2 += 1;
						c2 += 1;
					}
					alive += checkAlive(board1, r2, c2, w);
				}

				if( r == 5 && c == 8 ) {
					printf("Alive: %d\n", alive);
				}

				if( board1[rc2i(r,c,w)]  == 'L' ) {
					if( alive == 0 ) {
						board2[rc2i(r,c,w)] = '#';
					}
					else {
						board2[rc2i(r,c,w)] = 'L';
					}
				}
				else {
					if( alive < 5 ) {
						board2[rc2i(r,c,w)] = '#';
					}
					else {
						board2[rc2i(r,c,w)] = 'L';
					}
				}


			}
		}

		printBoard(board1, w, l);
		printf("\n");

		if( sameBoard( board1, board2, l) ){
			break;
		}
		
		iter += 1;
		copyBoard(board2, board1, l);
	}

	printf("Iteration: %d\n", iter);

	alive = 0;
	for( i = 0; i < l; i++ ) {
		alive += (board1[i] == '#');
	}

	printf("Seats: %d\n", alive);

	free(board1);
	free(board2);
}

int rc2i(int r, int c, int w) {
	return (r * w) + c;
}

int checkAlive(char* board, int r, int c, int w) {
	return (board[rc2i(r, c, w)] == '#');
}

int copyBoard(char *from, char* to, int l) {
	int i;

	for( i = 0; i < l; i++){
		to[i] = from[i];
	}
}

int sameBoard(char *b1, char* b2, int l) {
	int i;

	for( i = 0; i < l; i++) {
		if( b1[i] != b2[i] ) {
			return 0;
		}
	}

	return 1;
}

int printBoard(char *board, int w, int l) {
	int i;

	for( i = 0; i < l; i++ ) {
		printf("%c", board[i]);

		if( (i+1) % w == 0 ) {
			printf("\n");
		}
	}
}
