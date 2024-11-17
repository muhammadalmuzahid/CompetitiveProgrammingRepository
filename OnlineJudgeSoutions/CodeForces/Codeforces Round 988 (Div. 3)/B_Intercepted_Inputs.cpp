#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    int k;
    cin >> k;  

    vector <int> a(k);
    map <int, int> frq;
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        frq[a[i]]++;
    }

    
    int n, m;
    for (int i = 1; i <= k - 2; i++) {
        if ((k - 2) % i == 0) {
            n = i;
            m = (k - 2)/ i;
            if(n != m) {
                if(frq[n] and frq[m]) {
                    cout << n << " " << m << '\n';
                    return;
                }
            }
            if (n == m) {
                if(frq[n] >= 2) {
                    cout << n << " " << m << '\n';
                    return;
                }
            }
        }
    }

    // cout << n << " " << m << '\n';
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