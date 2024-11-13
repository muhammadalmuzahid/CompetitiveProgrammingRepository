#include <bits/stdc++.h>
using namespace std;

const int N = 1e8 + 3; 
vector <bool> is_prime(N + 1, true);
vector <long long> saved_primes;
void standard_sieve() { // TC: O(N log log N)
    is_prime[0] = is_prime[1] = false; 
    for (int i = 3; i * i < N; i += 2) {
        if (is_prime[i]) {
            for (int j = i * i; j < N; j += i + i) {
                is_prime[j] = false;
            }
        }
    }
    saved_primes.push_back(2);
    for (int i = 3; i < N; i += 2) {
        if (is_prime[i]) {
            saved_primes.push_back(i);
        }
    }
}
// Use case: multiple queries with n <= 1e7 or higher if memory allows
vector <unsigned long long> Prime_Factorization(unsigned long long n) {
    vector <unsigned long long> prime_factors;
    for (size_t i = 0; i < saved_primes.size() && saved_primes[i] * saved_primes[i] <= n; i++) {
        if (n % saved_primes[i] == 0) {
            prime_factors.push_back(saved_primes[i]);
            while (n % saved_primes[i] == 0)
                n /= saved_primes[i];
        }
    }
    if (n > 1) prime_factors.push_back(n);
    return prime_factors;
}

int main() {
    standard_sieve();
    
    cout << "Number of primes found: " << saved_primes.size() << '\n';
    cout << "Last prime: " << saved_primes.back() << '\n';
    
    unsigned long long n = (1ULL << 63ULL) - 1 + (1ULL << 63ULL);
    vector <unsigned long long> factors = Prime_Factorization(n);
    
    cout << "Prime factors of " << n << ": ";
    for (unsigned long long factor : factors) {
        cout << factor << ' ';
    }
    cout << '\n';
    
    return 0;
}
