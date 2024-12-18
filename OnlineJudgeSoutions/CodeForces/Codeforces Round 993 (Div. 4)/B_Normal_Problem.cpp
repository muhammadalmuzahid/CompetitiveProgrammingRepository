#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
using ll = long long;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    string a;
    cin >> a;

    string b = a;
    for (char i = 0; i < b.size(); i++) {
        if (b[i] == 'p') {
            b[i] = 'q';
        }
        else if (b[i] == 'q') {
            b[i] = 'p';
        }
    }

    reverse(b.begin(), b.end());

    cout << b << '\n';
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