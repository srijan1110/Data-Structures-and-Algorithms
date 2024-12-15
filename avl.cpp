#include <iostream>
using namespace std;

struct Node {
    int key, height;
    Node *left, *right;
    Node(int val) : key(val), height(1), left(NULL), right(NULL) {}
};

int height(Node* n) { return n ? n->height : 0; }

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    x->right = y->left; y->left = x;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

Node* rotateRight(Node* y) {
    Node* x = y->left;
    y->left = x->right; x->right = y;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

Node* insert(Node* node, int key) {
    if (!node) return new Node(key);
    if (key < node->key) node->left = insert(node->left, key);
    else if (key > node->key) node->right = insert(node->right, key);
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = height(node->left) - height(node->right);
    if (balance > 1 && key < node->left->key) return rotateRight(node);
    if (balance < -1 && key > node->right->key) return rotateLeft(node);
    if (balance > 1 && key > node->left->key) { node->left = rotateLeft(node->left); return rotateRight(node); }
    if (balance < -1 && key < node->right->key) { node->right = rotateRight(node->right); return rotateLeft(node); }
    return node;
}

void inorder(Node* root) {
    if (root) { inorder(root->left); cout << root->key << " "; inorder(root->right); }
}

int main() {
    Node* root = NULL;
    for (int key : {30, 20, 40, 10, 25}) root = insert(root, key);
    inorder(root); 
    return 0;
}
