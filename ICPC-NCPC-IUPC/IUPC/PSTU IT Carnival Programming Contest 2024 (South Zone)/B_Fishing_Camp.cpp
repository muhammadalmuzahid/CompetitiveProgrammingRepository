#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = (ll) 1e7 + 5;
const ll mod = (ll) 998244353;

vector <ll> v (N + 5);

void pre() {
    ll ans = 1;
    for (ll i = 1; i + 3 < N; i++) {
        ans = ((ans % mod * i % mod) % mod + mod ) % mod;
        v[i] = ans;
    }
}

void idea() {
    ll n;
    cin >> n;
    cout << v[n + 1] << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    pre();
    int T = 1;
    cin >> T;
    for (int C = 1; C <= T; C++) {
        // cout << "Case " << C << ": " << '\n';
        idea();
    }
    return 0;
}