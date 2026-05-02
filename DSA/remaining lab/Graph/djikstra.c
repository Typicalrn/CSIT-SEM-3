// Dijkstra's Algorithm in C
#include <stdio.h>
#define INF 9999
#define V 7     // 0..6 → printed as 1..7

int Graph[V][V] = {
    {0,0,1,2,0,0,0},
    {0,0,2,0,0,3,0},
    {1,2,0,1,3,0,0},
    {2,0,1,0,0,0,1},
    {0,0,3,0,0,2,0},
    {0,3,0,0,2,0,1},
    {0,0,0,1,0,1,0}
};

void dijkstra(int src) {
    int dist[V], spt[V];  // spt[i] = 1 if shortest dist to i is final

    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        spt[i] = 0;
    }
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1, min = INF;
        for (int i = 0; i < V; i++) {
            if (!spt[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }
        if (u == -1) break;
        spt[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!spt[v] && Graph[u][v] && dist[u] + Graph[u][v] < dist[v]) {
                dist[v] = dist[u] + Graph[u][v];
            }
        }
    }

    for (int i = 0; i < V; i++) {
        if (i != src){
            printf("Distance from source to %d: %d\n", i, dist[i]);
        }
    }
}

int main() {
    int src = 0;
    dijkstra(src);
    return 0;
}