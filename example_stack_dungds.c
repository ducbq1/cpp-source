#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int elementType;

typedef struct _StackNode
{
	elementType Inf;
	struct _StackNode *Next;
} StackNode;

typedef struct _Stack
{
	StackNode *top;
} Stack;


Stack *init()
{
	Stack *s = (Stack*)malloc(sizeof(Stack));
	if(s==NULL) 
	{
		printf("Error");
		return NULL;
	}
	s->top = NULL;
	return s;
}

int isEmpty(Stack *st)
{
	return st->top==NULL;
}


int push(Stack *st, elementType X)
{	
	StackNode *newnode = (StackNode*)malloc(sizeof(StackNode));
	if(newnode==NULL) return 0;
	newnode->Inf = X;
	newnode->Next = st->top;
	st->top = newnode;
	return 1;	
}

elementType pop(Stack *st)
{
	if(isEmpty(st)) return 0;
	StackNode *tempnode = st->top;
	elementType e = st->top->Inf;
	st->top = st->top->Next;
	free(tempnode);
	return e;
}

int main(void) {
	Stack *s = init();
	push(s,1000);
	push(s,100);
	push(s,10);
	while(!isEmpty(s)) printf("%d \n", pop(s));	
	return 1;
}

