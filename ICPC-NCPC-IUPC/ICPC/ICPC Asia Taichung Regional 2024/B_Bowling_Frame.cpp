#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
using ll = long long;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    ll w, b;
    cin >> w >> b;

    ll L = 0, R = 1e9;
    ll ans = 0;
    while (L <= R) {
        ll M = (L + R) / 2;
        ll total_pin_can_made = M * (M + 1) / 2;
        if (total_pin_can_made <= w + b) {
            L = M + 1;
            ans = M;
        }
        else {
            R = M - 1;
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