#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
using ll = long long;
const int N  = (int) 2e6+3;

void idea() {
    ll n;
    cin >> n;
    vector <ll> v(n);
    vector <ll> wtf(N, 0);
    ll max_val = 0;
    for(ll i = 0; i < n; i++){
        cin >> v[i];
        max_val = max(v[i], max_val);
        wtf[v[i]]++;
    }
    
    for(ll i = max_val; i >= 1; i--){
        ll cnt = 0;
        for(ll j = i; j <= max_val; j += i){
            if(wtf[j] >= 2){
                cout << j << '\n';
                return;
            }
            if(wtf[j]){
                ++cnt;
            }
            if(cnt == 2){
                cout << i << '\n';
                return;
            }
        }
    }
    cout << 1 << '\n';
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