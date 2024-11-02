#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    ll n, single_room, double_room; 
    cin >> n >> single_room >> double_room;
 
    ll ans = 0;
    while (n--) {
        string s; cin >> s;
        sort(s.begin(), s.end());
 
        ll val = 0;
        if (s[0] == s[1] and s[1] == s[2]) {
            val = 3 * single_room;
            val = min(val, (3 * double_room));
            val = min(val, (single_room + double_room));
            val = min(val, (double_room + double_room));
        }
 
        else if (s[0] != s[1] and s[1] != s[2] and s[0] != s[2]) {
            val = 3 * single_room;
            val = min(val, (3 * double_room));
        }
 
        else {
            val = 3 * single_room;
            val = min(val, (3 * double_room));
            val = min(val, (single_room + double_room));
            val = min(val, (double_room + double_room));
        }
 
        ans += val;
    }
 
    cout << ans << '\n';
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