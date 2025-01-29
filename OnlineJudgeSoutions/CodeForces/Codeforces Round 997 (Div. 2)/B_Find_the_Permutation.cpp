#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
using ll = long long;
const int ARRAY_SIZE  = (int) 2e6+3;

vector <string> vs;

bool custom_sort(int u, int v) {
    if (u < v) return vs[u][v] == '1';
    return vs[v][u] == '0';
}

void idea() {
    int n;
    cin >> n;

    vs.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> vs[i];
    }

    vector <int> res(n);
    for (int i = 0; i < n; i++) res[i] = i;

    sort(res.begin(), res.end(), custom_sort);

    for (int i : res) cout << i + 1 << ' ';
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


        