// Write a program to implement Kruskal’s algorithm.
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct Edge {
    int u, v, weight;
};
struct Edge edges[MAX];
int parent[MAX];
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}
void union_set(int u, int v) {
    parent[u] = v;
}
void kruskal(int n, int e) {
    int i, j, min_cost = 0;
    struct Edge temp;
    
    for (i = 0; i < n; i++)
        parent[i] = i;
    
    for (i = 0; i < e - 1; i++) {
        for (j = 0; j < e - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
    
    printf("Minimum Spanning Tree:\n");
    for (i = 0; i < e; i++) {
        int u = find(edges[i].u);
        int v = find(edges[i].v);
        
        if (u != v) {
            printf("%d - %d: %d\n", edges[i].u, edges[i].v, edges[i].weight);
            min_cost += edges[i].weight;
            union_set(u, v);
        }
    }
    
    printf("Minimum Cost Spanning Tree: %d\n", min_cost);

int main() {
    int n, e, i;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);
    
    printf("Enter edges (u v weight):\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }
    
    kruskal(n, e);
    printf("\n\nProgram By: KUSHAL DHAKAL");
    return 0;
}
