#include <bits/stdc++.h>
using namespace std;

#define MAXSIEVE 100000001
#define MAXSIEVEHALF (MAXSIEVE >> 1)
#define MAXSQRT 5000
#define isprime(n) ((is_prime[n >> 4] & (1 << ((n >> 1) & 7))) && ((n & 1) || (n == 2)))

char is_prime[MAXSIEVE / (1 << 4) + 2];
vector<int> Yarin_primes;

void Yarin() {
    
    memset(is_prime, (1 << (1 << 3)) - 1, sizeof(is_prime)); 
    is_prime[0] = 0xFE; 

    for (int i = 1; i < MAXSQRT; i++) {
        if (is_prime[i >> 3] & (1 << (i & 7))) { 
            for (int j = 2 * i * (i + 1); j < MAXSIEVEHALF; j += (i << 1) + 1) {
                is_prime[j >> 3] &= ~(1 << (j & 7)); 
            }
        }
    }
    
}

void nPrime() {
    for (int i = 2; i < MAXSIEVE; i++) {
        if (isprime(i)) {
            Yarin_primes.push_back(i);
        }
    }
}

int main() {
    Yarin();
    nPrime();
    
    // Output the number of primes found and the last prime for verification
    cout << "Number of primes found: " << Yarin_primes.size() << '\n';
    if (!Yarin_primes.empty()) {
        cout << "Last prime: " << Yarin_primes.back() << '\n';
    }
    for (int prime : Yarin_primes) {
        cout << prime << " ";
    }
    cout << '\n';
    return 0;
}
