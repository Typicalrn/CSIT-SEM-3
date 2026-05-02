#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data, height;
    struct Node *left, *right;
} Node;

int max(int a, int b) { return a > b ? a : b; }
int height(Node *n) { return n ? n->height : 0; }

Node* createNode(int key) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = key;
    n->left = n->right = NULL;
    n->height = 1;
    return n;
}

Node* rightRotate(Node* y) {
    Node* x = y->left, *T2 = x->right;
    x->right = y; y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right, *T2 = y->left;
    y->left = x; x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

int getBalance(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

Node* insert(Node* n, int k) {
    if (!n) return createNode(k);
    if (k < n->data) n->left = insert(n->left, k);
    else if (k > n->data) n->right = insert(n->right, k);
    else return n;

    n->height = 1 + max(height(n->left), height(n->right));
    int b = getBalance(n);

    if (b > 1 && k < n->left->data)  return rightRotate(n);
    if (b < -1 && k > n->right->data) return leftRotate(n);
    if (b > 1 && k > n->left->data)  { n->left = leftRotate(n->left); return rightRotate(n); }
    if (b < -1 && k < n->right->data) { n->right = rightRotate(n->right); return leftRotate(n); }
    return n;
}

// simplified delete: no 2‑child case (no minValueNode)
Node* deleteNode(Node* n, int k) {
    if (!n) return n;
    if (k < n->data) n->left = deleteNode(n->left, k);
    else if (k > n->data) n->right = deleteNode(n->right, k);
    else {
        if (!n->left || !n->right) {
            Node* temp = n->left ? n->left : n->right;
            if (!temp) { free(n); return NULL; }
            *n = *temp; free(temp);
        } else {
            // skip 2‑child: just print a note
            printf("Delete 2‑child not supported.\n");
            return n;
        }
    }

    if (!n) return n;
    n->height = 1 + max(height(n->left), height(n->right));
    int b = getBalance(n);

    if (b > 1 && getBalance(n->left) >= 0)  return rightRotate(n);
    if (b > 1 && getBalance(n->left) < 0)   { n->left = leftRotate(n->left); return rightRotate(n); }
    if (b < -1 && getBalance(n->right) <= 0) return leftRotate(n);
    if (b < -1 && getBalance(n->right) > 0)  { n->right = rightRotate(n->right); return leftRotate(n); }
    return n;
}

void inorder(Node* n) {
    if (n) {
        inorder(n->left);
        printf("%d ", n->data);
        inorder(n->right);
    }
}

int main() {
    Node* root = NULL;
    int vals[] = {50, 30, 70, 20, 40, 60, 80}, n = 7;

    for (int i = 0; i < n; i++)
        root = insert(root, vals[i]);

    printf("Inorder after insert: ");
    inorder(root); puts("");

    root = deleteNode(root, 70);

    printf("Inorder after delete: ");
    inorder(root); puts("");

    return 0;
}