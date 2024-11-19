#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    int n;
    cin >> n;

    ll people = 0;
    
    for (int i = 1; i <= n; i++) {
        char x; 
        ll val;
        cin >> x >> val;
        if (x == 'P') {
            people += val;
        }
        else {
            if (people + 1 <= val) {
                cout << "YES" << '\n';
                people = 0;
            }
            else {
                cout << "NO" << '\n';
                people -= val;
            }
        }
    }
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