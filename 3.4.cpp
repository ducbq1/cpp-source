#include <bits/stdc++.h>
using namespace std;

int a[1000], n;
int mem[1000];

void init() {
    memset(mem, -1, sizeof(mem));
}

// quy hoach dong
int lis(int i) {
    if (i == 1) return 1;
    if (mem[i] != -1) return mem[i];
    int res = 1;
    for (int j = 0; j < i; j++) {
        if (a[j] < a[i])
            res = max(res, lis(j) + 1);
    }
    mem[i] = res;
    return res;
}
// truy vet loi giai
void trace(int i) {
    int res = i;
    for (int j = 0; j < i; j++) {
        if (mem[j] == mem[i] - 1 && a[j] < a[i]) {
            trace(j);
            break;
        }
    }
    cout << a[i] << " ";
}

int main() {
    init();
    cin >> n;
    for (int i  = 0; i < n; i++) 
        cin >> a[i];
    int res = 1, pos = 0;
    for (int i = 1; i < n; i++) {
        if (res < lis(i)) {
            res = lis(i);
            pos = i;
        }
    }
    cout << res << endl;
    trace(pos);
    return 0;
}

// int _lis( int arr[], int n, int *max_ref) 
// { 
//     /* Base case */
//     if (n == 1) 
//         return 1; 
  
//     // 'max_ending_here' is length of LIS ending with arr[n-1] 
//     int res, max_ending_here = 1;  
  
//     /* Recursively get all LIS ending with arr[0], arr[1] ... 
//        arr[n-2]. If   arr[i-1] is smaller than arr[n-1], and 
//        max ending with arr[n-1] needs to be updated, then 
//        update it */
//     for (int i = 1; i < n; i++) 
//     { 
//         res = _lis(arr, i, max_ref); 
//         if (arr[i-1] < arr[n-1] && res + 1 > max_ending_here) 
//             max_ending_here = res + 1; 
//     } 
  
//     // Compare max_ending_here with the overall max. And 
//     // update the overall max if needed 
//     if (*max_ref < max_ending_here) 
//        *max_ref = max_ending_here; 
  
//     // Return length of LIS ending with arr[n-1] 
//     return max_ending_here; 
// } 
  
// // The wrapper function for _lis() 
// int lis(int arr[], int n) 
// { 
//     // The max variable holds the result 
//     int max = 1; 
  
//     // The function _lis() stores its result in max 
//     _lis( arr, n, &max ); 
  
//     // returns max 
//     return max; 
// } 

// int main() {
//     int n;
//     cin >> n;
//     int a[n];
//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//     }
//     cout << lis(a, n);
    
//     return 0;
// }