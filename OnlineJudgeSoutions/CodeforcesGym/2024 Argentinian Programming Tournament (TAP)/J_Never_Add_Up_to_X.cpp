#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    int n, x;
    cin >> n >> x;
    vector<int> ar(n);
    
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    
    // Sort the array of beauties
    sort(ar.begin(), ar.end());

    int l = 0;     // leftmost pointer
    int r = n - 1; // rightmost pointer
    bool f = true; // flag to check if a valid arrangement exists

    for (int i = 1; i < n; i++) {
        if (!f) break;
        if (ar[i] + ar[i - 1] == x) {
            if (ar[i - 1] != ar[l]) {
                swap(ar[l], ar[i - 1]);
                l += 2;
            }
            else if (ar[i] != ar[r]) {
                swap(ar[r], ar[i]);
                r -= 2;
            }
            else {
                f = false;
            }
        }
    }

    f = true;
    // Second check to ensure no two adjacent elements sum to x
    for (int i = 1; i < n; i++) {
        if (ar[i] + ar[i - 1] == x) {
            f = false;
            break;
        }
    }

    // Output the result
    if (f) {
        for (int i = 0; i < n; i++)
            cout << ar[i] << " ";
        cout << '\n';
    } else {
        cout << "*" << '\n';
    }
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