#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;
const ll   MOD1e9     = (ll) 1e9+7;

ll Factoeial_Store[ARRAY_SIZE];

ll Factorial_Pre_Computation() { 
    
    Factoeial_Store[0] = 1;
    Factoeial_Store[1] = 1;
    ll ans = 1;
    for(ll i = 2; i + 1 <= ARRAY_SIZE; i++) {
        if(ans * i > MOD1e9) {
            ans *= i;
            ans %= MOD1e9;
        }
        else {
            ans *= i;
        }
        Factoeial_Store[i] = ans;
    }
    return ans;
}
ll Modular_Multiplication(ll x, ll y, ll Mod){
    x = x % Mod;
    y = y % Mod;
    return (((x * y) % Mod) + Mod) % Mod;
}
ll Modular_Exponentiation(ll base, ll exponent, ll Mod){
    ll res = 1LL;
    base = base % Mod;
    if (base == 0)
        return 0;
    while (exponent > 0){
        if (exponent & 1)
            res = (res * base) % Mod;
        exponent = exponent >> 1;
        base = (base * base) % Mod;
    }
    return res;
}

void idea() {
    ll S, N, M;
    cin >> S >> N >> M;
    // ans = S! N!^(M-K)  where K = S / N
    
    ll s_fact = Factoeial_Store[S];
    ll n_fact = Factoeial_Store[N];
    ll K = S / N;
    ll m_minus_k = M - K;

    ll n_fact_power_m_minus_k = Modular_Exponentiation(n_fact, m_minus_k, MOD1e9);
    ll ans = Modular_Multiplication(s_fact, n_fact_power_m_minus_k, MOD1e9);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Factorial_Pre_Computation();
    int T = 1;
    cin >> T;
    for(int C = 1; C <= T; C++) {
        // cout << "Case " << C << ": " << '\n';
        idea();
    }
    return 0;
}