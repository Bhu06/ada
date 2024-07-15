#include <stdio.h>
#include <stdlib.h>

// Adjacency list representation of the graph
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjList;
} Graph;

// Function to create a new node
Node* createNode(int vertex) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new graph
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = (Node**)malloc(numVertices * sizeof(Node*));
    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int source, int destination) {
    Node* newNode = createNode(destination);
    newNode->next = graph->adjList[source];
    graph->adjList[source] = newNode;
}

// Function to perform topological sorting
int* topologicalSort(Graph* graph) {
    int* topologicalOrder = (int*)malloc(graph->numVertices * sizeof(int));
    int* inDegree = (int*)calloc(graph->numVertices, sizeof(int));
    int topologicalIndex = 0;

    // Calculate the in-degree of each vertex
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjList[i];
        while (temp != NULL) {
            inDegree[temp->vertex]++;
            temp = temp->next;
        }
    }

    // Add vertices with zero in-degree to the topological order
    for (int i = 0; i < graph->numVertices; i++) {
        if (inDegree[i] == 0) {
            topologicalOrder[topologicalIndex++] = i;
        }
    }

    // Perform the source removal process
    for (int i = 0; i < topologicalIndex; i++) {
        int vertex = topologicalOrder[i];
        Node* temp = graph->adjList[vertex];
        while (temp != NULL) {
            int neighbor = temp->vertex;
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                topologicalOrder[topologicalIndex++] = neighbor;
            }
            temp = temp->next;
        }
    }

    return topologicalOrder;
}

int main() {
    int numVertices, numEdges;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    Graph* graph = createGraph(numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < numEdges; i++) {
        int source, destination;
        scanf("%d %d", &source, &destination);
        addEdge(graph, source, destination);
    }

    int* result = topologicalSort(graph);
    printf("Topological Ordering: ");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    free(graph->adjList);
    free(graph);
    return 0;
    
}
