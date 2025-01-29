#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
using ll = long long;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    int n, m;
    cin >> n >> m;

    vector <vector <int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> v[i][j];
        
        sort(v[i].begin(), v[i].end());
    }

    vector <pair <int, int>> vp;
    for (int i = 0; i < n; i++){
        vp.push_back({v[i][0], i});
    }
    sort(vp.begin(), vp.end());

    vector <int> serial;
    for (auto x : vp){
        serial.push_back(x.second + 1);
    }

    bool flag = true;
    int ans = -1;

    for (int i = 0; i < m; i++) {
        for (int index : serial) {
            
            int idx = index - 1;
            if (!v[idx].empty() and v[idx][0] > ans) {
                ans = v[idx][0];
                v[idx].erase(v[idx].begin());
            } 
            else {
                flag = false;
                break;
            }
        }
        if (!flag) {
            break;
        }
    }

    if (flag) {
        for (int i = 0; i < (int) serial.size(); i++) {
            cout << serial[i];
            if(i +1 == serial.size()) cout << '\n';
            else cout << ' ';
        }
    }
    else {
        cout << -1 << '\n';
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