#include <bits/stdc++.h>
using namespace std;

const int mx = 2e5 + 5;

vector<int> adj[mx];
bool visited[mx];
int level[mx];
int parent[mx];

void bfs(int src) {
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;
    parent[src] = -1;
    
    while (!q.empty()) {
        int par = q.front();
        q.pop();
        
        for (int child : adj[par]) {
            if (!visited[child]) {
                q.push(child);
                visited[child] = true;
                level[child] = level[par] + 1;
                parent[child] = par;
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
  
    int src, des;
    cin >> src >> des;
    memset(visited, false, sizeof(visited));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));
    
    bfs(src);
    
    if (level[des] == -1) {
        cout << "Destination not reachable" << '\n';
    } else {
        vector<int> path;
        int x = des;
        while (x != -1) {
            path.push_back(x);
            x = parent[x];
        }
        reverse(path.begin(), path.end());
        
        cout << "Shortest path length: " << level[des] << '\n';
        cout << "Path: ";
        for (int val : path) {
            cout << val << " ";
        }
        cout << '\n';
    }
    
    return 0;
}
