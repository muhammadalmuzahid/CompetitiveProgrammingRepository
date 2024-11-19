#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    int n, k;
    cin >> n >> k;
    vector <int> a(n), b(n);
    for (int &in : a) {cin >> in;}
    for (int &in : b) {cin >> in;}

    int sum = 0;
    vector <int> c(n);
    for (int i = 0; i < n; i++) {
        c[i] = a[i] / b[i];
        sum += c[i];
    }

    if (sum < k) {
        for (int i = 0; i < n; i++) {c[i] = 0;}
    }
    else {
        int over_k = sum - k;
        for (int i = 0; i < n; i++) {
            if (c[i] >= over_k) {
                c[i] -= over_k;
                over_k = 0;
            }
            else if (over_k > c[i]) {
                over_k -= c[i];
                c[i] = 0;
            }
        }
    }
    for (int out : c) {cout << out << ' ';} cout << '\n';
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