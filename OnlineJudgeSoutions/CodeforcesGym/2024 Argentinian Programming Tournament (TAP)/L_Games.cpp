#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    int n, q;
    cin >> n >> q;
    vector <int> a(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector <int> alice(n + 1, 0), bob(n + 1, 0), count_one(n + 1, 0);

    for(int i = 1; i <= n; i++){
        int x = a[i];
        if((x & (~(x - 1))) == x){
            alice[i] += x;
        }
        if(x & 1){
            bob[i] += x;
        }
        if(x == 1){
            count_one[i] += x;
        }
        alice[i] += alice[i - 1];
        bob[i] += bob[i - 1];
        count_one[i] += count_one[i - 1];
    }

    while(q--){
        int L, R;
        cin >> L >> R;

        ll A = alice[R] - alice[L- 1];
        ll B = bob[R] - bob[L - 1];
        ll one = count_one[R] - count_one[L - 1];

        A -= one;
        B -= one;

        if(one & 1ll){
            A += (one + 1) / 2;
            B += (one / 2);
        }
        else{
            A += (one / 2);
            B += (one / 2);
        }

        if(A > B) cout << 'A' << '\n';
        else if(B > A)  cout << 'B' << '\n';
        else cout << 'E' << '\n';
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