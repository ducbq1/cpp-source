#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

bool isBitpartite(vector<int> adj[], int v, vector<bool>& visited, vector<int>& color) {
  for (int u : adj[v]) {
    if (visited[u] == false) {
      visited[u] = true;
      color[u] = !color[v];
      if (!isBitpartite(adj, u, visited, color)) {
        return false;
      }
    } else if (color[u] == color[v]) {
      return false;
    }
  }
  return true;
}

int main() {
  int n, m, temp1, temp2;
  cin >> n >> m;
  vector<int> adj[n + 1];
  vector<bool> visited(n + 1);
  vector<int> color(n + 1);
  for (int i = 0; i < m; i++) {
    cin >> temp1 >> temp2;
    addEdge(adj, temp1, temp2);
  }
  visited[1] = true;
  if (isBitpartite(adj, 1, visited, color)) {
    cout << 1;
  } else {
    cout << 0;
  }
  return 0;
}
