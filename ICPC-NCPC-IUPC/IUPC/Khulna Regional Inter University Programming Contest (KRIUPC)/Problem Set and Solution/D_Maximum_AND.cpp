#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    int n; 
    cin >> n; 
    
    vector <int> arr(n + 1, 0);
    vector <vector <int>> prefix_bit(n + 1, vector <int>(32, 0));

    
    for (int i = 1; i <= n; i++) {
        int x; 
        cin >> x; 
        arr[i] = x;

        for (int bit = 0; bit < 32; bit++) {
            if (x & (1 << bit)) {
                prefix_bit[i][bit] = prefix_bit[i - 1][bit] + 1;
            } 
            else {
                prefix_bit[i][bit] = prefix_bit[i - 1][bit]; 
            }
        }
    }

    int increment_range = (n % 2 == 0) ? 2 : 1; 

    for (int k = 1; k <= n; k++) {
        if (k <= (n / 2)) {
            
            int ans = 0;
            for (int bit = 0; bit < 32; bit++) {
                if (prefix_bit[n][bit] > 0) {
                    ans += (1 << bit); // Add bit to result if it is present in any number
                }
            }
            cout << ans; 
        } 
        else {
           
            int ans = 0;
            if (n % 2 == 1) {
                
                for (int bit = 0; bit < 32; bit++) {
                    if ((prefix_bit[(n / 2) + 1 + (increment_range / 2)][bit] - prefix_bit[(n / 2) - (increment_range / 2)][bit] >= increment_range)
                        && (prefix_bit[n][bit] > 0)) {
                        ans += (1 << bit); 
                    }
                }
                cout << ans;
                increment_range += 2; 
            } 
            else {
                for (int bit = 0; bit < 32; bit++) {
                    if ((prefix_bit[(n / 2) + (increment_range / 2)][bit] - prefix_bit[(n / 2) - (increment_range / 2)][bit] >= increment_range)
                        && (prefix_bit[(n / 2) - (increment_range / 2)][bit] > 0)) {
                        ans += (1 << bit); 
                    }
                }
                cout << ans;
                increment_range += 2; 
            }
        }

        if (k < n) {
            cout << " "; 
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