#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    set <ll> sum_track;
    ll sum = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if(sum_track.find(sum) != sum_track.end() or sum == 0) {
            ++ans;
            sum_track.clear();
            sum = 0;
        }
        else {
            sum_track.insert(sum);
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