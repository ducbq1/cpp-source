#include <stdio.h>
#include <conio.h>


typedef int elementtype;
typedef struct list_node {
                elementtype coeff;
                elementtype pow;
                struct list_node  *link;
} TPol;

TPol *sum(TPol *Poly1, TPol *Poly2)
{
    if(Poly1==NULL&&Poly2==NULL) return NULL;
    TPol *node=(TPol *)malloc (sizeof(TPol));
    TPol *PolySum=node;
    TPol *ptr1=Poly1; TPol *ptr2=Poly2;TPol *ptr;
    while(ptr1!=NULL && ptr2!=NULL){
       ptr=node;
       if  (ptr1->pow > ptr2->pow ) {
	       node->coeff=ptr2->coeff;
	       node->pow=ptr2->pow;
	       ptr2=ptr2->link;   //update ptr list 2
       }
       else if ( ptr1->pow < ptr2->pow )
         {
	          node->coeff=ptr1->coeff;
	          node->pow=ptr1->pow;
	          ptr1=ptr1->link;   //update ptr list 1
	      }
	      else
	      {  node->coeff=ptr2->coeff+ptr1->coeff;
	         node->pow=ptr2->pow;
	         ptr1=ptr1->link;   //update ptr list 1
	         ptr2=ptr2->link;   //update ptr list 2
	      }

       node=(TPol *)malloc (sizeof(TPol));
	   ptr->link=node;   //update ptr list 3
    } //end of while

    if (ptr1==NULL)     //end of list  1
    {
      while(ptr2!=NULL){
 	     node->coeff=ptr2->coeff; node->pow=ptr2->pow;
	     ptr2=ptr2->link;   //update ptr list 2
	     ptr=node; node=(TPol *)malloc (sizeof(TPol));
	     ptr->link=node;
      }  //update ptr list 3
    }
    else if (ptr2==NULL)     //end of list  2
	  {
	    while(ptr1!=NULL) {
	       node->coeff=ptr1->coeff;
	       node->pow=ptr1->pow;
	       ptr1=ptr1->link;   //update ptr list 2
	       ptr=node;
	       node=(TPol *)malloc (sizeof(TPol));
	       ptr->link=node;   //update ptr list 3
	   }
	}
  node=NULL;
  ptr->link=node;
  return PolySum;
}

TPol *createnewnode(int c, int p)
{
    TPol *pq=(TPol*)malloc(sizeof(TPol));
    if(pq==NULL)return NULL;
    pq->coeff=c;
    pq->pow=p;
    pq->link=NULL;
    return pq;
}

void indathuc(TPol *p)
{
    if(p==NULL) return;
    printf("\nDa thuc:\n");
    while(p!=NULL)
    {
        printf("%d;%d ",p->coeff,p->pow);
        p=p->link;
    }
    printf("\n");
}

int main()
{
    TPol *p,*q;
    p = createnewnode(3,0);
    p->link=createnewnode(-1,2);
    p->link->link=createnewnode(5,3);
    q=createnewnode(2,1);
    q->link=createnewnode(3,2);
    q->link->link=createnewnode(3,4);
    indathuc(p);
    indathuc(q);
    TPol *s=sum(p,q);
    indathuc(s);
	
	getch();
    return 1;
}
