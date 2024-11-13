#include <bits/stdc++.h>
using namespace std;

const int mx = 2e5 + 5;

vector<int> adj[mx];
bool visited[mx];

void bfs(int src, int des) {
    queue<pair<int, int>> q;
    q.push({src, 0});
    visited[src] = true;
    bool found = false;
    
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int node = p.first;
        int level = p.second;
        
        if (node == des) {
            cout << "Shortest path length: " << level << '\n';
            found = true;
            break;
        }
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                q.push({neighbor, level + 1});
                visited[neighbor] = true;
            }
        }
    }
    
    if (!found) {
        cout << "Destination not reachable" << '\n';
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
  
    int src, des;
    cin >> src >> des;
    memset(visited, false, sizeof(visited));
    bfs(src, des);
    
    return 0;
}
