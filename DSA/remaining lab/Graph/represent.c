#include <stdio.h>
#include <stdlib.h>

#define V 5
#define E 5

typedef struct Node {
    int v;
    struct Node *next;
} Node;

void addE(Node *adj[], int u, int v) {
    Node *n = malloc(sizeof(*n));
    n->v = v; n->next = adj[u]; adj[u] = n;
}

void pM(int g[V][V]) {
    puts("Adjacency Matrix:");
    for (int i = 0; i < V; i++, puts(""))
        for (int j = 0; j < V; j++)
            printf("%d ", g[i][j]);
}

void pL(Node *adj[]) {
    puts("Adjacency List:");
    for (int i = 0; i < V; i++) {
        printf("%d: ", i);
        for (Node *p = adj[i]; p; p = p->next) printf("%d -> ", p->v);
        puts("NULL");
    }
}

void dfs(Node *adj[], int v, int visit[]) {
    visit[v] = 1;
    printf("%d ", v);
    for (Node *p = adj[v]; p; p = p->next)
        if (!visit[p->v])
            dfs(adj, p->v, visit);
}

void bfs(Node *adj[], int start) {
    int visit[V] = {0}, q[V], front = 0, rear = 0;
    visit[start] = 1;
    q[rear++] = start;

    while (front < rear) {
        int v = q[front++];
        printf("%d ", v);

        for (Node *p = adj[v]; p; p = p->next) {
            if (!visit[p->v]) {
                visit[p->v] = 1;
                q[rear++] = p->v;
            }
        }
    }
}

int main() {
    int edges[E][2] = {{0,1},{0,4},{1,2},{2,3},{3,4}};
    int mat[V][V] = {0}, visit[V] = {0};
    Node *adj[V] = {0};

    for (int i = 0; i < E; i++) {
        int u = edges[i][0], v = edges[i][1];
        mat[u][v] = mat[v][u] = 1;
        addE(adj, u, v);
        addE(adj, v, u);
    }

    pM(mat);
    pL(adj);

    printf("DFS: ");
    dfs(adj, 0, visit);
    printf("\n");

    printf("BFS: ");
    bfs(adj, 0);
    printf("\n");

    return 0;
}