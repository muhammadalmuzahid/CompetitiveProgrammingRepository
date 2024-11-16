#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector <pair <int, int>> pos;

    for(int i = 0; i < n; i++) {
        
        if(s[i] == '1') {
            int L = i + 1, R = i + 1;
            int j = i;
            while(j < n and s[j] == '1') {
                R = j + 1;
                j++;
            }
            pos.push_back({L, R});
            i = j - 1;
        }
    }
    pair <int, int> k_minus1 = pos[k - 2];
    pair <int, int> k_minus2 = pos[k - 1];
    int gap = k_minus2.second - k_minus2.first;
    int fill = k_minus2.first - k_minus1.second - 1;
    for(int i = k_minus1.second; i <= k_minus1.second + gap; i++) {
        s[i] = '1';
    }
    for(int i = k_minus1.second + gap + 1; i <= k_minus1.second + gap + 1 + fill; i++) {
        s[i] = '0';
    }
    cout << s << '\n';
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