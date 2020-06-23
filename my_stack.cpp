#include <bits/stdc++.h>
using namespace std;

typedef struct IntegerStack {
    int *stackArray;
    int count;
    int stackMax;
    int top;
} IntStack;

IntStack *create_stack(int max) {
    IntStack *stack = new IntStack();
    if (stack == nullptr) return nullptr;
    stack->top = -1;
    stack->count = 0;
    stack->stackMax = max;
    stack->stackArray = new int[max];
    return stack; 
}

int push_stack(IntStack* stack, int data) {
    if (stack->count == stack->stackMax) return 0;
    (stack->count)++;
    (stack->top)++;
    stack->stackArray[stack->top] = data;
    return 1;
}

int pop_stack(IntStack* stack, int* data) {
    if (stack->count == 0) return 0;
    *data = stack->stackArray[stack->top];
    (stack->count)--;
    (stack->top)--;
    return 1;
}

bool is_empty_stack(IntStack* stack) {
    return stack->count == 0;
}

bool is_full(IntStack* stack) {
    return stack->count == stack->stackMax;
}

void changeRadix(int n, int m) {
    const char* digitChar = "0123456789ABCDEF";
    IntStack* stack = create_stack(100);
    do {
        push_stack(stack, n % m);
        n /= m;
    } while (n != 0);
    int p;
    while (!is_empty_stack(stack)) {
        pop_stack(stack, &p);
        printf("%c", digitChar[p]);
    }
    printf("\n");

}

int main() {
    changeRadix(3524362, 16);
    return 0;
}