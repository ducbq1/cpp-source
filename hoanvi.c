// #include "conio.h"
#include <iostream>

int count=0;
int n = 6;
int X[6] = {0,0,0,0,0,0};
int A[6] = {1,2,3,4,5,6};

void inloigiai()
{
    int i;
    count++;
    printf("\nloi giai thu %d: ",count);
    for(i=0;i<n;i++)
        printf(" %d",X[i]);
    printf("\n");
}

int kiemtra_ucv(int ai,int k)
{
    int i;
    for(i=0;i<k-1;i++)
        if(ai==X[i]) return 0;

    return 1;
}

void Hoanvi(int k)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(kiemtra_ucv(A[i],k)==1)
        {
            X[k-1] = A[i];
            if(k==n) inloigiai();
            else Hoanvi(k+1);
        }
    }
}

int main()
{
    Hoanvi(1);
    // getch();
    return 1;
}
