#include <stdio.h>
#include <conio.h>

typedef char datatype;
typedef struct Tnode
{
	datatype inf;                 // Dữ liệu cất giữ ở nút
	struct Tnode *left;
	struct Tnode *right;
}treeNode;

treeNode *maketreenode(datatype X)
{
    treeNode *newnode=(treeNode*)malloc(sizeof(treeNode));
    if(newnode==NULL)return NULL;
    newnode->inf=X;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

void preorder(treeNode *r)
{
    if(r==NULL)return;
    printf("%c",r->inf);
    preorder(r->left);
    preorder(r->right);
}

void postorder(treeNode *r)
{
    if(r==NULL)return;
    postorder(r->left);
    postorder(r->right);
    printf("%c",r->inf);
}

void inorder(treeNode *r)
{
    if(r==NULL)return;
    inorder(r->left);
    printf("%c",r->inf);
    inorder(r->right);
}

int height(treeNode *r)
{
    if(r==NULL)return 0;
    int i = height(r->left);
    int j = height(r->right);
    if(i>j) return i+1;
    else return j+1;
}

int cnode(treeNode *r)
{
    if(r==NULL)return 0;
    int s = 0;
    s += cnode(r->left);
    s += cnode(r->right);
    return s+1;
}

int cleaf(treeNode *r)
{
    if(r==NULL)return 0;
    if((r->left==NULL)&&(r->right==NULL)) return 1;
    int s = 0;
    s += cleaf(r->left);
    s += cleaf(r->right);
    return s;
}

int main()
{
    treeNode *root=NULL;
    treeNode *nutA=maketreenode('A');
    root=nutA;
    treeNode *nutB=maketreenode('B');
    treeNode *nutC=maketreenode('C');
    treeNode *nutD=maketreenode('D');
    treeNode *nutE=maketreenode('E');
    treeNode *nutF=maketreenode('F');
    treeNode *nutG=maketreenode('G');
    treeNode *nutH=maketreenode('H');
    treeNode *nutI=maketreenode('I');
    treeNode *nutJ=maketreenode('J');
    treeNode *nutK=maketreenode('K');
    nutA->left=nutB;
    nutB->left=nutE;
    nutB->right=nutC;
    nutC->left=nutG;
    nutC->right=nutD;
    nutE->right=nutF;
    nutG->left=nutH;
    nutH->right=nutI;
    nutI->right=nutJ;
    nutJ->right=nutK;
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    printf("chieu cao la %d\n",height(root));
    printf("so nut la %d\n",cnode(root));
    printf("so nut la la %d\n",cleaf(root));

    getch();
    return 0;
}
