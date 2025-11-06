#include <stdio.h>
#include <stdlib.h>
#define MAXVERTICES 100
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;
typedef struct {
    int numVertices;
    Node* adjLists[MAXVERTICES];
    int visited[MAXVERTICES];
} Graph;
Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v; newNode->next = NULL;
    return newNode;
}
void initGraph(Graph* graph, int vertices) {
    graph->numVertices = vertices;
    for(int i=0; i<vertices; i++) { graph->adjLists[i]=NULL; graph->visited[i]=0; }
}
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
    // Add src <-> dest if undirected
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}
void DFS(Graph* graph, int vertex) {
    graph->visited[vertex] = 1;
    printf("%d ", vertex);
    Node* temp = graph->adjLists[vertex];
    while(temp!=NULL) {
        int adjVertex = temp->vertex;
        if(!graph->visited[adjVertex])
            DFS(graph, adjVertex);
        temp = temp->next;
    }
}
void BFS(Graph* graph, int startVertex) {
    // BFS implementation using queue (see details in file for code)
}
int main() {
    Graph graph; int vertices = 6;
    initGraph(&graph, vertices);
    addEdge(&graph, 0, 1); addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 3); addEdge(&graph, 1, 4);
    addEdge(&graph, 2, 4); addEdge(&graph, 3, 4);
    addEdge(&graph, 3, 5); addEdge(&graph, 4, 5);
    printf("DFS starting from vertex 0: ");
    DFS(&graph, 0);
    // Reset visited and call BFS
    return 0;
}
