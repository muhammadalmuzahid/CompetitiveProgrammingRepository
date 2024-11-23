#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
using ll = long long;
const int ARRAY_SIZE  = (int) 2e6+3;

ll number_of_leap_from_1_to_n (ll year) {
    return (year / 4 - year / 100 + year / 400);
}

void idea() {
    ll start_y, end_y; 
    cin >> start_y >> end_y;

    ll R = number_of_leap_from_1_to_n(end_y);
    ll L = number_of_leap_from_1_to_n(start_y - 1);
    ll total_leap = R - L;
    ll not_leap_year = (end_y - start_y + 1) - total_leap;

    ll ans = (total_leap * 53) + (not_leap_year * 52);
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