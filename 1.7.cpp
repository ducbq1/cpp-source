#include <stdio.h>
#include <stdlib.h>

int* a; 
int n, tmp;

int main() {
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    a = (int*)malloc(sizeof(int) * n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }

    printf("The input array is: \n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", *(a + i));
    }
    printf("\n");

    for (int i = 0; i < n - 1; i++) {
        int indexMin = i;
        for (int j = i; j < n; j++) {
            if (*(a + j) < *(a + indexMin))
                indexMin = j;
        }
        if (indexMin != i) {
            tmp = *(a + i);
            *(a + i) = *(a + indexMin);
            *(a + indexMin) = tmp;
        }
    }

    printf("The sorted array is: \n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", *(a + i));
    }
    printf("\n");

    free(a);
    return 0;
    

}