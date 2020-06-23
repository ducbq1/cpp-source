#include <stdio.h>

int main() {
    int a[7] = {13, -335, 235, 47, 67, 943, 1222};
    printf("Address of first five elements in memory.\n");
    for (int i = 0; i < 5; i++) {
        printf("\ta[%d] = %d", i, &a[i]);
        // printf("%d", a + i);
    }
    return 0;
}