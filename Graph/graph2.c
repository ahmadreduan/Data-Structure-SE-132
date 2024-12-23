#include <stdio.h>
#include <stdlib.h>

// A structure to represent an adjacency list node
struct AdjListNode {
    char dest;
    struct AdjListNode* next;
};

// A structure to represent an adjacency list
struct AdjList {
    struct AdjListNode* head;
};

// A structure to represent a graph. A graph
// is an array of adjacency lists.
// Size of array will be V (number of vertices
// in graph)
struct Graph {
    int V;
    struct AdjList* array;
};

// A utility function to create a new adjacency list node
struct AdjListNode* newAdjListNode(char dest) {
    struct AdjListNode* newNode = malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// A utility function that creates a graph of V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->V = V;

    // Create an array of adjacency lists. Size of
    // array will be V
    graph->array = malloc(V * sizeof(struct AdjList));

    // Initialize each adjacency list as empty by
    // making head as NULL
    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, char src, char dest) {
    // Add an edge from src to dest. A new node is
    // added to the adjacency list of src. The node
    // is added at the beginning
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src - 'A'].head;
    graph->array[src - 'A'].head = newNode;

    // Since the graph is undirected, add an edge from
    // dest to src also
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest - 'A'].head;
    graph->array[dest - 'A'].head = newNode;
}

// A utility function to print the adjacency list
// representation of the graph
void printGraph(struct Graph* graph) {
    int v;
    for (v = 0; v < graph->V; ++v) {
        struct AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %c\n head ", v + 'A');
        while (pCrawl) {
            printf("-> %c", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

// Driver program to test above functions
int main() {
    // Create the graph given in above figure
    int V = 5; // Total number of vertices
    struct Graph* graph = createGraph(V);
    addEdge(graph, 'A', 'B');
    addEdge(graph, 'A', 'E');
    addEdge(graph, 'B', 'C');
    addEdge(graph, 'B', 'D');
    addEdge(graph, 'B', 'E');
    addEdge(graph, 'C', 'D');
    addEdge(graph, 'D', 'E');

    // Print the adjacency list representation of the above graph
    printGraph(graph);

    return 0;
}