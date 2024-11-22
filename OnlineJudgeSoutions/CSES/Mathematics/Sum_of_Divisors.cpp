#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

// Modular arithmetic functions
ll Modular_Exponentiation(ll base, ll exp, ll mod) {
    ll res = 1LL;
    base = base % mod;
    if (base == 0) return 0;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp = exp / 2LL;
    }
    return res;
}

ll Modular_Addition(ll x, ll y, ll mod) {
    x = x % mod; y = y % mod;
    return (x + y + mod) % mod;
}

ll Modular_Subtraction(ll x, ll y, ll mod) {
    x = x % mod; y = y % mod;
    return (x - y + mod) % mod;
}

ll Modular_Multiplication(ll x, ll y, ll mod) {
    x = x % mod; y = y % mod;
    return (x * y) % mod;
}

ll Modular_Inverse(ll x, ll mod) {
    return Modular_Exponentiation(x, mod - 2LL, mod);
}

// Function to compute the sum of divisors up to n
void idea() {
    ll n;
    cin >> n;
    ll ans = 0;

    // First loop: Direct contributions from divisors up to sqrt(n)
    for (ll i = 1; i * i <= n; i++) {
        ans = Modular_Addition(ans, Modular_Multiplication(n / i, i, MOD), MOD);
    }

    // Second loop: Contributions from ranges where floor(n/d) stays constant
    ll sqrt_n = sqrt(n);
    for (ll i = sqrt_n; i >= 1; i--) {
        ll r = n / i;
        ll l = n / (i + 1);

        if (r > sqrt_n) {
            // Calculate the sum of integers from l+1 to r
            ll sum_r = Modular_Multiplication(r, (r + 1), MOD);
            sum_r = Modular_Multiplication(sum_r, Modular_Inverse(2LL, MOD), MOD);

            ll sum_l = Modular_Multiplication(l, (l + 1), MOD);
            sum_l = Modular_Multiplication(sum_l, Modular_Inverse(2LL, MOD), MOD);

            ll range_sum = Modular_Subtraction(sum_r, sum_l, MOD);
            ans = Modular_Addition(ans, Modular_Multiplication(range_sum, i, MOD), MOD);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    int T = 1;
    // cin >> T;
    for (int C = 1; C <= T; C++) {
        // cout << "Case " << C << ": ";
        idea();
    }
    return 0;
}
