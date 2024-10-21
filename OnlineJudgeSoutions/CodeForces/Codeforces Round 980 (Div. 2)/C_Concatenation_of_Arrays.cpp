#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    int n;
    cin >> n;
    
    vector <pair <int, int>> a(n);
    map <pair <ll, ll>, bool > transgender;

    for (int ii = 0; ii < n; ii++){
        int x, y;
        cin >> x >> y;
        a[ii] = {x, y}; 
    }
    
    sort(a.begin(), a.end(), [](pair <int, int> &x, pair <int, int> &y){
        return (x.first + x.second) < (y.first + y.second);
    });
    
    for(auto [x, y] : a){
        cout << x << ' ' << y << ' ';
    }
    cout << '\n';
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