#include <iostream>
using namespace std;

class Graph {
    int v;
    int adj[10][10];
    bool visited[10];

public:
    Graph(int vertices) {
        v = vertices;
        for (int i = 0; i < v; i++)
            for (int j = 0; j < v; j++)
                adj[i][j] = 0;
    }

    void addEdge(int u, int w) {
        adj[u][w] = adj[w][u] = 1;
    }

    void BFS(int start) {
        bool vis[10] = {false};
        int q[10], front = 0, rear = 0;
        vis[start] = true;
        q[rear++] = start;

        cout << "BFS: ";
        while (front < rear) {
            int node = q[front++];
            cout << char(node + 'A') << " ";
            for (int i = 0; i < v; i++) {
                if (adj[node][i] && !vis[i]) {
                    vis[i] = true;
                    q[rear++] = i;
                }
            }
        }
        cout << endl;
    }

    void DFSrec(int node, bool vis[]) {
        vis[node] = true;
        cout << char(node + 'A') << " ";
        for (int i = 0; i < v; i++)
            if (adj[node][i] && !vis[i])
                DFSrec(i, vis);
    }

    void DFS(int start) {
        bool vis[10] = {false};
        cout << "DFS: ";
        DFSrec(start, vis);
        cout << endl;
    }

    void display() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++)
                cout << adj[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;
    Graph g(v);
    cout << "Enter number of edges: ";
    cin >> e;
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, w;
        cin >> u >> w;
        g.addEdge(u, w);
    }
    g.display();
    int start;
    cout << "Enter start vertex (0-" << v - 1 << "): ";
    cin >> start;
    g.BFS(start);
    g.DFS(start);
}
