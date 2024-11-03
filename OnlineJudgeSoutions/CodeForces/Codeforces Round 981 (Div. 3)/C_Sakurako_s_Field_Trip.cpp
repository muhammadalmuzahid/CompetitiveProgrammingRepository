#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    int n; 
    cin >> n;
    vector <int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for(int i = 1; i * 2 < n; i++) {
        if (a[i] == a[i - 1]) {
            swap(a[i], a[n - i - 1]);
        }
        else if (a[n - i - 1] == a[n - i]) {
            swap(a[i], a[n - i - 1]);
        }
    }
    ll ans = 0;
    for(int i = 0; i < n - 1; i++) {
        if(a[i] == a[i + 1]){
            ans++;
        }
    }
    cout << ans << '\n';
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