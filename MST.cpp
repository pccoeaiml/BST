// #include <iostream>
// using namespace std;

// const int V = 10; 
// const int INF = 999; 

// int minKey(int key[], bool mstSet[], int vertices) {
//     int min = INF, min_index = -1;

//     for (int v = 0; v < vertices; v++) {
//         if (mstSet[v] == false && key[v] < min) {
//             min = key[v];
//             min_index = v;
//         }
//     }

//     return min_index;
// }

// void printMST(int parent[], int graph[V][V], int vertices) {
//     cout << "Edge \tWeight\n";
//     for (int i = 1; i < vertices; i++)
//         cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
// }

// void primMST(int graph[V][V], int vertices) {
//     int parent[V];
//     int key[V];
//     bool mstSet[V];

//     for (int i = 0; i < vertices; i++) {
//         key[i] = INF;
//         mstSet[i] = false;
//     }

//     key[0] = 0;
//     parent[0] = -1;

//     for (int count = 0; count < vertices - 1; count++) {
//         int u = minKey(key, mstSet, vertices);
//         mstSet[u] = true;

//         for (int v = 0; v < vertices; v++) {
//             if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
//                 parent[v] = u;
//                 key[v] = graph[u][v];
//             }
//         }
//     }

//     printMST(parent, graph, vertices);
// }

// int main() {
//     int vertices;
//     cout << "Enter the number of vertices (maximum " << V << "): ";
//     cin >> vertices;

//     int graph[V][V] = { {0} };

//     cout << "Enter the adjacency matrix for the graph (enter 0 for no edge and weight for existing edges):\n";
//     for (int i = 0; i < vertices; i++) {
//         for (int j = 0; j < vertices; j++) {
//             cin >> graph[i][j];
//         }
//     }

//     primMST(graph, vertices);

//     return 0;
// }

// OUTPUT:
// Enter the number of vertices (maximum 10): 4
// Enter the adjacency matrix for the graph (enter 0 for no edge and weight for existing edges):
// 0 10 11 44
// 10 0 0 9
// 11 0 0 6
// 44 9 6 0
// Edge    Weight
// 0 - 1   10
// 3 - 2   6
// 1 - 3   9

// #include <iostream>
// using namespace std;
// const int V = 10;
// const int INF = 999999; // A large constant value
// class PrimMST {
// public:
//     PrimMST(int vertices);
//     void addEdge(int u, int v, int weight);
//     void findMST();
// private:
//     int minKey(int key[], bool mstSet[]);
//     void printMST(int parent[]);
//     int vertices;
//     int graph[V][V];
// };
// PrimMST::PrimMST(int vertices) : vertices(vertices) {
//     for (int i = 0; i < V; ++i)
//         for (int j = 0; j < V; ++j)
//             graph[i][j] = 0;
// }
// void PrimMST::addEdge(int u, int v, int weight) {
//     graph[u][v] = graph[v][u] = weight;
// }
// int PrimMST::minKey(int key[], bool mstSet[]) {
//     int min = INF, min_index = -1;
//     for (int v = 0; v < vertices; ++v) {
//         if (!mstSet[v] && key[v] < min) {
//             min = key[v];
//             min_index = v;
//         }
//     }

//     return min_index;
// }

// void PrimMST::printMST(int parent[]) {
//     cout << "Edge \tWeight\n";
//     for (int i = 1; i < vertices; ++i)
//         cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
// }

// void PrimMST::findMST() {
//     int parent[V];
//     int key[V];
//     bool mstSet[V];

//     for (int i = 0; i < vertices; ++i) {
//         key[i] = INF;
//         mstSet[i] = false;
//     }

//     key[0] = 0;
//     parent[0] = -1;

//     for (int count = 0; count < vertices - 1; ++count) {
//         int u = minKey(key, mstSet);
//         mstSet[u] = true;

//         for (int v = 0; v < vertices; ++v) {
//             if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
//                 parent[v] = u;
//                 key[v] = graph[u][v];
//             }
//         }
//     }

//     printMST(parent);
// }

// int main() {
//     int vertices;
//     cout << "Enter the number of vertices (maximum " << V << "): ";
//     cin >> vertices;

//     PrimMST mst(vertices);

//     cout << "Enter the edges and weights (u, v, weight) for the graph (enter 0 for no edge):\n";
//     for (int i = 0; i < vertices; ++i) {
//         for (int j = 0; j < vertices; ++j) {
//             int weight;
//             cin >> weight;
//             mst.addEdge(i, j, weight);
//         }
//     }

//     mst.findMST();

//     return 0;
// }
