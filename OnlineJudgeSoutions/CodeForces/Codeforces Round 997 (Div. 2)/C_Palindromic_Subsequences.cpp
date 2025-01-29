#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
using ll = long long;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    int n;
    cin >> n;

    vector <int> a;

    if (n >= 4) {
        a = {1, 1, 2, 3};
        n -= 4;
    } 
    else {
        if (n == 1) a = {1};
        if (n == 2) a = {1, 1};
        if (n == 3) a = {1, 1, 2};
        for (int x : a) cout << x << ' ';
        cout << '\n';
        return;
    }

    while (n > 0) {
        a.push_back(1);
        if (--n > 0) a.push_back(2);
        if (--n > 0) a.push_back(3);
        --n;
    }

    for (int x : a) cout << x << ' ';
    cout << '\n';
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

