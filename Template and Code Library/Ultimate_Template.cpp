#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

#define PI 3.14159265358979323846
#define toLowerCase(s) transform(s.begin(), s.end(), s.begin(), ::tolower);
#define toUpperCase(s) transform(s.begin(), s.end(), s.begin(), ::toupper);

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int dx[] = {+1, -1, 0, 0, +1, +1, -1, -1};
int dy[] = {0, 0, -1, +1, +1, -1, +1, -1};

bool check_prime(ll n) {
    if (n == 2) return true; if (n < 2 or n % 2 == 0) return false;
    for (ll i = 3; i * i <= n; i += 2) { if (n % i == 0) return false; }
    return true;
}
bool check_power_of_two(ll n){ return !(n & (n - 1)); }
bool check_perfect_square(ll n){ if (n < 0) return false; ll root = sqrt(n); return (root * root == n); }
bool check_fibonacci(int n) { return check_perfect_square(5*n*n + 4) or check_perfect_square(5*n*n - 4); }
bool check_parity(ll n) { return __builtin_parityll(n); } // returns 1 if the number has odd parity

void idea(){
    
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    int T = 1;
    // cin >> T;
    for(int C = 1; C <= T; C++) {
        // cout << "Case " << C << ": " << '\n';
        idea();
    }
    return 0;
}