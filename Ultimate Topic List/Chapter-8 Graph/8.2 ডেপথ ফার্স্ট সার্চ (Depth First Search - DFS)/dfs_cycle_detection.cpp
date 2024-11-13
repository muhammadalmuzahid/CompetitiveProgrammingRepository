#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
bool vis[N];
bool pathVisit[N];
vector<int> adj[N];
bool ans;

void dfs(int parent) {
    vis[parent] = true;
    pathVisit[parent] = true;

    for (int child : adj[parent]) {
        if (pathVisit[child]) {
            ans = true;
        }
        if (!vis[child]) {
            dfs(child);
        }
    }
    
    // Mark the node as not part of the current path
    pathVisit[parent] = false;
}

int main() {
    int n, e;
    cin >> n >> e;

    while (e--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        // Uncomment the following line for an undirected graph
        // adj[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));
    memset(pathVisit, false, sizeof(pathVisit));
    ans = false;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    if (ans)
        cout << "Cycle detected";
    else
        cout << "Cycle not detected";

    return 0;
}

/*
Test Case 1:
Input:
4 4
0 1
1 2
2 3
3 1
Output:
Cycle detected

Explanation:
There is a cycle in the graph: 1 -> 2 -> 3 -> 1.

Test Case 2:
Input:
4 3
0 1
1 2
2 3
Output:
Cycle not detected

Explanation:
There is no cycle in the graph.
*/
