#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    int n, k;
    cin >> n >> k;
    
    map <ll, ll> sum;
    for(int i = 1; i <= k; i++) {
        ll b, c;
        cin >> b >> c;
        if(sum[b] == 0) {
            sum[b] = c;
        }
        else {
            sum[b] += c;
        }
    }

    vector <pair <ll, ll>> v;
    for(auto [x, y] : sum) {
        v.push_back({y, x});
    }
    sort(v.rbegin(), v.rend());
    ll ans = 0;
    for(int i = 0; i < min(n, (int)v.size()); i++) {
        ans += v[i].first;
    }
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