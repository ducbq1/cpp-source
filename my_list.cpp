#include <bits/stdc++.h>
using namespace std;
#define NO 0
#define YES 1

typedef struct list_node {
    int data;
    struct list_node *next;
} list_node;

list_node* create(int data) {
    list_node* temp = new list_node;
    if (temp == nullptr) cout << "Error malloc storage!";
    temp->data = data;
    temp->next = nullptr;
    return temp;
}

bool isEmpty(list_node* list) {
    return list == nullptr;
}

int size_of(list_node* list) {
    int size = 0;
    list_node* temp = list;
    while (temp != nullptr) {
        size++;
        temp = temp->next;
    }
    return size;
}

void clear(list_node* list) {
    if (list == nullptr) return;
    clear(list->next);
    delete list;
}

void insert_push(list_node* first, int data) {
    if (first == nullptr) {
        first = create(data);
        return;
    }
    list_node* temp = first;
    list_node* tempNode = new list_node();
    tempNode->data = data;
    tempNode->next = nullptr;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = tempNode;
}

int find_node(list_node* first, int x) {
    list_node* temp = first;
    int index = 1;
    while (temp != nullptr && temp->data != x) {
        index++;
        temp = temp->next;
    }
    if (temp != nullptr) return index;
    else return 0;
}

void destroy_list(list_node** first) {
    list_node* currentNode = *first;
    list_node* nextNode = nullptr;
    while (currentNode != nullptr) {
        nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }
    *first = nullptr;
}

int main() {

    // list_node* first = create(65);
    // cout << first->data << '\n';
    // cout << "Size of list: " << size_of(first) << '\n';
    // cout << isEmpty(first) << '\n';

    list_node* first = create(5454);

    insert_push(first, 34);
    cout << first->data << '\n';
    cout << "Size of list: " << size_of(first) << '\n';

    insert_push(first, 55);
    insert_push(first, 45);
    insert_push(first, 77);
    cout << "Size of list: " << size_of(first) << '\n';
    cout << "Find x = 45: ";
    cout << find_node(first, 45) << '\n';

    destroy_list(&first);
    // clear(first);
    cout << "Size of list: " << size_of(first) << '\n';
    return 0;
}