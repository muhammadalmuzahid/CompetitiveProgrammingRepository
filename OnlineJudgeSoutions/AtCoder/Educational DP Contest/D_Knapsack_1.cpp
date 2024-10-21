#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;

const int mx = (int) 1e5 + 5;
int n, c;
int w[mx], profit[mx];
ll dp[103][mx];

ll knapsack (int idx, int currWeight) {
    if (idx > n) return 0;
    if (dp[idx][currWeight] != -1) return dp[idx][currWeight];
    ll taken = 0, not_taken = 0;
    if (currWeight + w[idx] <= c) {
        taken = profit[idx] + knapsack(idx + 1, currWeight + w[idx]);
    }
    not_taken = 0 + knapsack(idx + 1, currWeight);
    
    dp[idx][currWeight] = max(taken, not_taken);
    return dp[idx][currWeight];
}

void idea(){

    cin >> n >> c;
    for(int ii = 1; ii <= n; ii++){
        cin >> w[ii] >> profit[ii];
    }
    memset(dp, -1, sizeof(dp));
    cout << knapsack(1, 0) << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int T = 1;
    // cin >> T;
    for(int C = 1; C <= T; C++){
        idea();
    }

    return 0;
}
