#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
using ll = long long;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    map <int, int> frq;
    for (int i = 1; i <= 4; i++) {
        ll x;
        cin >> x;
        frq[x]++;
    }

    for (int i = 1; i <= 5; i++) {
        if (frq[i] == 0) {
            cout << i << '\n';
            return;
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