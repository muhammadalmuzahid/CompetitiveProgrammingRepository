#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    ll N;
    cin >> N;
    vector <ll> a(N + 5, 0), b(N + 5, 0), c(N + 5, 0);
    for(ll ii = 1; ii <= N; ii++){
        cin >> a[ii] >> b[ii] >> c[ii];
    }
    vector <ll> dp1(N + 3, 0), dp2(N + 3, 0), dp3(N + 3, 0);
    dp1[1] = a[1];
    dp2[1] = b[1];
    dp3[1] = c[1];

    for(ll ii = 2; ii <= N; ii++){
        ll max_hap1 = max(dp2[ii - 1] + a[ii], dp3[ii - 1] + a[ii]);
        dp1[ii] = max_hap1;

        ll max_hap2 = max(dp1[ii - 1] + b[ii], dp3[ii - 1] + b[ii]);
        dp2[ii] = max_hap2;

        ll max_hap3 = max(dp1[ii - 1] + c[ii], dp2[ii - 1] + c[ii]);
        dp3[ii] = max_hap3;
    }

    cout << max({dp1[N], dp2[N], dp3[N]}) << '\n';
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