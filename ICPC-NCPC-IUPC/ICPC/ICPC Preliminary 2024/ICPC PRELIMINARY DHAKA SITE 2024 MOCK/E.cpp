#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    double S;
    while (cin >> S && S >= 0) {
        double left = 0.0001, right = sqrt(S); 
        double precision = 1e-7;

        while (right - left > precision) {
            double mid = (left + right) / 2;
            double l = (S - mid * mid) / (2 * mid);

 
            if (l <= 0) {
                right = mid;
                continue;
            }

            double h = sqrt(l * l - (mid / 2) * (mid / 2));
            double V1 = (h > 0) ? (1.0 / 3) * mid * mid * h : 0;

    
            double leftMid = (left + mid) / 2;
            double rightMid = (mid + right) / 2;

            double lLeftMid = (S - leftMid * leftMid) / (2 * leftMid);
            double hLeftMid = (lLeftMid > 0) ? sqrt(lLeftMid * lLeftMid - (leftMid / 2) * (leftMid / 2)) : 0;
            double VLeft = (hLeftMid > 0) ? (1.0 / 3) * leftMid * leftMid * hLeftMid : 0;

            double lRightMid = (S - rightMid * rightMid) / (2 * rightMid);
            double hRightMid = (lRightMid > 0) ? sqrt(lRightMid * lRightMid - (rightMid / 2) * (rightMid / 2)) : 0;
            double VRight = (hRightMid > 0) ? (1.0 / 3) * rightMid * rightMid * hRightMid : 0;

            if (VLeft > V1) {
                right = mid;
            } 
            else if (VRight > V1) {
                left = mid;
            } 
            else {
                left = leftMid;
                right = rightMid;
            }
        }

        double a = (left + right) / 2;
        double l = (S - a * a) / (2 * a);
        double h = sqrt(l * l - (a / 2) * (a / 2));
        double V = (1.0 / 3) * a * a * h;


        cout << fixed << setprecision(4) << V << '\n';
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
