#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int par[N];
int level[N];

class Edge {
public:
    int u, v, w;
    Edge(int x, int y, int z) {
        u = x;
        v = y;
        w = z;
    }
};

int dsu_find(int node) {
    if (par[node] == -1) return node;
    int leader = dsu_find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union_by_rank(int a, int b) {
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);

    if (leaderA != leaderB) {
        if (level[leaderA] < level[leaderB]) {
            par[leaderA] = leaderB;
        } else if (level[leaderA] > level[leaderB]) {
            par[leaderB] = leaderA;
        } else {
            par[leaderB] = leaderA;
            level[leaderA]++;
        }
    }
}

bool cmp(Edge list1, Edge list2) {
    return list1.w < list2.w;
}

int main() {
    int n, e;
    cin >> n >> e;
    vector<Edge> list;
    
    // Reading edges
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        list.push_back(Edge(a, b, c));
    }
    
    // Sorting edges by weight
    sort(list.begin(), list.end(), cmp);
    
    // Initializing DSU structures
    memset(par, -1, sizeof(par));
    memset(level, 0, sizeof(level));
    
    int totalCost = 0;
    
    // Kruskal's algorithm
    for (Edge ed : list) {
        int ledA = dsu_find(ed.u);
        int ledB = dsu_find(ed.v);
        if (ledA != ledB) {
            dsu_union_by_rank(ed.u, ed.v);
            totalCost += ed.w;
            cout << ed.u << " " << ed.v << " " << ed.w << endl;
        }
    }
    
    // Output total cost of MST
    cout << "Total cost of MST: " << totalCost << endl;
    
    return 0;
}

/*
Test Case:
Input:
4 5
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4

Output:
2 3 4
0 3 5
0 1 10
Total cost of MST: 19
*/
