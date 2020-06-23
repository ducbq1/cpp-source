Dart: google
Flutter: google
Typescript: microsoft
React-native: facebook



fprintf(stderr, "There is an error!\n");
fprintf(stderr, "%d", keyVariable);


FILE* fp = fopen("logfile", "w");
printf(fp, "%d", keyVariable);
fflush(fp);

try {
    ...
} catch () {
    ...
}

assert([condition]);





Pointer:
        
    Syntax: dataType * PointerName; // sau khi khai bao ta duoc con tro NULL
    // su dung con tro ta dung toan tu lay dia chi
    PointerName = &VarName;
    int a;
    int *p;
    a = 10;
    p = &a;
    // lay noi dung bien do con tro tro toi, ta dung toan tu lay noi dung
    * PointerName
    // con tro void* co the tro toi bat ki mot loai bien nao, chi chua mot dia chi bo nho ma khong biet rang tai dia chi do co doi tuong kieu du lieu gi => khong the truy cap noi dung cua mot doi tuong thong qua con tro void
    // de truy cap duoc doi tuong thi truoc het phai ep kieu bien tro void thanh bien tro co dinh kieu cua kieu doi tuong
    float x;
    int y;
    void *p;
    p  = &x;
    *((float*)p) = 2.5;
    p = &y;
    *((int*)p) = 2;

    // con tro mang: gia su ta co int a[30]; thi &a[0] la dia chi phan tu dau tien, dong thoi la dia chi cua mang
    a = &a[0];
    a + i = &a[i];
    *(a + i) = a[i];

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

    // quan ly co nho dong
    // C: malloc, calloc, realloc, free
    // C++: new va delete

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
    // de hoan doi hai bien A va B
    Swap(&A, &B);

    // ham nhan tham so la tham chieu
    void Swap(int &X, int &Y) {
        int temp = X;
        X = Y;
        Y = temp;
    }
    // de hoan doi hai bien A va B
    Swap(A, B);

    // phep tham chieu
    #include <iostream>

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

// algorithms
// Input: dau vao
// Output: dau ra
// Precision: do chinh xac
// Finiteness: huu han
// Uniqueness: don tri
// Generality: tong quat



Recursive: gom phan neo de quy va phan quy nap
    De quy truc tiep:
        De quy tuyen tinh
        P() {
            if (B) S;
            else {
                S*;
                P();
            }
        }
        De quy nhi phan
        P() {
            if (B) S;
            else {
                S*;
                P();
                P();
            }
        }
        De quy phi tuyen
        P() {
            for (<begin> to <end>) {
                S;
                if (<stop condition>) {
                    S*;
                } else {
                    P();
                }
            }
        }
    De quy gian tiep
        De quy tuong ho: co hai ham, trong than cua ham nay co loi goi cua ham kia, dieu kien dung va gia tri tra ve cua ca hai ham co the giong hoac khac nhau




int n = sizeof(arr) / sizeof(arr[0]);
while (scanf("%d", &n), n) {};
while (scanf("%d", &n) == 1 && n != 0) {};
while (cin >> data) {}
matrix[i][j] = matrix_one_demensional[i * n + j];


Imperative paradigm <huong menh lenh> {
    first do this and next do that
    {
        Declaretive statements
        Assignment statements
        Program flow control statements
        Module {
            Function
            Procedures
        }
    }
}

Functional paradigm <huong chuc nang> {
    evaluate an expression and use the resulting value for something
    {
        Tap hop cac cau truc du lieu va cac ham lien quan
        Tap hop cac ham co so
        Tap hop cac toan tu
    }
}

Logical paradigm <huong logic> {
    answer a question via searching for a solution
    Tu dong kiem chung trong AI
    Dua tren cac tien de - axioms, quy luat suy dien - inference rules, cac truy van - queries
}

Object-oriented paradigm <huong doi tuong> {
    send messages between objects to simulate a temporal evolution of a set of real world phenomena
    Mo hinh tuong tac trong the gioi thuc
    Du lieu cung nhu thao tac tren du lieu duoc bao goi
    Co che che giau thong tin noi bo duoc su dung de tranh tac dong ben ngoai
    Cac doi tuong tuong tac voi nhau qua viec truyen thong diep
    Doi tuong phan loai thanh cac lop gom thuoc tinh va phuong thuc
    Co tinh ke thua, da hinh ...
}

Visual paradigm
Parallel paradigm
Concurrent paradigm
Distributed paradigm
Service-oriented paradigm

Chu trình phát triển phần mềm: {
    Analyse requirements: {
        Thiet lap requirements,
        Gap cac nha phan tich he thong va users
        Xac dinh input, output, processing va cac thanh phan du lieu
    },
    Design solution: {
        Object-oriented design,
        Structure design (top-down design),
        Design hierarchy chart
        Design algorithm
    },
    Validate design,
    Implement design: {
        Syntax,
        Comments,
    },
    Test solution,
    Document solution,
}
