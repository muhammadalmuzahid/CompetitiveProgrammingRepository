#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    ll n, m;
    cin >> n >> m;
    vector <ll> a(n);
    for (ll &in : a) cin >> in;
    sort(a.begin(), a.end());
    ll sum = accumulate(a.begin(), a.end(), 0ll);

    if (sum <= m) {
        cout << "infinite" << '\n';
        return;
    }

    ll low = 0, high = (ll) 1e11;
    ll limitx = 0;
    
    while (low <= high) {
        ll mid = (low + high)/ 2; // upto mid is my cur_limit

        ll cur_subsidy = 0;
        for (int i = 0; i < n; i++) {
            cur_subsidy += min(a[i], mid);
        }

        if (cur_subsidy > m) {
            high = mid - 1;
        }
        else if (cur_subsidy <= m) {
            limitx = mid;
            low = mid + 1;
        }
    }

    cout << limitx << '\n';
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