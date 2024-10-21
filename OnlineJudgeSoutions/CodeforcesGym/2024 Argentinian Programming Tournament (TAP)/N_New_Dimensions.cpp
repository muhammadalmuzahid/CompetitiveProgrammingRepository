#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    ll n;
    cin >> n;
    vector <ll> a(n);
    for(ll &in : a) cin >> in;
    if(n == 1){
        cout << 0 << '\n';
        return;
    }
    
    sort(a.rbegin(), a.rend());

    ll x = a[0], y, z;
    ll profit = 0;
    for(ll ii = 0; ii < n; ii++){
        y = a[ii];
        for(ll jj = 0; jj < n; jj++) {
            z = a[jj];
            ll sell = x * x + y * y + z * z;
            ll buy = x * y + y * x + z * x;
            profit = max(profit, sell - buy);
        }
    }
    cout << profit << '\n';
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