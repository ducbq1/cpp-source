#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _node{
    int inf;
    struct _node *next;
} Node;

Node *makeNode(int X)
{
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->inf = X;
    newnode->next = NULL;
    return newnode;
}

void duyetds(Node *root)
{
    if(root==NULL) return;
    Node *p = root;
    while(p!=NULL)
    { printf("%d ",p->inf);
      p = p->next;
    }
}
void InsertToMiddle(Node *cur, int X)
{
    if(cur==NULL) return;
    Node *newnode = makeNode(X);
    newnode->next = cur->next;
    cur->next = newnode;
}

Node *InsertToHead(Node *root, int X)
{
    Node *newnode = makeNode(X);
    if(newnode==NULL) return root;
    newnode->next = root;
    root = newnode;
    return root;
}

int InsertToLast(Node *root, int X)
{
    if(root==NULL) return 0;
    Node *p = root;
    while(p->next!=NULL)
    { 
         p = p->next;
    }
    Node *newnode = makeNode(X);
    if(newnode==NULL) return 0;
    p->next = newnode;
    return 1;
}

int DeleteAtMiddle(Node *cur)
{
    if(cur==NULL) return 0;
    if(cur->next==NULL) return 0;
    Node *p = cur->next;
    cur->next = cur->next->next;
    free(p);
    return 1;
}

int main(void) {
        Node *root, *cur;
        Node *nut1 = makeNode(10);
        Node *nut2 = makeNode(5);
        Node *nut3 = makeNode(45);
        root = nut1;
        nut1->next = nut2;
        nut2->next = nut3;
        //duyetds(root);
        cur = nut2;
        InsertToMiddle(cur, 100);
        root = InsertToHead(root, 1000);
        InsertToLast(root, 20);
        cur = root;
        DeleteAtMiddle(cur);
        duyetds(root);
	return 1;
}

