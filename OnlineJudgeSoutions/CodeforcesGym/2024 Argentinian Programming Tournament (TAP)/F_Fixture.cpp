#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    int n;
    cin >> n;
    vector <int> a(n);
    int ans = 0;
    for(int &in : a) {
        cin >> in;
        if(in == 0){
            ans--;
        }
        else {
            ans++;
        }
    }
    if(n >= 3){
        if(a[0] == 1 and a[1] == 1 and a[2] == 1){
            ++ans;
        }
        for(int i = 3; i < n; i++) {
            if(a[i - 2] == 1 and a[i - 1] == 1 and a[i] == 1) {
                ++ans;
            }
        }
    }
    cout << ans << '\n';
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