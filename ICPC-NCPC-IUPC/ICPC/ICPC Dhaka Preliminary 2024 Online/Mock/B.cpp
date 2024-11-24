#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    vector<char> alpha;

    for (int i = 33; i <= 126; i++) {
        alpha.push_back(char(i));
    }
    char x, y;
    cin >> x >> y;
    vector <pair <int, int>> ans;

    for (int row = 1; row <= 94; row++) {
        int col = (94 / row) + (94 % row != 0);

        for (int i = 0; i < row; i++) {
            int found = 0;
            for (int j = 0; j < col; j++) {
                if (i + row * j < 94 and (alpha[i + row * j] == x or alpha[i + row * j] == y))
                    found++;
            }
            if (found == 2)
                ans.push_back({row, col});
        }
    }

    sort(ans.begin(), ans.end());
    for (auto u : ans)
        cout << u.first << " " << u.second << '\n';
    cout << '\n';
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