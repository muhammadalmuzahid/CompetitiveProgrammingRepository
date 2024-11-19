#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    int n;
    cin >> n;
    vector <int> a(n);
    map <int, int> frq;
    vector <int> ans;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        frq[a[i]]++;
    }
    for (int val : a) {
        if (frq[val] >= 2) {
            ans.push_back(val);
            frq[val] -= 2;
        }
    }

    sort(ans.begin(), ans.end());

    if ((int) ans.size() < 4) { cout << "NO" << '\n'; }
    else {
        int sz = ans.size();
        
        int x1 = ans[0];
        int y1 = ans[1];

        int x2 = ans[sz - 2];
        int y2 = ans[1];

        int x3 = ans[sz - 2];
        int y3 = ans[sz - 1];

        int x4 = ans[0];
        int y4 = ans[sz - 1];

        cout << "YES" << '\n';
        cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ';
        cout << x3 << ' ' << y3 << ' ' << x4 << ' ' << y4 << '\n';
    }
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