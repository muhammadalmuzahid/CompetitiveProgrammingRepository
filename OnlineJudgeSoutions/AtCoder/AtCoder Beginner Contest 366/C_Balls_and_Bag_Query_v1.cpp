#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 2e6 + 5;
vector<ll> cnt(N, 0);
ll d = 0;
void solve(){
    ll x;
    cin >> x;
    if (x == 1) {
        ll val;
        cin >> val;
        if (cnt[val] == 0) {
            d++;
        }
        cnt[val]++;
    }
    else if (x == 2){
        ll val;
        cin >> val;
        if (cnt[val] > 0) {
            cnt[val]--;
         if (cnt[val] == 0) {
            d--;
            }
        }
    }
     else if (x == 3){
        cout << d << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
