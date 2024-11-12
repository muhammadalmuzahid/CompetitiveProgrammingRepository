#include<bits/stdc++.h>
using namespace std;
#define endl '\n';

typedef long long ll;
typedef unsigned long long ull;


void solve () {
    int n; cin >> n;
    vector<int> a(n, 0);

    vector<bool> pos(n + 1, false); pos[0] = true;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        vector<int> banano_jabe;
        banano_jabe.push_back(a[i]);

        int val = a[i];
        for (int bit = 0; bit < 32; bit++) {
            if (a[i] & (1 << bit)) {
                val = val - (1 << bit);
                banano_jabe.push_back(val);

                val += (1 << bit);
            }
        }

        sort(banano_jabe.begin(), banano_jabe.end());

        // cout << a[i] << ": ";

        // for (auto u: banano_jabe) cout << u << " "; cout << endl;

        for (int j = 0; j < banano_jabe.size(); j++) {
            if (banano_jabe[j] <= n and pos[banano_jabe[j]] == false) {
                pos[banano_jabe[j]] = true;
                // cout << banano_jabe[j];
                break;
            }
        }
    }

    int ok = true;
    for (int i = 1; i < pos.size(); i++) {
        if (pos[i] == false) {
            ok = false;
        }
    }

    cout << (ok == true ? "Yes" : "No") << endl;
}

int main () {
    ios_base::sync_with_stdio(NULL);cin.tie(0);cout.tie(0);

    int t = 1;
    // cin >> t;

    for (int C = 1; C <= t; C++) {
        // cout << "Case " << C << ": ";
        solve();
    }
}