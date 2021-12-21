#include<stdio.h>
#include<stdlib.h>

void	print2D( char*, int, int );

float	power( float, float );
float	fact( float );
float	choose( float );
float	signf( float );
float	absf( float );

struct Stack*	newStack( int );
void	freeStack( struct Stack* );
void	push( int, struct Stack* );
int		pop( struct Stack* );

void	insertionsort( long*, long );
