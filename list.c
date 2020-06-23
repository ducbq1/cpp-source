#include "conio.h"
#include "stdlib.h"

#define maxlength 1000

typedef int elementtype;
typedef struct list_tag {
                elementtype elements [maxlength];
                int last;
} list_type;

int checkempty(list_type *lt)
{
    if(lt==NULL) return 1;//empty
    if(lt->last==-1) return 1;
    else return 0;
}

int checkfull(list_type *lt)
{
    if(lt==NULL) return 0;
    if(lt->last==maxlength-1) return 1;
    else return 0;
}

int insert(list_type *lt, int p, elementtype x)
{
     if(lt==NULL) return 0;
     if(checkfull(lt)==1) return 0;
     if(p<0||p>lt->last+1) return 0;
     if(p==lt->last+1)
     {
        lt->elements[lt->last+1]=x;
        lt->last++;
     }
     else{
        int i;
        for(i=lt->last;i>p-1;i--)
                lt->elements[i+1]=lt->elements[i];
        lt->elements[p]=x;
        lt->last++;
     }
     return 1;
}

int delete(list_type *lt, int p)
{
     if(lt==NULL) return 0;
     if(checkempty(lt)==1) return 0;
     if(p<0||p>lt->last) return 0;
     int i;
     for(i=p;i<lt->last;i++)
        lt->elements[i]=lt->elements[i+1];
     lt->last--;
     return 1;
}

void inds(list_type *lt)
{
    if(lt==NULL) return;
    int i;
    printf("\nds gom cac ptu: ");
    for(i=0;i<lt->last+1;i++)
        printf("\n %d",lt->elements[i]);
        printf("\n");
}

int main()
{
    list_type *lt=NULL;
    lt = (list_type*)malloc(sizeof(list_type));
    if(lt==NULL){return 0;}
    lt->last=-1;
    //printf("%d\n",lt->last);
    insert(lt,0,3);
    insert(lt,1,1);
    insert(lt,2,8);
    insert(lt,3,4);
    insert(lt,2,5);
    inds(lt);
    delete(lt,2);
    inds(lt);
	getch();
    return 1;
}
