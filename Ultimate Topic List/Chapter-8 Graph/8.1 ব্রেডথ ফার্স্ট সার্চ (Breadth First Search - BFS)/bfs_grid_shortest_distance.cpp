#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;
bool visited[MAX][MAX];
int level[MAX][MAX];
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int row, col;
char grid[MAX][MAX];

bool isValid(int i, int j) {
    return (i >= 0 and i < row and j >= 0 and j < col);
}

void bfs(int startX, int startY) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;
    level[startX][startY] = 0;
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        for (auto [dx, dy] : directions) {
            int newX = x + dx;
            int newY = y + dy;
            
            if (isValid(newX, newY) and !visited[newX][newY]) {
                q.push({newX, newY});
                visited[newX][newY] = true;
                level[newX][newY] = level[x][y] + 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> row >> col;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> grid[i][j];
        }
    }
    
    int startX, startY;
    cin >> startX >> startY;
    memset(visited, false, sizeof(visited));
    memset(level, -1, sizeof(level));
    
    bfs(startX, startY);
    
    cout << "Distance to (2, 3): " << level[2][3] << '\n';
    
    return 0;
}
