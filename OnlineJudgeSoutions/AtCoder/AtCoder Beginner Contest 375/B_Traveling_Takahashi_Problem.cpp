#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    int n;
    cin >> n;

    double ans = 0;
    double x1, x2, y1, y2;
    cin >> x1 >> y1;

    ans += sqrt((x1 - 0) * (x1 - 0) + (y1 - 0) * (y1 - 0));
    for(int i = 2; i <= n; i++) {
        cin >> x2 >> y2;
        ans += sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        x1 = x2;
        y1 = y2;
    }
    ans += sqrt((x1 - 0) * (x1 - 0) + (y1 - 0) * (y1 - 0));

    cout << fixed << setprecision(12) << ans << '\n';
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