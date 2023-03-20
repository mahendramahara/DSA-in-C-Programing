#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    struct Node* adjacencyList[100];
    int visited[100];
};

void initializeGraph(struct Graph* graph, int numVertices) {
    for (int i = 0; i < numVertices; ++i) {
        graph->adjacencyList[i] = NULL;
        graph->visited[i] = 0;
    }
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = dest;
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = src;
    newNode->next = graph->adjacencyList[dest];
    graph->adjacencyList[dest] = newNode;
}

void dfs(struct Graph* graph, int startVertex) {
    int stack[100];
    int top = -1;
    stack[++top] = startVertex;
    graph->visited[startVertex] = 1;
    while (top != -1) {
        int currentVertex = stack[top--];
        printf("%d ", currentVertex);
        struct Node* current = graph->adjacencyList[currentVertex];
        while (current != NULL) {
            int neighbor = current->vertex;
            if (!graph->visited[neighbor]) {
                stack[++top] = neighbor;
                graph->visited[neighbor] = 1;
            }
            current = current->next;
        }
    }
}

void bfs(struct Graph* graph, int startVertex) {
    int queue[100];
    int front = 0, rear = -1;
    queue[++rear] = startVertex;
    graph->visited[startVertex] = 1;
    while (front <= rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);
        struct Node* current = graph->adjacencyList[currentVertex];
        while (current != NULL) {
            int neighbor = current->vertex;
            if (!graph->visited[neighbor]) {
                queue[++rear] = neighbor;
                graph->visited[neighbor] = 1;
            }
            current = current->next;
        }
    }
}

int main() {
    struct Graph graph;
    int numVertices, numEdges;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    initializeGraph(&graph, numVertices);
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);
    printf("Enter the edges (format: src dest):\n");
    for (int i = 0; i < numEdges; ++i) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(&graph, src, dest);
    }
    printf("\n\nDepth-First Search (DFS) starting from vertex 0:\n");
    dfs(&graph, 0);
    
    // Resetting visited array for BFS
    for (int i = 0; i < numVertices; ++i) {
        graph.visited[i] = 0;
    }

    printf("\n\nBreadth-First Search (BFS) starting from vertex 0:\n");
    bfs(&graph, 0);

    return 0;
}
