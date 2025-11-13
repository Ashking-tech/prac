#include<bits/stdc++.h>
using namespace std;

class Graph {
    int vertices;
    int adj[10][10]; // adjacency matrix
    bool visited[10];

    public:
    Graph(int v){
        vertices =v;
        // initialize adjacency matrix
        for (int i=0;i<v;i++)
          for (int j=0;j<v;j++)
          adj[i][j]=0;

    }
     // Add an edge between two vertices
    void addEdge(int u,int v){
        adj[u][v] =1;
        adj[v][u] =1; //unidirected Graph

    }
    void BFS(int start){
        bool visited[10]= {false};
        int queue[10],front=0 ,rear=0;

        visited[start]= true;
        queue[rear++]= start;

        cout << "BFS Traversal: ";
        while (front<rear){
            int node =queue[front++];
            cout << char(node+ 'A') << " ";

             for (int i = 0; i < vertices; i++){
                if (adj[node][i]==1 && !visited[i]) {
                    visited[i] = true;
                    queue[rear++] =i;

                }
            }

        }
        cout << endl;


    }
    void DFS_Recursion(int node,bool visited[]) {
        visited[node]= true;
        cout << char(node+ 'A') << " ";

        for (int i =0;i<vertices;i++) {
            if (adj[node][i]==1 && !visited[i]){
                DFS_Recursion(i,visited);
            }
        }

    }
    void DFS(int start) {
        bool visited[10]={false};
        cout << "DFS Traversal: " << endl;
        DFS_Recursion(start,visited);
        cout << endl;

    }
    void displayMatrix() {
        cout << "Adejancy Matrix:" << endl;

        for(int i=0; i<vertices;i++){
            for (int j=0;j<vertices;j++)
            cout << adj[i][j] << " ";
            cout << endl;

        }
     }
};

int main () {
    int v,e;
    cout << "Enter the number of locations (vvertices): " << endl;
    cin >> v;

    Graph g(v);

    cout << "Enter number of Connections (edges): " <<endl;
    cin >> e;

    cout << "Enter the edges: " << endl;
      for (int i=0; i< e;i++){
        int u, vtx;
        cin >> u>> vtx;
        g.addEdge(u,vtx);

      }
      g.displayMatrix();

      int start;
      cout << "Enter Starting Node: " <<endl;
      cin>> start;


      cout << " " << endl;
      g.BFS(start);
      g.DFS(start);

      return 0;


}
