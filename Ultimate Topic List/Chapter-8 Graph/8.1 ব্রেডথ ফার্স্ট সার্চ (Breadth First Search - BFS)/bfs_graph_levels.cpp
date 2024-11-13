#include <bits/stdc++.h>
using namespace std;

const int mx = 2e5 + 5;

vector<int> adj[mx];
bool visited[mx];
int level[mx];

void bfs(int src) {
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                level[neighbor] = level[node] + 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e;
    cin >> n >> e;
    
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
  
    int src;
    cin >> src;
    memset(visited, false, sizeof(visited));
    memset(level, -1, sizeof(level));
    bfs(src);
    
    for (int i = 0; i < n; i++) {
        cout << "Node: " << i << ", Level: " << level[i] << '\n';
    }
    
    return 0;
}