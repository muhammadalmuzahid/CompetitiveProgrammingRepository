#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;
bool visited[MAX][MAX];
int distanceGrid[MAX][MAX];
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;
char grid[MAX][MAX];

bool isValid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs(int startX, int startY) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;
    distanceGrid[startX][startY] = 0;
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        for (auto [dx, dy] : directions) {
            int newX = x + dx;
            int newY = y + dy;
            
            if (isValid(newX, newY) && !visited[newX][newY]) {
                q.push({newX, newY});
                visited[newX][newY] = true;
                distanceGrid[newX][newY] = distanceGrid[x][y] + 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    
    int startX, startY;
    cin >> startX >> startY;
    memset(visited, false, sizeof(visited));
    memset(distanceGrid, -1, sizeof(distanceGrid));
    
    bfs(startX, startY);
    
    cout << "Distance to (2, 3): " << distanceGrid[2][3] << '\n';
    
    return 0;
}
