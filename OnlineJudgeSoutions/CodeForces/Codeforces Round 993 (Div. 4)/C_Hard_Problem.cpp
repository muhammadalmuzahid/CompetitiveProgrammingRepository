#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
using ll = long long;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    ll m, a, b, c;
    cin >> m >> a >> b >> c;

    ll x = min(a, m);  
    ll y = min(b, m); 


    ll rem1 = m - x;
    ll rem2 = m - y;

    ll extra = min(c, rem1 + rem2);
    ll ans = x + y + extra;
    cout << ans << '\n';
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