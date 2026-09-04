#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data, ht;
    struct Node *l, *r;
} Node;

int max(int a, int b) { return a > b ? a : b; }
int ht(Node *n) { return n ? n->ht : 0; }
Node* create(int k) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = k;n->l = n->r = NULL;n->ht = 1;
    return n;
}

Node* rRo(Node* y) {
    Node* x = y->l, *T2 = x->r;
    x->r = y; y->l = T2;
    y->ht = max(ht(y->l), ht(y->r)) + 1;
    x->ht = max(ht(x->l), ht(x->r)) + 1;
    return x;}

Node* lRo(Node* x) {
    Node* y = x->r, *T2 = y->l;
    y->l = x; x->r = T2;
    x->ht = max(ht(x->l), ht(x->r)) + 1;
    y->ht = max(ht(y->l), ht(y->r)) + 1;
    return y;}

int gBal(Node* n) {return n ? ht(n->l) - ht(n->r) : 0;}

Node* in(Node* n, int k) {
    if (!n) return create(k);
    if (k < n->data) n->l = in(n->l, k);
    else if (k > n->data) n->r = in(n->r, k);
    else return n;

    n->ht = 1 + max(ht(n->l), ht(n->r));int b = gBal(n);
    if (b > 1 && k < n->l->data)        return rRo(n);
    if (b < -1 && k > n->r->data)       return lRo(n);
    if (b > 1 && k > n->l->data)        { n->l = lRo(n->l); return rRo(n); }
    if (b < -1 && k < n->r->data)       { n->r = rRo(n->r); return lRo(n); }
    return n;
}

Node* min(Node* n) {while (n && n->l){ n = n->l; }return n;}

Node* del(Node* n, int k) {
    if (!n) return n;

    if (k < n->data) n->l = del(n->l, k);
    else if (k > n->data) n->r = del(n->r, k);
    else {
        if (n->l == NULL || n->r == NULL) {
            Node* temp = n->l ? n->l : n->r;
            if (!temp) {
                free(n);
                return NULL;
            }
            *n = *temp;   // copy temp to n
            free(temp);
        } else {
            // 2‑child case
            Node* temp = min(n->r);   // ino successor
            n->data = temp->data;
            n->r = del(n->r, temp->data); // delete the successor
        }
    }

    if (!n) return n;
    n->ht = 1 + max(ht(n->l), ht(n->r));
    int b = gBal(n);

    if (b > 1 && gBal(n->l) >= 0)   return rRo(n);
    if (b > 1 && gBal(n->l) < 0)    { n->l = lRo(n->l); return rRo(n); }
    if (b < -1 && gBal(n->r) <= 0)  return lRo(n);
    if (b < -1 && gBal(n->r) > 0)   { n->r = rRo(n->r); return lRo(n); }
    return n;
}

void ino(Node* n) {
    if (n) {
        ino(n->l);
        printf("%d ", n->data);
        ino(n->r);}
}

int main() {
    Node* root = NULL;
    int vals[] = {50, 30, 70, 20, 40, 60, 80}, n = 7;

    for (int i = 0; i < n; i++){
        root = in(root, vals[i]);}
    
    printf("Inorder after insert: ");
    ino(root); puts("");
    root = del(root, 70);   // 70 has two children (60 and 80)
    printf("Inorder after delete: ");
    ino(root); puts("");
    return 0;
}