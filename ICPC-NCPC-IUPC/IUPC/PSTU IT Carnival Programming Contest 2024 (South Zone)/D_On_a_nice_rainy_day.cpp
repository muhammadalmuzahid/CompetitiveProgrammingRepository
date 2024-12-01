#include <bits/stdc++.h>
using namespace std;
using ll =  long long;

const int mx_sz = (int) 2e6 + 5;

void idea() {
    ll x, y;
    cin >> x >> y;
    cout << x << ' ' << -y << '\n';
    cout << -x << ' ' << -y << '\n';
    cout << -x << ' ' << y << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    for (int C = 1; C <= T; C++) {
        // cout << "Case " << C << ": " << '\n';
        idea();
    }
    return 0;
}