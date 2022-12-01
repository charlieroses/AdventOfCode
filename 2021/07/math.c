// Charlie Stuart : src322
// CS-536 Fa21

#include"fns.h"

float power(float a, float b) {
	float r;

	r = 1;
	while( b > 0 ) {
		r *= a;
		b--;
	}
	while( b < 0 ) {
		r /= a;
		b++;
	}

	return r;
}

float fact(float a) {
	float r;

	r = 1;
	while( a > 0 )
		r *= a--;

	return r;
}

float choose(float a, float b) {
	return (fact(a))/(fact(b) * fact(a-b));
}

float signf( float x ) {
	if( x > 0.0f )
		return 1.0f;
	else if( x < 0.f )
		return -1.0f;
	else
		return 0.0f;
}

int abs( int x ) {
	if( x < 0 )
		return (x * -1);
	else
		return x;
}

float absf( float x ) {
	if( x < 0 )
		return (x * -1);
	else
		return x;
}
