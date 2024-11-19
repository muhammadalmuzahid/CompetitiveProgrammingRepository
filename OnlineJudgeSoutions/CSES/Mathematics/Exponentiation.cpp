#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

ll Modular_Exponentiation(ll base, ll exp, ll mod) {
    ll res = 1LL; base = base % mod;
    if (base == 0) return 0;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    } return res;
}

void idea() {
    ll a, b;
    cin >> a >> b;
    if (a == 0 and b == 0) {
        cout << 1 << '\n';
        return;
    }
    ll ans = Modular_Exponentiation(a, b, (ll) 1e9 + 7);
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