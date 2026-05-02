#include <stdio.h>
#include <stdlib.h>

#define V 5
#define E 5

typedef struct Node {
    int v;
    struct Node *next;
} Node;

void addEdge(Node *adj[], int u, int v) {
    Node *n = malloc(sizeof(*n));
    n->v = v; n->next = adj[u]; adj[u] = n;
}

void printMatrix(int g[V][V]) {
    puts("Adjacency Matrix:");
    for (int i = 0; i < V; i++, puts(""))
        for (int j = 0; j < V; j++)
            printf("%d ", g[i][j]);
}

void printList(Node *adj[]) {
    puts("Adjacency List:");
    for (int i = 0; i < V; i++) {
        printf("%d: ", i);
        for (Node *p = adj[i]; p; p = p->next) printf("%d -> ", p->v);
        puts("NULL");
    }
}

void dfs(Node *adj[], int v, int visited[]) {
    visited[v] = 1;
    printf("%d ", v);
    for (Node *p = adj[v]; p; p = p->next)
        if (!visited[p->v])
            dfs(adj, p->v, visited);
}

void bfs(Node *adj[], int start) {
    int visited[V] = {0}, q[V], front = 0, rear = 0;
    visited[start] = 1;
    q[rear++] = start;

    while (front < rear) {
        int v = q[front++];
        printf("%d ", v);

        for (Node *p = adj[v]; p; p = p->next) {
            if (!visited[p->v]) {
                visited[p->v] = 1;
                q[rear++] = p->v;
            }
        }
    }
}

int main() {
    int edges[E][2] = {{0,1},{0,4},{1,2},{2,3},{3,4}};
    int mat[V][V] = {0}, visited[V] = {0};
    Node *adj[V] = {0};

    for (int i = 0; i < E; i++) {
        int u = edges[i][0], v = edges[i][1];
        mat[u][v] = mat[v][u] = 1;
        addEdge(adj, u, v);
        addEdge(adj, v, u);
    }

    printMatrix(mat);
    printList(adj);

    printf("DFS: ");
    dfs(adj, 0, visited);
    printf("\n");

    printf("BFS: ");
    bfs(adj, 0);
    printf("\n");

    return 0;
}