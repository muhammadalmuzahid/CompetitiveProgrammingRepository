#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
using ll = long long;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    int n;
    cin >> n;
    vector <int> a(n);
    map <int, int> frq, used;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        used[a[i]]++;
    }

    int unused = 1; 
    for (int i = 0; i < n; i++) {
        if (frq[a[i]] == 0) {
            frq[a[i]]++;
            cout << a[i] << ' ';
        } 
        else {
            while (used[unused]) {
                unused++;
            }
            used[unused] = 1; 
            cout << unused << ' ';
        }
    }
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