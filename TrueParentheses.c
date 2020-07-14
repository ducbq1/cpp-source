#include "conio.h"
#include "stdlib.h"

int soloigiai=0;
int n=6;
char A[6]={'(','?','?','?','(',')'};
char X[6]={' ',' ',' ',' ',' ',' '};

void inloigiai()
{
    printf("\n%d: ",++soloigiai);
    int i;
    for(i=0;i<n;i++)
    {
        printf(" %c",X[i]);
    }
    printf("\n");
}

void btngoacdung(int k, int m)
{
    int i;
    int dauhoithuk=0;
    if(m==0)
    {
        if(kiemtrabt(A,n)==1) printf("Day la bt ngoac dung\n");
        else printf("Day khong la bt ngoac dung\n");
        return;
    }

    for(i=0;i<n;i++)
    {
        if(A[i]=='?') dauhoithuk++;
        if (dauhoithuk==k) break;
    }

    X[i] = '(';
    if(k==m){ if(kiemtrabt(X,n)==1) inloigiai();}
    else btngoacdung(k+1,m);
    X[i] = ')';
    if(k==m){ if(kiemtrabt(X,n)==1) inloigiai();}
    else btngoacdung(k+1,m);
}

int kiemtrabt(char bt[], int size)
{
    int s=0;
    int i;
    for(i=0;i<size;i++)
    {
        if(bt[i]=='(') s++;
        else s--;
        if(s<0) return 0;
    }
    if(s>0) return 0;
    return 1;
}

void inday(char bt[], int size)
{
    printf("\nDay da cho la: ");
    int i;
    for(i=0;i<size;i++)
    {
        printf(" %c",bt[i]);
    }
    printf("\n");
}

void khoitaoX()
{
    int i;
    for(i=0;i<n;i++)
    {
        X[i] = A[i];
    }
}

int demkitu(char x)
{
    int i;
    int t=0;
    for(i=0;i<n;i++)
    {
        if(A[i]=='?') t++;
    }
    return t;
}

int main()
{
    inday(A,n);
    khoitaoX();
    int m = demkitu('?');
    btngoacdung(1,m);
	getch();
    return 1;
}
