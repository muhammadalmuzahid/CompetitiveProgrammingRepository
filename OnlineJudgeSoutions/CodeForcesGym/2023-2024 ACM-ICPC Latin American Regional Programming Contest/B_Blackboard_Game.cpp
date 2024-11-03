#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    int n; 
    cin >> n;
 
    map <int, int> freq;
    for (int i = 0; i < 3 * n; i++) {
        int x; cin >> x;
        freq[x]++;
    }
 
    bool ok = false;
    for (auto [key, val]: freq) {
        if (val % 3 != 0) {
            ok = true;
            break;
        }
    }
    cout << (ok ? "Y" : "N") << '\n';
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