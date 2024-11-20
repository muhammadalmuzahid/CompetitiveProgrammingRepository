#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
using ll = long long;
const int ARRAY_SIZE  = (int) 2e6+3;

ll f(ll n, ll k) {
    if (n == 1) return 1; // Base case: only one child left.
    
    if (k <= (n + 1) / 2) {
        if (2 * k > n) {
            return (2 * k) % n;
        }
        return 2 * k;
    }
    
    // Recursively find the solution for the second half.
    ll temp = f(n / 2, k - (n + 1) / 2);
    
    // Remap the result to the original range.
    // to map the result to the correct odd position
    if (n % 2 == 1) {
        return 2 * temp + 1;
    }
    else { // to map the result to the correct  even position 
        return 2 * temp - 1;
    }
}


void idea() {
    ll q;
    cin >> q;
    while (q--) {
        ll n, k;
        cin >> n >> k;
        cout << f(n, k) << "\n";
    }
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
