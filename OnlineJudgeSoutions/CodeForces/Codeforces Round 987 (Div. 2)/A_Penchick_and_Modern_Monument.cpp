#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    int n;
    cin >> n;
    vector <int> a(n);

    vector <int> pos;
    map <int, int> frq;
    int val = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        frq[a[i]]++;
        if(cnt < frq[a[i]]) {
            cnt = frq[a[i]];
            val = a[i]; // wtf
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == val) {
            pos.push_back(i);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if(a[i] > val) {
            if (i < pos.back()) {
                ++ans;
            }
        }
    }
    for (int i = (int) pos.back() + 1; i < n; i++) {
        if (a[i] < val) {
            ++ans;
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