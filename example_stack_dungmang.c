#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxN 100

typedef int elementType;

elementType stack[maxN];
int top;

void init()
{
	top = -1;
}

int isFull()
{
	if((top==(maxN-1))||(top>(maxN-1))) return 1;
	return 0;
}

int isEmpty()
{
	if(top==-1) return 1;
	return 0;
}


int push(elementType X)
{
	if(isFull()) return 0;
	stack[++top] = X;
	//printf("push %d\n",top);
	return 1;
}

elementType pop()
{
	if(isEmpty()) return 0;
	elementType e = stack[top--];
	//printf("pop %d\n",top);
	return e;
}

int main(void) {
	init();
	push(1000);
	push(100);
	while(!isEmpty())
	    printf("%d\n",pop());
	return 1;
}

