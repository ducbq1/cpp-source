#include "Burrtito"


#ifndef BURRTITO_H
#define BURRTITO_H

// code 

#endif // BURRTITO_H




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

string str1("first string");
string str2(str1);
string str3(5, '#');
string str4(str1, 6, 6);
string str5(str2.begin(), str2.begin() + 5);
string str6 = str4;
str4.clear();
int len = str6.length();
char ch = str6.at(2);
char ch_f = str6.front();
char ch_b = str6.back();
const char* charstr = str6.c_str();
str6.append(" extension");
str4.append(str6, 0, 6);
if (str6.find(str4) != string::npos) { /*  */ }
str6.substr(7, 3);
str6.substr(7);
str6.erase(7, 4);
str6.erase(str6.begin() + 5, str6.end() - 3);
str6.replace(2, 7, "ese are test");

int a[3];
int a[3] = {1, 2, 3};
int a[3] = {};
int a[3] = {[0...1] = 3};
int *a;
int* a;
int*a;
int * a;

g++ -std=c++11 -O2 -Wall test.cpp -o test


#include <bits/stdc++.h>
using namespace std;

int main() {
  /* Enter your code here */
  int n;
  cin >> n;
  string s[n];
  cin >> ws;
  for (int i = 0; i < n; i++) {
    getline(cin, s[i]);
  }
}

int hashFunction(Person person) {
  int hash = person.age;
  hash = hash + peron.name.length();
  if (person.sex == "M") {
    hash += 1;
  }
  return hash % 6;
}

cin >> doubleNumber;
cin.ignore();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
getline(cin, stringName);

cout << endl;
cout << '\n' << flush;

cout << fixed << setprecision(1) << x << endl;


2^10 === 10^3


sort(arr, arr + x);
sort(arr.begin(), arr.end());
find(arr.begin(), arr.end(), x);
lower_bound(arr.begin(), arr.end(), x);
string: size(), length()


bool (boolean)
char 
short
int / long
long long

unsigned char
unsigned short
unsigned int
unsigned long long

float
double

mảng tĩnh: int arr[10]
mảng động: vector<int>
danh sách liên kết list<int>
ngăn xếp stack<int>
hàng đợi queue<int>
hàng đợi ưu tiên priority_queue<int>
hàng đợi hai đầu deque<int>
tập hợp set<int>
ánh xạ map<int, int>

vector<pair<int, int>>
brute force - exhaustive search


use std::vector and std::string


istream::get()
istream::getline()
istream::ignore()

QuickSort: nếu số lượng phần tử nhỏ, chạy  theo sắp xếp chèn (InsertSort), nếu phần tử chốt không tốt, chuyển sang sắp xếp trộn MergeSort


set<int>::iterator it = s.begin();
auto it = s.begin();





