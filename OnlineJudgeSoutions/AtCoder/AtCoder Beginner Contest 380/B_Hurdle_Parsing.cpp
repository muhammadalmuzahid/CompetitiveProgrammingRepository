#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    string s;
    cin >> s;
    vector <ll> res;
    for(int i = (int)s.size() - 1; i >= 0; ) {
        int cnt = 0;
        int j = i;
        while (j > 0 and s[j] != '|') {
            j--;
            ++cnt;
        }
        res.push_back(cnt);
        i = j - 1;
        i--;
    }
    reverse(res.begin(), res.end());
    res.pop_back();
    for(auto x : res) cout << x + 1 << ' '; cout << '\n';
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