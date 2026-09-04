//demonstrate and implement the operations of a binary search tree (BST) in C.
// The program should allow the user to insert values into the BST, search for values, 
// and display the contents of the BST in sorted order(inorder, preorder, postorder).
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* create(int val) {
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = val;
    new->left = new->right = NULL;
    return new;
}

Node* in(Node* root, int val) {
    if (root == NULL) return create(val);
    if (val < root->data) root->left = in(root->left, val);
    else if (val > root->data) root->right = in(root->right, val);
    return root;
}

Node* ser(Node* root, int key) {
    if (root == NULL || root->data == key) return root;
    if (key < root->data) return ser(root->left, key);
    return ser(root->right, key);
}

Node* min(Node* root) {
    Node* curr = root;
    while (curr && curr->left != NULL)
        curr = curr->left;
    return curr;
}

Node* del(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->data)
        root->left = del(root->left, key);
    else if (key > root->data)
        root->right = del(root->right, key);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = min(root->right);
        root->data = temp->data;
        root->right = del(root->right, temp->data);
    }
    return root;
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    Node* root = NULL;
    int values[] = {50, 30, 70, 20, 40, 60, 80},n = 7;

    for (int i = 0; i < n; i++)
        root = in(root, values[i]);

    printf("Inorder before delete: ");
    inorder(root);
    printf("\n");

    printf("Preorder before delete: ");
    preorder(root);
    printf("\n");

    printf("Postorder before delete: ");
    postorder(root);
    printf("\n");

    int key = 70;
    root = del(root, key);

    printf("Inorder after delete: ");
    inorder(root);
    printf("\n");

    printf("Searching %d: ", 60);
    if (ser(root, 60))
        printf("Found\n");
    else
        printf("Not Found\n");

    return 0;
}

