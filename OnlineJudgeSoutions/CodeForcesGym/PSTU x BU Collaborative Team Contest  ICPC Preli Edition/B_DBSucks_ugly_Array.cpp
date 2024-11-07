#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const ll ARRAY_SIZE = (ll) 2e6 + 3;

ll spf[ARRAY_SIZE];
void sieve() {
    for (ll i = 1; i <= ARRAY_SIZE; i++) {
        spf[i] = i;
    }
    for (ll i = 2; i * i <= ARRAY_SIZE; i++) {
        if (spf[i] == i) { 
            for (ll j = i * i; j <= ARRAY_SIZE; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

void idea() {
    ll n, m;
    cin >> n >> m;
    vector <ll> a(n);

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    while(!a.empty() and a.back() == 1) {
        a.pop_back();
    }

    set <ll> all_spf;
    for(ll val : a) {
        while (val > 1) {
            all_spf.insert(spf[val]);
            val /= spf[val];
        }
    }
    
    ll ans = 1; // for x = 1, 1 <= x <= m

    vector <bool> not_coprime(m + 1, false);
    for (ll prime : all_spf) {
        for (ll mul = prime; mul <= m; mul += prime) {
            not_coprime[mul] = true;
        }
    }

    for (ll i = 2; i <= m; i++) {
        if (!not_coprime[i]) {
            ++ans;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sieve();
    int T = 1;
    cin >> T;
    for (int C = 1; C <= T; C++) {
        idea();
    }
    return 0;
}
