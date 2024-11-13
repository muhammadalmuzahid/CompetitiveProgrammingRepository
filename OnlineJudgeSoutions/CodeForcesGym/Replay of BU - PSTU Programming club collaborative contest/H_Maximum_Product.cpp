#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    ll n;
    cin >> n;
    vector <ll> a(n);
    for (ll &in : a) cin >> in;
    
    sort(a.begin(), a.end());
    ll ans = LLONG_MIN;
    if (count(a.begin(), a.end(), 0) > 0) {
        ans = 0;
    }
    ans = max(ans, a[0] * a[1] * a[2]);
    ans = max(ans, a[0] * a[1] * a[n - 1]);
    ans = max(ans, a[0] * a[n - 2] * a[n - 1]);
    ans = max(ans, a[n - 3] * a[n - 2] * a[n - 1]);
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