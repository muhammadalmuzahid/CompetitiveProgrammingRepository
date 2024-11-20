#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int ARRAY_SIZE  = (int) 2e6+3;

ll Modular_Exponentiation(ll base, ll exp, ll mod) {
    if (exp == 0ll) {
        return 1ll;
    }
    ll res = 1LL; base = base % mod;
    if (base == 0) return 0;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    } 
    return res;
}

void idea() {
    ll a, b, c;
    cin >> a >> b >> c;
    
    ll ans1 = Modular_Exponentiation(b, c, (ll) 1e9 + 6);
    ll ans2 = Modular_Exponentiation(a, ans1, (ll) 1e9 + 7);
    cout << ans2 << '\n';
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