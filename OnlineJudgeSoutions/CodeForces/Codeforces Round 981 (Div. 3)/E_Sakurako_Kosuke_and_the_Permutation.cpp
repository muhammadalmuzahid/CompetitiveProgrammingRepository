#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    int n;
    cin >> n; 
    vector <int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; 
    }
    
    int ans = 0;
    vector <bool> visited(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            int len_cycle = 0;
            int j = i;
            while (!visited[j]){
                visited[j] = true;
                j = a[j]; 
                len_cycle++;
            }
            if (len_cycle >= 3) {
                int operation = (len_cycle - 1) / 2;
                ans += operation;
            }
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