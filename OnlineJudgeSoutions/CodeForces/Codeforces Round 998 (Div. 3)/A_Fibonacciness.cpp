#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
using ll = long long;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    int a1, a2, a4, a5;
    cin >> a1 >> a2 >> a4 >> a5;

    int x = a5 - a4;
    int y =  a4 - a2;
    int z =  a1 + a2 ;

    vector <int> v = {x,  y, z };

    int res = 0;

    for (int a3 : v) {
        int ans = 0;
        
        if (a1 + a2 == a3) ans++;
        if (a2 + a3 == a4) ans++;
        if (a3 + a4 == a5) ans++;

        res = max(res, ans);
    }
    cout << res << '\n';
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