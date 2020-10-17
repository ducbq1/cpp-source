// a native cpp program to find maximum sum rotation
#include <bits/stdc++.h>
using namespace std;

int maxSum(int arr[], int n) {
    
    // initialize result
    int res = INT_MIN;
    
    // consider rotation beginning with i
    // for all possible values of i
    for (int i = 0; i < n; i++) {
        
        // inintialize sum of current rotation
        int curr_sum = 0;
        
        // compute sum of all values. We don't
        // acutally rotation the array, but compute
        // sum by finding indexs when arr[i] is
        // first element
        for (int j = 0; j < n; j++) {
            int index = (i + j) % n;
            curr_sum += j * arr[index];
        }

        // update result if required
        res = max(res, curr_sum);
    }

    return res;
}

// driver code
int main() {
    int arr[] = {8, 3, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSum(arr, n) << '\n';
    return 0;
}
