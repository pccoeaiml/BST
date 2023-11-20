#include <iostream>

using namespace std;

#define MAX 100

class Queue {
private:
    int front, rear;
    int queueArray[MAX];

public:
    Queue() {
        front = 0;
        rear = -1;
    }

    void enqueue(int item) {
        if (rear == MAX - 1) {
            cout << "Queue is full" << endl;
        } else {
            rear++;
            queueArray[rear] = item;
        }
    }

    int dequeue() {
        if (front > rear) {
            cout << "Queue is empty" << endl;
            return -1;
        } else {
            int item = queueArray[front];
            front++;
            return item;
        }
    }

    bool isEmpty() {
        return (front > rear);
    }
};

class Graph {
private:
    bool visited[MAX];
    int adj[MAX][MAX];
    int nodes;

public:
    Graph() {
        for (int i = 0; i < MAX; ++i) {
            visited[i] = false;
            for (int j = 0; j < MAX; ++j) {
                adj[i][j] = 0;
            }
        }
    }

    void addEdge(int node1, int node2) {
        adj[node1][node2] = 1;
        adj[node2][node1] = 1;  // For an undirected graph, add the reverse edge
    }

    void BFS(int start) {
        Queue queue;
        visited[start] = true;
        queue.enqueue(start);

        while (!queue.isEmpty()) {
            int current = queue.dequeue();
            cout << current << " ";

            for (int i = 0; i < nodes; ++i) {
                if (adj[current][i] && !visited[i]) {
                    visited[i] = true;
                    queue.enqueue(i);
                }
            }
        }
    }

    void setNodes(int numNodes) {
        nodes = numNodes;
    }
};

int main() {
    Graph graph;
    int nodes, edges;
    cout << "Enter number of nodes and edges: ";
    cin >> nodes >> edges;
    graph.setNodes(nodes);

    cout << "Enter edges (node1 node2):" << endl;
    for (int i = 0; i < edges; ++i) {
        int node1, node2;
        cin >> node1 >> node2;
        graph.addEdge(node1, node2);
    }

    int startNode;
    cout << "Enter the starting node for BFS: ";
    cin >> startNode;

    cout << "BFS Traversal starting from node " << startNode << ": ";
    graph.BFS(startNode);

    return 0;
}
