#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
using ll = long long;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    ll k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;

    vector <ll> expo;
    ll p = 1LL;
    while (p <= r2) {
        expo.push_back(p);
        if (p * k > r2) {
            break;
        } 
        p *= k;
    }

    ll ans = 0;
    for (ll x : expo) {
        ll L = max(l1, (l2 + x - 1) / x); 
        ll R = min(r1, r2 / x);             
        if (L <= R) {
            ans += (R - L + 1);
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