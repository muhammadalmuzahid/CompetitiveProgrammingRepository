#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    int n;
    cin >> n;
    vector <string> vs(n);
    int mx_sz = 0;
    for (int i = 0; i < n; i++) {
        cin >> vs[i];
        mx_sz = max(mx_sz, (int)vs[i].size());

    }
    for (int i = 0; i < n; i++) {
        for (int j = vs[i].size(); j < mx_sz; j++) {
            vs[i].push_back('*');
        }
    }

    char sad[n][mx_sz];
    for (int i = 0; i < n; i++) {
        string s = vs[i];
        for (int j = 0; j < mx_sz; j++) {
            sad[i][j] = s[j];
        }
    }

    for (int j = 0; j < mx_sz; j++) {
        string ans = "";
        for (int i = n - 1; i >= 0; i--) {
            ans.push_back(sad[i][j]);
        }
        while(!ans.empty() and ans.back() == '*') {
            ans.pop_back();
        }
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    for(int C = 1; C <= T; C++) {
        // cout << "Case " << C << ": " << '\n';
        idea();
    }
    return 0;
}