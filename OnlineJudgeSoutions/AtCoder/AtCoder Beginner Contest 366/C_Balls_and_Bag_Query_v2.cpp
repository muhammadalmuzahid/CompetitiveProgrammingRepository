#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    int n;
    cin >> n;
    map <int, int> frq;
    set <int> s;

    while(n--) {
        int T, x;
        cin >> T;

        if (T == 1) {
            cin >> x;
            frq[x]++;
            s.insert(x);
        }
        else if (T == 2) {
            cin >> x;
            frq[x]--;
            if (frq[x] == 0) {
                s.erase(s.find(x));
            }
        }
        else {
            cout << (int)s.size() << '\n';
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