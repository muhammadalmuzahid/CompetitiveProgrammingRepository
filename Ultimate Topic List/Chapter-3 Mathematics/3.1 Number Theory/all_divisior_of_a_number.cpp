#include <bits/stdc++.h>
using namespace std;

vector <long long> all_diviosors(long long n) {
    vector<long long> divisor;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisor.push_back(i);
            if (i * i != n) {
                divisor.push_back(n / i);
            }
        }
    }
    return divisor; // TC: O(Root(N))
}
int main() {
    vector <long long> div = all_diviosors(30);
    for (long long i : div) { cout << i << ' '; cout << '\n'; }
    return 0;
}