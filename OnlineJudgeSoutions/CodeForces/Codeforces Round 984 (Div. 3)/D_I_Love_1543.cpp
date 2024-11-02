#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    ll n, m;
    cin >> n >> m;

    char matrix[n + 10][m + 10];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> matrix[i][j];
        }
    }

    int top = 1, bottom = n, left = 1, right = m;
    int sum = 0;

    while (top < bottom and left < right) {
        
        vector <char> v;

        // Top row (left to right)
        for (int j = left; j <= right; j++) {
            v.push_back(matrix[top][j]);
        }
        top++; // Move top boundary down

        // Right column (top to bottom)
        for (int i = top; i <= bottom; i++) {
            v.push_back(matrix[i][right]);
        }
        right--; // Move right boundary left

        // Bottom row (right to left)
        for (int j = right; j >= left; j--) {
            v.push_back(matrix[bottom][j]);
        }
        bottom--; // Move bottom boundary up

        // Left column (bottom to top)
        for (int i = bottom; i >= top; i--) {
            v.push_back(matrix[i][left]);
        }
        left++; // Move left boundary right

        if (v.size() >= 4) {
            v.push_back(v[0]);
            v.push_back(v[1]);
            v.push_back(v[2]);
        }

        ll cnt = 0;
        for (int i = 0; i + 3 < (int) v.size(); i++) {
            if (v[i] == '1' and v[i + 1] == '5' and v[i + 2] == '4' and v[i + 3] == '3') {
                cnt++;
                i += 3; 
            }
        }
        sum += cnt;
    }
    cout << sum << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    for(int C = 1; C <= T; C++) {
        // cout << "Case " << C << ": " << '\n';
        idea();
    }
    return 0;
}