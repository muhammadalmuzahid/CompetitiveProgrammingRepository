#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll ARRAY_SIZE = (ll)2e6 + 3;

void idea() {
    int n;
    cin >> n;
    vector<string> strings(n);
    map<string, map<char, int>> frq;

    for (int i = 0; i < n; i++) {
        cin >> strings[i];
        
        // Initialize character frequencies for each string
        for (char ch = 'a'; ch <= 'z'; ch++) {
            frq[strings[i]][ch] = 0;
        }
        
        for (char ch : strings[i]) {
            frq[strings[i]][ch]++;
        }
    }

    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        
        map <char, int> count;
        // Initialize count map for each character
        for (char ch = 'a'; ch <= 'z'; ch++) {
            count[ch] = 0;
        }
        
        for (char ch : s) {
            count[ch]++;
        }

        int ans = 0;
        for (auto &word : strings) {
            map<char, int> now = frq[word];
            bool found = true;

            for (char i = 'a'; i <= 'z'; i++) {
                int need = now[i];
                int have = count[i];
                if (need > have) {
                    found = false;
                    break;
                }
            }

            if (found) {
                ++ans;
            }
        }
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    for (int C = 1; C <= T; C++) {
        cout << "Case " << C << ": " << '\n';
        idea();
    }
    return 0;
}
