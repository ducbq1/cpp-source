#include <stdlib.h>
#include <stdio.h>

int main()
{
    int i=0;
    int arr[] = {1,2,3};
    int *myarr;
    myarr = (int*)malloc(3*sizeof(int));
    myarr[0] = 1;
    myarr[1] = 2;
    myarr[2] = 3;
    while(i<1000)
    {
        i++;
    }

    printf("Hello world\n");
}
