#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    int n;
    cin >> n; 
    vector < vector <int> > a(n, vector <int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> diag_min(2 * n - 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            diag_min[i - j + n - 1] = min(diag_min[i - j + n - 1], a[i][j]);
        }
    }

    int ans = 0;
    for (int i = 0; i < (int) diag_min.size(); i++) {
        if (diag_min[i] < 0) {
            ans += abs(diag_min[i]);  
        }
    }
    cout << ans << '\n';
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