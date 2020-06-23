#include <stdio.h>

void reverse_array_method_one(int arr[], int size) {
    int l = 0, r = size - 1, temp;
    while (l < r) {
        int temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;
        l++;
        r--;
    }
}

void reverse_array_method_two(int* arr, int size) {
    int l = 0, r = size - 1, temp;
    while (l < r) {
        int temp = *(arr + r);
        *(arr + r) = *(arr + l);
        *(arr + l) = temp;
        l++;
        r--;
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main() {
    int myArray[] = {1, 3, 5, 6, 7, 8, 9, 11};
    int size = sizeof(myArray) / sizeof(myArray[0]);
    print_array(myArray, size);
    reverse_array_method_one(myArray, size);
    print_array(myArray, size);
    reverse_array_method_two(myArray, size);
    print_array(myArray, size);

}