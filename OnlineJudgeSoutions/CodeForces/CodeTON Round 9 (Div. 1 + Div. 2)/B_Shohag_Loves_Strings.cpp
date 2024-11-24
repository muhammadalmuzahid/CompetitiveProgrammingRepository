#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
using ll = long long;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    string s;
    cin >> s;
    int n = s.size();
    if (n == 1) {
        cout << -1 << '\n';
    }
    else {
        for (int i = 0; i + 1 < n; i++) {
            if (s[i] == s[i + 1]) {
                cout << s[i] << s[i + 1] << '\n';
                return;
            }
        }
        for (int i = 0; i + 2 < n; i++) {
            if (s[i] != s[i + 1] and s[i + 1] != s[i + 2] and s[i] != s[i + 2]) {
                cout << s[i] << s[i + 1] << s[i + 2] << '\n';
                return;
            }
        }
        cout << -1 << '\n';
    }
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