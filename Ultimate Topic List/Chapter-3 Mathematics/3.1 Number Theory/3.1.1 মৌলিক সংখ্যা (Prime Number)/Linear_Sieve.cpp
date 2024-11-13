#include <bits/stdc++.h>
using namespace std;

const int N = 1e8 + 3; 
vector <int> spf(N + 1, 0); 
vector <long long> saved_primes; 
void linear_sieve() {
    for (int i = 2; i <= N; i += 2) {
        if (spf[i] == 0) { 
            spf[i] = 2;
            if (i == 2) {
                saved_primes.push_back(2);
            }
        }
    }
    for (int i = 3; i <= N; i += 2) {
        if (spf[i] == 0) { 
            spf[i] = i;
            saved_primes.push_back(i);
        }
        for (int j = 0; j < (int)saved_primes.size() and saved_primes[j] <= spf[i] and i * saved_primes[j] <= N; j++) {
            spf[i * saved_primes[j]] = saved_primes[j];
        }
    }
}

int main() {
    linear_sieve();
    cout << (int)saved_primes.size() << '\n';
    cout << saved_primes.back() << '\n';
    return 0;
}
