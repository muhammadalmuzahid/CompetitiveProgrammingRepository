#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    int n; 
    cin >> n;
    vector <string> strings(n);
 
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }
 
    string secret = strings[0];
    map <string, int> freq;
 
    for (int i = 0; i < n; i++) {
        string cur_string = strings[i];
 
        for (int j = 0; j < 5; j++) {
            bool found = false;
            for (int k = 0; k < 5; k++) {
                if (cur_string[j] == secret[k]) {
                    if (j == k) cur_string[j] = '*';
                    else cur_string[j] = '!';
                    found = true;
                }
            }
            if (!found) cur_string[j] = 'X';
        }
        freq[cur_string]++;
    }
 
    int q; 
    cin >> q;
    while (q--) {
        string s; 
        cin >> s;
        cout << freq[s] << '\n';
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