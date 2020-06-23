#include <iostream>

using namespace std;
struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};


Node* prepend(Node* head, int data) {
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
    return head;
}

void print(Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node* reverse(Node* head) {
    Node* current = head;
    Node* prev = NULL;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

int main() {
    Node* head;
    for (int i = 0; i < 10; ++i) {
        head = prepend(head, i);
    }
    cout << "Original list: ";
    print(head);
    head = reverse(head);
    cout << "\nReversed list: ";
    print(head);

    return 0;
}