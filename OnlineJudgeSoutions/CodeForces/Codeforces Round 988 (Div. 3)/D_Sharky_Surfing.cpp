#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;

// Pair Input
template <typename typC, typename typD> 
istream &operator>>(istream &cin, pair<typC, typD> &a) {
    return cin >> a.first >> a.second;
}

// Pair Output
template <typename typC, typename typD> 
ostream &operator<<(ostream &cout, const pair<typC, typD> &a) {
    return cout << a.first << ' ' << a.second;
}

// Vector Input
template <typename typC> 
istream &operator>>(istream &cin, vector<typC> &a) {
    for (auto &x: a) cin >> x;
    return cin;
}

// Vector Output
template <typename typC> 
ostream &operator<<(ostream &cout, const vector<typC> &a) {
    int n = a.size();
    if (n == 0) return cout;
    cout << a[0];
    for (int ii = 1; ii < n; ii++) cout << ' ' << a[ii];
    return cout;
}

// Vector of Pairs Output
template <typename typC, typename typD> 
ostream &operator<<(ostream &cout, const vector<pair<typC, typD>> &a) {
    for (const auto &x : a) cout << x << '\n';
    return cout;
}

// Map Output
template <typename typC, typename typD> 
ostream &operator<<(ostream &cout, const map<typC, typD> &m) {
    for (const auto &[x, y] : m) cout << x << ' ' << y << '\n';
    return cout;
}

// Set Output
template <typename typC> 
ostream &operator<<(ostream &cout, const set<typC> &s) {
    for (const auto &x : s) cout << x << ' ';
    return cout;
}

// Matrix Input
template <typename typC>
istream &operator>>(istream &cin, vector<vector<typC>> &mat) {
    for (auto &row : mat) {
        for (auto &elem : row) {
            cin >> elem;
        }
    }
    return cin;
}

// Matrix Output
template <typename typC>
ostream &operator<<(ostream &cout, const vector<vector<typC>> &mat) {
    for (const auto &row : mat) {
        for (const auto &elem : row) {
            cout << elem << ' ';
        }
        cout << '\n';
    }
    return cout;
}


void idea() {
    int n, m, L;
    cin >> n >> m >> L;

    vector <pair <ll, ll>> obst(n);
    for (auto &[x, y] : obst) {
        cin >> x >> y;
    }

    vector <pair <ll, ll>> power(m);
    for (auto &[x, y] : power) {
        cin >> x >> y;
    }

    // cout << obst << '\n';
    // cout << power << '\n';

    priority_queue <ll> pq;

    ll jump = 1;
    ll ans = 0;
    bool possible = true;

    for (int i = 0, j = 0; i < n; i++) {

        while (j < m and power[j].first < obst[i].first) {
            pq.push(power[j].second);
            j++;
        }
        ll need_covering_dis = obst[i].second - obst[i].first + 2;
        while (jump < need_covering_dis ) {
            if(pq.empty()) {
                cout << -1 << '\n';
                return;
            }
            jump += pq.top();
            pq.pop();
            ans++;
        }
    }
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