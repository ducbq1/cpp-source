#include <stdlib.h>
#include <stdio.h>

typedef char elementType;
typedef struct _treeNode
{
    elementType inf;
    struct _treeNode *left, *right;
} treeNode;

treeNode *maketreenode(elementType X)
{
    treeNode *t = (treeNode*)malloc(sizeof(treeNode));
    if(t==NULL) return NULL;
    t->inf = X;
    t->left = NULL;
    t->right = NULL;
    return t;
}

void preOrder(treeNode *root)
{
    if(root==NULL) return;
    else
    {
        printf("%c ", root->inf);
        if(root->left!=NULL)
            preOrder(root->left);
        if(root->right!=NULL)
            preOrder(root->right);
    }
}

void inOrder(treeNode *root)
{
    if(root==NULL) return;
    else
    {
        if(root->left!=NULL)
            inOrder(root->left);
        printf("%c ", root->inf);
        if(root->right!=NULL)
            inOrder(root->right);
    }
}

void postOrder(treeNode *root)
{
    if(root==NULL) return;
    else
    {
        if(root->left!=NULL)
            postOrder(root->left);
        if(root->right!=NULL)
            postOrder(root->right);
        printf("%c ", root->inf);
    }
}


int countNodes(treeNode *root)
{
    if(root==NULL) return 0;
    else
    {
        int i = 0,j = 0;
        if(root->left!=NULL)
            i = countNodes(root->left);
        if(root->right!=NULL)
            j = countNodes(root->right);
        return i+j+1;
    }
}

int height(treeNode *root)
{
    if(root==NULL) return 0;
    else
    {
        int i = 0,j = 0;
        if(root->left!=NULL)
            i = height(root->left);
        if(root->right!=NULL)
            j = height(root->right);
        if(i>j) return i+1;
        else return j+1;
    }
}

int main()
{
    treeNode *root = NULL;
    treeNode *nutA, *nutB, *nutC, *nutD, *nutE, *nutF, *nutG, *nutH;

    nutA = maketreenode('A');
    nutB = maketreenode('B');
    nutC = maketreenode('C');
    nutD = maketreenode('D');
    nutE = maketreenode('E');
    nutF = maketreenode('F');
    nutG = maketreenode('G');
    nutH = maketreenode('H');

    nutA->left = nutB;
    nutA->right = nutD;
    nutB->left = nutC;
    nutD->left = nutE;
    nutD->right = nutF;
    nutE->right = nutG;
    nutG->right = nutH;
    root = nutA;

    preOrder(root);

    printf("\nChieu cao cua cay la %d\n",height(root));
    return 1;
}
