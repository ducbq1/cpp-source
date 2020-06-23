#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 4

typedef int elementType;

elementType queue[N];
int f,r;

void init()
{
	f = -1;
	r = 0;
}

int isFull()
{
	if(f==r) return 1;
	return 0;
}

int isEmpty()
{
	if((f==-1)&&(r==0)) return 1;
	return 0;
}


int enqueue(elementType X)
{
	if(!isFull())
	{
	     queue[r] = X;
	     r = (r+1)%N;
	     if(f==-1) f=0;
	}
}


int dequeue()
{
	if(!isEmpty())
	{
	     elementType X = queue[f];
	     f = (f+1)%N;
	     if(f==r)
	     {
		f = -1;
		r = 0;
	     }
	     return X;
	}
	return -1;
}


int main(void) {
	init();
        enqueue(1000);
	printf("r = %d, f=%d\n",r,f);
	enqueue(100);
	printf("r = %d, f=%d\n",r,f);
	enqueue(10);
	printf("r = %d, f=%d\n",r,f);
	dequeue();
	printf("r = %d, f=%d\n",r,f);
	enqueue(20);
	printf("r = %d, f=%d\n",r,f);
	enqueue(200);
	printf("r = %d, f=%d\n",r,f);
	while(!isEmpty())
		printf("%d\n",dequeue());
	return 1;
}

