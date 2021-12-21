#include<stdio.h>
#include<stdlib.h>

typedef struct Stack;

struct Stack {
	int top;
	int alloced;
	int *stack;
};

