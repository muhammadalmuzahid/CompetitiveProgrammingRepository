#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
using ll = long long;
const int ARRAY_SIZE  = (int) 2e6+3;

void idea() {
    ll n, p, x, a;
    cin >> n >> p >> x >> a;

    p += x;

    vector <ll> v(n + 1, 0), pre(n + 3, 0);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        pre[i] = pre[i - 1] + v[i];
    }

    priority_queue<ll, vector<ll>, greater<ll> > pq;
    // pq.push(0);
    ll big_sum = 0;

    for (int i = 1; i <= a; i++) {
        pq.push(v[i]);
        big_sum += v[i];
    }

    ll ans = a;

    for (int i = a + 1; i <= n; i++) {
        if (!pq.empty()) {
            if (v[i] > pq.top()) {
                ll x = pq.top(); pq.pop();
                big_sum -= x;
                big_sum += v[i];
                pq.push(v[i]);
            }
        }

        ll need_p = pre[i] - big_sum;
        if (need_p <= p) {
            ans++;
        }
        else {
            break;
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