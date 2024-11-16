#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    int n;
    cin >> n;
    if(n <= 25 and n % 2 != 0) {
        cout << -1 << '\n';
        return;
    }


    if (n % 2 == 0) {
        for (int i = 1; i * 2 <= n; i++) {
            cout << i << ' ' << i << ' ';
        }
        cout << '\n';
        return;
    }

    int x = 3, loop = 2;
    for (int i = 1; i <= n; i++) {
        if (i == 1 or i == 10 or i == 26) {
            cout << 1 << ' ';
        } 
        else if (i == 23 or i == 27) {
            cout << 2 << ' ';
        } 
        else {
        
            cout << x << ' ';
            loop--;
            if(loop == 0) {
                loop = 2;
                x++;
            }
        }
    }
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