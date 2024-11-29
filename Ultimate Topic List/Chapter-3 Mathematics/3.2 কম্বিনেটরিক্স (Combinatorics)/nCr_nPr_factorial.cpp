#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
vector<ll> fact;

// Binary exponentiation to compute base^exp % mod
ll Modular_Exponentiation(ll base, ll exp, ll mod) {
    ll res = 1LL;
    base %= mod;
    if (base == 0) return 0;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        exp >>= 1;
        base = (base * base) % mod;
    }
    return res;
}

// nPr % MOD calculation
ll nPr(ll n, ll r, ll mod) { // O(log(MOD))
    if (r > n) return -1;
    ll numerator = fact[n] % mod;
    ll denominator = fact[n - r] % mod;
    numerator = (numerator * Modular_Exponentiation(denominator, mod - 2, mod)) % mod;
    return numerator;
}

// nCr % MOD calculation
ll nCr(ll n, ll r, ll mod) { // O(log(MOD))
    if (r == 0) return 1;
    if (r > n) return -1;
    ll numerator = fact[n] % mod;
    ll denominator = (fact[n - r] * fact[r]) % mod;
    numerator = (numerator * Modular_Exponentiation(denominator, mod - 2, mod)) % mod;
    return numerator;
}

// Precompute factorials up to n % mod
void cal_fact(ll n, ll mod) { 
    fact.resize(n + 1);
    fact[0] = 1;
    for (ll i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

int main() {
    ll N = 1e6;
    cal_fact(N, MOD);

    ll n = 5, r = 3;
    cout << "nPr(" << n << ", " << r << ") % MOD = " << nPr(n, r, MOD) << '\n';
    cout << "nCr(" << n << ", " << r << ") % MOD = " << nCr(n, r, MOD) << '\n';

    return 0;
}
