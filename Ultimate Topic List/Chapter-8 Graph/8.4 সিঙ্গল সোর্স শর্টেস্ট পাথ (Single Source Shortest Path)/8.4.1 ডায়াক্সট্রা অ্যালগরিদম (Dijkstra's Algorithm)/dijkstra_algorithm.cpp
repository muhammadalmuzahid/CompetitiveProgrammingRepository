#include <bits/stdc++.h>
using namespace std;

const int N = 100;
vector<pair<int, int>> v[N];
int dis[N];

class cmp {
public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }
};

void dijkstra(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({src, 0});
    dis[src] = 0;

    while (!pq.empty()) {
        pair<int, int> parent = pq.top();
        pq.pop();
        int node = parent.first;
        int cost = parent.second;

        for (pair<int, int> child : v[node]) {
            int childNode = child.first;
            int childCost = child.second;

            if (cost + childCost < dis[childNode]) {
                // Path relaxation
                dis[childNode] = cost + childCost;
                pq.push({childNode, dis[childNode]});
            }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    while (e--) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    for (int i = 0; i < n; i++) {
        dis[i] = INT_MAX;
    }

    dijkstra(0);

    for (int i = 0; i < n; i++) {
        cout << i << " -> " << dis[i] << endl;
    }

    return 0;
}

/*
Test Cases:

1. Basic Test Case
Input:
5 6
0 1 2
0 2 4
1 2 1
1 3 7
2 3 3
3 4 1
Output:
0 -> 0
1 -> 2
2 -> 3
3 -> 6
4 -> 7

2. Disconnected Graph
Input:
4 2
0 1 5
2 3 10
Output:
0 -> 0
1 -> 5
2 -> 2147483647
3 -> 2147483647

3. Single Node Graph
Input:
1 0
Output:
0 -> 0

4. All Nodes Connected
Input:
3 3
0 1 1
1 2 2
0 2 4
Output:
0 -> 0
1 -> 1
2 -> 3

5. Large Weights
Input:
3 3
0 1 100000
1 2 200000
0 2 500000
Output:
0 -> 0
1 -> 100000
2 -> 300000
*/
