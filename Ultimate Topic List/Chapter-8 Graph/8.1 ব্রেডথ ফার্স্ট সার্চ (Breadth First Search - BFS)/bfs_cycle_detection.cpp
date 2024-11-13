#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
bool vis[N];
vector<int> adj[N];
int parentArray[N];
bool ans;

void bfs(int s) {
    queue<int> q;
    q.push(s);
    vis[s] = true;

    while (!q.empty()) {
        int parent = q.front();
        q.pop();

        for (int child : adj[parent]) {
            if (vis[child] == true && parentArray[parent] != child) {
                ans = true;
            }
            if (vis[child] == false) {
                vis[child] = true;
                parentArray[child] = parent;
                q.push(child);
            }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    while (e--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));
    memset(parentArray, -1, sizeof(parentArray));
    ans = false;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            bfs(i);
        }
    }

    if (ans) {
        cout << "Cycle found";
    } else {
        cout << "Cycle not found";
    }

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
Cycle found

Explanation:
There is a cycle in the graph: 1 -> 2 -> 3 -> 1.

Test Case 2:
Input:
4 3
0 1
1 2
2 3
Output:
Cycle not found

Explanation:
There is no cycle in the graph.
*/