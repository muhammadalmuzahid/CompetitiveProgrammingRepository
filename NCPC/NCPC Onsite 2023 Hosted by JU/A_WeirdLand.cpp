#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    ll x, y, g;
    cin >> x >> y >> g;

    ll X = (ll) 1e9 - g; // prior_prob1 = (1e9 - g) / 1e9
    ll Y = (ll) g; // prior_prob2 = (g) / 1e9

    ll G = gcd(X, Y);
    X /= G;
    Y /= G;

    cout << X << '/' << Y << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    for(int C = 1; C <= T; C++) {
        cout << "Case " << C << ": ";
        idea();
    }
    return 0;
}