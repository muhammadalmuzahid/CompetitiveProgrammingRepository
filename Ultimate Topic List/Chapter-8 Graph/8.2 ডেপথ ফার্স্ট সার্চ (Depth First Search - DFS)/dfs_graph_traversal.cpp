#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;
char grid[MAX][MAX];
bool visited[MAX][MAX];
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;

bool isValid(int row, int col) {
    return (row >= 0 && row < n && col >= 0 && col < m);
}

void dfs(int row, int col) {
    cout << "Visited cell: (" << row << ", " << col << ")\n";
    visited[row][col] = true;

    for (auto [dRow, dCol] : directions) {
        int newRow = row + dRow;
        int newCol = col + dCol;

        if (isValid(newRow, newCol) && !visited[newRow][newCol]) {
            dfs(newRow, newCol);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    int startRow, startCol;
    cin >> startRow >> startCol;
    memset(visited, false, sizeof(visited));

    dfs(startRow, startCol);

    return 0;
}
