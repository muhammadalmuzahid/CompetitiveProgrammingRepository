#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
using ll = long long;
const int ARRAY_SIZE  = (int) 2e6+3;


void idea() {
    ll x, m;
    cin >> x >> m;

    ll ans = 0;
    for (ll y = 1; y <= min(10LL * x, m); y++) {
        ll val = x ^ y; 
        if (val > 0) {
            if ((y % val == 0 or x % val == 0) and x != y) { 
                ans++;
            }
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