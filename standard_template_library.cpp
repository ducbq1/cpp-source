#include <bits/std++.h>
using namespace std;

int main() { /*  */ }
int main(int argc, char* argv[]) { /*  */ }

fprintf(stderr, "There is an error!\n");
fprintf(stderr, "%d", keyVariable);

FILE* fp = fopen("logfile", "w");
printf(fp, "%d", keyVariable);
fflush(fp);

assert([condition]);

float x;
int y;
void *p;
p  = &x;
*((float*)p) = 2.5;
p = &y;
*((int*)p) = 2;

a === &a[0];
a + i === &a[i];
*(a + i) === a[i];

// inline: compiler
// macros: preprocessor
define max(a, b) (a > b ? a : b)

inline double delta(double a, double b) {
    return sqrt(a * a + b * b);
}
   
// con tro ham
int (*ptr)(int) = MyFunc;
// con tro tro toi con tro
int x = 12;
int *p1 = &x;
int **p2 = &p1;

// mo ta mang 2 chieu qua con tro cua con tro theo:
M[i][k] = *(*(M + i) + k)


int *pds;
pds = new int[200];
delete []pds;

x[i][j] = y[i * n + j]

int **mt;
mt = new int *[R];
int * temp = new int[R*C];
for (int i = 0; i < R; ++i) {
    mt[i] = temp;
    temp += C;
}

delete [] mt[0];
delete [] mt;

float ** M = new float *[R];
for (int i = 0; i < R; i++) {
    M[i] = new float[C];
}
// giai phong bo nho
for (int i = 0; i < R; i++) {
    delete []M[i];
}
delete []M;

// ham nhan tham so la con tro
void Swap(int *X, int *Y) {
    int temp = *X;
    *X = *Y;
    *Y = temp;
}
Swap(&A, &B);

// ham nhan tham so la tham chieu
void Swap(int &X, int &Y) {
    int temp = X;
    X = Y;
    Y = temp;
}
Swap(A, B);

// phep tham chieu
int X = 4;
int & MyFunc() {
    return X;
}

int main() {
    cout << X << endl;
    cout << MyFunc() << endl;
    MyFunc() = 20;
    cout << X;
    return 0;
}


// ham voi tham so ngam dinh

void MyDelay(long Loops = 1000) {
    for (int i = 0; i < Loops; ++i);
}

MyDelay() // Loops co gia tri la 1000
MyDelay(5000) // Loops co gia tri la 5000

int MyFunc(int a, int b = 2, int c = 3, int d = 4) {}

// da nang hoa ham
int abs(int i);
long abs(long l);
double fabs(double d);

// trong C++
Syntax: data_type operator operator_symbol(parameters) {}
#include <iostream>

typedef struct SP {
    double THUC;
    double AO;
};
// khai bao prototype
SP SetSP(double R, doube I);
void DisplaySP(SP C);
SP operator + (SP C1, SP C2);
SP operator - (SP C1, SP C2);

int n = sizeof(arr) / sizeof(arr[0]);
while (scanf("%d", &n), n) {};
while (scanf("%d", &n) == 1 && n != 0) {};
while (cin >> data) {}
matrix[i][j] = matrix_one_demensional[i * n + j];
x & 1 ==== x % 2
x >> 1 ===== x / 2

Parameter is variable in the declaration of function.
Argument is the actual value of this variable that gets passed to function.