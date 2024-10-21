#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    int N;
    cin >> N;
    vector <int> h(N + 5, 0);
    for(int ii = 1; ii <= N; ii++){
        cin >> h[ii];
    }
    vector <ll> dp (N + 5, 0);
    dp[N] = 0;
    
    for(ll ii = N - 1; ii >= 1; ii--){
        ll cost1 = LLONG_MAX, cost2 = LLONG_MAX;
        if(ii + 1 <= N) cost1 = abs(h[ii] - h[ii + 1]) + dp[ii + 1];
        if(ii + 2 <= N) cost2 = abs(h[ii] - h[ii + 2]) + dp[ii + 2];
        dp[ii] = min(cost1, cost2);
    }
    cout << dp[1] << '\n';
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