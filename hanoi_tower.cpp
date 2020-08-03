#include <iostream>

int solanchuyendia=0;

void HanoiTower(int n, char a, char b, char c)
{
     if (n==1){
        solanchuyendia++;
        printf("Lan %d: Chuyen 1 dia tu %c sang %c\n",solanchuyendia,a,c);
     }
     else{
           HanoiTower(n-1,a,c,b);
           HanoiTower(1,a,b,c);
           HanoiTower(n-1,b,a,c);
    }
}

void move(int n, int a, int b, int c) {
    if (n > 0) {
        move(n - 1, a, c, b);
        printf("\n Move disk %d from %c to %c", n, a, c);
        move(n - 1, b, a, c);
    }
}

int main(){

    // HanoiTower(4,'A','B','C');
    move(4, 'A', 'B', 'C');
    system("pause");
    return 1;
}
