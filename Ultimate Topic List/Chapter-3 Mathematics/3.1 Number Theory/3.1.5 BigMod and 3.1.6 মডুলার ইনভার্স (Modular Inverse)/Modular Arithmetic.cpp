#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll Modular_Exponentiation(ll base, ll exp, ll mod) {
    ll res = 1LL;
    base %= mod;
    while (exp) {
        if (exp % 2) res = res * base % mod;
        base = base * base % mod;
        exp /= 2;
    }
    return res;
}
ll Modular_Addition(ll x, ll y, ll mod) {
    return ((x % mod + y % mod) % mod + mod) % mod;
}
ll Modular_Subtraction(ll x, ll y, ll mod) {
    return ((x % mod - y % mod) % mod + mod) % mod;
}
ll Modular_Multiplication(ll x, ll y, ll mod) {
    return ((x % mod * y % mod) % mod + mod) % mod;
}
ll Modular_Inverse(ll x, ll mod) {
    return Modular_Exponentiation(x, mod - 2, mod);
}

int main() {
    ll base = 3, exp = 5, mod = 1000000007;
    cout << "Modular Exponentiation: " << Modular_Exponentiation(base, exp, mod) << '\n';

    ll a = 15, b = 10;
    cout << "Modular Addition: " << Modular_Addition(a, b, mod) << '\n';
    cout << "Modular Subtraction: " << Modular_Subtraction(a, b, mod) << '\n';
    cout << "Modular Multiplication: " << Modular_Multiplication(a, b, mod) << '\n';

    ll num = 7;
    cout << "Modular Inverse: " << Modular_Inverse(num, mod) << '\n';

    return 0;
}
