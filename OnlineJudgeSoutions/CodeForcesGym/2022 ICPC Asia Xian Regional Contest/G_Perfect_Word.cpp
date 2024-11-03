#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

bool perfect (string &s, set <string> &st) {
    int n = s.size();
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= n - i; j++) {
            string substring = s.substr(j, i); // starting from j and its length i
            // cout << substring << '\n';
            if(st.find(substring) == st.end()) {
                return false;
            }
        }
    }

    return true;
}

void idea() {
    int n;
    cin >> n;
    vector <string> strings(n);
    for(int i = 0; i < n; i++) {
        cin >> strings[i];
    }
    sort(strings.begin(), strings.end(), [] (const string &a, const string &b){
        return a.size() > b.size();
    });
    set <string> name_set (strings.begin(), strings.end());
    
    for(string s : strings) {
        if(perfect(s, name_set)) {
            cout << (int) s.size() << '\n';
            return;
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