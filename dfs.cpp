//Graph ADT - DFS Traversal  Implementation
#include <iostream>
using namespace std;
#define MAX 20

class Graph {
private:
    struct Node {
        int vertex;
        struct Node* next;
    }* G[MAX], *p, *temp;       // Adjacency list representation of the graph
    bool visited[MAX];  // Visited array for DFS
    int vertices;

public:
    Graph(int v);                
    struct Node* createNode(int v);
    void addEdges(int edges[][2], int e); // Method to add edges from predefined input
    void insert(int vs, int vd); // Method to insert a node in adjacency list
    void DFS(int source);        // Depth First Search traversal
};

// Method to create and initialize a new node
Graph::Node* Graph::createNode(int v) {
    temp = new Node;
    temp->vertex = v;
    temp->next = NULL;
    return temp;
}

// Constructor: Initializes the graph and visited array
Graph::Graph(int v) {
    p = NULL;
    temp = NULL;
    vertices = v;
    for (int i = 0; i < v; i++) {
        G[i] = NULL;
        visited[i] = false;
    }
}

// Algorithm to add edges to the graph
void Graph::addEdges(int edges[][2], int e) {
    for (int i = 0; i < e; i++) {
        int vs = edges[i][0];
        int vd = edges[i][1];
        insert(vs, vd); // Add edge from vs to vd in the adjacency list
    }
}

// Algorithm for adjacency list for directed edges
void Graph::insert(int vs, int vd) {
    temp = createNode(vd);
    if (G[vs] == NULL) {
        G[vs] = temp; // First node in the list
        return;
    }
        p = G[vs];
        while (p->next != NULL) // Traverse to the end of the list
            p = p->next;
        p->next = temp;
}

// Recursive DFS Algorithm
void Graph::DFS(int source) {
    cout << source << " --> ";
    visited[source] = true;
    Node* p = G[source];
    while (p != NULL) {
        int vertex = p->vertex;
        if (!visited[vertex])
            DFS(vertex); // Recursively visit adjacent vertice
        p = p->next;
    }
}

int main() {
    int vertices = 5;
    Graph graph(vertices);
    // Define edges as pairs of vertices
    int edges[][2] = {
        {0, 1},
        {0, 2},
        {1, 3},
        {1, 4},
        {2, 4},
        {3, 4}
    };
    int numEdges = 6;
    //int numEdges = sizeof(edges) / sizeof(edges[0]);
    // Add edges to the graph
    graph.addEdges(edges, numEdges);
    int source = 0; // Define the source vertex for DFS
    cout << "\nDFS Traversal from vertex " << source << ":\n";
    graph.DFS(source);
    return 0;