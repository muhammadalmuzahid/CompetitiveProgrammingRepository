#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    ll a, b, c;
    cin >> a >> b >> c;

    ll x = 4 * (a + b+ c);
    ll y = (a + b - c) * (a + c - b) * (b + c - a);

    ll G = gcd(x, y);
    x /= G;
    y /= G;

    cout << y << '/' << x << '\n';
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