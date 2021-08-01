#include <bits/stdc++.h>

using namespace std;

class Graph {
  int V;
  list<int>* adj;
  void DFSUtil(int v, bool visited[]);

  public:
    Graph(int V) {
      this->V = V;
      adj = new list<int>[V];
    }
    ~Graph() {
      delete[] adj;
    }
    void addEdge(int v, int w);
    int connectedComponents();
    // int NumberOfconnectedComponents();
};

int Graph::connectedComponents() {
  bool* visited = new bool[V];
  int count = 0;
  for (int v = 0; v < V; v++) {
     visited[v] = false;
  }
  // bool visited[V] = {0};
  for (int v = 0; v < V; v++) {
    if (visited[v] == false) {
      DFSUtil(v, visited);
      // cout << '\n';
      count += 1;
    }
  }
  // delete[] visited;
  return count;
}

void Graph::DFSUtil(int v, bool visited[]) {
  visited[v] = true;
  // cout << v << ' ';
  list<int>::iterator i;
  for (i = adj[v].begin(); i != adj[v].end(); ++i) {
    if (!visited[*i]) {
      DFSUtil(*i, visited);
    }
  }
}

void Graph::addEdge(int v, int w) {
  adj[v].push_back(w);
  adj[w].push_back(v);
}

int main() {
  int n, m, temp1, temp2;
  cin >> n >> m;
  Graph g(n);
  for (int i = 0; i < m; i++) {
    cin >> temp1 >> temp2;
    g.addEdge(temp1 - 1, temp2 - 1);
  }
  
  cout << g.connectedComponents(); 
  return 0;
}
