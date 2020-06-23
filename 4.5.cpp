#include <vector>
#include <list>
#include <iostream>
#include <stack>

using namespace std;

void dfs(const vector<list<int>> & adj) {
    vector<bool> visited(adj.size());
    visited[1] = true;
    stack<int> s;
    s.push(1);
    while (!s.empty()) {
        int u = s.top();
        s.pop();
        cout << u << ' ';
        for (int v: adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                s.push(v);
            }
        }
    }
    cout << endl;
}

int main() {

    int n = 7;
    vector<list<int>> adj;
    adj.resize(n + 1);
    adj[1].push_back(2);
    adj[2].push_back(4);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[3].push_back(5);
    adj[5].push_back(2);
    adj[2].push_back(7);
    adj[6].push_back(7);
    dfs(adj);

}