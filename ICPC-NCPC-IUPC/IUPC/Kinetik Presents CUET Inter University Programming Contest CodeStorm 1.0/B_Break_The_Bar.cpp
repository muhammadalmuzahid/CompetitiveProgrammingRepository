#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
using ll = long long;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    ll  n, m, p;
    cin >> n >> m >> p;

    if (n * m < p) {
        cout << -1 << '\n';
        return;
    }

    if (n * m == p) {
        cout << p - 1 << '\n';
        return;
    }

    if (n == 1) {
        if (p != m) cout << p << '\n';
        return;
    }

    if (m == 1) {
        if (p != n) cout << p << '\n';
        return;
    }

    if (min(n, m) > p) {
        cout << p + 1 << '\n';
        return;
    }


    ll mn = min(n, m);
    ll mx = max(n, m);


    for (int i = 1; i <= mn; i++) {

        ll baki = n * m - p;

        if (baki % i == 0 and baki / i <= mx) {

            cout << p << '\n';
            return;
        }
    }

    cout << p + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    for(int C = 1; C <= T; C++) {
        // cout << "Case " << C << ": " << '\n';
        idea();
    }
    return 0;
}