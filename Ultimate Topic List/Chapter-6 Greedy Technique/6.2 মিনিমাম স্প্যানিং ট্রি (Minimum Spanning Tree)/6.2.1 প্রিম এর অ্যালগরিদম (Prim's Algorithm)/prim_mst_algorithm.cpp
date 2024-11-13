#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<pair<int, int>> mat[N];
bool vis[N];

class cmp {
public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

int prims(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({src, 0});
    int totalCost = 0;
    while (!pq.empty()) {
        pair<int, int> current = pq.top();
        int pnode = current.first;
        int pcost = current.second;
        pq.pop();
        
        if (!vis[pnode]) {
            totalCost += pcost;
            vis[pnode] = true;
            
            for (pair<int, int> child : mat[pnode]) {
                int cnode = child.first;
                int ccost = child.second;
                if (!vis[cnode]) {
                    pq.push({cnode, ccost});
                }
            }
        }
    }
    return totalCost;
}

int main() {
    int n, e;
    cin >> n >> e;
    
    // Reading edges
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        mat[a].push_back({b, c});
        mat[b].push_back({a, c});
    }
    
    memset(vis, false, sizeof(vis));
    int totalCost = prims(1);
    
    // Output total cost of MST
    cout << "Total cost of MST: " << totalCost << endl;
    
    return 0;
}

/*
Test Case:
Input:
5 6
1 2 3
1 3 4
4 2 6
5 2 2
2 3 5
3 5 7

Output:
Total cost of MST: 15
*/
