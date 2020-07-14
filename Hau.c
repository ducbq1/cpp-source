#include "conio.h"

int n = 8;
int X[8] = {0,0,0,0,0,0,0,0};

void inloigiai()
{
    int i;
    printf("\n");
    for(i=0;i<n;i++)
        printf(" %d",X[i]);
    printf("\n");
}

int fabs(int x, int y)
{
        if(x>y) return x-y;
        else return y-x;
}

int kiemtraUCV(int cot, int k)
{
    int i;
    for(i=0;i<k-1;i++)
    {
        if(cot==X[i]) return 0;
        if(fabs(cot,X[i])==fabs(i+1,k)) return 0;
    }
    return 1;
}

void Hau(int k)
{
    int cot;
    for(cot=1;cot<n+1;cot++)
    {
        int kt = kiemtraUCV(cot,k);//kt = 1 thi cot la ucv
        if(kt==1)//la ucv
        {
            X[k-1] = cot;
            if(k==n) inloigiai();
            else Hau(k+1);
        }
    }
}

int main()
{
    Hau(1);
    getch();
    return 1;
}
