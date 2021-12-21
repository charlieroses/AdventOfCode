#include<stdlib.h>
#include"fns.h"
#include"dat.h"

struct Stack* newStack( int a ) {
	struct Stack *S;

	S = malloc(sizeof(struct Stack));

	S->top = 0;
	S->alloced = a;
	S->stack = malloc( a * sizeof(int) );

	return S;
}

void freeStack( struct Stack *S ) {
	free( S->stack );
	free( S );
}

void push( int val, struct Stack *S ) {
	S->top++;
	if( S->top == S->alloced ) {
		S->alloced *= 2;
		S->stack = realloc(S->stack, S->alloced * sizeof(int) );
	}

	S->stack[S->top] = val;
}

int pop( struct Stack *S ) {
	if( S->top == 0 )
		return NULL;

	S->top--;
	return S->stack[S->top + 1];


}
