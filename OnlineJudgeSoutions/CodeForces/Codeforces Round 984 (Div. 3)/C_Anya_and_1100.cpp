#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    string s;
    cin >> s;
    int n = s.size();
    set <pair <int, int>> have;
    for(int i = 0; i < n; i++) {
        if(i >= 0 and i + 3 < n) {
            if(s[i] == '1' and s[i + 1] == '1' and s[i + 2] == '0' and s[i + 3] == '0') {
                have.insert({i, i + 3});
            }
        }
        if(i - 1 >= 0 and i + 2 < n) {
            if(s[i - 1] == '1' and s[i] == '1' and s[i + 1] == '0' and s[i + 2] == '0') {
                have.insert({i - 1, i + 2});
            }
        }
        if(i - 2 >= 0 and i + 1 < n) {
            if(s[i - 2] == '1' and s[i - 1] == '1' and s[i] == '0' and s[i + 1] == '0') {
                have.insert({i - 2, i + 1});
            }
        }
        if(i - 3 >= 0 and i < n) {
            if(s[i - 3] == '1' and s[i - 2] == '1' and s[i - 1] == '0' and s[i] == '0') {
                have.insert({i - 3, i});
            }
        }
    }

    int q;
    cin >> q;
    while(q--) {
        int i;
        char val;
        cin >> i >> val;
        i -= 1;
        if(n < 4) {
            cout << "NO" << '\n';
            continue;
        }

        if(s[i] == val) {
            if(!have.empty()) {
                cout << "YES" << '\n';
                continue;
            } 
            else {
                cout << "NO" << '\n'; continue;
            }
        }
        else {
            s[i] = val;
            
            if(i - 3 >= 0 and i < n) {
                if(have.find({i - 3, i}) != have.end()) {
                    have.erase(have.find({i - 3, i}));
                }
                if(s[i - 3] == '1' and s[i - 2] == '1' and s[i - 1] == '0' and s[i] == '0') {
                    have.insert({i - 3, i});
                }
            }
            if(i - 2 >= 0 and i + 1 < n) {
                if(have.find({i - 2, i + 1}) != have.end()) {
                    have.erase(have.find({i - 2, i + 1}));
                }
                if(s[i - 2] == '1' and s[i - 1] == '1' and s[i] == '0' and s[i + 1] == '0') {
                    have.insert({i - 2, i + 1});
                }
            }
            if(i - 1 >= 0 and i + 2 < n) {
                if(have.find({i - 1, i + 2}) != have.end()) {
                    have.erase(have.find({i - 1, i + 2}));
                }
                if(s[i - 1] == '1' and s[i] == '1' and s[i + 1] == '0' and s[i + 2] == '0') {
                    have.insert({i - 1, i + 2});
                }
            }
            if(i >= 0 and i + 3 < n) {
                if(have.find({i, i + 3}) != have.end()) {
                    have.erase(have.find({i, i + 3}));
                }
                if(s[i] == '1' and s[i + 1] == '1' and s[i + 2] == '0' and s[i + 3] == '0') {
                    have.insert({i, i + 3});
                }
            }
            if(!have.empty()) {
                cout << "YES" << '\n';
                continue;
            } 
            else {
                cout << "NO" << '\n'; continue;
            }
        }
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