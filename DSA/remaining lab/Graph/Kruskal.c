#include <stdio.h>
#include <stdlib.h>

#define V 4
#define E 5

typedef struct {
    int u, v, w;
} Edge;

int parent[V];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int a, int b) {
    parent[find(a)] = find(b);
}

int cmp(const void *a, const void *b) {
    return ((Edge *)a)->w - ((Edge *)b)->w;
}

void kruskal(Edge edges[]) {
    int cost = 0, count = 0;

    for (int i = 0; i < V; i++)
        parent[i] = i;

    qsort(edges, E, sizeof(Edge), cmp);

    printf("Edges in MST:\n");
    for (int i = 0; i < E && count < V - 1; i++) {
        int x = find(edges[i].u);
        int y = find(edges[i].v);

        if (x != y) {
            printf("%d - %d : %d\n", edges[i].u, edges[i].v, edges[i].w);
            cost += edges[i].w;
            unionSet(x, y);
            count++;
        }
    }

    printf("Minimum cost = %d\n", cost);
}

int main() {
    Edge edges[E] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskal(edges);
    return 0;
}