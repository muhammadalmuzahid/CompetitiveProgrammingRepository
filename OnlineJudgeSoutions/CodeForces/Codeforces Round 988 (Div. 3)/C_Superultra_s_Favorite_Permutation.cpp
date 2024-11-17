#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

bool check_prime(ll n) {
    if (n == 2)
        return true;
    if (n < 2 or not(n & 1))
        return false;
    for (ll ii = 3; ii * ii <= n; ii += 2) {
        if (n % ii == 0)
            return false;
    }
    return true;
}

void idea() {
    int n;
    cin >> n;

    if (n <= 4) {
        cout << -1<< '\n';
        return;
    }

    vector <int> have;
    for(int i = 2; i <= n; i += 2) {
        have.push_back(i);
    }

    vector <int> res;
    for(int i = 1; i <= n; i+=2){
        res.push_back(i);
    }

    bool got = false;
    int last = res.back();
    for(auto &x : have) {
        if( !check_prime(last + x) ){
            res.push_back(x);
            x = -1;
            got = true;
            break;
        }
    }

    if(!got) {
        cout << -1 << '\n';
        return;
    }

    for(auto i : res) cout << i << ' ';
    for(auto i : have) {if (i != -1) cout << i << ' ';}cout << '\n';
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