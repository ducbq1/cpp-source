#include "conio.h"

int FibRec(int n, int F[]){
   printf("Goi ham fibo voi n=%d\n",n);
   if (n<=1)return n;
   else
   {
       if(F[n-1]<0)
           F[n-1] = FibRec(n-1,F);
       if(F[n-2]<0)
           F[n-2] = FibRec(n-2,F);
       return  F[n-1] + F[n-2];
   }
}

int Fact(int n){
  printf("Goi ham fact voi n=%d\n",n);
  if (n==0)
  {
      printf("Ket thuc ham fact voi n=0, tra ve 1\n");
      return 1;
  }
  else{
      int k = Fact(n-1);
      printf("Ket thuc ham fact voi n=%d, tra ve %d\n",n,n*k);
      return n*k;
  }
}

int C(int n, int k){
    if ((k==0)||(k==n)) return 1;
    else return C(n-1,k-1)+C(n-1,k);
}

//tinh f(n)=x^n
int power(int x, int n)
{
    if(n==0) return 1;
    else return x*power(x,n-1);
}

//tim min trong mang n phan tu
int timmin(int A[], int n)
{
    if(n==1) return A[0];
    else{
        int k = timmin(A,n-1);
        if(k>A[n-1])
            return A[n-1];
        else return k;
    }
}

int main(){
    int F[10];
    int k;
    for(k=0;k<10;k++) F[k] = -1;
    F[0] = 0;F[1]=1;
    int i = FibRec(10,F);
    /*
    int j = Fact(5);
    int cnk = C(5,3);
    int p2mu5 = power(2,5);
    int A[5] = {5,3,4,1,7};
    int minA = timmin(A,5);
    printf("fibo(10)=%d\n",i);
    printf("fact(5)=%d\n",j);
    printf("C(5,3)=%d\n",cnk);
    printf("2^5=%d\n",p2mu5);
    printf("minA = %d\n",minA);
    */
    getch();
    return 1;
}
