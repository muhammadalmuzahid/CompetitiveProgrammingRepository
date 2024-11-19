#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    int n;
    cin >> n;

    int ans = 0;

    if (n <= 6) {
        cout << n + 1 << '\n';
        return;
    }
    

    if (n % 2 == 0) {
        // n / 2 sonkhok plank nile amar 18 width  n / 2 sonkhok tokta sesh hoye zay
        // as well 21 width tokta purapuri clear
        ans += n / 2; 
        ans += n / 2; // 25 width er jonno sob neya sesh
        n /= 2;
        ans += (n + 2)/ 3; // bki 18 ta neya sesh
        cout << ans << '\n';
    }

    else {
        ans += n/2; // 18w -> n/2 + 1 remain, 21w -> 1 ta
        ans += n/2; // 25 width er jonno sob neya sesh hoy nai pagla

        ans++; // 25 21

        n = n / 2;
        n += 1;
        // n -= 2;

        if(n > 0) {
            // sobgula 18 er
            ans += (n + 2) / 3;
        }
        cout << ans << '\n';
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