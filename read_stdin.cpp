#include <stdio.h>

#define MAXLINE 50


// double average(double* a, int n) {
//     int i;
//     double sum = 0.0;
    
//     try {        
//         for (i = 0; i < n; i++)
//             sum += a[i];
//         return sum / n;
//     } catch (int error) {
//         printf("Error");
//         return 0;
//     }
// }

int main() {

    // double a[] = {4, 57, 7, 4};
    // int n = sizeof(a) / sizeof(a[0]);
    // printf("%f", average(a, n));

    int i;
    char s[MAXLINE];
    for (i = 0; i < MAXLINE - 1; i++) {
        int c = getchar();
        if (c == '\n' || c == EOF) {
            s[i] = '\0';
            break;
        } else {
            s[i] = c;
            // putchar(c);
        };
    }
    s[i] = '\0';
    printf("String: %s\n", s);
    return 0;
}

