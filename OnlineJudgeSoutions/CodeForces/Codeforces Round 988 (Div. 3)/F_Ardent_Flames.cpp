#include <bits/stdc++.h>
#define debug(x) cout << #x << " = "; cout << x << '\n';
using namespace std;
typedef long long ll;
const int ARRAY_SIZE  = (int) 2e6+3;


bool comp( pair<ll, ll> &a,  pair<ll, ll> &b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    else {
        return a.first < b.first;
    }
}


void idea() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector <ll> h(n), p(n);

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    ll damage_m = m;

    ll low = 1, high = 1e11;
    ll res = -1;

    while (low <= high) {

        ll mid = (low + high) / 2;
        // debug(mid);

        vector <pair <ll, ll>> vp;
        for (int i = 0; i < n; i++) {
            ll need = (h[i] + mid - 1) / mid;
            
            if (need > damage_m) {
                continue;
            }

            ll dis = damage_m - need;
            // debug(dis);

            ll L = p[i] - dis;
            ll R = p[i] + dis;
            // debug(L);
            // debug(R);
            
            vp.push_back({L, 1});  
            vp.push_back({R + 1, -1}); 
        }

        if (vp.empty()) {
            low = mid + 1;
            continue;
        }
        sort(vp.begin(), vp.end(), comp);
        // cout << vp << '\n';
        
        bool possible = false;
        ll cnt = 0;

        for (int i = 0; i < (int) vp.size(); i++) {
            cnt += vp[i].second;
            // cout << cnt<< '\n';
            if(i + 1 < (int) vp.size()) {
                if (vp[i].first == vp[i + 1].first){
                    continue;
                }
            }

            if (cnt >= k) {
                possible = true;
                break;
            }
        }

        if (possible) {
            high = mid - 1;
            res = mid;
        } 
        else {
            low = mid + 1;
        }
        vp.clear();
    }

    cout << res << '\n';
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