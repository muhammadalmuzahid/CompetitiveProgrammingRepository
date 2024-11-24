#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
using ll = long long;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    int mean, med;
    cin >> mean >> med;

    if (mean == med) {
        cout << 1 << '\n';
        cout << mean << '\n';
    }
    else {
        ll val = mean * 3 - med;
        ll x1 = med;
        ll x2 = med;
        ll x3 = med;
        if (x1 + x3 > val) {
            ll extra =  x1 + x3 - val;
            x1 -= extra;
        }
        else if (x1 + x3 < val) {
            ll extra = val -  x1 - x3;
            x3 += extra;
        }
        cout << 3 << '\n';
        cout << x1 << ' ' << x2 << ' ' << x3 << '\n';
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