#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent, rank;
};

int find(struct Subset subsets[], int i);
void Union(struct Subset subsets[], int x, int y);
int compareEdges(const void* a, const void* b);
void KruskalMST(struct Edge edges[], int V, int E);

int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

void KruskalMST(struct Edge edges[], int V, int E) {
    qsort(edges, E, sizeof(edges[0]), compareEdges);
    struct Subset subsets[V];
    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    struct Edge result[V - 1];
    int e = 0;
    for (int i = 0; i < E && e < V - 1; i++) {
        int x = find(subsets, edges[i].src);
        int y = find(subsets, edges[i].dest);
        if (x != y) {
            result[e++] = edges[i];
            Union(subsets, x, y);
        }
    }
    printf("Edge   Weight\n");
    for (int i = 0; i < e; i++)
        printf("%d - %d    %d\n", result[i].src, result[i].dest, result[i].weight);
}

int main() {
    int V = 4;
    int E = 5;
    struct Edge edges[] = {
        {0, 1, 2},
        {0, 2, 1},
        {1, 2, 4},
        {1, 3, 5},
        {2, 3, 6}
    };
    printf("Minimum Spanning Tree (MST) using Kruskal's algorithm:\n");
    KruskalMST(edges, V, E);
    return 0;
}
