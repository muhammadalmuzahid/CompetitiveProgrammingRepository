#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    string s;
    cin >> s;
    map <char, int> frq;
    for(int i = 0; i < (int)s.size(); i++) {
        frq[s[i]]++;
    }

    if(frq['1' ] == 1 and frq['2' ] == 2 and frq['3' ] == 3) {
        cout << "Yes" << '\n';
    }
    else {
        cout << "No" << '\n';
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