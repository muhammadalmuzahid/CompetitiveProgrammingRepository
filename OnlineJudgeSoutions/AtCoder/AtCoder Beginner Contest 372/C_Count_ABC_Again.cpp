#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    set <int> pos;
    for (int i = 0; i + 2 < n; i++) {
        if(s[i] == 'A' and s[i + 1] == 'B' and s[i + 2] == 'C') {
            pos.insert(i);
        }
    }

    while(q--) {
        int x;
        cin >> x;
        x -= 1; // 0 base

        char ch;
        cin >> ch;

        for(int i = x - 2; i <= x; i++) {
            if(i + 2 < n and s[i] == 'A' and s[i + 1] == 'B' and s[i + 2] == 'C') {
                pos.erase(pos.find(i));
            }
        }

        s[x] = ch; // replaced

        for(int i = x - 2; i <= x; i++) {
            if(i + 2 < n and s[i] == 'A' and s[i + 1] == 'B' and s[i + 2] == 'C') {
                pos.insert(i);
            }
        }
        cout << (int) pos.size() << '\n';
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