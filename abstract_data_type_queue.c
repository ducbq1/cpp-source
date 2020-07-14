#include <stdio.h>
#include <conio.h>

typedef int ElementType;
typedef struct _StackNode{
    ElementType Inf;
    struct _StackNode *Next;
    } StackNode;


typedef struct _Stack{
     StackNode *top;
    } Stack;


Stack *Init()
{
    Stack *s=(Stack*)malloc(sizeof(Stack));
    if(s==NULL) return s;
    s->top=NULL;
    return s;
}

int isEmpty(Stack *st)
{
    if((st==NULL)||(st->top==NULL))
                return 1;
    return 0;
}

void push(Stack *st, ElementType X)
{
    StackNode *TempNode;
	TempNode = (StackNode *) malloc(sizeof(StackNode));
	TempNode->Inf=X;
	TempNode->Next=st->top;
	st->top=TempNode;
}

ElementType pop(Stack *st)
{
    if(isEmpty(st)) return 0;
    StackNode *temp = st->top;
    ElementType X = st->top->Inf;
    st->top=st->top->Next;
    free(temp);
    return X;
}

void chuyencs(int n, int b,Stack *st)
{
    if(!isEmpty(st))return;
    while(n>0)
    {
        push(st,n%b);
        n=n/b;
    }
    while(!isEmpty(st))
        printf("%d",pop(st));
    printf("\n");
}

int main()
{
    Stack *st=Init();
    /*push(st, 5);
    push(st, 7);
    push(st, 9);
    while(!isEmpty(st))
        printf("%d\n",pop(st));*/
    int n=20;
    chuyencs(n,2,st);
	
	getch();
    return 1;
}
