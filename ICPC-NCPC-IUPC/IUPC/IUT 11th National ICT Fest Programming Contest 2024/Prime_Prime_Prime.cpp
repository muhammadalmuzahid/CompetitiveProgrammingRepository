#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int sieve_size = 1e6 + 3; // Limit within 10^9 is unnecessary due to prime density
vector<int> save_primes;
vector<bool> is_prime(sieve_size, true);

void Eratosthenes_Sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= sieve_size; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= sieve_size; j += i)
                is_prime[j] = false;
        }
    }
    for (int i = 2; i < sieve_size; i++) {
        if (is_prime[i])
            save_primes.push_back(i);
    }
}

void idea() {
    ll n;
    cin >> n;

    if (n == 1) { // any prime is the answer
        cout << 2 << "\n"; 
        return;
    } 
    else if (n == 2) {
        cout << "2 7\n";
        return;
    } 
    else if (n == 3) {
        cout << "2 3 6\n";
        return;
    }

    // General case for n >= 4
    vector <ll> result;
    result.push_back(2);
    result.push_back(6);
    
    ll base = 10; 
    for (int i = 2; i + 1 < n; i++) {
        result.push_back(base);
        base += 4;
    }

    ll and_ = result[0];
    ll or_ = result[0];
    ll xor_ = result[0];
    for (int i = 1; i + 1 < n; i++) {
        and_ &= result[i];
        or_ |= result[i];
        xor_ ^= result[i];
    }
    for(int i = result.back() + 1; i < (int) 1e6; i++) {
        ll x_and = and_ & i;
        ll x_or = or_ | i;
        ll x_xor = xor_ ^ i;
        if(is_prime[x_and] and is_prime[x_or] and is_prime[x_xor]) {
            result.push_back(i);
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << result[i] << (i < n - 1 ? " " : "\n");
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Eratosthenes_Sieve();
    int T = 1;
    // cin >> T;
    for (int C = 1; C <= T; C++) {
        idea();
    }
    return 0;
}
