#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int u, v, c;
    Edge(int u, int v, int c) {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

const int N = 1e5 + 5;
int dis[N];

int main() {
    int n, e;
    cin >> n >> e;
    vector<Edge> EdgeList;
    
    // Reading edges
    for (int i = 0; i < e; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        EdgeList.push_back(Edge(u, v, c));
    }
    
    // Initialize distances to infinity
    for (int i = 0; i < n; i++) {
        dis[i] = INT_MAX;
    }
    dis[0] = 0;
    
    // Relaxing edges n-1 times
    for (int i = 1; i <= n - 1; i++) {
        for (Edge ed : EdgeList) {
            int u = ed.u;
            int v = ed.v;
            int c = ed.c;
            if (dis[u] < INT_MAX && dis[u] + c < dis[v]) {
                dis[v] = dis[u] + c;
            }
        }
    }
    
    // Detecting negative weight cycle
    bool hasNegativeCycle = false;
    for (Edge ed : EdgeList) {
        int u = ed.u;
        int v = ed.v;
        int c = ed.c;
        if (dis[u] < INT_MAX && dis[u] + c < dis[v]) {
            hasNegativeCycle = true;
            break;
        }
    }
    
    if (hasNegativeCycle) {
        cout << "Graph contains a negative weight cycle" << endl;
    } else {
        // Output distances
        for (int i = 0; i < n; i++) {
            if (dis[i] == INT_MAX)
                cout << i << " -> " << "INF" << endl;
            else
                cout << i << " -> " << dis[i] << endl;
        }
    }
    
    return 0;
}

/*
Test Case:
Input:
5 6
0 1 4
0 2 1
2 1 2
1 3 1
2 3 5
3 4 3

Output:
0 -> 0
1 -> 3
2 -> 1
3 -> 4
4 -> 7
*/
