/*
---------------------------------------------------------------------------------------------------------------------------------
EX:08
DATE:13.11.2024
GRAPH -NONLINEAR DATA STRUCTURE-BFS TRAVERSAL
---------------------------------------------------------------------------------------------------------------------------------
*/
//Name:JEFFY D
//RollNo:23bec009
//Class:II-ECE
//Section:A
//Problem Statement:paperfree scholarship

#include <iostream>
#include <string>
using namespace std;
#define MAX 20

class QueueLinked {
private:
    struct node {
        int data;
        struct node* next;
    } * front, * rear, * p, * temp;

public:
    QueueLinked() {
        front = NULL;
        rear = NULL;
        p = NULL;
        temp = NULL;
    }

    void ENQUEUE(int);
    int DEQUEUE();
    bool isEmpty();
};
void QueueLinked::ENQUEUE(int d) {
    temp = new struct node;
    if(!temp) {
        cout << "Memory allocation failed" << endl;
        exit(1);
    }
    temp->data = d;
    temp->next = NULL;
    if (front == NULL) {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}
int QueueLinked::DEQUEUE() {
    if (front == NULL) {
        cout << "\nSorry Queue is empty; can't dequeue";
        return -1;
    }
    int x = front->data;
    node* temp = front;
    front = front->next;
    delete temp; // Free the dequeued node
    return x;
}
bool QueueLinked::isEmpty() {
    return front == NULL;
}

class Graph {
private:
    struct Node {
        string name;
        string gender;
        int hsc_mark;
        float parent_income;
        long int aadhar_no;
        long int account_no;
        int vertex;
        struct Node* next;
    }* G[MAX], * p, * temp; // Adjacency list representation of the graph
    bool visited[MAX];  // Visited array for BFS
    int vertices;

public:
    Graph(int v);
    struct Node* createNode(int v, string name, string gender, int hsc_mark, float parent_income, long int aadhar_no, long int account_no);
    void addEdges(int edges[][2], int e, string names[], string genders[], int marks[], float incomes[], long int aadhars[], long int accounts[]); // Method to add edges from predefined input
    void insert(int vs, int vd, string name, string gender, int hsc_mark, float parent_income, long int aadhar_no, long int account_no); // Method to insert a node in adjacency list
    void BFS(int source);        // Breadth-First Search traversal
    void display();              // Method to display the adjacency list
    ~Graph();
};

// Destructor to free the memory used by the graph
Graph::~Graph() {
    for (int i = 0; i < vertices; i++) {
        Node* head = G[i];
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
}

// Method to create and initialize a new node
Graph::Node* Graph::createNode(int v, string name, string gender, int hsc_mark, float parent_income, long int aadhar_no, long int account_no) {
    temp = new Node;
    if(!temp) {
        cout << "Memory allocation failed" << endl;
        exit(1);
    }
    temp->vertex = v;
    temp->name = name;
    temp->gender = gender;
    temp->hsc_mark = hsc_mark;
    temp->parent_income = parent_income;
    temp->aadhar_no = aadhar_no;
    temp->account_no = account_no;
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
void Graph::addEdges(int edges[][2], int e, string names[], string genders[], int marks[], float incomes[], long int aadhars[], long int accounts[]) {
    for (int i = 0; i < e; i++) {
        int vs = edges[i][0];
        int vd = edges[i][1];
        insert(vs, vd, names[vd], genders[vd], marks[vd], incomes[vd], aadhars[vd], accounts[vd]); // Add edge from vs to vd in the adjacency list
    }
}

// Algorithm for adjacency list for directed edges
void Graph::insert(int vs, int vd, string name, string gender, int hsc_mark, float parent_income, long int aadhar_no, long int account_no) {
    temp = createNode(vd, name, gender, hsc_mark, parent_income, aadhar_no, account_no);
    if (G[vs] == NULL) {
        G[vs] = temp; // First node in the list
        return;
    }
    p = G[vs];
    while (p->next != NULL) // Traverse to the end of the list
        p = p->next;
    p->next = temp;
}

// BFS Algorithm using `QueueLinked`
void Graph::BFS(int source) {
    QueueLinked q;
    q.ENQUEUE(source);
    visited[source] = true;

    while (!q.isEmpty()) {
        int current = q.DEQUEUE();
        if (current == -1) break; // Handle dequeue failure (queue empty)
        cout << "Vertex " << current << " --> Name: " << G[current]->name << ", Gender: " << G[current]->gender
             << ", HSC Mark: " << G[current]->hsc_mark << ", Parent Income: " << G[current]->parent_income
             << ", Aadhar No: " << G[current]->aadhar_no << ", Account No: " << G[current]->account_no << "\n";
        Node* p = G[current];
        while (p != NULL) {
            int vertex = p->vertex;
            if (!visited[vertex]) {
                q.ENQUEUE(vertex);
                visited[vertex] = true;
            }
            p = p->next;
        }
    }
}

// Method to display the adjacency list
void Graph::display() {
    for (int i = 0; i < vertices; i++) {
        Node* p = G[i];
        cout << "Adjacency list of vertex " << i << ":\n";
        while (p) {
            cout << " -> Vertex " << p->vertex << " (Name: " << p->name << ", Gender: " << p->gender
                 << ", HSC Mark: " << p->hsc_mark << ", Parent Income: " << p->parent_income
                 << ", Aadhar No: " << p->aadhar_no << ", Account No: " << p->account_no << ")";
            p = p->next;
        }
        cout << "\n";
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
    
    // Additional attributes for nodes
    string names[] = {"Alice", "Bob", "Charlie", "David", "Eve"};
    string genders[] = {"F", "M", "M", "M", "F"};
    int marks[] = {550, 600, 580, 620, 570};
    float incomes[] = {150000.0, 180000.0, 160000.0, 190000.0, 155000.0};
    long int aadhars[] = {123456789012, 234567890123, 345678901234, 456789012345, 567890123456};
    long int accounts[] = {987654321012, 876543210123, 765432101234, 654321012345, 543210123456};

    // Add edges to the graph
    graph.addEdges(edges, numEdges, names, genders, marks, incomes, aadhars, accounts);
    
    int source = 0; // Define the source vertex for BFS
    cout << "\nBFS Traversal from vertex " << source << ":\n";
    graph.BFS(source);

    // Display the entire adjacency list
    cout << "\nAdjacency List of the Graph:\n";
    graph.display();

    return 0;
}
/*


BFS Traversal from vertex 0:
Vertex    Name      Gender    HSC       Parent Income  Aadhar No      Account No     
-------------------------------------------------------------------------------------------------
0         Bob       M         600       180000         234567890123   876543210123   
1         David     M         620       190000         456789012345   654321012345   
2         Eve       F         570       155000         567890123456   543210123456   
3         Eve       F         570       155000         567890123456   543210123456   
*/
