#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

const double eps = 1e-14;
double L, n, C, L1;

// Function to calculate arc length for a given height h
double calc (double h) {
    double r = (h * h + (L * L / 4)) / (2 * h); // Calculate the radius
    double theta = asin(L / (2 * r));            // Calculate the angle theta
    return 2 * theta * r;                        // Return the arc length
}

void idea() {
    cin >> L >> n >> C; 
    L1 = (1 + n * C) * L; 

    // If no expansion, print 0
    if(L1 == L) {
        cout << 0 << '\n';
    }
    else {
        // Binary search to find the correct height h
        double l = 0, r = L, mid; 

        while(abs(r - l) > eps) {
            mid = (l + r) / 2;
            double curr_arc_len = calc(mid);
            if(curr_arc_len - L1 <= eps) l = mid;
            else r = mid;
        }
        cout << fixed << setprecision(9) << r << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    for(int C = 1; C <= T; C++) {
        cout << "Case " << C << ": ";
        idea();
    }
    return 0;
}