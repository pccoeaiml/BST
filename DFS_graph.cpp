#include <iostream>
#define MAX_VERTICES 100 // Maximum number of vertices
using namespace std;
struct Graph {
    int V;
    int adjList[MAX_VERTICES][MAX_VERTICES];
};
void addEdge(Graph *graph, int v, int w) {
    graph->adjList[v][w] = 1;
    graph->adjList[w][v] = 1; // For undirected graph (remove this line for directed graphs)
}
void DFS(Graph *graph, int start, bool visited[]) {
    cout << start << " ";
    visited[start] = true;
    for (int i = 0; i < graph->V; ++i) {
        if (graph->adjList[start][i] && !visited[i]) {
            DFS(graph, i, visited);
        }
    }
}
int main() {
    Graph graph;
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    graph.V = vertices;
    int edgesMatrix[MAX_VERTICES][MAX_VERTICES] = {0};
    cout << "Enter the number of edges: ";
    cin >> edges;
    cout << "Enter the edges (format: source destination):" << endl;
    for (int i = 0; i < edges; ++i) {
        int source, dest;
        cin >> source >> dest;
        addEdge(&graph, source, dest);
    }
    int startVertex;
    cout << "Enter the starting vertex for DFS: ";
    cin >> startVertex;
    bool visited[MAX_VERTICES] = {false};
    cout << "Depth-First Traversal starting from vertex " << startVertex << ": ";
    DFS(&graph, startVertex, visited);
    return 0;
}
