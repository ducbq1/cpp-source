#include <stdio.h>
#include <conio.h>

typedef int DataType;
typedef struct _node {
         DataType element;
         struct _node *next; } node;
typedef struct { node *front; node *back; } queue;

queue *init()
{
    queue *q=(queue*)malloc(sizeof(queue));
    if(q==NULL) return NULL;
    q->front=NULL;
    q->back=NULL;
    return q;
}

int isEmpty(queue *q)
{
    if(q==NULL) return -1;
    if(q->front==NULL&&q->back==NULL) return 1;
    return 0;
}

void enqueue(queue *q, DataType X)
{
    if(isEmpty(q)==-1) return;
    node *newnode =(node*)malloc(sizeof(node));
    if(newnode==NULL)return;
    newnode->next=NULL;
    newnode->element=X;
    if(isEmpty(q)==1)
    {
        q->front=newnode;
        q->back=newnode;
    }
    else{
        q->back->next=newnode;
        q->back=newnode;
    }
}

DataType dequeue(queue *q)
{
    if(isEmpty(q)==-1) return NULL;
    if(isEmpty(q)==1)
        return NULL;
    else{
        if(q->front==q->back)
        {
            node *tmp=q->front;
            DataType t=tmp->element;
            q->front=NULL;
            q->back=NULL;
            free(tmp);
            return t;
        }
        else{
            node *tmp=q->front;
            DataType t=tmp->element;
            q->front=q->front->next;
            free(tmp);
            return t;
        }
    }
}

int size(queue *q)
{
    if(isEmpty(q)==-1) return 0;
    if(isEmpty(q)) return 0;
    int spt=0;
    node *p=q->front;
    while(p!=NULL)
    {
        spt++;
        //printf("%d ",p->element);
        p=p->next;
    }
    return spt;
}

int main()
{
    queue *q=init();
    if(isEmpty(q)) printf("Khoi tao hang doi ok\n");
    enqueue(q,9);
    enqueue(q,7);
    enqueue(q,3);
    printf("spt la %d\n",size(q));
    while(!isEmpty(q))
    printf("%d ",dequeue(q));
    printf("\n");
	
	getch();
    return 1;
}
