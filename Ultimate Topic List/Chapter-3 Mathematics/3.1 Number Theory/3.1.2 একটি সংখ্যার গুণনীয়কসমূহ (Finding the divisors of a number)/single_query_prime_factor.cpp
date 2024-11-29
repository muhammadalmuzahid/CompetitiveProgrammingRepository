#include <bits/stdc++.h>
using namespace std;

// Use case: For a single query and n <= ((1LL << 63) - 1) or 1e19
vector<unsigned long long> Factorization(unsigned long long n) {
    vector<unsigned long long> Factors;
    for (unsigned long long ii = 2; ii * ii <= n; ii++) {
        if (n % ii == 0) Factors.push_back(ii);
        while (n % ii == 0) n /= ii;
    }
    if (n > 1) Factors.push_back(n);
    return Factors;
}

void idea() {
    unsigned long long n = (1ULL << 63ULL) - 1 + (1ULL << 63ULL);
    vector <unsigned long long> v = Factorization(n);
    for(auto i : v) cout << i << ' '; cout << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    // cin >> T;
    for(int C = 1; C <= T; C++) {
        // cout << "Case " << C << ": " << '\n';
        idea();
    }
    return 0;
}