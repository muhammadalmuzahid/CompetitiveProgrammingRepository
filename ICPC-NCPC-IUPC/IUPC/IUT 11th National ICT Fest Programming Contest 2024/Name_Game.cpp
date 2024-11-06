#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    string s;
    cin >> s;

    transform(s.begin(), s.end(), s.begin(), ::tolower);
    char x = s[0];
    s.pop_back();
    
    if(s.empty()) {
        if(x != 'z'){
            s += 'z';
        }
        else{
            s += 'a';
        }
    }
    cout << s << '\n';
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