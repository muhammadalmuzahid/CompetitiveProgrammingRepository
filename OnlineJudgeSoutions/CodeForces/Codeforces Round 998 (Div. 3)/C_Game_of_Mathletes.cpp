#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
using ll = long long;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    int n, k;
    cin >> n >> k;

    vector <int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    map <int, int> frq;
    int ans = 0;

    for (auto u : v) {
        int rest = k - u;

        if (frq[rest] > 0) {
            ans++;
            frq[rest]--;
        } 
        else{
            frq[u]++;
        }
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