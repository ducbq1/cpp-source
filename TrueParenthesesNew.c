#include <stdio.h>
#include <conio.h>

typedef char ElementType;
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
    if(isEmpty(st)) return NULL;
    StackNode *temp = st->top;
    ElementType X = st->top->Inf;
    st->top=st->top->Next;
    free(temp);
    return X;
}
int ktloai(char c, char p)
{
    if((c=='[')&&(p==']'))return 1;
    if((c=='(')&&(p==')'))return 1;
    if((c=='{')&&(p=='}'))return 1;
    return 0;
}

int ktbt(char x[],int n,Stack *st)
{
    if(!isEmpty(st)) return -1;
    int i;
    for(i=0;i<n;i++)
    {
        if((x[i]=='[')||(x[i]=='{')||(x[i]=='('))
           push(st,x[i]);
        else{
            if(isEmpty(st)) return 0;
            ElementType p = pop(st);
            if(ktloai(p,x[i])==0) return 0;
        }
    }
    if(!isEmpty(st)) return 0;
    return 1;
}

int main()
{
    Stack *st=Init();
    char a[6]={'{','[','(',')','}',']'};
    printf("%d\n",ktbt(a,6,st));
	
	getch();
    return 1;
}
