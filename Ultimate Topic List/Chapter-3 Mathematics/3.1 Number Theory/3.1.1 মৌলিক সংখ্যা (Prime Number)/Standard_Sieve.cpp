#include <bits/stdc++.h>
using namespace std;

const int N = 1e8 + 3; // Adjust limit as needed
vector <bool> is_prime(N + 1, true);
vector <long long> saved_primes;

void standard_sieve() { // TC: O(NloglogN)
    is_prime[0] = is_prime[1] = false; 
    for (int i = 3; i * i < N; i += 2) {
        if (is_prime[i]) {
            for (int j = i * i; j < N; j += i + i) {
                is_prime[j] = false;
            }
        }
    }
    // Saved primes up to N
    saved_primes.push_back(2);
    for (int i = 3; i < N; i += 2) {
        if (is_prime[i]) {
            saved_primes.push_back(i);
        }
    }
}

int main() {
    standard_sieve();
    cout << (int) saved_primes.size() << '\n';
    cout << saved_primes.back() << '\n';
    return 0;
}

/*
https://codeforces.com/problemset/customtest
=====
Used: 562 ms, 108184 KB
*/
