#include <bits/stdc++.h>
using namespace std;

typedef struct tree_node {
    int data;
    struct tree_node* left;
    struct tree_node* right;
    tree_node(int key) {
        data = key;
        left = right = nullptr;
    }
} TREE_NODE;



void preorder(TREE_NODE* root) {
    if (root != nullptr) {
        cout << root->data << '\n';
        preorder(root->left);
        preorder(root->right);
    }
}

int height(TREE_NODE* tree) {
    if (tree == nullptr) return -1;
    else return 1 + max(height(tree->left), height(tree->right));
}

int count_leaf(TREE_NODE* tree) {
    if (tree == nullptr) return 0;
    int count = 0;
    if (tree->left == nullptr && tree->right == nullptr)
        count++;
    else count += count_leaf(tree->left) + count_leaf(tree->right);
    return count;
}

void delete_tree(TREE_NODE* tree) {
    if (tree != nullptr) {
        delete_tree(tree->left);
        delete_tree(tree->right);
        delete(tree);
    }
}

enum OpType {OPERATOR, OPERAND};
struct InfoNode {
    OpType whichType;
    union {
        char operator;
        int operand;
    }
};

int main() {
    TREE_NODE* leftChild = new TREE_NODE(20);
    TREE_NODE* rightChild = new TREE_NODE(30);
    TREE_NODE* root = new TREE_NODE(10);
    root->right = rightChild;
    root->left = leftChild;
    root->data = 50;
    preorder(root);
    cout << height(root);
    cout << '\n' << count_leaf(root);
    return 0;
}

