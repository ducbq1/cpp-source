#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef int elementType;

typedef struct _QueueNode
{
	elementType Inf;
	struct _QueueNode *Next;
} QueueNode;


typedef struct _Queue
{
	QueueNode *front;
	QueueNode *rear;
} Queue;


Queue *init()
{
	Queue *q = (Queue*)malloc(sizeof(Queue));
	if(q==NULL) return NULL;
	q->front = NULL;
	q->rear = NULL;
	return q;
}

int isEmpty(Queue *q)
{
	if(q==NULL) return 1;
	if((q->front==NULL)&&(q->rear==NULL)) 
		return 1;
	else return 0;
}


int enqueue(Queue *q, elementType X)
{
	if(q==NULL) return 0;
	if(isEmpty(q))
	{
		QueueNode *newnode = (QueueNode*)malloc(sizeof(QueueNode));
		if(newnode==NULL) return 0;
		newnode->Next = NULL;
		newnode->Inf = X;
		q->rear = newnode;
		q->front= newnode;
		return 1;
	}
	else
	{
		QueueNode *newnode = (QueueNode*)malloc(sizeof(QueueNode));
		if(newnode==NULL) return 0;
		newnode->Next = NULL;
		newnode->Inf = X;
		q->rear->Next = newnode;
		q->rear = newnode;
		return 1;
	}
}


elementType dequeue(Queue *q)
{
	if(q==NULL) return 0;	
	if(q->front==q->rear)
	{
		elementType X = q->front->Inf;
		free(q->front);
		q->front = NULL;
		q->rear = NULL;
		return X;
	}
	else
	{
		elementType X = q->front->Inf;
		QueueNode *p = q->front;
		q->front = q->front->Next;
		free(p);
		return X;
	}
}


int main(void) {
	Queue *q = init();
        enqueue(q,1000);
	enqueue(q,100);
	enqueue(q,10);
	dequeue(q);
	enqueue(q,20);
	enqueue(q,200);
	while(!isEmpty(q))
		printf("%d\n",dequeue(q));
	return 1;
}

