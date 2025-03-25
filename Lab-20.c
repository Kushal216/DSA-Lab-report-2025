// Write a program to implement Dijkastra’s algorithm. 
#include <stdio.h>
#include<conio.h>
#define MAX 10
#define INF 9999  // Large number as infinity
void dijkstra(int G[MAX][MAX], int n, int src) {
    int dist[MAX], visited[MAX] = {0};
    int i, count, u, v, min;
    for (i = 0; i < n; i++){ 
        dist[i] = INF;
    }
    dist[src] = 0;
    for (count = 0; count < n - 1; count++) {
        u = -1;
        min = INF;
        for (v = 0; v < n; v++) {
            if (!visited[v] && dist[v] < min) {
                min = dist[v];
                u = v;
            }
        }
        if (u == -1) break;
        visited[u] = 1;
        for (v = 0; v < n; v++) {
            if (!visited[v] && G[u][v] && dist[u] + G[u][v] < dist[v]) {
                dist[v] = dist[u] + G[u][v];
            }
        }
    }
    for (i = 0; i < n; i++){
        printf("Vertex %d -> Distance: %d\n", i, dist[i]);
    }
}
int main() {
    int G[MAX][MAX], n, src, i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++){
            scanf("%d", &G[i][j]);
        }
    }
    printf("Enter source vertex: ");
    scanf("%d", &src);
    dijkstra(G, n, src);
    printf("\nProgram By: KUSHAL DHAKAL");
    return 0;
}
