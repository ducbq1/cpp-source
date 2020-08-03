#include <stdio.h>
#include <conio.h>

typedef int ElementType;
struct NodeType{
    ElementType Inf;
    struct NodeType *Next;
    };
typedef struct NodeType List;

List *createnewnode(ElementType X){
    List *nutmoi=(List*)malloc(sizeof(List));
    if(nutmoi==NULL){printf("Loi cap phat bo nho\n");return;}
    nutmoi->Inf=X;
    nutmoi->Next=NULL;
    return nutmoi;
}

void duyetds(List *l)
{
    if(l==NULL)return;
    List *p=l;
    printf("\n");
    while(p!=NULL){
        printf(" %d",p->Inf);
        p=p->Next;
    }
    printf("\n");
}

List *Insert_ToHead(List *First, ElementType X)
{
    List *TempNode;
	TempNode = (List *) malloc(sizeof(List));
	TempNode->Inf=X;
	TempNode->Next=First;
	First=TempNode;
	return First;
}

void Insert_ToLast(List *head, ElementType X)
{
    List *NewNode;
    List *TempNode;
    NewNode = (List *) malloc(sizeof(List));
    NewNode->Inf=X;
    NewNode->Next=NULL;
    TempNode=head;
    while (TempNode->Next != NULL) // go to the end of a list
        TempNode= TempNode->Next;
    TempNode->Next = NewNode;
}

void Insert_ToMiddle(List *Pred, ElementType X)
{
    if(Pred==NULL) return;
    List *NewNode;
    NewNode = (List *) malloc(sizeof(List));
    NewNode->Inf=X;
    NewNode->Next=Pred->Next;
    Pred->Next = NewNode;
}

List *Delete_AtHead(List *first)
{
    if(first==NULL) return NULL;
    List *temp = first;
    first=first->Next;
    free(temp);
    return first;
}

List *Delete_AtLast(List *First)
{
    if(First==NULL) return NULL;
    List *TempNode1, *TempNode2;
	TempNode1= First; TempNode2= First;
   while (TempNode1->Next != NULL) // Go to the end of a list
   {
        TempNode2 = TempNode1;
        TempNode1= TempNode1->Next;
    }
   TempNode2->Next = NULL;

   if(TempNode1==First)
   {
    free(TempNode1);
    return NULL;
   }
   else{
    free(TempNode1);
    return First;
   }
}

List *daods(List *f)
{
    if(f==NULL)return NULL;
    if(f->Next==NULL) return f;
    List *p1=NULL,*p2=f,*p3=f->Next;
    while(p3!=NULL)
    {
        p2->Next=p1;
        p1=p2;
        p2=p3;
        p3=p3->Next;
    }
    p2->Next=p1;
    f=p2;
    return f;
}

List *daods_dq(List *f)
{
    if(f->Next==NULL) return f;
    else
    {
        List *p=daods_dq(f->Next);
        //them ma de thay doi noi dung cac con tro
        f->Next->Next=f;
        f->Next=NULL;
        return p;
    }
}

int main(){
    List *first=NULL;
    first = (List*)malloc(sizeof(List));
    first->Inf=100;
    first->Next=NULL;

    List *nut2=(List*)malloc(sizeof(List));
    nut2->Inf=110;
    nut2->Next=NULL;

    first->Next=nut2;
    List *nut3=createnewnode(200);
    nut2->Next=nut3;
    duyetds(first);

    List *ds10knut=NULL,*p=NULL;
    int i;
    for(i=1;i<101;i++)
    {
        /*if(ds10knut==NULL){
            ds10knut=createnewnode(i);p=ds10knut;}
        else{
            p->Next=createnewnode(i);p=p->Next;
        }*/
        if(ds10knut==NULL){
            ds10knut=Insert_ToHead(ds10knut,i);}
        else{
            Insert_ToLast(ds10knut,i);
        }
    }
    ds10knut = Insert_ToHead(ds10knut,0);
    Insert_ToLast(ds10knut,101);
    duyetds(ds10knut);
    Insert_ToMiddle(ds10knut->Next->Next,1000);
    duyetds(ds10knut);
    ds10knut = Delete_AtHead(ds10knut);
    duyetds(ds10knut);
    ds10knut = Delete_AtLast(ds10knut);
    duyetds(ds10knut);
    ds10knut=daods_dq(ds10knut);
    duyetds(ds10knut);

    getch();
    return 1;
}
