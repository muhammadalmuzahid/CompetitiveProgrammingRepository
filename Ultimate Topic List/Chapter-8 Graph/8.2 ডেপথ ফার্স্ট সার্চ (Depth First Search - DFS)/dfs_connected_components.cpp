#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];

void dfs(int src) {
    cout << "Visited node: " << src << '\n';
    visited[src] = true;
    
    for (int child : adj[src]) {
        if (!visited[child]) {
            dfs(child);
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
    
    memset(visited, false, sizeof(visited));
    int componentCount = 0;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            cout << "Starting DFS at component: " << componentCount + 1 << " starting from node " << i << '\n';
            dfs(i);
            componentCount++;
        }
    }
    
    cout << "Number of components: " << componentCount << '\n';
    
    return 0;
}
